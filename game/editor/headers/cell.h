#ifndef CELL_H
#define CELL_H
#include "mapa_editor.h"
#include "terrain.h"
#include <QGraphicsPixmapItem>
#include <QList>
#include <QPixmap>
#include <memory>

class Cell : public QGraphicsPixmapItem
{
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    Cell(MapaEditor& map, std::shared_ptr<Terrain> terrain, coordenada_t position);
    virtual ~Cell() = default;
    void update();
    void place_tile(std::shared_ptr<Terrain> terrain);

private:
    QList<QPixmap> pixmaps;
    QPixmap currentTexture; //unscaled current texture
    int currentPixmap;
    bool hovering;
    MapaEditor& map;
    coordenada_t position;
    std::shared_ptr<Terrain> current_brush;
};

#endif // CELL_H
