#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class TextEdit : public QWidget
{
    Q_OBJECT
public:
    TextEdit(QWidget *parent = nullptr);
};

#endif // TEXTEDIT_H
