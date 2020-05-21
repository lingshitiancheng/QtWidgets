#include "mytextedit.h"

MyTextEdit::MyTextEdit(QWidget *parent): QTextEdit(parent)
{

}

void MyTextEdit::paintEvent(QPaintEvent *event)
{
    pPainter = new QPainter(this);
    pBrush = new QBrush();
    pPainter->setRenderHint(QPainter::Antialiasing);

}
