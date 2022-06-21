#include <iostream>
#include "../../game/editor/headers/mapa_editor.h"
#include "../../game/editor/headers/editorwindow.h"
#include "ui_mainwindow.h"
#include "ui_newmap.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    EditorWindow w;
    w.show();
    int return_val = a.exec(); 
    return return_val;
}
