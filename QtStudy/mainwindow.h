#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QFrame>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QListView>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringListModel>
#include <QPushButton>
#include <QStackedWidget>
#include <QSplitter>
#include <QTextEdit>

#include "button.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void initUI();
    void changeStackedWidget();

private:
    QHBoxLayout *pHBoxLayout;
    QVBoxLayout *pVBoxLayoutFrameLeft;
    QVBoxLayout *pVBoxLayoutFrameRight;
    QFrame *pFrameLeft;
    QFrame *pFrameRight;
    QListView *pListView;
    QStandardItemModel *pStandarItemModel;
    QListWidget *pListWidget;
    QStackedWidget *pStackedWidget;
    QWidget *pWidget;
    QSplitter *pSplitter;

    /* 类指针 */
    Button *pButton;

    QMap<QString, QWidget *> itemNameWiget;

};
#endif // MAINWINDOW_H







