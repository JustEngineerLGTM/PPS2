/********************************************************************************
** Form generated from reading UI file 'materialselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALSELECTIONDIALOG_H
#define UI_MATERIALSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Materialselectiondialog
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_material2;
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Materialselectiondialog)
    {
        if (Materialselectiondialog->objectName().isEmpty())
            Materialselectiondialog->setObjectName("Materialselectiondialog");
        Materialselectiondialog->resize(400, 300);
        gridLayout = new QGridLayout(Materialselectiondialog);
        gridLayout->setObjectName("gridLayout");
        comboBox_material2 = new QComboBox(Materialselectiondialog);
        comboBox_material2->setObjectName("comboBox_material2");

        gridLayout->addWidget(comboBox_material2, 0, 0, 1, 1);

        tableWidget = new QTableWidget(Materialselectiondialog);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setColumnCount(4);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Materialselectiondialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(Materialselectiondialog);

        QMetaObject::connectSlotsByName(Materialselectiondialog);
    } // setupUi

    void retranslateUi(QDialog *Materialselectiondialog)
    {
        Materialselectiondialog->setWindowTitle(QCoreApplication::translate("Materialselectiondialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Materialselectiondialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Materialselectiondialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Materialselectiondialog", "\320\225\320\264.\320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Materialselectiondialog", "\320\242\320\270\320\277 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Materialselectiondialog: public Ui_Materialselectiondialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALSELECTIONDIALOG_H
