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
     updateStaffList();
}

Administrator::~Administrator()
{
    delete ui;
}
void Administrator::updateStaffList()
{
    // Сохраняем текущий id и текст (имя и фамилия) выбранного сотрудника
    int currentId = ui->comboBox_StaffSelected->currentData().toInt();
    QString currentText = ui->comboBox_StaffSelected->currentText();

    ui->comboBox_StaffSelected->clear();

    auto employees = DatabaseManager::instance().getEmployeeList();

    // Сортировка сотрудников по фамилии, а затем по имени
    std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return (a.lastName < b.lastName) || (a.lastName == b.lastName && a.firstName < b.firstName);
    });

    // Заполняем ComboBox отсортированными значениями
    for (const auto& employee : employees) {
        QString fullName = employee.firstName + " " + employee.lastName;
        ui->comboBox_StaffSelected->addItem(fullName, employee.id);
    }

    // Восстанавливаем прежний выбор
    int index = ui->comboBox_StaffSelected->findData(currentId);

    // Если id не найден, устанавливаем на тот, который имеет текстовое совпадение
    if (index == -1) {
        index = ui->comboBox_StaffSelected->findText(currentText);
    }

    if (index != -1) {
        ui->comboBox_StaffSelected->setCurrentIndex(index);
    }
}

void Administrator::updateStuff()
{
    int employeeId = ui->comboBox_StaffSelected->currentData().toInt();
    auto employee = DatabaseManager::instance().getEmployeeById(employeeId);
    int salary = employee.workdays * employee.salary + employee.salary * 0.01 * employee.workdone;
    if (employee.id != -1) {
        ui->lineEdit_StaffNameInfo->setText(employee.firstName + " " + employee.lastName + " " + employee.middleName);
        ui->lineEdit_StaffJobInfo->setText(employee.positionName);
        ui->lineEdit_StaffSalary->setText(QString::number(employee.salary));
        ui->lineEdit_WorkDays->setText(QString::number(employee.workdays));
        ui->lineEdit_WorkDone->setText(QString::number(employee.workdone));
        ui->lineEdit_SalarySum->setText(QString::number(salary));
    }
}
void Administrator::on_pushButton_AddStaff_clicked()
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
    updateStaffList();
    // Очистка полей после добавления
    ui->lineEditStaffName->clear();
    ui->lineEdit_StaffJobAdd->clear();
    ui->lineEditStaffSalaryAdd->clear();
    ui->lineEditStaffLogin->clear();
    ui->lineEditStaffPassword->clear();
}

void Administrator::on_pushButton_SaveStaff_clicked()
{
    int employeeId = ui->comboBox_StaffSelected->currentData().toInt();
       QStringList nameParts = ui->lineEdit_StaffNameInfo->text().trimmed().split(" ");

       if (nameParts.size() < 2) {
           QMessageBox::warning(this, "Ошибка ввода", "Укажите полное имя, или хотя бы имя и фамилию");
           return;
       }

       QString firstName = nameParts[0];
       QString lastName = nameParts[1];
       QString middleName = (nameParts.size() > 2) ? nameParts[2] : "";
       QString positionName = ui->lineEdit_StaffJobInfo->text();
       QString salaryStr = ui->lineEdit_StaffSalary->text().trimmed();
       int workdays = ui->lineEdit_WorkDays->text().toInt();
       int workdone = ui->lineEdit_WorkDone->text().toInt();

       bool salaryConversionOk;
       double salary = salaryStr.toDouble(&salaryConversionOk);

       if (!salaryConversionOk) {
           QMessageBox::warning(this, "Ошибка ввода", "Некорректное значение зарплаты");
           return;
       }

       if (!DatabaseManager::instance().updateEmployee(employeeId, firstName, lastName, middleName, positionName, salary,workdays,workdone)) {
           QMessageBox::critical(this, "Ошибка базы данных", "Не удалось сохранить данные сотрудника");
           return;
       }

       QMessageBox::information(this, "Успех", "Данные сотрудника успешно сохранены!");
       updateStaffList(); // Обновляем список сотрудников после изменений
}


void Administrator::on_pushButton_RemoveStaff_clicked()
{
    int employeeId = ui->comboBox_StaffSelected->currentData().toInt();

       if (QMessageBox::question(this, "Подтверждение удаления", "Вы уверены, что хотите удалить этого сотрудника?") == QMessageBox::Yes) {
           if (!DatabaseManager::instance().removeEmployee(employeeId)) {
               QMessageBox::critical(this, "Ошибка базы данных", "Не удалось удалить сотрудника");
               return;
           }

           QMessageBox::information(this, "Успех", "Сотрудник успешно удален!");
           updateStaffList(); // Обновляем список сотрудников после удаления
       }
}


void Administrator::on_comboBox_StaffSelected_currentIndexChanged(int index)
{
     updateStuff();
}

