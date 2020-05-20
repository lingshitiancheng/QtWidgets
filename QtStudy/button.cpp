#include "button.h"

Button::Button(QWidget *parent) : QWidget(parent)
{
    pHBoxLayout = new QHBoxLayout(this);
    pPushButton = new QPushButton(this);
    pPushButton->setText(tr("按钮1"));

    QPushButton *pPushButton1 = new QPushButton(this);
    pPushButton1->setText(tr("按钮2"));
    pHBoxLayout->addStretch();
    pHBoxLayout->addWidget(pPushButton);
    pHBoxLayout->addStretch();
    pHBoxLayout->addWidget(pPushButton1);
    pHBoxLayout->addStretch();
    this->setLayout(pHBoxLayout);
}
