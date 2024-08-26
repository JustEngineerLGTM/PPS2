#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materialselectiondialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_orderList->setColumnCount(4);  // Количество столбцов
    ui->tableWidget_orderList->setHorizontalHeaderLabels(QStringList() << "Клиент" << "Номер договора" << "Статус" << "Контроль качества");

    // Заполняем comboBox_Material
    populateMaterialTypeComboBox();
    populateMaterialComboBox();
    populateOrderTable();

    // Обновляем таблицу при загрузке формы
    updateMaterialTable();
    updateOrderComboBox();
    connect(ui->lineEdit_orderId, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_customerInfo, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    ui->TextEdit_orderInfo->installEventFilter(this);
    connect(ui->lineEdit_orderPrice, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderManufacturePrice, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->dateEdit_orderTakeDate, &QDateEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->dateEdit_orderCompletionDate, &QDateEdit::editingFinished, this, &MainWindow::saveOrderData);
    connect(ui->lineEdit_orderQuality, &QLineEdit::editingFinished, this, &MainWindow::saveOrderData);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// MainWindow.cpp
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    // Проверяем, что это ваш QTextEdit
    if (watched == ui->TextEdit_orderInfo) {
        // Проверяем, что произошло событие потери фокуса
        if (event->type() == QEvent::FocusOut) {
            // Действие при потере фокуса (аналогично editingFinished)
            onTextEditEditingFinished();
        }
    }
    return QMainWindow::eventFilter(watched, event);  // Возвращаем стандартное поведение
}

void MainWindow::onTextEditEditingFinished()
{
    qDebug() << "Editing finished!";
    saveOrderData();  // Например, сохранение данных
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

// Метод для добавления материала к заказу
void MainWindow::on_pushButton_addMaterialOrder_clicked() {
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

        // Проверяем, есть ли материал уже в таблице заказа
        bool materialExists = false;
        for (int row = 0; row < ui->tableWidget_order->rowCount(); ++row) {
            if (ui->tableWidget_order->item(row, 0)->text() == selectedMaterial) {
                // Если материал уже есть, добавляем количество
                double currentQuantity = ui->tableWidget_order->item(row, 1)->text().toDouble();
                double newQuantity = currentQuantity + selectedQuantity;

                // Обновляем количество материала в таблице
                ui->tableWidget_order->item(row, 1)->setText(QString::number(newQuantity));
                materialExists = true;

                // Обновляем количество материала на складе
                if (!DatabaseManager::instance().updateMaterialQuantity(selectedMaterial, material.quantity - selectedQuantity)) {
                    QMessageBox::warning(this, "Ошибка", "Не удалось обновить количество материала на складе.");
                    return;
                }

                break;
            }
        }

        // Если материал не найден в таблице, добавляем его
        if (!materialExists) {
            // Добавляем материал в заказ
            if (DatabaseManager::instance().addMaterialToOrder(orderId, selectedMaterial, selectedQuantity)) {
                // Уменьшаем количество материала на складе
                double newQuantity = material.quantity - selectedQuantity;
                if (!DatabaseManager::instance().updateMaterialQuantity(selectedMaterial, newQuantity)) {
                    QMessageBox::warning(this, "Ошибка", "Не удалось обновить количество материала на складе.");
                    return;
                }

                // Добавляем новую строку в таблицу
                int row = ui->tableWidget_order->rowCount();
                ui->tableWidget_order->insertRow(row);
                ui->tableWidget_order->setItem(row, 0, new QTableWidgetItem(selectedMaterial));
                ui->tableWidget_order->setItem(row, 1, new QTableWidgetItem(QString::number(selectedQuantity)));
                ui->tableWidget_order->setItem(row, 2, new QTableWidgetItem(material.type));

            } else {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить материал в заказ.");
            }
        }
    }
}

