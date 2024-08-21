#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <vector>
struct Material {
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

private:
    DatabaseManager();
    ~DatabaseManager();

    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
