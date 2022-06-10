#include "gamescene.h"
#include <iostream>
GameScene::GameScene()
{
    std::shared_ptr<std::string> texture(new std::string("rock"));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 18; j++){
            Cell* p = new Cell(texture);
            QRect rect = p->pixmap().rect();
            std::cout << rect.x() << "-" << rect.y()<< "-" << rect.width()<< "-" << rect.height()<< ",";
            p->setAcceptHoverEvents(true);
            p->setPos(j*30,i*30);
            this->addItem(p);
        }
    }
}

void GameScene::set_active_texture(std::string& texture) {
    this->active_texture.reset(new std::string(texture));
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
}
