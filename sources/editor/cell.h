#ifndef CELL_H
#define CELL_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QPixmap>

class Cell : public QGraphicsPixmapItem
{
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    Cell();
    virtual ~Cell() = default;
    void update();

private:
    QList<QPixmap> pixmaps;
    int currentPixmap;
    bool hovering;
    qreal xOffset = 0;
};

#endif // CELL_H
