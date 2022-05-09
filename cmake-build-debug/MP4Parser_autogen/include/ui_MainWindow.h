/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTreeWidget *structTree;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *baseInfoTab;
    QGridLayout *gridLayout_3;
    QTextEdit *baseInfoTextEdit;
    QWidget *sampleTab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioVideo;
    QLabel *label;
    QPushButton *homeButton;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QPushButton *endButton;
    QLineEdit *lineEditSample;
    QRadioButton *radioAudio;
    QTextEdit *textEditSampleInfo;
    QTextEdit *hexView;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filePathEdit;
    QPushButton *openButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(920, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        structTree = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        structTree->setHeaderItem(__qtreewidgetitem);
        structTree->setObjectName(QString::fromUtf8("structTree"));
        structTree->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        splitter->addWidget(structTree);
        structTree->header()->setVisible(false);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 200));
        tabWidget->setMaximumSize(QSize(16777215, 200));
        baseInfoTab = new QWidget();
        baseInfoTab->setObjectName(QString::fromUtf8("baseInfoTab"));
        gridLayout_3 = new QGridLayout(baseInfoTab);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        baseInfoTextEdit = new QTextEdit(baseInfoTab);
        baseInfoTextEdit->setObjectName(QString::fromUtf8("baseInfoTextEdit"));
        baseInfoTextEdit->setReadOnly(true);

        gridLayout_3->addWidget(baseInfoTextEdit, 0, 0, 1, 1);

        tabWidget->addTab(baseInfoTab, QString());
        sampleTab = new QWidget();
        sampleTab->setObjectName(QString::fromUtf8("sampleTab"));
        layoutWidget = new QWidget(sampleTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 535, 151));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(20);
        radioVideo = new QRadioButton(layoutWidget);
        radioVideo->setObjectName(QString::fromUtf8("radioVideo"));

        gridLayout_2->addWidget(radioVideo, 0, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        homeButton = new QPushButton(layoutWidget);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));

        gridLayout_2->addWidget(homeButton, 2, 0, 1, 1);

        prevButton = new QPushButton(layoutWidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));

        gridLayout_2->addWidget(prevButton, 2, 1, 1, 1);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        gridLayout_2->addWidget(nextButton, 2, 2, 1, 1);

        endButton = new QPushButton(layoutWidget);
        endButton->setObjectName(QString::fromUtf8("endButton"));

        gridLayout_2->addWidget(endButton, 2, 3, 1, 1);

        lineEditSample = new QLineEdit(layoutWidget);
        lineEditSample->setObjectName(QString::fromUtf8("lineEditSample"));
        lineEditSample->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditSample, 1, 1, 1, 2);

        radioAudio = new QRadioButton(layoutWidget);
        radioAudio->setObjectName(QString::fromUtf8("radioAudio"));

        gridLayout_2->addWidget(radioAudio, 0, 2, 1, 2);


        horizontalLayout_2->addLayout(gridLayout_2);

        textEditSampleInfo = new QTextEdit(layoutWidget);
        textEditSampleInfo->setObjectName(QString::fromUtf8("textEditSampleInfo"));
        textEditSampleInfo->setReadOnly(true);

        horizontalLayout_2->addWidget(textEditSampleInfo);

        tabWidget->addTab(sampleTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        hexView = new QTextEdit(widget);
        hexView->setObjectName(QString::fromUtf8("hexView"));
        hexView->setLineWrapMode(QTextEdit::NoWrap);
        hexView->setReadOnly(true);

        verticalLayout_2->addWidget(hexView);

        splitter->addWidget(widget);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 0, 0);
        filePathEdit = new QLineEdit(centralwidget);
        filePathEdit->setObjectName(QString::fromUtf8("filePathEdit"));
        filePathEdit->setReadOnly(true);

        horizontalLayout->addWidget(filePathEdit);

        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        horizontalLayout->addWidget(openButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(openButton, filePathEdit);
        QWidget::setTabOrder(filePathEdit, structTree);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MediaParser", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(baseInfoTab), QCoreApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        radioVideo->setText(QCoreApplication::translate("MainWindow", "video", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sample:", nullptr));
        homeButton->setText(QCoreApplication::translate("MainWindow", "|<<", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        endButton->setText(QCoreApplication::translate("MainWindow", ">>|", nullptr));
        radioAudio->setText(QCoreApplication::translate("MainWindow", "audio", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sampleTab), QCoreApplication::translate("MainWindow", "Sample", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
