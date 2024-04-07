#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listWindow = new ListCategories();
    QObject::connect(listWindow, &ListCategories::on_btn_add_clicked, this, &MainWindow::returnWindow);
    QObject::connect(listWindow, &ListCategories::on_btn_back_clicked, this, &MainWindow::returnWindow);
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


void MainWindow::returnWindow()
{
    listWindow->close();
    this->show();
}
