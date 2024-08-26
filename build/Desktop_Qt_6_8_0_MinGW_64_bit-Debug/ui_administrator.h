/********************************************************************************
** Form generated from reading UI file 'administrator.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Administrator
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QFrame *line;
    QGroupBox *staffControl;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_SaveStaff;
    QPushButton *pushButton_RemoveStaff;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_StaffNameInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_SalarySum;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_StaffSalary;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_StafJobInfo;
    QLineEdit *lineEdit_StaffJobInfo;
    QComboBox *comboBox_StaffSelected;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_WorkDays;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_WorkDone;
    QGroupBox *staffAdd;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_StaffNameAdd;
    QLineEdit *lineEditStaffName;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_10;
    QLineEdit *lineEditStaffSalaryAdd;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonAddStaff;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_11;
    QLineEdit *lineEditStaffLogin;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_StaffJobAdd;
    QLineEdit *lineEdit_StaffJobAdd;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_12;
    QLineEdit *lineEditStaffPassword;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_StaffJobAdd_2;
    QComboBox *comboBox_StaffRole;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QDateEdit *dateEdit_start;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QDateEdit *dateEdit_end;
    QPushButton *pushButton_generate;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_8;
    QLineEdit *lineEdit_income;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_14;
    QLineEdit *lineEdit_orderCompletinoNumber;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_9;
    QLineEdit *lineEdit_outcome;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_13;
    QChartView *chartWidget;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_profit;
    QLineEdit *lineEdit_profit;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_16;
    QLineEdit *lineEdit_profitPeriod;

    void setupUi(QWidget *Administrator)
    {
        if (Administrator->objectName().isEmpty())
            Administrator->setObjectName("Administrator");
        Administrator->resize(763, 424);
        gridLayout = new QGridLayout(Administrator);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(Administrator);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName("gridLayout_3");
        line = new QFrame(tab);
        line->setObjectName("line");
        line->setFrameShadow(QFrame::Shadow::Raised);
        line->setLineWidth(5);
        line->setMidLineWidth(2);
        line->setFrameShape(QFrame::Shape::VLine);

        gridLayout_3->addWidget(line, 0, 1, 1, 1);

        staffControl = new QGroupBox(tab);
        staffControl->setObjectName("staffControl");
        staffControl->setAutoFillBackground(false);
        gridLayout_4 = new QGridLayout(staffControl);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        pushButton_SaveStaff = new QPushButton(staffControl);
        pushButton_SaveStaff->setObjectName("pushButton_SaveStaff");

        verticalLayout_7->addWidget(pushButton_SaveStaff);

        pushButton_RemoveStaff = new QPushButton(staffControl);
        pushButton_RemoveStaff->setObjectName("pushButton_RemoveStaff");

        verticalLayout_7->addWidget(pushButton_RemoveStaff);


        gridLayout_4->addLayout(verticalLayout_7, 8, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(staffControl);
        label->setObjectName("label");

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit_StaffNameInfo = new QLineEdit(staffControl);
        lineEdit_StaffNameInfo->setObjectName("lineEdit_StaffNameInfo");

        verticalLayout->addWidget(lineEdit_StaffNameInfo);


        gridLayout_4->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(staffControl);
        label_5->setObjectName("label_5");

        verticalLayout_5->addWidget(label_5, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit_SalarySum = new QLineEdit(staffControl);
        lineEdit_SalarySum->setObjectName("lineEdit_SalarySum");
        lineEdit_SalarySum->setReadOnly(true);

        verticalLayout_5->addWidget(lineEdit_SalarySum);


        gridLayout_4->addLayout(verticalLayout_5, 7, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(staffControl);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit_StaffSalary = new QLineEdit(staffControl);
        lineEdit_StaffSalary->setObjectName("lineEdit_StaffSalary");

        verticalLayout_2->addWidget(lineEdit_StaffSalary);


        gridLayout_4->addLayout(verticalLayout_2, 3, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_StafJobInfo = new QLabel(staffControl);
        label_StafJobInfo->setObjectName("label_StafJobInfo");

        verticalLayout_6->addWidget(label_StafJobInfo, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit_StaffJobInfo = new QLineEdit(staffControl);
        lineEdit_StaffJobInfo->setObjectName("lineEdit_StaffJobInfo");

        verticalLayout_6->addWidget(lineEdit_StaffJobInfo);


        gridLayout_4->addLayout(verticalLayout_6, 2, 1, 1, 1);

        comboBox_StaffSelected = new QComboBox(staffControl);
        comboBox_StaffSelected->setObjectName("comboBox_StaffSelected");

        gridLayout_4->addWidget(comboBox_StaffSelected, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(staffControl);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit_WorkDays = new QLineEdit(staffControl);
        lineEdit_WorkDays->setObjectName("lineEdit_WorkDays");

        verticalLayout_3->addWidget(lineEdit_WorkDays);


        gridLayout_4->addLayout(verticalLayout_3, 5, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(staffControl);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit_WorkDone = new QLineEdit(staffControl);
        lineEdit_WorkDone->setObjectName("lineEdit_WorkDone");

        verticalLayout_4->addWidget(lineEdit_WorkDone);


        gridLayout_4->addLayout(verticalLayout_4, 6, 1, 1, 1);


        gridLayout_3->addWidget(staffControl, 0, 2, 1, 1);

        staffAdd = new QGroupBox(tab);
        staffAdd->setObjectName("staffAdd");
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        staffAdd->setFont(font);
        staffAdd->setFlat(false);
        staffAdd->setCheckable(false);
        gridLayout_2 = new QGridLayout(staffAdd);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_StaffNameAdd = new QLabel(staffAdd);
        label_StaffNameAdd->setObjectName("label_StaffNameAdd");

        verticalLayout_12->addWidget(label_StaffNameAdd, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEditStaffName = new QLineEdit(staffAdd);
        lineEditStaffName->setObjectName("lineEditStaffName");

        verticalLayout_12->addWidget(lineEditStaffName);


        gridLayout_2->addLayout(verticalLayout_12, 0, 0, 1, 1);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_10 = new QLabel(staffAdd);
        label_10->setObjectName("label_10");

        verticalLayout_13->addWidget(label_10, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEditStaffSalaryAdd = new QLineEdit(staffAdd);
        lineEditStaffSalaryAdd->setObjectName("lineEditStaffSalaryAdd");

        verticalLayout_13->addWidget(lineEditStaffSalaryAdd);


        gridLayout_2->addLayout(verticalLayout_13, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 1, 1);

        pushButtonAddStaff = new QPushButton(staffAdd);
        pushButtonAddStaff->setObjectName("pushButtonAddStaff");

        gridLayout_2->addWidget(pushButtonAddStaff, 11, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 5, 0, 1, 1);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        label_11 = new QLabel(staffAdd);
        label_11->setObjectName("label_11");

        verticalLayout_14->addWidget(label_11, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEditStaffLogin = new QLineEdit(staffAdd);
        lineEditStaffLogin->setObjectName("lineEditStaffLogin");

        verticalLayout_14->addWidget(lineEditStaffLogin);


        gridLayout_2->addLayout(verticalLayout_14, 8, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 7, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_StaffJobAdd = new QLabel(staffAdd);
        label_StaffJobAdd->setObjectName("label_StaffJobAdd");

        verticalLayout_8->addWidget(label_StaffJobAdd, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit_StaffJobAdd = new QLineEdit(staffAdd);
        lineEdit_StaffJobAdd->setObjectName("lineEdit_StaffJobAdd");

        verticalLayout_8->addWidget(lineEdit_StaffJobAdd);


        gridLayout_2->addLayout(verticalLayout_8, 4, 0, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        label_12 = new QLabel(staffAdd);
        label_12->setObjectName("label_12");

        verticalLayout_15->addWidget(label_12, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEditStaffPassword = new QLineEdit(staffAdd);
        lineEditStaffPassword->setObjectName("lineEditStaffPassword");

        verticalLayout_15->addWidget(lineEditStaffPassword);


        gridLayout_2->addLayout(verticalLayout_15, 10, 0, 1, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        label_StaffJobAdd_2 = new QLabel(staffAdd);
        label_StaffJobAdd_2->setObjectName("label_StaffJobAdd_2");

        verticalLayout_16->addWidget(label_StaffJobAdd_2, 0, Qt::AlignmentFlag::AlignHCenter);

        comboBox_StaffRole = new QComboBox(staffAdd);
        comboBox_StaffRole->addItem(QString());
        comboBox_StaffRole->addItem(QString());
        comboBox_StaffRole->setObjectName("comboBox_StaffRole");

        verticalLayout_16->addWidget(comboBox_StaffRole);


        gridLayout_2->addLayout(verticalLayout_16, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 9, 0, 1, 1);


        gridLayout_3->addWidget(staffAdd, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName("gridLayout_5");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");

        verticalLayout_10->addWidget(label_7);

        dateEdit_start = new QDateEdit(tab_2);
        dateEdit_start->setObjectName("dateEdit_start");

        verticalLayout_10->addWidget(dateEdit_start);


        gridLayout_5->addLayout(verticalLayout_10, 0, 0, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");

        verticalLayout_9->addWidget(label_6);

        dateEdit_end = new QDateEdit(tab_2);
        dateEdit_end->setObjectName("dateEdit_end");

        verticalLayout_9->addWidget(dateEdit_end);


        gridLayout_5->addLayout(verticalLayout_9, 0, 1, 1, 1);

        pushButton_generate = new QPushButton(tab_2);
        pushButton_generate->setObjectName("pushButton_generate");

        gridLayout_5->addWidget(pushButton_generate, 1, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");

        verticalLayout_11->addWidget(label_8);

        lineEdit_income = new QLineEdit(tab_2);
        lineEdit_income->setObjectName("lineEdit_income");
        lineEdit_income->setReadOnly(true);

        verticalLayout_11->addWidget(lineEdit_income);


        gridLayout_5->addLayout(verticalLayout_11, 2, 0, 1, 1);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        label_14 = new QLabel(tab_2);
        label_14->setObjectName("label_14");

        verticalLayout_19->addWidget(label_14);

        lineEdit_orderCompletinoNumber = new QLineEdit(tab_2);
        lineEdit_orderCompletinoNumber->setObjectName("lineEdit_orderCompletinoNumber");
        lineEdit_orderCompletinoNumber->setReadOnly(true);

        verticalLayout_19->addWidget(lineEdit_orderCompletinoNumber);


        gridLayout_5->addLayout(verticalLayout_19, 2, 1, 1, 1);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");

        verticalLayout_17->addWidget(label_9);

        lineEdit_outcome = new QLineEdit(tab_2);
        lineEdit_outcome->setObjectName("lineEdit_outcome");
        lineEdit_outcome->setReadOnly(true);

        verticalLayout_17->addWidget(lineEdit_outcome);


        gridLayout_5->addLayout(verticalLayout_17, 3, 0, 1, 1);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");

        verticalLayout_20->addWidget(label_13);

        chartWidget = new QChartView(tab_2);
        chartWidget->setObjectName("chartWidget");

        verticalLayout_20->addWidget(chartWidget);


        gridLayout_5->addLayout(verticalLayout_20, 3, 1, 1, 1);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName("verticalLayout_18");
        label_profit = new QLabel(tab_2);
        label_profit->setObjectName("label_profit");

        verticalLayout_18->addWidget(label_profit);

        lineEdit_profit = new QLineEdit(tab_2);
        lineEdit_profit->setObjectName("lineEdit_profit");
        lineEdit_profit->setReadOnly(true);

        verticalLayout_18->addWidget(lineEdit_profit);


        gridLayout_5->addLayout(verticalLayout_18, 4, 0, 1, 1);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName("verticalLayout_21");
        label_16 = new QLabel(tab_2);
        label_16->setObjectName("label_16");

        verticalLayout_21->addWidget(label_16);

        lineEdit_profitPeriod = new QLineEdit(tab_2);
        lineEdit_profitPeriod->setObjectName("lineEdit_profitPeriod");
        lineEdit_profitPeriod->setReadOnly(true);

        verticalLayout_21->addWidget(lineEdit_profitPeriod);


        gridLayout_5->addLayout(verticalLayout_21, 4, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Administrator);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Administrator);
    } // setupUi

    void retranslateUi(QWidget *Administrator)
    {
        Administrator->setWindowTitle(QCoreApplication::translate("Administrator", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        staffControl->setTitle(QCoreApplication::translate("Administrator", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\270 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        pushButton_SaveStaff->setText(QCoreApplication::translate("Administrator", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        pushButton_RemoveStaff->setText(QCoreApplication::translate("Administrator", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        label->setText(QCoreApplication::translate("Administrator", "\320\244\320\230\320\236", nullptr));
        label_5->setText(QCoreApplication::translate("Administrator", "\320\240\320\260\321\201\321\201\321\207\320\265\321\202\320\275\320\260\321\217 \320\267\320\260\321\200\320\260\320\261\320\276\321\202\320\275\320\260\321\217 \320\277\320\273\320\260\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("Administrator", "\320\241\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_StafJobInfo->setText(QCoreApplication::translate("Administrator", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("Administrator", "\320\232\320\276\320\273-\320\262\320\276 \321\200\320\260\320\261\320\276\321\207\320\270\321\205 \320\264\320\275\320\265\320\271", nullptr));
        label_4->setText(QCoreApplication::translate("Administrator", "\320\232\320\276\320\273-\320\262\320\276 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\275\321\213\321\205 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        staffAdd->setTitle(QCoreApplication::translate("Administrator", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        label_StaffNameAdd->setText(QCoreApplication::translate("Administrator", "\320\244\320\230\320\236", nullptr));
        label_10->setText(QCoreApplication::translate("Administrator", "\320\241\321\202\320\260\320\262\320\272\320\260", nullptr));
        pushButtonAddStaff->setText(QCoreApplication::translate("Administrator", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        label_11->setText(QCoreApplication::translate("Administrator", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_StaffJobAdd->setText(QCoreApplication::translate("Administrator", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("Administrator", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_StaffJobAdd_2->setText(QCoreApplication::translate("Administrator", "\320\224\320\276\321\201\321\202\321\203\320\277", nullptr));
        comboBox_StaffRole->setItemText(0, QCoreApplication::translate("Administrator", "\320\234\320\260\321\201\321\202\320\265\321\200\321\201\320\272\320\260\321\217", nullptr));
        comboBox_StaffRole->setItemText(1, QCoreApplication::translate("Administrator", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Administrator", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260\320\274\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("Administrator", "\320\224\320\260\321\202\320\260 \320\276\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("Administrator", "\320\224\320\260\321\202\320\260 \320\264\320\276", nullptr));
        pushButton_generate->setText(QCoreApplication::translate("Administrator", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\207\321\221\321\202", nullptr));
        label_8->setText(QCoreApplication::translate("Administrator", "\320\224\320\276\321\205\320\276\320\264 \320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        label_14->setText(QCoreApplication::translate("Administrator", "\320\222\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        label_9->setText(QCoreApplication::translate("Administrator", "\320\240\320\260\321\201\321\205\320\276\320\264 \320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        label_13->setText(QCoreApplication::translate("Administrator", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\277\321\200\320\270\320\261\321\213\320\273\320\270", nullptr));
        label_profit->setText(QCoreApplication::translate("Administrator", "\320\237\321\200\320\270\320\261\321\213\320\273\321\214 \320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        label_16->setText(QCoreApplication::translate("Administrator", "\320\240\320\276\321\201\321\202 \320\272\320\276\320\274\320\277\320\260\320\275\320\270\320\270 \320\267\320\260 \320\277\321\200\320\265\320\264.\320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Administrator", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\321\201\321\202\320\262\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Administrator: public Ui_Administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
