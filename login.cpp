#include "login.h"
#include "ui_login.h"
#include "administrator.h"  // Форма администратора
#include "mainwindow.h"     // Основное окно

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)

{
    ui->setupUi(this);

    // Настройка соединения с базой данных PostgreSQL

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("WoodWorks");
    db.setUserName("postgres");
    db.setPassword("1001");

    if (!db.open()) {
      //  QMessageBox::critical(this, "Ошибка", "Не удалось подключиться к базе данных: " + db.lastError().text());
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text(); // В реальном приложении пароли нужно хешировать

    QSqlQuery query;
    query.prepare("SELECT role FROM employees WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) {
            QString role = query.value(0).toString();

            if (role == "admin") {
                Administrator *adminForm = new Administrator();
                adminForm->show();
            } else if (role == "master") {
                MainWindow *mainForm = new MainWindow();
                mainForm->show();
            }

            this->close(); // Закрываем форму логина
        } else {
            QMessageBox::warning(this, "Ошибка", "Неправильное имя пользователя или пароль");
        }
    } else {
       // QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
    }
}






