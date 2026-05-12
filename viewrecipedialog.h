#ifndef VIEWRECIPEDIALOG_H
#define VIEWRECIPEDIALOG_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>

class ViewRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewRecipeDialog(const QVector<QString> &recipes, QWidget *parent = nullptr);
    ~ViewRecipeDialog();

private:
    QTextEdit *textEdit;
};

#endif