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
    void place_tile(std::string terrain);

private:
    QList<QPixmap> pixmaps;
    QPixmap currentTexture; //unscaled current texture
    std::string current_terrain;
    int currentPixmap;
    bool hovering;
    qreal xOffset = 0;
};

#endif // CELL_H
