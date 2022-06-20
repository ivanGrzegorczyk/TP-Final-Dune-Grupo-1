#ifndef CELL_H
#define CELL_H
#include "mapa_editor.h"
#include "terrain.h"
#include "shared_brush.h"
#include "graphics_map.h"
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
    enum {Type = UserType + 1};
    Cell(std::shared_ptr<MapaEditor> map, std::shared_ptr<EditorState> brush, coordenada_t position);
    virtual ~Cell() = default;
    void place_tile(std::shared_ptr<Terrain> terrain, unsigned int seed = -1);
    void move_building();
    void update();
    int type() const override {
        return Type;
    }

private:
    QList<QPixmap> pixmaps;
    QPixmap currentTexture; //unscaled current texture
    bool hovering;
    std::shared_ptr<MapaEditor> map;
    coordenada_t position;
    std::shared_ptr<EditorState> current_brush;
};

#endif // CELL_H
