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

private slots:
    void populateMaterialComboBox();  // Заполнение ComboBox с типами материалов
    void updateMaterialTable();  // Обновление таблицы с материалами
    void on_pushButton_AddToWarehouse_clicked();  // Добавление материала в базу данных
    void on_pushButton_DeleteFromWarehouse_clicked();  // Удаление материала
    void on_pushButton_UpdateToWarehouse_clicked();  // Редактирование материала

private:
    Ui::MainWindow *ui;
    int selectedRow;  // Переменная для хранения текущей выбранной строки
};

#endif // MAINWINDOW_H
