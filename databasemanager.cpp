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

bool DatabaseManager::addMaterialToOrder(int orderId, const QString& materialName, double quantity) {
    QSqlQuery query;

    // Получаем ID материала
    query.prepare("SELECT material_id FROM materials WHERE material_name = :material_name");
    query.bindValue(":material_name", materialName);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось найти материал.");
        return false;
    }
    int materialId = query.value(0).toInt();

    // Проверяем, добавлен ли этот материал уже в заказ
    query.prepare("SELECT quantity FROM order_materials WHERE order_id = :order_id AND material_id = :material_id");
    query.bindValue(":order_id", orderId);
    query.bindValue(":material_id", materialId);

    if (query.exec() && query.next()) {
        // Если материал уже в заказе, обновляем его количество
        double existingQuantity = query.value(0).toDouble();
        query.prepare("UPDATE order_materials SET quantity = :quantity WHERE order_id = :order_id AND material_id = :material_id");
        query.bindValue(":quantity", existingQuantity + quantity);
        query.bindValue(":order_id", orderId);
        query.bindValue(":material_id", materialId);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Ошибка", "Не удалось обновить количество материала в заказе.");
            return false;
        }
    } else {
        // Если материал ещё не в заказе, добавляем его
        query.prepare("INSERT INTO order_materials (order_id, material_id, quantity) VALUES (:order_id, :material_id, :quantity)");
        query.bindValue(":order_id", orderId);
        query.bindValue(":material_id", materialId);
        query.bindValue(":quantity", quantity);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Ошибка", "Не удалось добавить материал в заказ.");
            return false;
        }
    }

    return true;
}

bool DatabaseManager::updateMaterialQuantity(const QString& materialName, double newQuantity) {
    QSqlQuery query;
    query.prepare("UPDATE materials SET quantity = :new_quantity WHERE material_name = :material_name");
    query.bindValue(":new_quantity", newQuantity);
    query.bindValue(":material_name", materialName);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось обновить количество материала на складе.");
        return false;
    }

    return true;
}

Material DatabaseManager::getMaterialByName(const QString& materialName) {
    QSqlQuery query;
    query.prepare("SELECT material_name, quantity, unit, material_type FROM materials WHERE material_name = :material_name");
    query.bindValue(":material_name", materialName);

    Material material;
    if (query.exec() && query.next()) {
        material.name = query.value("material_name").toString();
        material.quantity = query.value("quantity").toDouble();
        material.unit = query.value("unit").toString();
        material.type = query.value("material_type").toString();
    }

    return material;
}
bool DatabaseManager::createOrder(const QString& contractNumber, const QString& description, double price, double manufacturePrice, const QDate& startDate, const QDate& endDate, const QString& status, bool qualityControl, QString customer)
{
    QSqlQuery query;
    query.prepare("INSERT INTO orders (contract_number, description, price, start_date, end_date, status, quality_control, customer, manufacture_price) "
                  "VALUES (:contract_number, :description, :price, :start_date, :end_date, :status, :quality_control, :customer, :manufacture_price)");
    query.bindValue(":contract_number", contractNumber);
    query.bindValue(":description", description);
    query.bindValue(":price", price);
    query.bindValue(":manufacture_price", manufacturePrice);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    query.bindValue(":status", status);
    query.bindValue(":quality_control", qualityControl);
    query.bindValue(":customer", customer);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка создания нового заказа: " + query.lastError().text());
        return false;
    }
    return true;
}

bool DatabaseManager::updateOrder(int orderId, int contractNumber, const QString& description, double price, const QDate& startDate, const QDate& endDate, const QString& status, bool qualityControl, QString customer, double manufacturePrice)
{
    QSqlQuery query;
    query.prepare("UPDATE orders SET contract_number = :contract_number, description = :description, price = :price, start_date = :start_date, "
                  "end_date = :end_date, status = :status, quality_control = :quality_control, customer = :customer, manufacture_price = :manufacture_price "
                  "WHERE order_id = :order_id");

    query.bindValue(":contract_number", contractNumber);
    query.bindValue(":description", description);
    query.bindValue(":price", price);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    query.bindValue(":status", status);
    query.bindValue(":quality_control", qualityControl);
    query.bindValue(":customer", customer);
    query.bindValue(":manufacture_price", manufacturePrice);
    query.bindValue(":order_id", orderId);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка обновления заказа: " + query.lastError().text());
        return false;
    }
    return true;
}


bool DatabaseManager::deleteOrder(int orderId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM orders WHERE order_id = :order_id");
    query.bindValue(":order_id", orderId);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка удаления заказа: " + query.lastError().text());
        return false;
    }

    return true;
}

Order DatabaseManager::getOrderById(int orderId)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE order_id = :order_id");
    query.bindValue(":order_id", orderId);

    Order order;
    if (query.exec() && query.next()) {
        order.orderId = query.value("order_id").toInt();
        order.contractNumber = query.value("contract_number").toString();
        order.description = query.value("description").toString();
        order.price = query.value("price").toDouble();
        order.manufacturePrice = query.value("manufacture_price").toDouble();
        order.startDate = query.value("start_date").toDate();
        order.endDate = query.value("end_date").toDate();
        order.status = query.value("status").toString();
        order.qualityControl = query.value("quality_control").toBool();
        order.customer = query.value("customer").toString();
    }

    return order;
}

QList<Order> DatabaseManager::getOrders()
{
    QList<Order> orders;

    QSqlQuery query("SELECT * FROM orders");

    while (query.next()) {
        Order order;
        order.orderId = query.value("order_id").toInt();
        order.contractNumber = query.value("contract_number").toString();
        order.description = query.value("description").toString();
        order.price = query.value("price").toDouble();
        order.manufacturePrice = query.value("manufacture_price").toDouble();
        order.startDate = query.value("start_date").toDate();
        order.endDate = query.value("end_date").toDate();
        order.status = query.value("status").toString();
        order.qualityControl = query.value("quality_control").toBool();
        order.customer = query.value("customer").toString();

        orders.append(order);
    }

    return orders;
}

int DatabaseManager::createEmptyOrder()
{
    QSqlQuery query;

    // Вставляем новый заказ с минимальной информацией и получаем новый `order_id`
    query.prepare("INSERT INTO orders (contract_number, description, price, start_date, end_date, status, quality_control, customer, manufacture_price) "
                  "VALUES (NULL, '', 0, NULL, NULL, '', false, NULL, 0) RETURNING order_id");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error", "Ошибка создания нового заказа: " + query.lastError().text());
        return -1;
    }

    if (query.next()) {
        // Возвращаем новый ID заказа
        return query.value(0).toInt();
    } else {
        return -1;
    }
}

