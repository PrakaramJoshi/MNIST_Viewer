/********************************************************************************
** Form generated from reading UI file 'mnist_viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MNIST_VIEWER_H
#define UI_MNIST_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MNIST_ViewerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *graphicsView;
    QSlider *verticalSlider;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MNIST_ViewerClass)
    {
        if (MNIST_ViewerClass->objectName().isEmpty())
            MNIST_ViewerClass->setObjectName(QStringLiteral("MNIST_ViewerClass"));
        MNIST_ViewerClass->resize(330, 375);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MNIST_ViewerClass->sizePolicy().hasHeightForWidth());
        MNIST_ViewerClass->setSizePolicy(sizePolicy);
        MNIST_ViewerClass->setMinimumSize(QSize(330, 375));
        MNIST_ViewerClass->setMaximumSize(QSize(330, 375));
        centralWidget = new QWidget(MNIST_ViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(lineEdit_2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMinimumSize(QSize(50, 0));
        lineEdit_3->setMaximumSize(QSize(50, 16777215));
        lineEdit_3->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(280, 280));
        graphicsView->setMaximumSize(QSize(280, 280));

        horizontalLayout_3->addWidget(graphicsView);

        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(verticalSlider);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MNIST_ViewerClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MNIST_ViewerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MNIST_ViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MNIST_ViewerClass);

        QMetaObject::connectSlotsByName(MNIST_ViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MNIST_ViewerClass)
    {
        MNIST_ViewerClass->setWindowTitle(QApplication::translate("MNIST_ViewerClass", "MNIST_Viewer", 0));
        pushButton->setText(QApplication::translate("MNIST_ViewerClass", "MNIST File", 0));
        label->setText(QApplication::translate("MNIST_ViewerClass", "Current Image Index", 0));
        label_2->setText(QApplication::translate("MNIST_ViewerClass", "Of", 0));
    } // retranslateUi

};

namespace Ui {
    class MNIST_ViewerClass: public Ui_MNIST_ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MNIST_VIEWER_H
