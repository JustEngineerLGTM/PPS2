#ifndef MATERIALSELECTIONDIALOG_H
#define MATERIALSELECTIONDIALOG_H

#include <QDialog>
#include <QTableWidget>
namespace Ui {
class Materialselectiondialog;
}

class Materialselectiondialog : public QDialog
{
    Q_OBJECT

public:
    explicit Materialselectiondialog(QWidget *parent = nullptr);
    ~Materialselectiondialog();

    QString selectedMaterial();
    int selectedQuantity();

    void updateMaterialTable();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
private:
    Ui::Materialselectiondialog *ui;
    QString m_selectedMaterial;
    double m_selectedQuantity;
};

#endif // MATERIALSELECTIONDIALOG_H
