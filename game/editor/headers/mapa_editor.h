#ifndef MAPA_EDITOR_H_
#define MAPA_EDITOR_H_

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "celda_editor.h"
#include "terrain.h"
#define MIN_PLAYERS 1
#define MIN_X 2
#define MIN_Y 2

typedef std::vector<std::vector<CeldaEditor>> matriz_t;
typedef std::vector<CeldaEditor> fila_t;

class MapaEditor {
    matriz_t mapa;
    int x; int y; int num_players;
    std::vector<coordenada_t> construction_center_location;
    std::vector<std::string> names = {"rock", "mountain", "sand"};
    std::vector<std::shared_ptr<Terrain>> terrain_types; 
    public:
    MapaEditor(MapaEditor& other) = delete;
    MapaEditor& operator=(MapaEditor& other) = delete;
    MapaEditor(MapaEditor&& other) = default;
    MapaEditor& operator=(MapaEditor&& other) = default;
    MapaEditor(int x, int y, int num_players) : x(x), y(y), num_players(num_players) {
        for(std::string name : names) { 
            std::shared_ptr<Terrain> terr(new Terrain(name));
            terrain_types.push_back(terr);
        }
        if(x < MIN_X || y < MIN_Y || num_players < MIN_PLAYERS)
            throw std::invalid_argument("bad user input");
        std::string name("rock"); //TODO centralize all terrains
        std::shared_ptr<Terrain> terr(new Terrain(name));
        for(int i = 0; i < y; i++) {
            fila_t fila;
            for(int j = 0; j < x; j++) {
                CeldaEditor c({j, i}, terr);
                fila.push_back(c);
            }
            mapa.push_back(fila);
        }
    }
    int width() const {
        return x;
    }
    int height() const {
        return y;
    }
    int get_num_players() const {
        return num_players;
    }
    const CeldaEditor& cell(coordenada_t coordinate) const {
        if(!is_cell(coordinate)) {
            throw std::invalid_argument("not a cell in the map\n");
        }
        return mapa[coordinate.second][coordinate.first];
    }
    bool is_cell(coordenada_t coordinate) const {
        return coordinate.first < x && coordinate.second < y;
    }

    bool is_buildable_cell(coordenada_t coordinate) const {
        return is_cell(coordinate) 
            && cell(coordinate).terrain->name() == "rock"
            && !(is_construction_center(coordinate));
    }

