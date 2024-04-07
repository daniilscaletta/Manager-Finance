#include "listcategories.h"
#include "ui_listcategories.h"

ListCategories::ListCategories(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListCategories)
{


    ui->setupUi(this);
}

ListCategories::~ListCategories()
{
    delete ui;
}
