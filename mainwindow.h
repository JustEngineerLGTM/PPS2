#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clearOrderFields();
    void updateOrderComboBox();
    void saveOrderData();
    bool eventFilter(QObject *watched, QEvent *event);
    void populateOrderTable();
    void populateMaterialTypeComboBox();
    void filterMaterialsForOrder(int orderId, const QString &materialType);
    void loadOrderMaterials(int orderId, const QString &materialType);

    void changeOrderStatus(const QString &newStatus);
private slots:
    void populateMaterialComboBox();  // Заполнение ComboBox с типами материалов
    void updateMaterialTable();  // Обновление таблицы с материалами
    void on_pushButton_AddToWarehouse_clicked();  // Добавление материала в базу данных
    void on_pushButton_DeleteFromWarehouse_clicked();  // Удаление материала
    void on_pushButton_UpdateToWarehouse_clicked();  // Редактирование материала
    void on_pushButton_addMaterialOrder_clicked();

    void on_pushButton_newOrder_clicked();
    void on_pushButton_deleteOrder_clicked();
    void on_comboBox_OrderSelect_currentIndexChanged(int index);
    void onTextEditEditingFinished();  // Слот для обработки завершения редактирования

    void on_comboBox_OrderNumber2_currentIndexChanged(const int &arg1);
    void on_comboBox_order_material_currentIndexChanged(int index);
    void on_pushButton_designStep_clicked();
    void on_pushButton_manufacturingStep_clicked();
    void on_pushButton_userStatus_clicked();
    void on_pushButton_paintingStep_clicked();
    void on_pushButton_assemblyStep_clicked();
    void on_pushButton_completeStep_clicked();
    void on_pushButton_DeleteMaterialOrder_clicked();

private:
    Ui::MainWindow *ui;
    int selectedRow;  // Переменная для хранения текущей выбранной строки
};

#endif // MAINWINDOW_H
