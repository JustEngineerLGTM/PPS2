#include "administrator.h"
#include "ui_administrator.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QLineSeries>
#include <QtCharts>
#include <QDateTimeAxis>
#include <qdatetimeaxis.h>
#include <qlineseries.h>
#include "LocaleManager.h"

Administrator::Administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)


{
    ui->setupUi(this);
    // Создание регулярного выражения для русских букв
    QRegularExpression regExp("[А-Яа-яЁё ]+");  // Разрешает вводить только русские буквы и пробел
    // Создание валидатора на основе регулярного выражения
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp);
    QIntValidator *intValidator = new QIntValidator(0, std::numeric_limits<int>::max());  // Ограничение ввода букв
    QDoubleValidator *doubleValidator = new QDoubleValidator(0.0, 0.01,std::numeric_limits<double>::max());  // Ограничение ввода букв

    ui->lineEditStaffName->setValidator(validator);
    ui->lineEdit_WorkDays->setValidator(intValidator);
    ui->lineEdit_WorkDone->setValidator(intValidator);
    ui->lineEditStaffSalaryAdd->setValidator(doubleValidator);

    ui->dateEdit_start->setDate(QDate::currentDate());
    ui->dateEdit_end->setDate(QDate::currentDate());
    // Подключение к базе данных через DatabaseManager
    if (!DatabaseManager::instance().connectToDatabase("localhost", "WoodWorks", "postgres", "1001")) {
        QMessageBox::critical(this, "Database Connection", "Ошибка подключения к базе данных");
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
        ui->lineEdit_StaffSalary->setText(LocaleManager::getRussianLocale().toString(employee.salary));
        ui->lineEdit_WorkDays->setText(LocaleManager::getRussianLocale().toString(employee.workdays));
        ui->lineEdit_WorkDone->setText(LocaleManager::getRussianLocale().toString(employee.workdone));
        ui->lineEdit_SalarySum->setText(LocaleManager::getRussianLocale().toString(salary));
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

    double salary =  LocaleManager::getRussianLocale().toDouble(salaryStr);

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
       double salary = LocaleManager::getRussianLocale().toDouble(salaryStr,&salaryConversionOk);

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

void Administrator::on_pushButton_generate_clicked()
{
    // Получаем даты из виджетов
    QDate startDate = ui->dateEdit_start->date();
    QDate endDate = ui->dateEdit_end->date();

    if (startDate >= endDate) {
        QMessageBox::warning(this, "Invalid Date Range", "Дата начала не может быть позже или в день даты окончания.");
        return;
    }

    // Запрашиваем данные из базы данных для указанного периода
    QList<Order> orders = DatabaseManager::instance().getOrdersForPeriod(startDate, endDate);

    // Инициализируем переменные для расчета
    double totalIncome = 0.0;
    double totalOutcome = 0.0;
    int completedOrders = 0;

    // Проходим по всем заказам и считаем доход, расходы и количество выполненных заказов
    for (const Order& order : orders) {
        totalIncome += order.price;  // Доход - сумма цен завершенных заказов
        totalOutcome += order.manufacturePrice;  // Расход - сумма затрат на производство
        completedOrders++;
    }

    double totalProfit = totalIncome - totalOutcome;  // Прибыль - разница между доходами и расходами

    // Для расчета роста компании необходимо сравнить показатели с предыдущим периодом
    QDate previousStartDate = startDate.addMonths(-1).addDays(1 - startDate.day());  // Первый день предыдущего месяца
    QDate previousEndDate = previousStartDate.addMonths(1).addDays(-1);  // Последний день предыдущего месяца

    QList<Order> previousOrders = DatabaseManager::instance().getOrdersForPeriod(previousStartDate, previousEndDate);

    double previousIncome = 0.0;
    for (const Order& order : previousOrders) {
        previousIncome += order.price;
    }

    double growthRate = 0.0;
    if (previousIncome > 0) {
        growthRate = ((totalIncome - previousIncome) / previousIncome) * 100;  // Рост в процентах
    }

    // Заполняем UI-поля данными
    ui->lineEdit_income->setText(LocaleManager::getRussianLocale().toString(totalIncome, 'f', 2));  // Доход за период
    ui->lineEdit_orderCompletinoNumber->setText(LocaleManager::getRussianLocale().toString(completedOrders));  // Выполнено заказов
    ui->lineEdit_outcome->setText(LocaleManager::getRussianLocale().toString(totalOutcome, 'f', 2));  // Расход за период
    ui->lineEdit_profit->setText(LocaleManager::getRussianLocale().toString(totalProfit, 'f', 2));  // Прибыль за период
    ui->lineEdit_profitPeriod->setText(LocaleManager::getRussianLocale().toString(growthRate, 'f', 2) + "%");  // Рост компании за предыдущий период

    // Построение графика доходов
    plotIncomeChart(startDate, endDate);
}

void Administrator::plotIncomeChart(QDate startDate, QDate endDate) {
    // Сбор данных для графика
    QList<Order> orders = DatabaseManager::instance().getOrdersForPeriod(startDate, endDate);
    QMap<QDate, double> incomeData;

    // Суммируем доход за каждый день
    for (const Order& order : orders) {
        QDate date = order.endDate;
        incomeData[date] += order.price;
    }
    QLayout *oldLayout = ui->chartWidget->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0))) {
            if (item->widget()) {
                delete item->widget(); // Удаляем виджет
            }
            delete item; // Удаляем элемент макета
        }
        delete oldLayout; // Удаляем сам макет
    }
    // Создаем новую серию данных для графика
    QLineSeries *series = new QLineSeries();

    // Добавляем данные в серию
    for (auto it = incomeData.begin(); it != incomeData.end(); ++it) {
        QDate date = it.key();
        QDateTime dateTime(date, QTime(0, 0)); // Преобразование QDate в QDateTime

        // Проверка и отладка
        // qDebug() << "Date:" << date.toString("yyyy-MM-dd") << "Income:" << it.value();
        series->append(dateTime.toMSecsSinceEpoch(), it.value());
    }

    // Создаем новый график и добавляем серию
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Настройка осей
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Дата");
    chart->setAxisX(axisX, series);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Доход");
    chart->setAxisY(axisY, series);

    // Настройка графика
    chart->setTitle("Доходы за выбранный период");

    // Создаем новый QChartView и добавляем его в макет
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Создаем новый макет и добавляем в него QChartView
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);

    // Устанавливаем макет в виджет
    ui->chartWidget->setLayout(layout);
}






