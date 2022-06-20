#include "../../game/editor/headers/gamescene.h"
#include <iostream>
#include <fstream>
#include <algorithm>
GameScene::GameScene(std::shared_ptr<MapaEditor> map) : map(map)
{
    std::vector<std::string> terrains = {"rock", "mountain", "sand"};
    for(std::string name : terrains) { 
        std::shared_ptr<Terrain> terr(new Terrain(name));
        terrain_types.push_back(terr);
    }
    brush.reset(new EditorState(terrain_types[0]));
    GraphicsMap* gm = new GraphicsMap();
    for(auto it = map->begin(); it != map->end(); ++it) {
        auto cell = *it;
        coordenada_t coord = cell.id;
        Cell* p = new Cell(map, brush, coord);
        p->setParentItem(gm);
        p->setAcceptHoverEvents(true);
        p->setPos(cell.id.first*30,cell.id.second*30);
    }
    this->addItem(gm);
}

// TODO Generalize to 'set current mode'. Mode can be placing a building, or painting terrain
void GameScene::set_active_texture(std::string& texture) {
    if(texture == "building") {
        brush->move_building();
        return;
    }
    //TODO use map
    auto lambda = [texture](std::shared_ptr<Terrain> t){  return t->name() == texture; };
    auto found = std::find_if(terrain_types.begin(), terrain_types.end(), lambda);
    if(found == terrain_types.end()) {
        throw std::invalid_argument("bad texture name");
    }
    brush->change_brush(*found);
}

void GameScene::save(std::string& filename) {
    std::ofstream my_file(filename);
    my_file << map->to_yaml();
    my_file.close();
}

