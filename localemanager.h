#ifndef LOCALEMANAGER_H
#define LOCALEMANAGER_H

#include <QObject>
#include <QLocale>
class LocaleManager : public QObject
{
    Q_OBJECT
public:
    explicit LocaleManager(QObject *parent = nullptr);
    static QLocale& getRussianLocale() {
        static QLocale russianLocale(QLocale::Russian);
        return russianLocale;
    }
signals:

};

#endif // LOCALEMANAGER_H