    //TODO building class with this logic
    /*
        Gets all positions that would be occupied by the 
        building if placed on the map,
        with its top left corner at <position>.
        Does not take into account if a position is invalid.
        Ordered first by y/height and then by x/width.
    */
    std::vector<coordenada_t> get_positions(
            const int x, const int y, const int size_x, const int size_y) const {
        std::vector<coordenada_t> myvect;
        for (char _y = 0; _y < size_y; _y++) {
            for (char _x = 0; _x < size_x; _x++) {
                int block_x = x + _x;
                int block_y = y + _y;
                coordenada_t _block({block_x,block_y});
                myvect.push_back(_block);
            }
        }
        return myvect;
    }
    void colocar_centro_construccion(coordenada_t& coord) {
        // TODO better property system
        // TODO building class
        if(construction_center_location.size() >= num_players) {
            throw std::invalid_argument("cant place any more construction centers!");
        }
        // check if building fits and terrain works
        std::vector<coordenada_t> occupied_cells = get_positions(coord.first, coord.second, 2,2);
        for(coordenada_t cell : occupied_cells) {
            if(!is_buildable_cell(cell)) 
                throw std::invalid_argument("cant place that building!");
        }
        
        construction_center_location.push_back(coord);
        mapa[coord.second][coord.first]
            .propiedades.emplace_back("centro_construccion");
    }
    /*
    For every construction center. do any of their cells intersect this one?
    */
    bool is_construction_center(coordenada_t coordinate) const {
        for(coordenada_t l : construction_center_location) {
            auto positions = get_positions(l.first, l.second, 2,2);
            auto found = std::find(positions.begin(), positions.end(), coordinate);
            if(found != positions.end()) {
                return true;
            }
        }
        return false;
    }
    void place_terrain(std::vector<coordenada_t> celdas, std::shared_ptr<Terrain> terrain, unsigned int seed = -1) {
        for(coordenada_t celda : celdas) {
            mapa[celda.second][celda.first].terrain = terrain;
            if(terrain->name() == "sand") {
                mapa[celda.second][celda.first].set_seed_level(seed);
            }
        }
    }
    std::string to_yaml() {
        YAML::Emitter out;
        out << YAML::BeginMap;
            out << YAML::Key << "name";
            out << YAML::Value << "My cool map";
            out << YAML::Key << "num_players";
            out << YAML::Value << num_players;
            out << YAML::Key << "map";
            out << YAML::Value 
                << YAML::BeginMap
                << YAML::Key << "rows"
                << YAML::Value << std::to_string(y)
                << YAML::Key << "columns"
                << YAML::Value << std::to_string(x)
                << YAML::Key << "cells"
                << YAML::Value  
                    << YAML::BeginSeq;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                std::string terrain(cell({i,j}).terrain->name());
                out 
                    << YAML::BeginMap
                        << YAML::Key << "terrain"
                        << YAML::Value <<  terrain
                        << YAML::Key << "buildings"
                        << YAML::BeginSeq;
                        // building is always defined at its rightmost position
                        coordenada_t current({i,j});
                        if(is_construction_center(current)) {
                            out << YAML::BeginMap
                                << YAML::Key << "name"
                                << YAML::Value << "Construction Center"
                                << YAML::Key << "size"
                                << YAML::Value 
                                << YAML::BeginSeq << "2" << "2" 
                                << YAML::EndSeq 
                                << YAML::EndMap;
                        }
                            
                        out << YAML::EndSeq
                        << YAML::Key << "pos"
                        << YAML::Value 
                        << YAML::BeginSeq
                            << std::to_string(i) << std::to_string(j)
                        << YAML::EndSeq
                    << YAML::EndMap;
                // end cell
            }
        }
        out << YAML::EndSeq 
        << YAML::EndMap
        << YAML::EndMap;
        return std::string(out.c_str());
    }

    // create from yaml, using first terrain type as default.
    static MapaEditor* from_yaml(std::string path) {
        YAML::Node read = YAML::LoadFile(path);
        int num_players = read["num_players"].as<int>();
        int y = read["map"]["rows"].as<int>();
        int x = read["map"]["columns"].as<int>();
        MapaEditor* m = new MapaEditor(x,y,num_players);
        for(YAML::Node cell : read["map"]["cells"]) {
            x = cell["pos"][0].as<int>();
            y = cell["pos"][1].as<int>();
            coordenada_t cell_pos = {x,y};
            std::vector<coordenada_t> cells{cell_pos};
            std::string terr = cell["terrain"].as<std::string>();
            std::shared_ptr<Terrain> terrain_ptr(new Terrain(terr)); //TODO dont create new terrain
            m->place_terrain(cells, terrain_ptr); //TODO centralized system
        }
        return m;
    }

    //iterator
    
    class MapIterator {
        const MapaEditor& _mapa;
        int max;
        public:
        int32_t num = 0;
        MapIterator(MapaEditor& mapa, int _num = 0) : 
            _mapa(mapa), max(mapa.x * mapa.y), num(_num) {}
        MapIterator& operator++() {
            if (num < max) num++;
            return *this;
        }
        MapIterator operator++(int) {
            MapIterator retval = *this; 
            ++(*this); 
            return retval;
        }
        bool operator==(MapIterator other) const {
            return num == other.num;
        }

        bool operator!=(MapIterator other) const {
            return !(*this == other);
        }
        const CeldaEditor& operator*() {
            int x = int(num / _mapa.y);
            int y = int(num % _mapa.y);
            std::cout << "updating:" << std::to_string(x) << " " << std::to_string(y) << std::endl;
            coordenada_t coord = {x,y};
            return _mapa.cell(coord);
        }
        // MapIterator traits
        using difference_type = long;
        using value_type = long;
        using pointer = const long*;
        using reference = const long&;
        using MapIterator_category = std::forward_iterator_tag;
    };
    MapIterator begin() {
        return MapIterator(*this, 0);
    }
    MapIterator end() {
        return MapIterator(*this, x * y);
    }
};

// MapIterator

#endif  // MAPA_EDITOR_H_
