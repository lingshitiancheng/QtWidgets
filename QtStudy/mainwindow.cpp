#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
    pWidget = new QWidget(this);
    this->setCentralWidget(pWidget);

    /* 添加分割线 */
    pSplitter = new QSplitter(Qt::Horizontal, pWidget); // 当作布局管理器使用


    /* 添加列表名字 */
    itemNameWiget.insert("Button", pButton);


    /* 左侧 */
    pStandarItemModel = new QStandardItemModel(pWidget);
    pListView = new QListView(pWidget);
    pListView->setEditTriggers(QListView::NoEditTriggers);
    pListView->setModel(pStandarItemModel);
    pSplitter->addWidget(pListView);
    pSplitter->setStretchFactor(0, 1);

    // 添加 items
    QStandardItem *pButtonItem = new QStandardItem(tr("Button"));
    pButtonItem->setBackground(QBrush(Qt::transparent));
    pStandarItemModel->appendRow(pButtonItem);



    /* 右侧 */
    // 添加 stackedwidget
    pStackedWidget = new QStackedWidget(pWidget);
    pButton = new Button(pWidget);
    pSplitter->addWidget(pStackedWidget);
    pSplitter->setStretchFactor(1, 7);
    pStackedWidget->addWidget(pButton);
    pStackedWidget->adjustSize();


    /* 设置分割线不可移动 */
    QSplitterHandle *splitterHandle = pSplitter->handle(1);
    splitterHandle->setDisabled(true);
    pStackedWidget->setCurrentWidget(pButton);

    pSplitter->setFixedSize(1000, 810);
}


