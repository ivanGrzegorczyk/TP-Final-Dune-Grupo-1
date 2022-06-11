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
    GameScene(MapaEditor&& mapa);
    virtual ~GameScene() = default;
    void set_active_texture(std::string& texture);
    std::shared_ptr<std::string> active_texture; //todo make readonly with method

private slots:
	// Método polimorfico definido por QWidget. Por default no hace nada
	// pero yo quiero procesar eventos del teclado para mover a mi personaje
    void keyPressEvent(QKeyEvent *event) override;

private:
    std::vector<std::shared_ptr<Cell>> cells;
};

#endif // GAMESCENE_H
