#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "cell.h"
#include "mapa_editor.h"
#include "shared_brush.h"
#include "terrain.h"
#include <memory>
#include "cell.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(std::shared_ptr<MapaEditor> map);
    virtual ~GameScene() = default;
    void set_active_texture(std::string& texture);
    void save();
    std::shared_ptr<SharedBrush> brush;

private slots:
    //void keyPressEvent(QKeyEvent *event) override;

private:
    std::vector<std::shared_ptr<Cell>> cells;
    std::shared_ptr<MapaEditor> map;
    std::vector<std::shared_ptr<Terrain>> terrain_types;
};

#endif // GAMESCENE_H