// Метод для удаления материала из заказа
void MainWindow::on_pushButton_DeleteMaterialOrder_clicked() {
    // Получаем текущую выбранную строку в таблице
    int currentRow = ui->tableWidget_order->currentRow();

    if (currentRow == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите материал для удаления.");
        return;
    }

    // Получаем данные о материале и его количестве из выбранной строки
    QString materialName = ui->tableWidget_order->item(currentRow, 0)->text();
    double quantityToRemove = ui->tableWidget_order->item(currentRow, 1)->text().toDouble();

    // Возвращаем материал на склад
    Material material = DatabaseManager::instance().getMaterialByName(materialName);
    double newQuantity = material.quantity + quantityToRemove;

    // Обновляем количество на складе
    if (!DatabaseManager::instance().updateMaterialQuantity(materialName, newQuantity)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось обновить количество материала на складе.");
        return;
    }

    // Удаляем запись из таблицы заказа
    ui->tableWidget_order->removeRow(currentRow);

    // Удаляем материал из базы данных, связанный с заказом
    int orderId = ui->comboBox_OrderNumber2->currentData().toInt();
    if (!DatabaseManager::instance().removeMaterialFromOrder(orderId, material.materialId)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось удалить материал из заказа.");
    }
}


void MainWindow::on_pushButton_newOrder_clicked()
{
    // Создаем новый заказ в базе данных
    int newOrderId = DatabaseManager::instance().createEmptyOrder();

    if (newOrderId > 0) {
        // Успешно создан новый заказ, обновляем UI
        updateOrderComboBox();
        int index = ui->comboBox_OrderSelect->findData(newOrderId);

        if (index != -1) {
            ui->comboBox_OrderSelect->setCurrentIndex(index);  // Восстанавливаем выбранный заказ
        }
        // Очищаем другие поля для заполнения пользователем
        ui->lineEdit_customerInfo->clear();
        ui->TextEdit_orderInfo->clear();
        ui->lineEdit_orderPrice->clear();
        ui->lineEdit_orderManufacturePrice->clear();
        ui->dateEdit_orderTakeDate->setDate(QDate::currentDate());
        ui->dateEdit_orderCompletionDate->setDate(QDate::currentDate());
        ui->lineEdit_orderQuality->clear();
        QMessageBox::information(this, "Новый заказ", "Новый заказ успешно создан. Теперь вы можете заполнить его детали.");
        populateOrderTable();
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
        ui->TextEdit_orderInfo->setText(order.description);
        ui->lineEdit_orderPrice->setText(QString::number(order.price));
        ui->lineEdit_orderManufacturePrice->setText(QString::number(order.manufacturePrice));
        ui->dateEdit_orderTakeDate->setDate(order.startDate);
        ui->dateEdit_orderCompletionDate->setDate(order.endDate);
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
    ui->TextEdit_orderInfo->clear();
    ui->lineEdit_orderPrice->clear();
    ui->lineEdit_orderManufacturePrice->clear();
    ui->dateEdit_orderTakeDate->setDate(QDate::currentDate());
    ui->dateEdit_orderCompletionDate->setDate(QDate::currentDate());
    ui->lineEdit_orderQuality->clear();
}
void MainWindow::updateOrderComboBox()
{
    ui->comboBox_OrderNumber2->clear();
    ui->comboBox_OrderSelect->clear();

    QList<Order> orders = DatabaseManager::instance().getOrders();

    for (const Order& order : orders) {
        ui->comboBox_OrderNumber2->addItem(QString::number(order.orderId) + " - " + order.contractNumber, order.orderId);
        ui->comboBox_OrderSelect->addItem(QString::number(order.orderId) + " - " + order.contractNumber, order.orderId);
    }
}
void MainWindow::saveOrderData()
{
    // Получаем ID выбранного заказа из comboBox_OrderSelect
    int orderId = ui->comboBox_OrderSelect->currentData().toInt();

    // Считываем данные из полей UI
    int contractNumber = ui->lineEdit_orderId->text().toInt();  // Contract number
    QString description = ui->TextEdit_orderInfo->toPlainText();  // Description of the order
    double orderPrice = ui->lineEdit_orderPrice->text().toDouble();  // Order price
    double manufacturePrice = ui->lineEdit_orderManufacturePrice->text().toDouble();  // Manufacture price
    QDate startDate = ui->dateEdit_orderTakeDate->date();  // Start date (Take date)
    QDate endDate = ui->dateEdit_orderCompletionDate->date();  // End date (Completion date)
    QString status = ui->lineEdit_orderStatus->text(); //Status
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
        populateOrderTable();
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
void MainWindow::populateOrderTable()
{
    // Очищаем таблицу перед заполнением новыми данными
    ui->tableWidget_orderList->clearContents();
    ui->tableWidget_orderList->setRowCount(0);

    // Получаем список заказов из базы данных
    QList<Order> orders = DatabaseManager::instance().getOrders();

    // Заполняем таблицу заказами
    for (int i = 0; i < orders.size(); ++i) {
        const Order& order = orders.at(i);

        // Добавляем новую строку в таблицу
        ui->tableWidget_orderList->insertRow(i);

        // Заполняем столбцы данными о заказе
        ui->tableWidget_orderList->setItem(i, 0, new QTableWidgetItem(order.customer));  // Клиент
        ui->tableWidget_orderList->setItem(i, 1, new QTableWidgetItem(order.contractNumber));  // Номер договора
        ui->tableWidget_orderList->setItem(i, 2, new QTableWidgetItem(order.status));  // Статус
        ui->tableWidget_orderList->setItem(i, 3, new QTableWidgetItem(order.qualityControl ? "Да" : "Нет"));  // Контроль качества
    }
}
void MainWindow::populateMaterialTypeComboBox()
{
    ui->comboBox_order_material->clear();
    QStringList materialTypes = {"Все материалы", "дерево", "металл", "расходники"};
    ui->comboBox_order_material->addItems(materialTypes);
}


void MainWindow::on_comboBox_OrderNumber2_currentIndexChanged(const int &arg1)
{
    int orderId = ui->comboBox_OrderNumber2->currentData().toInt();
    QString materialType = ui->comboBox_order_material->currentText();

    loadOrderMaterials(orderId, materialType);
}

void MainWindow::on_comboBox_order_material_currentIndexChanged(int index)
{
    int orderId = ui->comboBox_OrderNumber2->currentData().toInt();
    QString materialType = ui->comboBox_order_material->currentText();

    loadOrderMaterials(orderId, materialType);
}

void MainWindow::loadOrderMaterials(int orderId, const QString& materialType)
{
    // Очищаем таблицу перед добавлением новых данных
    ui->tableWidget_order->clearContents();
    ui->tableWidget_order->setRowCount(0);

    // Получаем материалы для данного заказа с фильтрацией по типу
    QList<Material> materials = DatabaseManager::instance().getOrderMaterials(orderId, materialType);

    // Заполняем таблицу материалами
    int row = 0;
    for (const Material& material : materials) {
        ui->tableWidget_order->insertRow(row);
        ui->tableWidget_order->setItem(row, 0, new QTableWidgetItem(material.name));  // Название материала
        ui->tableWidget_order->setItem(row, 1, new QTableWidgetItem(QString::number(material.quantity)));  // Количество
        ui->tableWidget_order->setItem(row, 2, new QTableWidgetItem(material.type));  // Тип материала

        row++;
    }

       // Загружаем данные о заказе из БД
       Order order = DatabaseManager::instance().getOrderById(orderId);

       // Заполняем поля
       ui->lineEdit_orderNumber->setText(order.contractNumber);  // Номер договора
       ui->lineEdit_orderStatus->setText(order.status);  // Текущий статус заказа
       ui->textEdit_orderInfo2->setText(order.description);
}
void MainWindow::changeOrderStatus(const QString& newStatus)
{
    int orderId = ui->comboBox_OrderNumber2->currentData().toInt();

    if (orderId > 0) {
        // Обновляем статус заказа в базе данных
        bool success = DatabaseManager::instance().updateOrderStatus(orderId, newStatus);

        if (success) {
            // Обновляем статус в UI
            ui->lineEdit_orderStatus->setText(newStatus);
        } else {
            QMessageBox::critical(this, "Error", "Ошибка обновления статуса заказа.");
        }
    }
}
void MainWindow::on_pushButton_userStatus_clicked()
{
    QString customStatus = ui->lineEdit_userStep->text();

    if (!customStatus.isEmpty()) {
        changeOrderStatus(customStatus);  // Используем ту же функцию для изменения статуса
    } else {
        QMessageBox::warning(this, "Warning", "Введите пользовательский статус.");
    }
}

void MainWindow::on_pushButton_designStep_clicked()
{
    changeOrderStatus("Проектирование");
}

void MainWindow::on_pushButton_manufacturingStep_clicked()
{
    changeOrderStatus("Изготовление");
}

void MainWindow::on_pushButton_paintingStep_clicked()
{
    changeOrderStatus("Покраска");
}

void MainWindow::on_pushButton_assemblyStep_clicked()
{
    changeOrderStatus("Сборка");
}

void MainWindow::on_pushButton_completeStep_clicked()
{
    changeOrderStatus("Завершен");
}



