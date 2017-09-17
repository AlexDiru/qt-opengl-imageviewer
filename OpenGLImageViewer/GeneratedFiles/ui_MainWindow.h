/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "RenderWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    RenderWidget *openGLWidget;
    QPushButton *loadImageButton;
    QPushButton *rotateLeftButton;
    QPushButton *rotateRightButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *panLeftButton;
    QPushButton *panRightButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->setWindowModality(Qt::ApplicationModal);
        MainWindowClass->resize(1605, 1037);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new RenderWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(20, 70, 1521, 901));
        loadImageButton = new QPushButton(centralWidget);
        loadImageButton->setObjectName(QStringLiteral("loadImageButton"));
        loadImageButton->setGeometry(QRect(20, 20, 112, 34));
        rotateLeftButton = new QPushButton(centralWidget);
        rotateLeftButton->setObjectName(QStringLiteral("rotateLeftButton"));
        rotateLeftButton->setGeometry(QRect(140, 20, 112, 34));
        rotateRightButton = new QPushButton(centralWidget);
        rotateRightButton->setObjectName(QStringLiteral("rotateRightButton"));
        rotateRightButton->setGeometry(QRect(260, 20, 112, 34));
        zoomInButton = new QPushButton(centralWidget);
        zoomInButton->setObjectName(QStringLiteral("zoomInButton"));
        zoomInButton->setGeometry(QRect(380, 20, 112, 34));
        zoomOutButton = new QPushButton(centralWidget);
        zoomOutButton->setObjectName(QStringLiteral("zoomOutButton"));
        zoomOutButton->setGeometry(QRect(500, 20, 112, 34));
        panLeftButton = new QPushButton(centralWidget);
        panLeftButton->setObjectName(QStringLiteral("panLeftButton"));
        panLeftButton->setGeometry(QRect(620, 20, 112, 34));
        panRightButton = new QPushButton(centralWidget);
        panRightButton->setObjectName(QStringLiteral("panRightButton"));
        panRightButton->setGeometry(QRect(740, 20, 112, 34));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1605, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        loadImageButton->setText(QApplication::translate("MainWindowClass", "Load Image", Q_NULLPTR));
        rotateLeftButton->setText(QApplication::translate("MainWindowClass", "Rotate Left", Q_NULLPTR));
        rotateRightButton->setText(QApplication::translate("MainWindowClass", "Rotate Right", Q_NULLPTR));
        zoomInButton->setText(QApplication::translate("MainWindowClass", "Zoom In", Q_NULLPTR));
        zoomOutButton->setText(QApplication::translate("MainWindowClass", "Zoom Out", Q_NULLPTR));
        panLeftButton->setText(QApplication::translate("MainWindowClass", "Pan Left", Q_NULLPTR));
        panRightButton->setText(QApplication::translate("MainWindowClass", "Pan Right", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
