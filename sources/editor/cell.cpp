#include "cell.h"
#include <iostream>
#include <qpainter.h>
#include <QBitmap>
Cell::Cell(): currentPixmap(0), hovering(false)
{
    QImage img;
    // qrc resource handling
    if(!img.load(":crate.png")) throw std::invalid_argument("bad filename");
    int imageCount = 1;
    int sideLength = img.width();

    auto pix = QPixmap::fromImage(img);
    pixmaps.push_back(pix);

    auto painter = QPainter();
    painter.setPen(QColor(0, 0, 255));
    painter.drawPixmap(pix.rect(), pix, pix.rect());
    pixmaps.push_back(pix);
    currentTexture = pixmaps[0];
    this->setPixmap(currentTexture);
}

void Cell::update()
{

}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    auto current = currentTexture;
    this->setPixmap(current.transformed(QTransform().scale(1.05, 1.05)));
}

void Cell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)  {
    auto current = currentTexture;
    this->setPixmap(current);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPixmap mask = QPixmap(pixmaps[1]);
    mask.fill(Qt::red);
    currentTexture = mask;
    this->setPixmap(mask);
}
