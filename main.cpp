#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <QObject>
#include "listcategories.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ListCategories LC;
    LC.show();
    w.show();

    return a.exec();
}


