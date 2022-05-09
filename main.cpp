#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "Parser.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
