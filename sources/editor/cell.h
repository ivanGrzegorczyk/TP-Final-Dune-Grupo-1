#ifndef CELL_H
#define CELL_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QPixmap>

class Cell : public QGraphicsPixmapItem
{
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
public:
    Cell();
    virtual ~Cell() = default;
    void update();

private:
    QList<QPixmap> pixmaps;
    int currentPixmap;
    bool flipImage;
    qreal xOffset = 0;
};

#endif // CELL_H
