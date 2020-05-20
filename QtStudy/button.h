#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class Button : public QWidget
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);

signals:

private:
    QPushButton *pPushButton;
    QHBoxLayout *pHBoxLayout;
};

#endif // BUTTON_H
