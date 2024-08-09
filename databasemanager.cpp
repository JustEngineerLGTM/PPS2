#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QPSQL");
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connectToDatabase(const QString& hostname, const QString& dbname, const QString& username, const QString& password) {
    db.setHostName(hostname);
    db.setDatabaseName(dbname);
    db.setUserName(username);
    db.setPassword(password);

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Connection", "Failed to connect to database: " + db.lastError().text());
        return false;
    }
    return true;
}

bool DatabaseManager::addEmployee(const QString& firstName, const QString& lastName, const QString& middleName, const QString& positionName, double salary, const QString& username, const QString& passwordHash, const QString& role) {
    QSqlQuery query;

    // Проверяем, существует ли уже такая должность
    query.prepare("SELECT position_id FROM positions WHERE position_name = :position_name");
    query.bindValue(":position_name", positionName);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка запроса на получение позиции: " + query.lastError().text());
        return false;
    }

    int positionId;
    if (query.next()) {
        // Если должность найдена, получаем её ID
        positionId = query.value(0).toInt();
    } else {
        // Если должность не найдена, добавляем её в таблицу positions
        query.prepare("INSERT INTO positions (position_name, salary) VALUES (:position_name, :salary)");
        query.bindValue(":position_name", positionName);
        query.bindValue(":salary", salary);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Database Error", "Ошибка добавления должности: " + query.lastError().text());
            return false;
        }

        // Получаем ID только что добавленной должности
        positionId = query.lastInsertId().toInt();
    }

    // Добавляем сотрудника в таблицу employees
    query.prepare("INSERT INTO employees (username, password, role, first_name, last_name, middle_name, position_id) "
                  "VALUES (:username, :password, :role, :first_name, :last_name, :middle_name, :position_id)");
    query.bindValue(":username", username);
    query.bindValue(":password", passwordHash);
    query.bindValue(":role", role);
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);
    query.bindValue(":middle_name", middleName.isEmpty() ? QVariant(QVariant::String) : middleName);
    query.bindValue(":position_id", positionId);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка добавления сотрудника: " + query.lastError().text());
        return false;
    }

    return true;
}
