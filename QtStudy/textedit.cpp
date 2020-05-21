#include "textedit.h"

TextEdit::TextEdit(QWidget *parent)
    : QWidget(parent),
      pVboxLayout(new QVBoxLayout(this))
{
    initUi();
}


/* 用于初始化翻译界面的整体布局 */
void TextEdit::initUi()
{
    this->setLayout(pVboxLayout);
    pOutput = new QTextEdit(this);
    pInput = new QTextEdit(this);
    pVboxLayout->addWidget(pOutput);
    pVboxLayout->addWidget(pInput);
}
