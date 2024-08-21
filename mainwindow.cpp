#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Заполняем comboBox_Material
    populateMaterialComboBox();

    // Обновляем таблицу при загрузке формы
    updateMaterialTable();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateMaterialComboBox()
{
    // Очищаем comboBox перед добавлением новых элементов
    ui->comboBox_Material->clear();
    ui->comboBox_Material_2->clear();

    // Добавляем типы материалов
    QStringList materialTypes = {"Все материалы", "дерево", "металл", "расходники"};

    for (const QString& type : materialTypes) {
        ui->comboBox_Material->addItem(type);
        if(type != "Все материалы")
        ui->comboBox_Material_2->addItem(type);
    }

    // Подключаем слот для обновления таблицы при изменении типа материала
    connect(ui->comboBox_Material, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::updateMaterialTable);
}

void MainWindow::updateMaterialTable()
{
    // Получаем выбранный тип материала
    QString selectedType = ui->comboBox_Material->currentText();

    // Получаем материалы из базы данных в зависимости от выбранного типа
    QList<Material> materials;
    if (selectedType == "Все материалы") {
        materials = DatabaseManager::instance().getMaterials();
    } else {
        materials = DatabaseManager::instance().getMaterialsByType(selectedType);
    }

    // Очищаем таблицу перед добавлением новых данных
    ui->tableWidget_Warehouse->clearContents();
    ui->tableWidget_Warehouse->setRowCount(0);

    // Заполняем таблицу материалами
    for (const Material& material : materials) {
        int row = ui->tableWidget_Warehouse->rowCount();
        ui->tableWidget_Warehouse->insertRow(row);
        ui->tableWidget_Warehouse->setItem(row, 0, new QTableWidgetItem(material.name));
        ui->tableWidget_Warehouse->setItem(row, 1, new QTableWidgetItem(QString::number(material.quantity)));
        ui->tableWidget_Warehouse->setItem(row, 2, new QTableWidgetItem(material.unit));
        ui->tableWidget_Warehouse->setItem(row, 3, new QTableWidgetItem(material.type));
    }

    // Разрешаем редактирование ячеек в таблице
    ui->tableWidget_Warehouse->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_pushButton_AddToWarehouse_clicked()
{
    // Получаем данные из полей ввода
    QString name = ui->lineEdit_AddName->text().trimmed();
    double quantity = ui->lineEdit_2lineEdit_AddQuantity->text().toDouble();
    QString unit = ui->lineEdit_AddMeasure->text().trimmed();
    QString materialType = ui->comboBox_Material_2->currentText();

    if (name.isEmpty() || quantity <= 0 || unit.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Заполните все поля корректно");
        return;
    }

    // Добавляем или обновляем материал в базе данных
    if (DatabaseManager::instance().addOrUpdateMaterial(name, quantity, unit, materialType)) {
        QMessageBox::information(this, "Success", "Материал успешно добавлен или обновлен");
        // Очищаем поля ввода
        ui->lineEdit_AddName->clear();
        ui->lineEdit_2lineEdit_AddQuantity->clear();
        ui->lineEdit_AddMeasure->clear();
        // Обновляем таблицу с материалами
        updateMaterialTable();
    } else {
        QMessageBox::critical(this, "Database Error", "Не удалось добавить или обновить материал");
    }

}

void MainWindow::on_pushButton_DeleteFromWarehouse_clicked()
{
    // Получаем текущую выбранную строку
    int row = ui->tableWidget_Warehouse->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите материал для удаления");
        return;
    }

    // Получаем имя материала из таблицы
    QString materialName = ui->tableWidget_Warehouse->item(row, 0)->text();

    // Удаляем материал из базы данных
    if (DatabaseManager::instance().deleteMaterial(materialName)) {
        QMessageBox::information(this, "Успех", "Материал успешно удален");

        // Удаляем строку из таблицы
        ui->tableWidget_Warehouse->removeRow(row);
        ui->tableWidget_Warehouse->setCurrentItem(nullptr);  // Сбрасываем текущий выбранный элемент
        ui->tableWidget_Warehouse->clearSelection();         // Очищаем все выделения
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось удалить материал");
    }
}
void MainWindow::on_pushButton_UpdateToWarehouse_clicked()
{
    if (ui->pushButton_UpdateToWarehouse->text() == "Редактировать") {
        // Разрешаем редактирование ячеек
        ui->tableWidget_Warehouse->setEditTriggers(QAbstractItemView::DoubleClicked);
        ui->pushButton_UpdateToWarehouse->setText("Сохранить");
    } else {
        // Отключаем редактирование ячеек
        ui->tableWidget_Warehouse->setEditTriggers(QAbstractItemView::NoEditTriggers);

        // Получаем данные из таблицы и обновляем их в базе данных
        for (int row = 0; row < ui->tableWidget_Warehouse->rowCount(); ++row) {
            QString materialName = ui->tableWidget_Warehouse->item(row, 0)->text();
            double quantity = ui->tableWidget_Warehouse->item(row, 1)->text().toDouble();
            QString unit = ui->tableWidget_Warehouse->item(row, 2)->text();
            QString materialType = ui->tableWidget_Warehouse->item(row, 3)->text();

            // Обновляем данные материала в базе данных
            if (!DatabaseManager::instance().updateMaterial(materialName, quantity, unit, materialType)) {
                QMessageBox::critical(this, "Ошибка", "Не удалось обновить материал: " + materialName);
            }
        }

        QMessageBox::information(this, "Успех", "Изменения сохранены");
        ui->pushButton_UpdateToWarehouse->setText("Редактировать");

        // Обновляем таблицу после сохранения
        updateMaterialTable();
    }
}
