#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>

namespace Ui {
class Administrator;
}

class Administrator : public QWidget
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();

private:
    Ui::Administrator *ui;
};

#endif // ADMINISTRATOR_H
