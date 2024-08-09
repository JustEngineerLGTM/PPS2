#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Administrator; }
QT_END_NAMESPACE

class Administrator : public QWidget
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();

private slots:
    void on_pushButtonAddStaff_clicked();

private:
    Ui::Administrator *ui;
};

#endif // ADMINISTRATOR_H
