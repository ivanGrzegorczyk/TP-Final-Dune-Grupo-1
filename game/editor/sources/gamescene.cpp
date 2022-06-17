#include "../../game/editor/headers/gamescene.h"
#include <iostream>
#include <fstream>
#include <algorithm>
GameScene::GameScene(MapaEditor&& map) : map(map)
{
    std::vector<std::string> names = {"rock", "mountain", "sand"};
    for(std::string name : names) { 
        std::shared_ptr<Terrain> terr(new Terrain(name));
        terrain_types.push_back(terr);
    }
    brush.reset(new SharedBrush(terrain_types[0]));
    for(auto it = map.begin(); it != map.end(); ++it) {
        auto cell = *it;
        Cell* p = new Cell(map, brush, cell.id);
        QRect rect = p->pixmap().rect();
        p->setAcceptHoverEvents(true);
        p->setPos(cell.id.first*30,cell.id.second*30);
        this->addItem(p);
    }
}

void GameScene::set_active_texture(std::string& texture) {
    //TODO use map
    auto lambda = [texture](std::shared_ptr<Terrain> t){  return t->name() == texture; };
    auto found = std::find_if(terrain_types.begin(), terrain_types.end(), lambda);
    if(found == terrain_types.end()) {
        throw std::invalid_argument("bad texture name");
    }
    brush->change_brush(*found);
    std::cout <<  "set:" << brush->brush()->name() << std::endl;
}

void GameScene::save() {
    std::ofstream my_file("data.yaml");
    my_file << map.to_yaml();
}

