#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
    changeStackedWidget();
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

    QStandardItem *pTextEditItem = new QStandardItem(tr("TextEdit"));
    pButtonItem->setBackground(QBrush(Qt::transparent));
    pStandarItemModel->appendRow(pTextEditItem);



    /* 右侧 */
    // 添加 stackedwidget
    pStackedWidget = new QStackedWidget(pWidget);
    pButton = new Button(pWidget);
    pTextEdit = new TextEdit(pWidget);

    /* 添加列表名字 */
    itemNameWiget.insert("Button", pButton);
    itemNameWiget.insert("TextEdit", pTextEdit);

    pSplitter->addWidget(pStackedWidget);
    pSplitter->setStretchFactor(1, 7);
    pStackedWidget->addWidget(pButton);
    pStackedWidget->addWidget(pTextEdit);
    pStackedWidget->adjustSize();


    /* 设置分割线不可移动 */
    QSplitterHandle *splitterHandle = pSplitter->handle(1);
    splitterHandle->setDisabled(true);
    pStackedWidget->setCurrentWidget(pButton);

    pSplitter->setFixedSize(1000, 810);
}

void MainWindow::changeStackedWidget()
{
    /* 在线翻译界面需要使用网络才能正确显示 */
    connect(pListView, &QListView::clicked, [ = ](const QModelIndex & index) {
        QString data = index.data().toString();
        pStackedWidget->setCurrentWidget(itemNameWiget.value(data));
    });
}

bool MainWindow::isOnline() //由于网络判断在界面加载之前，后期考虑添加线程解决
{
    /* 判断网络是否连接 */
    QString cmdStr = QString("ping -c 1 translate.google.cn");
    QProcess cmd;
    cmd.start(cmdStr);
    cmd.waitForFinished(700);
    QString response = cmd.readAll();
    if (-1 == response.indexOf("time")) {
        return false;
    } else {
        return true;
    }
}


