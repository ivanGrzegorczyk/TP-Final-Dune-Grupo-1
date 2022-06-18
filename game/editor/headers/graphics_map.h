#ifndef GRAPHICS_MAP_H_
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
    GraphicsMap() {};
    virtual ~GraphicsMap() = default;
    void update() {};
};
#endif // GRAPHICS_MAP_H_