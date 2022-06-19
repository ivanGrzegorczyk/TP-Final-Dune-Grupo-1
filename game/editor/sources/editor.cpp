#include <iostream>
#include "../../game/editor/headers/mapa_editor.h"
#include <SDL.h>
#include <SDL_image.h>

#include <SDL2pp/SDL2pp.hh>
#include "ui_mainwindow.h"
#include "ui_newmap.h"
#include "../../game/editor/headers/mainwindow.h"
#include <QApplication>

using namespace SDL2pp;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int return_val = a.exec(); 
    return return_val;
}
