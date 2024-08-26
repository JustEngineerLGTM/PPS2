/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *usernameEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *passwordEdit;
    QLabel *label_3;
    QPushButton *login;
    QLabel *label_4;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(452, 399);
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 170, 321, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        layoutWidget->setFont(font);
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter);

        usernameEdit = new QLineEdit(layoutWidget);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setFont(font);

        verticalLayout->addWidget(usernameEdit);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setFont(font);

        verticalLayout_2->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setFont(font);
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(passwordEdit);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        label_3 = new QLabel(Login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 110, 231, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(20);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        login = new QPushButton(Login);
        login->setObjectName("login");
        login->setGeometry(QRect(170, 300, 131, 41));
        login->setFont(font);
        login->setAutoFillBackground(false);
        login->setAutoDefault(false);
        label_4 = new QLabel(Login);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 10, 81, 101));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/clipart375318 (1).png")));
        label_4->setScaledContents(true);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\320\222\321\205\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        login->setText(QCoreApplication::translate("Login", "\320\222\321\205\320\276\320\264", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
