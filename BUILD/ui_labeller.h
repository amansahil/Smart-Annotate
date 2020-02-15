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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Labeller
{
public:
    QAction *actionMark_Object;
    QAction *actionAdd_Text;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelect;
    QAction *actionDelete;
    QAction *actionRectangle;
    QAction *actionSmart_annotate;
    QAction *actionSmart_Click;
    QWidget *centralwidget;
    QPushButton *imageBrowseButton;
    QLabel *label;
    QLineEdit *imageLineEdit;
    QListView *imageList;
    QPushButton *classBrowseButton;
    QListView *classList;
    QLabel *label_4;
    QPushButton *annotationBrowseButton;
    QLabel *label_5;
    QPushButton *saveButton;
    QPushButton *clearButton;
    QLabel *imageDirLabel;
    QLabel *classFileLabel;
    QPushButton *searchImages;
    QPushButton *sortImagesAsc;
    QPushButton *sortImagesDsc;
    QPushButton *sortImagesdateAsc;
    QPushButton *sortImagesDateDsc;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *sortClassDscButton;
    QPushButton *sortClassAscButton;
    QPushButton *addNameItemButton;
    QLineEdit *classItemLineEdit;
    QPushButton *deleteClassItemButton;
    QLabel *annotationDirLabel;
    QGraphicsView *graphicsView;
    QLabel *cursorLabel;
    QLabel *label_6;
    QPushButton *restoreImages;
    QLabel *label_7;
    QLabel *shapeLabel;
    QPushButton *connectButton;
    QPushButton *clearPoints;
    QMenuBar *menubar;
    QMenu *menuLabel;
    QMenu *menuEdit;
    QMenu *menuShape;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Labeller)
    {
        if (Labeller->objectName().isEmpty())
            Labeller->setObjectName(QString::fromUtf8("Labeller"));
        Labeller->resize(1308, 778);
        actionMark_Object = new QAction(Labeller);
        actionMark_Object->setObjectName(QString::fromUtf8("actionMark_Object"));
        actionAdd_Text = new QAction(Labeller);
        actionAdd_Text->setObjectName(QString::fromUtf8("actionAdd_Text"));
        actionCopy = new QAction(Labeller);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(Labeller);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionSelect = new QAction(Labeller);
        actionSelect->setObjectName(QString::fromUtf8("actionSelect"));
        actionDelete = new QAction(Labeller);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionRectangle = new QAction(Labeller);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        actionSmart_annotate = new QAction(Labeller);
        actionSmart_annotate->setObjectName(QString::fromUtf8("actionSmart_annotate"));
        actionSmart_Click = new QAction(Labeller);
        actionSmart_Click->setObjectName(QString::fromUtf8("actionSmart_Click"));
        centralwidget = new QWidget(Labeller);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        imageBrowseButton = new QPushButton(centralwidget);
        imageBrowseButton->setObjectName(QString::fromUtf8("imageBrowseButton"));
        imageBrowseButton->setGeometry(QRect(70, 40, 89, 25));
        imageBrowseButton->setAutoFillBackground(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 61, 21));
        imageLineEdit = new QLineEdit(centralwidget);
        imageLineEdit->setObjectName(QString::fromUtf8("imageLineEdit"));
        imageLineEdit->setGeometry(QRect(10, 70, 221, 25));
        imageList = new QListView(centralwidget);
        imageList->setObjectName(QString::fromUtf8("imageList"));
        imageList->setGeometry(QRect(10, 180, 451, 171));
        classBrowseButton = new QPushButton(centralwidget);
        classBrowseButton->setObjectName(QString::fromUtf8("classBrowseButton"));
        classBrowseButton->setGeometry(QRect(70, 360, 89, 25));
        classList = new QListView(centralwidget);
        classList->setObjectName(QString::fromUtf8("classList"));
        classList->setGeometry(QRect(10, 500, 451, 151));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(classList->sizePolicy().hasHeightForWidth());
        classList->setSizePolicy(sizePolicy);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 360, 67, 21));
        annotationBrowseButton = new QPushButton(centralwidget);
        annotationBrowseButton->setObjectName(QString::fromUtf8("annotationBrowseButton"));
        annotationBrowseButton->setGeometry(QRect(140, 660, 89, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 650, 121, 41));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(370, 690, 89, 25));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(1190, 10, 89, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/redo-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon);
        imageDirLabel = new QLabel(centralwidget);
        imageDirLabel->setObjectName(QString::fromUtf8("imageDirLabel"));
        imageDirLabel->setGeometry(QRect(170, 40, 281, 21));
        classFileLabel = new QLabel(centralwidget);
        classFileLabel->setObjectName(QString::fromUtf8("classFileLabel"));
        classFileLabel->setGeometry(QRect(180, 350, 271, 41));
        searchImages = new QPushButton(centralwidget);
        searchImages->setObjectName(QString::fromUtf8("searchImages"));
        searchImages->setGeometry(QRect(240, 70, 89, 25));
        sortImagesAsc = new QPushButton(centralwidget);
        sortImagesAsc->setObjectName(QString::fromUtf8("sortImagesAsc"));
        sortImagesAsc->setGeometry(QRect(10, 140, 101, 25));
        sortImagesDsc = new QPushButton(centralwidget);
        sortImagesDsc->setObjectName(QString::fromUtf8("sortImagesDsc"));
        sortImagesDsc->setGeometry(QRect(120, 140, 101, 25));
        sortImagesdateAsc = new QPushButton(centralwidget);
        sortImagesdateAsc->setObjectName(QString::fromUtf8("sortImagesdateAsc"));
        sortImagesdateAsc->setGeometry(QRect(230, 140, 101, 25));
        sortImagesDateDsc = new QPushButton(centralwidget);
        sortImagesDateDsc->setObjectName(QString::fromUtf8("sortImagesDateDsc"));
        sortImagesDateDsc->setGeometry(QRect(340, 140, 101, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 91, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 430, 91, 20));
        sortClassDscButton = new QPushButton(centralwidget);
        sortClassDscButton->setObjectName(QString::fromUtf8("sortClassDscButton"));
        sortClassDscButton->setGeometry(QRect(120, 460, 101, 25));
        sortClassAscButton = new QPushButton(centralwidget);
        sortClassAscButton->setObjectName(QString::fromUtf8("sortClassAscButton"));
        sortClassAscButton->setGeometry(QRect(10, 460, 101, 25));
        addNameItemButton = new QPushButton(centralwidget);
        addNameItemButton->setObjectName(QString::fromUtf8("addNameItemButton"));
        addNameItemButton->setGeometry(QRect(270, 390, 89, 25));
        classItemLineEdit = new QLineEdit(centralwidget);
        classItemLineEdit->setObjectName(QString::fromUtf8("classItemLineEdit"));
        classItemLineEdit->setGeometry(QRect(10, 390, 251, 25));
        deleteClassItemButton = new QPushButton(centralwidget);
        deleteClassItemButton->setObjectName(QString::fromUtf8("deleteClassItemButton"));
        deleteClassItemButton->setGeometry(QRect(370, 390, 89, 25));
        annotationDirLabel = new QLabel(centralwidget);
        annotationDirLabel->setObjectName(QString::fromUtf8("annotationDirLabel"));
        annotationDirLabel->setGeometry(QRect(230, 660, 231, 21));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(500, 40, 781, 651));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        cursorLabel = new QLabel(centralwidget);
        cursorLabel->setObjectName(QString::fromUtf8("cursorLabel"));
        cursorLabel->setGeometry(QRect(610, 10, 111, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 10, 101, 21));
        restoreImages = new QPushButton(centralwidget);
        restoreImages->setObjectName(QString::fromUtf8("restoreImages"));
        restoreImages->setGeometry(QRect(340, 70, 89, 25));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(740, 10, 101, 21));
        shapeLabel = new QLabel(centralwidget);
        shapeLabel->setObjectName(QString::fromUtf8("shapeLabel"));
        shapeLabel->setGeometry(QRect(850, 10, 151, 21));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(960, 10, 89, 25));
        clearPoints = new QPushButton(centralwidget);
        clearPoints->setObjectName(QString::fromUtf8("clearPoints"));
        clearPoints->setGeometry(QRect(1070, 10, 101, 25));
        Labeller->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Labeller);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1308, 22));
        menuLabel = new QMenu(menubar);
        menuLabel->setObjectName(QString::fromUtf8("menuLabel"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuShape = new QMenu(menubar);
        menuShape->setObjectName(QString::fromUtf8("menuShape"));
        Labeller->setMenuBar(menubar);
        statusbar = new QStatusBar(Labeller);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Labeller->setStatusBar(statusbar);

        menubar->addAction(menuLabel->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuShape->menuAction());
        menuLabel->addAction(actionMark_Object);
        menuLabel->addAction(actionAdd_Text);
        menuLabel->addAction(actionSelect);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuShape->addAction(actionRectangle);
        menuShape->addAction(actionSmart_annotate);
        menuShape->addAction(actionSmart_Click);

        retranslateUi(Labeller);

        QMetaObject::connectSlotsByName(Labeller);
    } // setupUi

    void retranslateUi(QMainWindow *Labeller)
    {
        Labeller->setWindowTitle(QApplication::translate("Labeller", "Labeller", nullptr));
        actionMark_Object->setText(QApplication::translate("Labeller", "Mark Object", nullptr));
        actionAdd_Text->setText(QApplication::translate("Labeller", "Add Text", nullptr));
        actionCopy->setText(QApplication::translate("Labeller", "Copy (Ctrl + C)", nullptr));
        actionPaste->setText(QApplication::translate("Labeller", "Paste (Ctrl + V)", nullptr));
        actionSelect->setText(QApplication::translate("Labeller", "Select", nullptr));
        actionDelete->setText(QApplication::translate("Labeller", "Delete (Del)", nullptr));
        actionRectangle->setText(QApplication::translate("Labeller", "Rectangle", nullptr));
        actionSmart_annotate->setText(QApplication::translate("Labeller", "Smart annotate", nullptr));
        actionSmart_Click->setText(QApplication::translate("Labeller", "Smart Click", nullptr));
        imageBrowseButton->setText(QApplication::translate("Labeller", "Browse", nullptr));
        label->setText(QApplication::translate("Labeller", "Images", nullptr));
        classBrowseButton->setText(QApplication::translate("Labeller", "Browse", nullptr));
        label_4->setText(QApplication::translate("Labeller", "Classes", nullptr));
        annotationBrowseButton->setText(QApplication::translate("Labeller", "Browse", nullptr));
        label_5->setText(QApplication::translate("Labeller", "Annotation File", nullptr));
        saveButton->setText(QApplication::translate("Labeller", "Save", nullptr));
        clearButton->setText(QApplication::translate("Labeller", "Clear", nullptr));
        imageDirLabel->setText(QString());
        classFileLabel->setText(QString());
        searchImages->setText(QApplication::translate("Labeller", "Search", nullptr));
        sortImagesAsc->setText(QApplication::translate("Labeller", "Name (ASC)", nullptr));
        sortImagesDsc->setText(QApplication::translate("Labeller", "Name (DSC)", nullptr));
        sortImagesdateAsc->setText(QApplication::translate("Labeller", "Date (ASC)", nullptr));
        sortImagesDateDsc->setText(QApplication::translate("Labeller", "Date (DSC)", nullptr));
        label_2->setText(QApplication::translate("Labeller", "Sort By :", nullptr));
        label_3->setText(QApplication::translate("Labeller", "Sort By :", nullptr));
        sortClassDscButton->setText(QApplication::translate("Labeller", "Name (DSC)", nullptr));
        sortClassAscButton->setText(QApplication::translate("Labeller", "Name (ASC)", nullptr));
        addNameItemButton->setText(QApplication::translate("Labeller", "Add", nullptr));
        deleteClassItemButton->setText(QApplication::translate("Labeller", "Delete", nullptr));
        annotationDirLabel->setText(QString());
        cursorLabel->setText(QApplication::translate("Labeller", "Select Mode", nullptr));
        label_6->setText(QApplication::translate("Labeller", "Cursor Mode:", nullptr));
        restoreImages->setText(QApplication::translate("Labeller", "Restore", nullptr));
        label_7->setText(QApplication::translate("Labeller", "Shape Mode:", nullptr));
        shapeLabel->setText(QApplication::translate("Labeller", "Rectangle", nullptr));
        connectButton->setText(QApplication::translate("Labeller", "Connect", nullptr));
        clearPoints->setText(QApplication::translate("Labeller", "Clear Points", nullptr));
        menuLabel->setTitle(QApplication::translate("Labeller", "Label", nullptr));
        menuEdit->setTitle(QApplication::translate("Labeller", "Edit", nullptr));
        menuShape->setTitle(QApplication::translate("Labeller", "Shape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Labeller: public Ui_Labeller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELLER_H
