#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include "ui_listcategories.h"
#include "listcategories.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_seld_clicked();
    void on_btn_bought_clicked();
    void returnWindow();

private:
    Ui::MainWindow *ui;
    ListCategories *listWindow;

};

#endif // MAINWINDOW_H
