#ifndef LISTCATEGORIES_H
#define LISTCATEGORIES_H

#include <QDialog>

namespace Ui {
class ListCategories;
}

class ListCategories : public QDialog
{
    Q_OBJECT

public:
    explicit ListCategories(QWidget *parent = 0);
    ~ListCategories();

private:
    Ui::ListCategories *ui;
};

#endif // LISTCATEGORIES_H
