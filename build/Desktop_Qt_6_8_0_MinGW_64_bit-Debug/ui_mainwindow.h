/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QPushButton *pushButton_AddToWarehouse;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2lineEdit_AddQuantity;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_Material;
    QTableWidget *tableWidget_Warehouse;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_DeleteFromWarehouse;
    QPushButton *pushButton_UpdateToWarehouse;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_AddName;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_AddMeasure;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QComboBox *comboBox_Material_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_8;
    QLabel *label_25;
    QComboBox *comboBox_OrderNumber2;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_24;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_27;
    QLineEdit *lineEdit_orderNumber;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_28;
    QLineEdit *lineEdit_orderStatus;
    QVBoxLayout *verticalLayout_14;
    QPushButton *pushButton_designStep;
    QPushButton *pushButton_manufacturingStep;
    QPushButton *pushButton_paintingStep;
    QPushButton *pushButton_assemblyStep;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_29;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_userStep;
    QPushButton *pushButton_userStatus;
    QPushButton *pushButton_completeStep;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_25;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *comboBox_order_material;
    QTableWidget *tableWidget_order;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton_addMaterialOrder;
    QPushButton *pushButton_DeleteMaterialOrder;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_31;
    QTextEdit *textEdit_orderInfo2;
    QHBoxLayout *horizontalLayout_15;
    QWidget *tab_3;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget_orderList;
    QLabel *label_16;
    QWidget *tab_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QLineEdit *lineEdit_orderId;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_20;
    QLineEdit *lineEdit_orderManufacturePrice;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_21;
    QDateEdit *dateEdit_orderCompletionDate;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_38;
    QDateEdit *dateEdit_orderTakeDate;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_23;
    QLineEdit *lineEdit_customerInfo;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_22;
    QLineEdit *lineEdit_orderQuality;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_18;
    QTextEdit *TextEdit_orderInfo;
    QPushButton *pushButton_newOrder;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_19;
    QLineEdit *lineEdit_orderPrice;
    QComboBox *comboBox_OrderSelect;
    QPushButton *pushButton_deleteOrder;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(732, 549);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName("gridLayout");
        pushButton_AddToWarehouse = new QPushButton(tab);
        pushButton_AddToWarehouse->setObjectName("pushButton_AddToWarehouse");

        gridLayout->addWidget(pushButton_AddToWarehouse, 4, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        lineEdit_2lineEdit_AddQuantity = new QLineEdit(tab);
        lineEdit_2lineEdit_AddQuantity->setObjectName("lineEdit_2lineEdit_AddQuantity");

        verticalLayout_3->addWidget(lineEdit_2lineEdit_AddQuantity);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox_Material = new QComboBox(tab);
        comboBox_Material->addItem(QString());
        comboBox_Material->setObjectName("comboBox_Material");

        horizontalLayout->addWidget(comboBox_Material);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget_Warehouse = new QTableWidget(tab);
        if (tableWidget_Warehouse->columnCount() < 4)
            tableWidget_Warehouse->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Warehouse->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Warehouse->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Warehouse->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Warehouse->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_Warehouse->rowCount() < 3)
            tableWidget_Warehouse->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Warehouse->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Warehouse->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Warehouse->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(1, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(1, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(2, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(2, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_Warehouse->setItem(2, 2, __qtablewidgetitem15);
        tableWidget_Warehouse->setObjectName("tableWidget_Warehouse");
        tableWidget_Warehouse->setEnabled(true);
        tableWidget_Warehouse->setBaseSize(QSize(100, 100));
        tableWidget_Warehouse->setSortingEnabled(true);
        tableWidget_Warehouse->setColumnCount(4);
        tableWidget_Warehouse->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_Warehouse->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Warehouse->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget_Warehouse);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_DeleteFromWarehouse = new QPushButton(tab);
        pushButton_DeleteFromWarehouse->setObjectName("pushButton_DeleteFromWarehouse");

        horizontalLayout_2->addWidget(pushButton_DeleteFromWarehouse);

        pushButton_UpdateToWarehouse = new QPushButton(tab);
        pushButton_UpdateToWarehouse->setObjectName("pushButton_UpdateToWarehouse");

        horizontalLayout_2->addWidget(pushButton_UpdateToWarehouse);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 3, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        lineEdit_AddName = new QLineEdit(tab);
        lineEdit_AddName->setObjectName("lineEdit_AddName");

        verticalLayout_2->addWidget(lineEdit_AddName);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        lineEdit_AddMeasure = new QLineEdit(tab);
        lineEdit_AddMeasure->setObjectName("lineEdit_AddMeasure");

        verticalLayout_4->addWidget(lineEdit_AddMeasure);


        gridLayout->addLayout(verticalLayout_4, 2, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        comboBox_Material_2 = new QComboBox(tab);
        comboBox_Material_2->addItem(QString());
        comboBox_Material_2->setObjectName("comboBox_Material_2");

        verticalLayout_5->addWidget(comboBox_Material_2);


        gridLayout->addLayout(verticalLayout_5, 3, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName("gridLayout_8");
        label_25 = new QLabel(tab_2);
        label_25->setObjectName("label_25");
        QFont font;
        font.setPointSize(12);
        label_25->setFont(font);

        gridLayout_8->addWidget(label_25, 0, 0, 1, 1);

        comboBox_OrderNumber2 = new QComboBox(tab_2);
        comboBox_OrderNumber2->setObjectName("comboBox_OrderNumber2");

        gridLayout_8->addWidget(comboBox_OrderNumber2, 1, 0, 1, 1);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName("verticalLayout_23");
        label_26 = new QLabel(tab_2);
        label_26->setObjectName("label_26");
        QFont font1;
        font1.setPointSize(16);
        label_26->setFont(font1);

        verticalLayout_23->addWidget(label_26);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName("verticalLayout_24");
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_27 = new QLabel(tab_2);
        label_27->setObjectName("label_27");

        horizontalLayout_4->addWidget(label_27);

        lineEdit_orderNumber = new QLineEdit(tab_2);
        lineEdit_orderNumber->setObjectName("lineEdit_orderNumber");
        lineEdit_orderNumber->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_orderNumber);


        verticalLayout_15->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_28 = new QLabel(tab_2);
        label_28->setObjectName("label_28");

        horizontalLayout_10->addWidget(label_28);

        lineEdit_orderStatus = new QLineEdit(tab_2);
        lineEdit_orderStatus->setObjectName("lineEdit_orderStatus");
        lineEdit_orderStatus->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_orderStatus);


        verticalLayout_15->addLayout(horizontalLayout_10);


        verticalLayout_24->addLayout(verticalLayout_15);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        pushButton_designStep = new QPushButton(tab_2);
        pushButton_designStep->setObjectName("pushButton_designStep");

        verticalLayout_14->addWidget(pushButton_designStep);

        pushButton_manufacturingStep = new QPushButton(tab_2);
        pushButton_manufacturingStep->setObjectName("pushButton_manufacturingStep");

        verticalLayout_14->addWidget(pushButton_manufacturingStep);

        pushButton_paintingStep = new QPushButton(tab_2);
        pushButton_paintingStep->setObjectName("pushButton_paintingStep");

        verticalLayout_14->addWidget(pushButton_paintingStep);

        pushButton_assemblyStep = new QPushButton(tab_2);
        pushButton_assemblyStep->setObjectName("pushButton_assemblyStep");

        verticalLayout_14->addWidget(pushButton_assemblyStep);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_29 = new QLabel(tab_2);
        label_29->setObjectName("label_29");

        verticalLayout_13->addWidget(label_29);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        lineEdit_userStep = new QLineEdit(tab_2);
        lineEdit_userStep->setObjectName("lineEdit_userStep");

        horizontalLayout_11->addWidget(lineEdit_userStep);

        pushButton_userStatus = new QPushButton(tab_2);
        pushButton_userStatus->setObjectName("pushButton_userStatus");

        horizontalLayout_11->addWidget(pushButton_userStatus);


        verticalLayout_13->addLayout(horizontalLayout_11);


        verticalLayout_14->addLayout(verticalLayout_13);

        pushButton_completeStep = new QPushButton(tab_2);
        pushButton_completeStep->setObjectName("pushButton_completeStep");

        verticalLayout_14->addWidget(pushButton_completeStep);


        verticalLayout_24->addLayout(verticalLayout_14);


        horizontalLayout_9->addLayout(verticalLayout_24);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setObjectName("verticalLayout_25");
        label_30 = new QLabel(tab_2);
        label_30->setObjectName("label_30");

        verticalLayout_25->addWidget(label_30);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        comboBox_order_material = new QComboBox(tab_2);
        comboBox_order_material->addItem(QString());
        comboBox_order_material->setObjectName("comboBox_order_material");

        horizontalLayout_13->addWidget(comboBox_order_material);


        verticalLayout_25->addLayout(horizontalLayout_13);

        tableWidget_order = new QTableWidget(tab_2);
        if (tableWidget_order->columnCount() < 3)
            tableWidget_order->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_order->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_order->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_order->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        tableWidget_order->setObjectName("tableWidget_order");

        verticalLayout_25->addWidget(tableWidget_order);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        pushButton_addMaterialOrder = new QPushButton(tab_2);
        pushButton_addMaterialOrder->setObjectName("pushButton_addMaterialOrder");

        horizontalLayout_14->addWidget(pushButton_addMaterialOrder);

        pushButton_DeleteMaterialOrder = new QPushButton(tab_2);
        pushButton_DeleteMaterialOrder->setObjectName("pushButton_DeleteMaterialOrder");

        horizontalLayout_14->addWidget(pushButton_DeleteMaterialOrder);


        verticalLayout_25->addLayout(horizontalLayout_14);


        horizontalLayout_12->addLayout(verticalLayout_25);


        horizontalLayout_9->addLayout(horizontalLayout_12);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setObjectName("verticalLayout_26");
        label_31 = new QLabel(tab_2);
        label_31->setObjectName("label_31");

        verticalLayout_26->addWidget(label_31);

        textEdit_orderInfo2 = new QTextEdit(tab_2);
        textEdit_orderInfo2->setObjectName("textEdit_orderInfo2");

        verticalLayout_26->addWidget(textEdit_orderInfo2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");

        verticalLayout_26->addLayout(horizontalLayout_15);


        horizontalLayout_9->addLayout(verticalLayout_26);


        verticalLayout_23->addLayout(horizontalLayout_9);


        gridLayout_8->addLayout(verticalLayout_23, 2, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_8, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        layoutWidget_2 = new QWidget(tab_3);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(0, 0, 721, 461));
        gridLayout_4 = new QGridLayout(layoutWidget_2);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tableWidget_orderList = new QTableWidget(layoutWidget_2);
        if (tableWidget_orderList->columnCount() < 4)
            tableWidget_orderList->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_orderList->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_orderList->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_orderList->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_orderList->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        if (tableWidget_orderList->rowCount() < 3)
            tableWidget_orderList->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_orderList->setVerticalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_orderList->setVerticalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_orderList->setVerticalHeaderItem(2, __qtablewidgetitem25);
        tableWidget_orderList->setObjectName("tableWidget_orderList");
        tableWidget_orderList->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        tableWidget_orderList->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_orderList->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_orderList->horizontalHeader()->setStretchLastSection(true);
        tableWidget_orderList->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_orderList->verticalHeader()->setStretchLastSection(false);

        gridLayout_4->addWidget(tableWidget_orderList, 1, 0, 1, 2);

        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName("label_16");
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_16, 0, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        gridLayout_2 = new QGridLayout(tab_5);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_17 = new QLabel(tab_5);
        label_17->setObjectName("label_17");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_17);

        lineEdit_orderId = new QLineEdit(tab_5);
        lineEdit_orderId->setObjectName("lineEdit_orderId");

        horizontalLayout_3->addWidget(lineEdit_orderId);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_20 = new QLabel(tab_5);
        label_20->setObjectName("label_20");
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);
        label_20->setScaledContents(false);

        horizontalLayout_7->addWidget(label_20);

        lineEdit_orderManufacturePrice = new QLineEdit(tab_5);
        lineEdit_orderManufacturePrice->setObjectName("lineEdit_orderManufacturePrice");

        horizontalLayout_7->addWidget(lineEdit_orderManufacturePrice);


        gridLayout_2->addLayout(horizontalLayout_7, 5, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_21 = new QLabel(tab_5);
        label_21->setObjectName("label_21");
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_21);

        dateEdit_orderCompletionDate = new QDateEdit(tab_5);
        dateEdit_orderCompletionDate->setObjectName("dateEdit_orderCompletionDate");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dateEdit_orderCompletionDate->sizePolicy().hasHeightForWidth());
        dateEdit_orderCompletionDate->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(dateEdit_orderCompletionDate);


        gridLayout_2->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_38 = new QLabel(tab_5);
        label_38->setObjectName("label_38");
        sizePolicy2.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy2);

        horizontalLayout_17->addWidget(label_38);

        dateEdit_orderTakeDate = new QDateEdit(tab_5);
        dateEdit_orderTakeDate->setObjectName("dateEdit_orderTakeDate");
        sizePolicy2.setHeightForWidth(dateEdit_orderTakeDate->sizePolicy().hasHeightForWidth());
        dateEdit_orderTakeDate->setSizePolicy(sizePolicy2);

        horizontalLayout_17->addWidget(dateEdit_orderTakeDate);


        gridLayout_2->addLayout(horizontalLayout_17, 6, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_23 = new QLabel(tab_5);
        label_23->setObjectName("label_23");
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);

        horizontalLayout_18->addWidget(label_23);

        lineEdit_customerInfo = new QLineEdit(tab_5);
        lineEdit_customerInfo->setObjectName("lineEdit_customerInfo");

        horizontalLayout_18->addWidget(lineEdit_customerInfo);


        gridLayout_2->addLayout(horizontalLayout_18, 2, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_22 = new QLabel(tab_5);
        label_22->setObjectName("label_22");
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(label_22);

        lineEdit_orderQuality = new QLineEdit(tab_5);
        lineEdit_orderQuality->setObjectName("lineEdit_orderQuality");
        lineEdit_orderQuality->setReadOnly(true);

        horizontalLayout_16->addWidget(lineEdit_orderQuality);


        gridLayout_2->addLayout(horizontalLayout_16, 8, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_18 = new QLabel(tab_5);
        label_18->setObjectName("label_18");
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_18);

        TextEdit_orderInfo = new QTextEdit(tab_5);
        TextEdit_orderInfo->setObjectName("TextEdit_orderInfo");

        horizontalLayout_5->addWidget(TextEdit_orderInfo);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        pushButton_newOrder = new QPushButton(tab_5);
        pushButton_newOrder->setObjectName("pushButton_newOrder");

        gridLayout_2->addWidget(pushButton_newOrder, 9, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_19 = new QLabel(tab_5);
        label_19->setObjectName("label_19");
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_19);

        lineEdit_orderPrice = new QLineEdit(tab_5);
        lineEdit_orderPrice->setObjectName("lineEdit_orderPrice");

        horizontalLayout_6->addWidget(lineEdit_orderPrice);


        gridLayout_2->addLayout(horizontalLayout_6, 4, 0, 1, 1);

        comboBox_OrderSelect = new QComboBox(tab_5);
        comboBox_OrderSelect->setObjectName("comboBox_OrderSelect");

        gridLayout_2->addWidget(comboBox_OrderSelect, 0, 0, 1, 1);

        pushButton_deleteOrder = new QPushButton(tab_5);
        pushButton_deleteOrder->setObjectName("pushButton_deleteOrder");

        gridLayout_2->addWidget(pushButton_deleteOrder, 10, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 732, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_AddToWarehouse->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        comboBox_Material->setItemText(0, QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget_Warehouse->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Warehouse->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Warehouse->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\225\320\264.\320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Warehouse->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Warehouse->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Warehouse->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Warehouse->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "3", nullptr));

        const bool __sortingEnabled = tableWidget_Warehouse->isSortingEnabled();
        tableWidget_Warehouse->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Warehouse->item(0, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\201\320\272\320\260 \320\270\320\267 \320\264\321\203\320\261\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Warehouse->item(0, 1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Warehouse->item(0, 2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\320\2743", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Warehouse->item(1, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\201\320\272\320\260 \320\270\320\267 \320\265\320\273\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Warehouse->item(1, 1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Warehouse->item(1, 2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\320\2743", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_Warehouse->item(2, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\263\320\273\321\203\321\210\320\272\320\260 \320\270\320\267 \320\272\320\273\321\221\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_Warehouse->item(2, 1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_Warehouse->item(2, 2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\321\210\321\202", nullptr));
        tableWidget_Warehouse->setSortingEnabled(__sortingEnabled);

        pushButton_DeleteFromWarehouse->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_UpdateToWarehouse->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\225\320\264.\320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", nullptr));
        comboBox_Material_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\241\320\272\320\273\320\260\320\264", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        comboBox_OrderNumber2->setCurrentText(QString());
        label_26->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\267\320\260\320\272\320\260\320\267\320\265 \342\204\226 1", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        lineEdit_orderNumber->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
        lineEdit_orderStatus->setText(QString());
        pushButton_designStep->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \321\215\321\202\320\260\320\277 \320\277\321\200\320\276\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        pushButton_manufacturingStep->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \321\215\321\202\320\260\320\277 \320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        pushButton_paintingStep->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \321\215\321\202\320\260\320\277 \320\277\320\276\320\272\321\200\320\260\321\201\320\272\320\270", nullptr));
        pushButton_assemblyStep->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \321\215\321\202\320\260\320\277 \321\201\320\261\320\276\321\200\320\272\320\270", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\320\243\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\321\202\320\260\321\202\321\203\321\201 \320\262\321\200\321\203\321\207\320\275\321\203\321\216", nullptr));
        lineEdit_userStep->setText(QString());
        pushButton_userStatus->setText(QCoreApplication::translate("MainWindow", "\320\243\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\321\202\320\260\321\202\321\203\321\201", nullptr));
        pushButton_completeStep->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\320\276\320\265 \321\201\321\213\321\200\321\214\320\265", nullptr));
        comboBox_order_material->setItemText(0, QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));

        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_order->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_order->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_order->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\320\225\320\264.\320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217", nullptr));
        pushButton_addMaterialOrder->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_DeleteMaterialOrder->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_orderList->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_orderList->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_orderList->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_orderList->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_orderList->verticalHeaderItem(0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_orderList->verticalHeaderItem(1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_orderList->verticalHeaderItem(2);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\275\321\217\321\202\320\270\321\217 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\260:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        TextEdit_orderInfo->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_newOrder->setText(QCoreApplication::translate("MainWindow", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\267\320\260\320\272\320\260\320\267", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260 \320\270\320\267\320\264\320\265\320\273\320\270\321\217", nullptr));
        pushButton_deleteOrder->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
