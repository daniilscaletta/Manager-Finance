#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <QObject>
#include "listcategories.h"


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}


