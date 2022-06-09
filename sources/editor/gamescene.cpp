#include "gamescene.h"
#include <iostream>
GameScene::GameScene()
{
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 18; j++){
            Cell* p = new Cell();
            QRect rect = p->pixmap().rect();
            std::cout << rect.x() << "-" << rect.y()<< "-" << rect.width()<< "-" << rect.height()<< ",";
            p->setAcceptHoverEvents(true);
            p->setPos(j*30,i*30);
            this->addItem(p);
        }
    }
}

void GameScene::set_active_texture(std::string& texture) {
    //todo
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
}
