#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "qboxlayout.h"
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

    void plotIncomeChart(QDate startDate, QDate endDate);
private slots:
    void on_pushButton_AddStaff_clicked();

    void on_pushButton_SaveStaff_clicked();

    void on_pushButton_RemoveStaff_clicked();

    void on_comboBox_StaffSelected_currentIndexChanged(int index);

      void on_pushButton_generate_clicked();


private:
    Ui::Administrator *ui;
    void updateStaffList();
    void updateStuff();
};

#endif // ADMINISTRATOR_H
