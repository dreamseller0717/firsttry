#include "randomrecipedialog.h"
#include <QRandomGenerator>

RandomRecipeDialog::RandomRecipeDialog(const QVector<QString> &recipes, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("随机食谱");
    resize(400, 200);
    
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    
    QRandomGenerator *generator = QRandomGenerator::global();
    int randomIndex = generator->bounded(recipes.size());
    QString randomRecipe = recipes[randomIndex];
    
    textEdit->setPlainText(randomRecipe);
}

RandomRecipeDialog::~RandomRecipeDialog()
{
}