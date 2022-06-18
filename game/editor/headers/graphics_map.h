#ifndef GRAPHICS_MAP_H_
#define GRAPHICS_MAP_H_
#include "mapa_editor.h"
#include "terrain.h"
#include "shared_brush.h"
#include <QGraphicsWidget>
#include <QRectF>
#include <QPixmap>

class GameScene;
class GraphicsMap : public QGraphicsWidget
{
public:
    enum {Type = UserType + 2}; //Todo use constant
    GraphicsMap();
    virtual ~GraphicsMap() = default;
    void update();
    int type() const override;
};
#endif // GRAPHICS_MAP_H_