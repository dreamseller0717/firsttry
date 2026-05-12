#include "viewrecipedialog.h"

ViewRecipeDialog::ViewRecipeDialog(const QVector<QString> &recipes, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("查看食谱");
    resize(400, 500);
    
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    
    QString displayText;
    for (int i = 0; i < recipes.size(); ++i) {
        displayText += QString::number(i + 1) + ". " + recipes[i] + "\n\n";
    }
    
    textEdit->setPlainText(displayText);
}

ViewRecipeDialog::~ViewRecipeDialog()
{
}