#include "addrecipedialog.h"

AddRecipeDialog::AddRecipeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("添加食谱");
    resize(400, 300);
    
    textEdit = new QTextEdit(this);
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    layout->addWidget(buttonBox);
    
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddRecipeDialog::onAccepted);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

AddRecipeDialog::~AddRecipeDialog()
{
}

void AddRecipeDialog::onAccepted()
{
    recipeText = textEdit->toPlainText();
    accept();
}

QString AddRecipeDialog::getRecipeText() const
{
    return recipeText;
}