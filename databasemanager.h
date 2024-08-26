#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "qdatetime.h"
#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <vector>
struct Material {
    int materialId;
    QString name;
    double quantity;
    QString unit;
    QString type;
};
struct Employee {
    int id;
    QString username;
    QString firstName;
    QString lastName;
    QString middleName;
    QString positionName;
    int workdays = 0;
    int workdone = 0;
    double salary;
};
struct Order {
    int orderId = 0;  // Уникальный идентификатор заказа
    QString contractNumber;  // Номер контракта
    QString description;  // Описание заказа
    double price = 0.0;  // Цена заказа
    QDate startDate;  // Дата начала выполнения заказа
    QDate endDate;  // Дата завершения заказа
    QString status;  // Статус заказа
    bool qualityControl = false;  // Контроль качества
    QString customer = 0;  // Идентификатор клиента
    double manufacturePrice = 0.0;  // Стоимость производства

    // Конструктор по умолчанию
    Order() = default;

    // Конструктор с параметрами
    Order(int _orderId, const QString& _contractNumber, const QString& _description, double _price, const QDate& _startDate, const QDate& _endDate, const QString& _status, bool _qualityControl, QString _customer, double _manufacturePrice)
        : orderId(_orderId),
          contractNumber(_contractNumber),
          description(_description),
          price(_price),
          startDate(_startDate),
          endDate(_endDate),
          status(_status),
          qualityControl(_qualityControl),
          customer(_customer),
          manufacturePrice(_manufacturePrice) {}
};



class DatabaseManager : public QObject {
    Q_OBJECT

public:
    static DatabaseManager& instance();
    bool connectToDatabase(const QString& hostname, const QString& dbname, const QString& username, const QString& password);

    QList<Material> getMaterials();
    QList<Material> getMaterialsByType(const QString &type);
    bool addOrUpdateMaterial(const QString& name, double quantity, const QString& unit, const QString& materialType);
    bool deleteMaterial(const QString& name);  // Удаление материала
    bool updateMaterial(const QString& name, double quantity, const QString& unit, const QString& type);  // Обновление материала

    bool addEmployee(const QString& firstName, const QString& lastName, const QString& middleName, const QString& positionName, double salary, const QString& username, const QString& passwordHash, const QString& role);
    std::vector<Employee> getEmployeeList();
    Employee getEmployeeById(int id);
    bool updateEmployee(int id, const QString& firstName, const QString& lastName, const QString& middleName, const QString& positionName, double salary,int workdays,int workdone);
    bool removeEmployee(int id);

    DatabaseManager();
    ~DatabaseManager();

    QSqlDatabase db;
    bool addMaterialToOrder(int orderId, const QString &materialName, double quantity);
    bool updateMaterialQuantity(const QString &materialName, double newQuantity);
    Material getMaterialByName(const QString &materialName);

    bool createOrder(const QString &contractNumber, const QString &description, double price, double manufacturePrice, const QDate &startDate, const QDate &endDate, const QString &status, bool qualityControl, QString customer);
    bool deleteOrder(int orderId);
    QList<Order> getOrders();
    int createEmptyOrder();
    Order getOrderById(int orderId);
    bool updateOrder(int orderId, int contractNumber, const QString &description, double price, const QDate &startDate, const QDate &endDate, const QString &status, bool qualityControl, QString customer, double manufacturePrice);
    QList<Material> getOrderMaterials(int orderId, const QString &materialType);
    bool updateOrderStatus(int orderId, const QString &newStatus);
    QList<Order> getOrdersForPeriod(const QDate &startDate, const QDate &endDate);
    bool removeMaterialFromOrder(int orderId, int material_id);
};

#endif // DATABASEMANAGER_H
