#include "materialselectiondialog.h"
#include "ui_materialselectiondialog.h"
#include "databasemanager.h"
#include "QInputDialog"
#include <QMessageBox>

Materialselectiondialog::Materialselectiondialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Materialselectiondialog),
    m_selectedQuantity(0)
{
    ui->setupUi(this);

    // Очищаем comboBox перед добавлением новых элементов
    ui->comboBox_material2->clear();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Добавляем типы материалов
    QStringList materialTypes = {"Все материалы", "дерево", "металл", "расходники"};
    ui->comboBox_material2->addItems(materialTypes);

    // Подключаем слот для обновления таблицы при изменении типа материала
    connect(ui->comboBox_material2, &QComboBox::currentTextChanged, this, &Materialselectiondialog::updateMaterialTable);

    // Инициализируем таблицу с материалами
    updateMaterialTable();
}

Materialselectiondialog::~Materialselectiondialog()
{
    delete ui;
}

void Materialselectiondialog::updateMaterialTable()
{
    // Очищаем таблицу
    ui->tableWidget->setRowCount(0);

    // Получаем выбранный тип материала
    QString selectedType = ui->comboBox_material2->currentText();

    // Получаем материалы из базы данных в зависимости от выбранного типа
    QList<Material> materials;
    if (selectedType == "Все материалы") {
        materials = DatabaseManager::instance().getMaterials();
    } else {
        materials = DatabaseManager::instance().getMaterialsByType(selectedType);
    }

    // Заполняем таблицу материалами
    for (const Material& material : materials) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(material.name));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(material.quantity)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(material.unit));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(material.type));
    }
}

void Materialselectiondialog::on_buttonBox_accepted()
{
    // Проверяем, была ли выбрана строка
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите материал для добавления.");
        return;
    }

    // Получаем выбранный материал и его количество
    m_selectedMaterial = ui->tableWidget->item(currentRow, 0)->text();
    double availableQuantity = ui->tableWidget->item(currentRow, 1)->text().toDouble();
    QString unit = ui->tableWidget->item(currentRow, 2)->text();

    // Получаем количество, которое хочет заказать пользователь
    bool ok;
    double orderQuantity = QInputDialog::getDouble(this, "Количество материала",
                                                   "Введите количество для заказа:", 0, 0, availableQuantity, 2, &ok);

    // Если пользователь нажал "Отмена" или не ввел корректное количество
    if (!ok || orderQuantity <= 0 || orderQuantity > availableQuantity) {
        QMessageBox::warning(this, "Ошибка", "Введите корректное количество.");
        return;
    }

    // Обновляем количество материала в базе данных
    m_selectedQuantity = orderQuantity;

    // Закрываем диалог с успешным результатом
    accept();
}

void Materialselectiondialog::on_buttonBox_rejected()
{
    // Закрываем диалог с результатом "Отмена"
    reject();
}

QString Materialselectiondialog::selectedMaterial()
{
    return m_selectedMaterial;
}

int Materialselectiondialog::selectedQuantity()
{
    return m_selectedQuantity;
}
