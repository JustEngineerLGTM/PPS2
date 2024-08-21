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

std::vector<Employee> DatabaseManager::getEmployeeList() {
    QSqlQuery query("SELECT e.id, e.first_name, e.last_name, e.middle_name, e.workdays, e.workdone, p.position_name, p.salary FROM employees e LEFT JOIN positions p ON e.position_id = p.position_id");
    std::vector<Employee> employees;

    while (query.next()) {
        Employee employee;
        employee.id = query.value("id").toInt();
        employee.firstName = query.value("first_name").toString();
        employee.lastName = query.value("last_name").toString();
        employee.middleName = query.value("middle_name").toString();
        employee.positionName = query.value("position_name").toString();
        employee.salary = query.value("salary").toDouble();
        employee.workdays = query.value("workdays").toInt();
        employee.workdone = query.value("workdone").toInt();
        employees.push_back(employee);
    }

    return employees;
}

Employee DatabaseManager::getEmployeeById(int id) {
    QSqlQuery query;
    query.prepare("SELECT e.id, e.first_name, e.last_name, e.middle_name, e.workdays, e.workdone, p.position_name, p.salary FROM employees e LEFT JOIN positions p ON e.position_id = p.position_id WHERE e.id = :id");
    query.bindValue(":id", id);

    Employee employee;
    employee.id = -1;

    if (query.exec() && query.next()) {
        employee.id = query.value("id").toInt();
        employee.firstName = query.value("first_name").toString();
        employee.lastName = query.value("last_name").toString();
        employee.middleName = query.value("middle_name").toString();
        employee.positionName = query.value("position_name").toString();
        employee.salary = query.value("salary").toDouble();
        employee.workdays = query.value("workdays").toInt();
        employee.workdone = query.value("workdone").toInt();
    }

    return employee;
}

bool DatabaseManager::updateEmployee(int id, const QString& firstName, const QString& lastName, const QString& middleName, const QString& positionName, double salary, int workdays, int workdone) {
    QSqlQuery query;

    // Проверяем, существует ли уже такая должность
    query.prepare("SELECT position_id FROM positions WHERE position_name = :position_name");
    query.bindValue(":position_name", positionName);

    int positionId = -1;
    if (query.exec() && query.next()) {
        // Получаем ID существующей должности
        positionId = query.value(0).toInt();

        // Обновляем зарплату для существующей должности
        query.prepare("UPDATE positions SET salary = :salary WHERE position_id = :position_id");
        query.bindValue(":salary", salary);
        query.bindValue(":position_id", positionId);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Database Error", "Ошибка обновления зарплаты: " + query.lastError().text());
            return false;
        }
    } else {
        // Если должность не найдена, создаем новую
        query.prepare("INSERT INTO positions (position_name, salary) VALUES (:position_name, :salary)");
        query.bindValue(":position_name", positionName);
        query.bindValue(":salary", salary);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Database Error", "Ошибка добавления должности: " + query.lastError().text());
            return false;
        }

        positionId = query.lastInsertId().toInt();
    }

    // Обновляем данные сотрудника
    query.prepare("UPDATE employees SET first_name = :first_name, last_name = :last_name, middle_name = :middle_name, position_id = :position_id, workdays = :workdays, workdone = :workdone WHERE id = :id");
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);
    query.bindValue(":middle_name", middleName);
    query.bindValue(":position_id", positionId);
    query.bindValue(":workdays", workdays);
    query.bindValue(":workdone", workdone);
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка обновления сотрудника: " + query.lastError().text());
        return false;
    }

    return true;
}


bool DatabaseManager::removeEmployee(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM employees WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка удаления сотрудника: " + query.lastError().text());
        return false;
    }

    return true;
}
QList<Material> DatabaseManager::getMaterials()
{
    QList<Material> materials;
    QSqlQuery query("SELECT material_name, quantity,unit, material_type FROM materials");

    while (query.next()) {
        Material material;
        material.name = query.value(0).toString();
        material.quantity = query.value(1).toDouble();
        material.unit = query.value(2).toString();
        material.type = query.value(3).toString();

        materials.append(material);
    }

    return materials;
}
QList<Material> DatabaseManager::getMaterialsByType(const QString &material_type)
{
    QList<Material> materials;
    QSqlQuery query;
    query.prepare("SELECT material_name, quantity, unit, material_type FROM materials WHERE material_type = :material_type");
    query.bindValue(":material_type", material_type);
    query.exec();

    while (query.next()) {
        Material material;
        material.name = query.value(0).toString();
        material.quantity = query.value(1).toDouble();
        material.unit = query.value(2).toString();
        material.type = query.value(3).toString();

        materials.append(material);
    }

    return materials;
}
bool DatabaseManager::addOrUpdateMaterial(const QString& name, double quantity, const QString& unit, const QString& materialType) {
    QSqlQuery query;

    // Проверяем, существует ли уже такой материал
    query.prepare("SELECT quantity FROM materials WHERE material_name = :name AND unit = :unit");
    query.bindValue(":name", name);
    query.bindValue(":unit", unit);

    if (query.exec() && query.next()) {
        // Если материал существует, обновляем его количество
        double existingQuantity = query.value(0).toDouble();
        query.prepare("UPDATE materials SET quantity = :quantity WHERE material_name = :name AND unit = :unit");
        query.bindValue(":quantity", existingQuantity + quantity);
        query.bindValue(":name", name);
        query.bindValue(":unit", unit);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Database Error", "Ошибка обновления материала: " + query.lastError().text());
            return false;
        }
    } else {
        // Если материал не найден, добавляем новый
        query.prepare("INSERT INTO materials (material_name, quantity, unit, material_type) VALUES (:name, :quantity, :unit, :material_type)");
        query.bindValue(":name", name);
        query.bindValue(":quantity", quantity);
        query.bindValue(":unit", unit);
        query.bindValue(":material_type", materialType);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Database Error", "Ошибка добавления материала: " + query.lastError().text());
            return false;
        }
    }

    return true;
}


bool DatabaseManager::deleteMaterial(const QString& name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM materials WHERE material_name = :name");
    query.bindValue(":name", name);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка удаления материала: " + query.lastError().text());
        return false;
    }

    return true;
}

bool DatabaseManager::updateMaterial(const QString& name, double quantity, const QString& unit, const QString& type)
{
    QSqlQuery query;
    query.prepare("UPDATE materials SET quantity = :quantity, unit = :unit, material_type = :type WHERE material_name = :name");
    query.bindValue(":quantity", quantity);
    query.bindValue(":unit", unit);
    query.bindValue(":type", type);
    query.bindValue(":name", name);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка обновления материала: " + query.lastError().text());
        return false;
    }

    return true;
}
