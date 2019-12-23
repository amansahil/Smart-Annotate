/********************************************************************************
** Form generated from reading UI file 'labeller.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELLER_H
#define UI_LABELLER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Labeller
{
public:
    QWidget *centralwidget;
    QPushButton *imageBrowseButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QListView *imageList;
    QPushButton *classBrowseButton;
    QListView *classList;
    QLabel *label_4;
    QPushButton *annotationBrowseButton;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *imageDirLabel;
    QLabel *classFileLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Labeller)
    {
        if (Labeller->objectName().isEmpty())
            Labeller->setObjectName(QString::fromUtf8("Labeller"));
        Labeller->resize(1278, 750);
        centralwidget = new QWidget(Labeller);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        imageBrowseButton = new QPushButton(centralwidget);
        imageBrowseButton->setObjectName(QString::fromUtf8("imageBrowseButton"));
        imageBrowseButton->setGeometry(QRect(70, 40, 89, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 67, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 61, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 90, 221, 25));
        imageList = new QListView(centralwidget);
        imageList->setObjectName(QString::fromUtf8("imageList"));
        imageList->setGeometry(QRect(10, 140, 441, 231));
        classBrowseButton = new QPushButton(centralwidget);
        classBrowseButton->setObjectName(QString::fromUtf8("classBrowseButton"));
        classBrowseButton->setGeometry(QRect(70, 390, 89, 25));
        classList = new QListView(centralwidget);
        classList->setObjectName(QString::fromUtf8("classList"));
        classList->setGeometry(QRect(10, 430, 441, 231));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 390, 67, 21));
        annotationBrowseButton = new QPushButton(centralwidget);
        annotationBrowseButton->setObjectName(QString::fromUtf8("annotationBrowseButton"));
        annotationBrowseButton->setGeometry(QRect(130, 680, 89, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 680, 121, 21));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(360, 680, 89, 25));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(480, 30, 811, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1150, 0, 89, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/redo-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1050, 0, 89, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/undo-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon1);
        imageDirLabel = new QLabel(centralwidget);
        imageDirLabel->setObjectName(QString::fromUtf8("imageDirLabel"));
        imageDirLabel->setGeometry(QRect(170, 40, 231, 21));
        classFileLabel = new QLabel(centralwidget);
        classFileLabel->setObjectName(QString::fromUtf8("classFileLabel"));
        classFileLabel->setGeometry(QRect(180, 380, 171, 41));
        Labeller->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Labeller);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1278, 22));
        Labeller->setMenuBar(menubar);
        statusbar = new QStatusBar(Labeller);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Labeller->setStatusBar(statusbar);

        retranslateUi(Labeller);

        QMetaObject::connectSlotsByName(Labeller);
    } // setupUi

    void retranslateUi(QMainWindow *Labeller)
    {
        Labeller->setWindowTitle(QApplication::translate("Labeller", "Labeller", nullptr));
        imageBrowseButton->setText(QApplication::translate("Labeller", "Browse", nullptr));
        label->setText(QApplication::translate("Labeller", "Images", nullptr));
        label_2->setText(QApplication::translate("Labeller", "Search", nullptr));
        classBrowseButton->setText(QApplication::translate("Labeller", "Browse", nullptr));
        label_4->setText(QApplication::translate("Labeller", "Classes", nullptr));
        annotationBrowseButton->setText(QApplication::translate("Labeller", "Browse", nullptr));
        label_5->setText(QApplication::translate("Labeller", "Annotation File", nullptr));
        pushButton_4->setText(QApplication::translate("Labeller", "Save", nullptr));
        pushButton_5->setText(QApplication::translate("Labeller", " Redo", nullptr));
        pushButton_6->setText(QApplication::translate("Labeller", " Undo", nullptr));
        imageDirLabel->setText(QString());
        classFileLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Labeller: public Ui_Labeller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELLER_H
