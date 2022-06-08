#include "cell.h"
#include <iostream>
Cell::Cell(): currentPixmap(0), flipImage(false)
{
    QImage img;
    // qrc resource handling
    if(!img.load(":crate.png")) throw std::invalid_argument("bad filename");
    int imageCount = 1;
    int sideLength = img.width();

    auto pix = QPixmap::fromImage(img);
    this->setPixmap(pix);
}

void Cell::update()
{
    auto current = this->pixmap();
    if (flipImage){
        // Espejo la imagen para dibujar una animación de movimiento hacia la derecha
        this->setPixmap(current.transformed(QTransform().scale(-1, 1)));
    } else {
        this->setPixmap(current);
    }
}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    flipImage = true;
    this->update();
}
