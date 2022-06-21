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
    int filas; int columnas;
    coordenada_t ubicacion_centro_construccion = {-1,-1};
    public:
    MapaEditor(MapaEditor& other) = delete;
    MapaEditor& operator=(MapaEditor& other) = delete;
    MapaEditor(MapaEditor&& other) = default;
    MapaEditor& operator=(MapaEditor&& other) = default;
    MapaEditor(int filas, int columnas) : filas(filas), columnas(columnas) {
        std::string name("default"); //TODO centralize all terrains
        std::shared_ptr<Terrain> terr(new Terrain(name));
        for(int i = 0; i < filas; i++) {
            fila_t fila;
            for(int j = 0; j < columnas; j++) {
                CeldaEditor c({i, j}, terr);
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
            mapa[celda.second][celda.first].terrain = terrain;
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
                << YAML::Value << std::to_string(filas)
                << YAML::Key << "columns"
                << YAML::Value << std::to_string(columnas)
                << YAML::Key << "cells"
                << YAML::Value  
                    << YAML::BeginSeq;
        for(int i = 0; i < filas; i++) {
            for(int j = 0; j < columnas; j++) {
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
            _mapa(mapa), max(mapa.filas * mapa.columnas), num(_num) {}
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
            int y = int(num / _mapa.columnas);
            int x = int(num % _mapa.columnas);
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
        return MapIterator(*this, filas * columnas);
    }
};

// MapIterator

#endif  // MAPA_EDITOR_H_
