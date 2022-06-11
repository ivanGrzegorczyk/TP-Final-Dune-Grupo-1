#include "../../headers/editor/gamescene.h"
#include <iostream>
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
    /*
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 18; j++){
            Cell* p = new Cell(this->active_texture);
            QRect rect = p->pixmap().rect();
            p->setAcceptHoverEvents(true);
            p->setPos(j*30,i*30);
            this->addItem(p);
        }
    }
    */
}

void GameScene::set_active_texture(std::string& texture) {
    std::cout << "Setting active texture to mountain" << std::endl;
    this->active_texture->assign("mountain");
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
}
