#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "cell.h"
#include "mapa_editor.h"
#include <memory>
#include "cell.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(MapaEditor&& map);
    virtual ~GameScene() = default;
    void set_active_texture(std::string& texture);
    std::shared_ptr<std::string> active_texture; //todo make readonly with method

private slots:
    //void keyPressEvent(QKeyEvent *event) override;

private:
    std::vector<std::shared_ptr<Cell>> cells;
    MapaEditor map;
};

#endif // GAMESCENE_H
