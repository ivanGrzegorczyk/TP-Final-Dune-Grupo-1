#include "../../headers/editor/gamescene.h"
#include <iostream>
GameScene::GameScene()
{
    this->active_texture.reset(new std::string("rock"));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 18; j++){
            Cell* p = new Cell(this->active_texture);
            QRect rect = p->pixmap().rect();
            p->setAcceptHoverEvents(true);
            p->setPos(j*30,i*30);
            this->addItem(p);
        }
    }
}

void GameScene::set_active_texture(std::string& texture) {
    std::cout << "Setting active texture to mountain" << std::endl;
    this->active_texture->assign("mountain");
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
}
