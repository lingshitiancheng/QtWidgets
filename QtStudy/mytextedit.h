#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QPainter>
#include <QBrush>

/* 实现自绘控件 */

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    MyTextEdit(QWidget *parent);

protected:
    void paintEvent(QPaintEvent *event);
//    void mousePressEvent(QMouseEvent *event);

private:
    QPainter *pPainter;
    QBrush *pBrush;
};

#endif // MYTEXTEDIT_H
