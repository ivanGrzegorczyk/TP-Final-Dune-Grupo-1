#ifndef CELL_H
#define CELL_H
#include "mapa_editor.h"
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
    Cell(MapaEditor& map, const std::shared_ptr<std::string> active_texture, coordenada_t position);
    virtual ~Cell() = default;
    void update();
    void place_tile(std::string terrain);

private:
    QList<QPixmap> pixmaps;
    QPixmap currentTexture; //unscaled current texture
    std::shared_ptr<std::string> current_brush;
    int currentPixmap;
    bool hovering;
    MapaEditor& map;
    coordenada_t position;
};

#endif // CELL_H
