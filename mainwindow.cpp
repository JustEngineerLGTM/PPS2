#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materialselectiondialog.h"
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
    updateOrderComboBox();
    connect(ui->lineEdit_orderId, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_customerInfo, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderInfo, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderPrice, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderManufacturePrice, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderTakeDate, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderCompletionDate, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderQuality, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
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

void MainWindow::on_pushButton_addMaterialOrder_clicked()
{
    // Открываем диалог выбора материала
    Materialselectiondialog dialog(this);

    // Если пользователь подтвердил выбор материала
    if (dialog.exec() == QDialog::Accepted) {
        QString selectedMaterial = dialog.selectedMaterial();
        double selectedQuantity = dialog.selectedQuantity();

        // Получаем ID текущего заказа
        int orderId = ui->comboBox_OrderNumber2->currentData().toInt();

        // Проверяем наличие выбранного материала на складе
        Material material = DatabaseManager::instance().getMaterialByName(selectedMaterial);
        if (material.name.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Выбранный материал не найден на складе.");
            return;
        }

        // Проверяем, есть ли достаточно материала на складе
        if (material.quantity < selectedQuantity) {
            QMessageBox::warning(this, "Ошибка", "Недостаточно материала на складе.");
            return;
        }

        // Добавляем материал в заказ
        if (DatabaseManager::instance().addMaterialToOrder(orderId, selectedMaterial, selectedQuantity)) {
            // Уменьшаем количество материала на складе
            double newQuantity = material.quantity - selectedQuantity;
            if (!DatabaseManager::instance().updateMaterialQuantity(selectedMaterial, newQuantity)) {
                QMessageBox::warning(this, "Ошибка", "Не удалось обновить количество материала на складе.");
                return;
            }

            // Обновляем таблицу с материалами в заказе
            int row = ui->tableWidget_order->rowCount();
            ui->tableWidget_order->insertRow(row);
            ui->tableWidget_order->setItem(row, 0, new QTableWidgetItem(selectedMaterial));
            ui->tableWidget_order->setItem(row, 1, new QTableWidgetItem(QString::number(selectedQuantity)));
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить материал в заказ.");
        }
    }
}

void MainWindow::on_pushButton_newOrder_clicked()
{
    // Создаем новый заказ в базе данных
    int newOrderId = DatabaseManager::instance().createEmptyOrder();

    if (newOrderId > 0) {
        // Успешно создан новый заказ, обновляем UI
        ui->lineEdit_orderId->setText(QString::number(newOrderId));
        updateOrderComboBox();

        // Очищаем другие поля для заполнения пользователем
        ui->lineEdit_customerInfo->clear();
        ui->lineEdit_orderInfo->clear();
        ui->lineEdit_orderPrice->clear();
        ui->lineEdit_orderManufacturePrice->clear();
        ui->lineEdit_orderTakeDate->clear();
        ui->lineEdit_orderCompletionDate->clear();
        ui->lineEdit_orderQuality->clear();

        QMessageBox::information(this, "Новый заказ", "Новый заказ успешно создан. Теперь вы можете заполнить его детали.");
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось создать новый заказ.");
    }
}


void MainWindow::on_pushButton_deleteOrder_clicked()
{
    int orderId = ui->comboBox_OrderSelect->currentData().toInt();

    if (orderId == 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите заказ для удаления.");
        return;
    }

    if (QMessageBox::question(this, "Удаление заказа", "Вы уверены, что хотите удалить этот заказ?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        if (DatabaseManager::instance().deleteOrder(orderId)) {
            QMessageBox::information(this, "Успех", "Заказ успешно удален.");
            clearOrderFields();
            updateOrderComboBox();  // обновляем список заказов
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось удалить заказ.");
        }
    }
}
void MainWindow::on_comboBox_OrderSelect_currentIndexChanged(int index)
{
    if (index < 0) return;

    int orderId = ui->comboBox_OrderSelect->currentData().toInt();

    Order order = DatabaseManager::instance().getOrderById(orderId);

    if (order.orderId > 0) {
        ui->lineEdit_orderId->setText(order.contractNumber);
        ui->lineEdit_customerInfo->setText(order.customer);
        ui->lineEdit_orderInfo->setText(order.description);
        ui->lineEdit_orderPrice->setText(QString::number(order.price));
        ui->lineEdit_orderManufacturePrice->setText(QString::number(order.manufacturePrice));
        ui->lineEdit_orderTakeDate->setText(order.startDate.toString());
        ui->lineEdit_orderCompletionDate->setText(order.endDate.toString());
        if (order.qualityControl == 1)
        {
            ui->lineEdit_orderQuality->setText("Пройдена");

        }
        else
        {
            ui->lineEdit_orderQuality->setText("Не пройдена");

        }
    }
}

void MainWindow::clearOrderFields()
{
    ui->lineEdit_orderId->clear();
    ui->lineEdit_customerInfo->clear();
    ui->lineEdit_orderInfo->clear();
    ui->lineEdit_orderPrice->clear();
    ui->lineEdit_orderManufacturePrice->clear();
    ui->lineEdit_orderTakeDate->clear();
    ui->lineEdit_orderCompletionDate->clear();
    ui->lineEdit_orderQuality->clear();
}
void MainWindow::updateOrderComboBox()
{
    ui->comboBox_OrderSelect->clear();

    QList<Order> orders = DatabaseManager::instance().getOrders();

    for (const Order& order : orders) {
        ui->comboBox_OrderSelect->addItem(QString::number(order.orderId) + " - " + order.contractNumber, order.orderId);
    }
}
void MainWindow::saveOrderData()
{
    // Получаем ID выбранного заказа из comboBox_OrderSelect
    int orderId = ui->comboBox_OrderSelect->currentData().toInt();

    // Считываем данные из полей UI
    int contractNumber = ui->lineEdit_orderId->text().toInt();  // Contract number
    QString description = ui->lineEdit_orderInfo->text();  // Description of the order
    double orderPrice = ui->lineEdit_orderPrice->text().toDouble();  // Order price
    double manufacturePrice = ui->lineEdit_orderManufacturePrice->text().toDouble();  // Manufacture price
    QDate startDate = QDate::fromString(ui->lineEdit_orderTakeDate->text(), "yyyy-MM-dd");  // Start date (Take date)
    QDate endDate = QDate::fromString(ui->lineEdit_orderCompletionDate->text(), "yyyy-MM-dd");  // End date (Completion date)
    QString status = "Pending";  // Для примера, пока установим статус как "Pending" (зависит от логики вашего приложения)
    bool qualityControl = (ui->lineEdit_orderQuality->text().toLower() == "yes");  // Quality control - булево значение
    QString customer = ui->lineEdit_customerInfo->text();  // Customer ID

    // Проверяем, существует ли заказ с данным ID
    if (orderId > 0) {
        // Обновляем существующий заказ в базе данных
        bool success = DatabaseManager::instance().updateOrder(
            orderId,  // ID заказа
            contractNumber,  // Contract number
            description,  // Описание заказа
            orderPrice,  // Цена заказа
            startDate,  // Дата начала (принятия заказа)
            endDate,  // Дата завершения
            status,  // Статус заказа
            qualityControl,  // Контроль качества
            customer,  // ID клиента
            manufacturePrice  // Стоимость производства

        );
        updateOrderComboBox();
        // Пытаемся снова выбрать текущий заказ
          int index = ui->comboBox_OrderSelect->findData(orderId);

          if (index != -1) {
              ui->comboBox_OrderSelect->setCurrentIndex(index);  // Восстанавливаем выбранный заказ
          }
        if (!success) {
            QMessageBox::critical(this, "Error", "Ошибка обновления заказа.");
        }
    }

}
