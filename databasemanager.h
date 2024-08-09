#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

class DatabaseManager : public QObject {
    Q_OBJECT

public:
    static DatabaseManager& instance();
    bool connectToDatabase(const QString& hostname, const QString& dbname, const QString& username, const QString& password);
    bool addEmployee(const QString& firstName, const QString& lastName, const QString& middleName, const QString& positionName, double salary, const QString& username, const QString& passwordHash, const QString& role);

private:
    DatabaseManager();
    ~DatabaseManager();

    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
