#include "../../headers/editor/gamescene.h"
#include <iostream>
#include <fstream>
GameScene::GameScene(MapaEditor&& map) : map(map)
{
    this->active_texture.reset(new std::string("rock"));
    for(auto it = map.begin(); it != map.end(); ++it) {
        auto cell = *it;
        Cell* p = new Cell(map, this->active_texture, cell.id);
        QRect rect = p->pixmap().rect();
        p->setAcceptHoverEvents(true);
        p->setPos(cell.id.first*30,cell.id.second*30);
        this->addItem(p);
    }
}

void GameScene::set_active_texture(std::string& texture) {
    this->active_texture->assign("mountain");
    std::ofstream my_file("data.yaml");
    my_file << map.to_yaml();
}

