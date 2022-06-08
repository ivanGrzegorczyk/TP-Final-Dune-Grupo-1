#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "cell.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene();
    virtual ~GameScene() = default;

private slots:
	// Método polimorfico definido por QWidget. Por default no hace nada
	// pero yo quiero procesar eventos del teclado para mover a mi personaje
    void keyPressEvent(QKeyEvent *event) override;

private:
    Cell c;
};

#endif // GAMESCENE_H
