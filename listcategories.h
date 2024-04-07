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

signals:
    void on_btn_add_clicked();
    void on_btn_back_clicked();

private:
    Ui::ListCategories *ui;
};

#endif // LISTCATEGORIES_H
