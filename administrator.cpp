#include "administrator.h"
#include "ui_administrator.h"
#include "databasemanager.h"

#include <QMessageBox>
#include <QCryptographicHash>

Administrator::Administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);

    // Подключение к базе данных через DatabaseManager
    if (!DatabaseManager::instance().connectToDatabase("localhost", "WoodWorks", "postgres", "1001")) {
        QMessageBox::critical(this, "Database Connection", "Failed to connect to database");
        return;
    }

}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::on_pushButtonAddStaff_clicked()
{
    // Получаем данные из полей ввода
    QString fullName = ui->lineEditStaffName->text().trimmed();
    QStringList nameParts = fullName.split(" ");

    if (nameParts.size() < 2) {
        QMessageBox::warning(this, "Ошибка ввода", "Укажите полное имя, или хотя бы имя и фамилию");
        return;
    }

    QString firstName = nameParts[0];
    QString lastName = nameParts[1];
    QString middleName = (nameParts.size() > 2) ? nameParts[2] : "";
    QString positionName = ui->lineEdit_StaffJobAdd->text();
    QString salaryStr = ui->lineEditStaffSalaryAdd->text().trimmed();
    QString username = ui->lineEditStaffLogin->text().trimmed();
    QString password = ui->lineEditStaffPassword->text().trimmed();
    QString role = (ui->comboBox_StaffRole->currentText() == "Администрация") ? "admin" : "master";

    if (firstName.isEmpty() || lastName.isEmpty() || positionName.isEmpty() ||
        salaryStr.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка ввода", "Заполните все поля");
        return;
    }

    // Хэшируем пароль
    QString passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // Преобразуем зарплату из строки в число
    bool salaryConversionOk;
    double salary = salaryStr.toDouble(&salaryConversionOk);

    if (!salaryConversionOk) {
        QMessageBox::warning(this, "Ошибка ввода", "Некорректное значение зарплаты");
        return;
    }

    // Используем DatabaseManager для добавления сотрудника
    if (!DatabaseManager::instance().addEmployee(firstName, lastName, middleName, positionName, salary, username, passwordHash, role)) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось добавить работника");
        return;
    }

    QMessageBox::information(this, "Успех", "Работник успешно добавлен!");

    // Очистка полей после добавления
    ui->lineEditStaffName->clear();
    ui->lineEdit_StaffJobAdd->clear();
    ui->lineEditStaffSalaryAdd->clear();
    ui->lineEditStaffLogin->clear();
    ui->lineEditStaffPassword->clear();
}
