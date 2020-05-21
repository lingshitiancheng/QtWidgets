#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>

class TextEdit : public QWidget
{
    Q_OBJECT
public:
    TextEdit(QWidget *parent = nullptr);
private:
    void initUi();
private:
    QVBoxLayout *pVboxLayout;
    QTextEdit *pInput;
    QTextEdit *pOutput;
};

#endif // TEXTEDIT_H
