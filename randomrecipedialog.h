#ifndef RANDOMRECIPEDIALOG_H
#define RANDOMRECIPEDIALOG_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>

class RandomRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RandomRecipeDialog(const QVector<QString> &recipes, QWidget *parent = nullptr);
    ~RandomRecipeDialog();

private:
    QTextEdit *textEdit;
};

#endif