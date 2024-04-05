#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listWindow = new ListCategories();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_seld_clicked()
{
    listWindow->show();
    this->close();
}

void MainWindow::on_btn_bought_clicked()
{
    listWindow->show();
    this->close();
}
