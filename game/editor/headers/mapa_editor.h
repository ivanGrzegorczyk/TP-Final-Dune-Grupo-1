#ifndef MAPA_EDITOR_H_
#define MAPA_EDITOR_H_

#include <vector>
#include <string>
#include <iostream>
#include "yaml-cpp/yaml.h"

#include "celda_editor.h"

typedef std::vector<std::vector<CeldaEditor>> matriz_t;
typedef std::vector<CeldaEditor> fila_t;

class MapaEditor {
    matriz_t mapa;
    int x; int y;
    coordenada_t ubicacion_centro_construccion = {-1,-1};
    public:
    MapaEditor(MapaEditor& other) = delete;
    MapaEditor& operator=(MapaEditor& other) = delete;
    MapaEditor(MapaEditor&& other) = default;
    MapaEditor& operator=(MapaEditor&& other) = default;
    MapaEditor(int x, int y) : x(x), y(y) {
        std::string name("default"); //TODO centralize all terrains
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
    const CeldaEditor& cell(coordenada_t coordinate) const {
        return mapa[coordinate.second][coordinate.first];
    }
    void colocar_centro_construccion(coordenada_t& coordenada) {
        // coordenada es valida
        // TODO sistema de propiedades mejor, clase mapa
        coordenada_t nula = {-1, -1};
        if(ubicacion_centro_construccion != nula) {
            mapa[ubicacion_centro_construccion.second][ubicacion_centro_construccion.first]
                .propiedades.clear();
        }
        ubicacion_centro_construccion = coordenada;
        mapa[coordenada.second][coordenada.first]
            .propiedades.emplace_back("centro_construccion");
    }
    coordenada_t construction_center() {
        return ubicacion_centro_construccion;
    }
    void place_terrain(std::vector<coordenada_t> celdas, std::shared_ptr<Terrain> terrain) {
        for(coordenada_t celda : celdas) {
            std::cout <<  "from " << mapa[celda.second][celda.first].terrain->name();
            mapa[celda.second][celda.first].terrain = terrain;
            std::cout << "to" << mapa[celda.second][celda.first].terrain->name() << std::endl;
        }
    }
    std::string to_yaml() {
        YAML::Emitter out;
        out << YAML::BeginMap;
            out << YAML::Key << "name";
            out << YAML::Value << "My cool map";
            out << YAML::Key << "num_players";
            out << YAML::Value << "12345"; // TODO set in ui
            out << YAML::Key << "map";
            out << YAML::Value 
                << YAML::BeginMap
                << YAML::Key << "rows"
                << YAML::Value << std::to_string(x)
                << YAML::Key << "columns"
                << YAML::Value << std::to_string(y)
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
                        if(ubicacion_centro_construccion == current) {
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
