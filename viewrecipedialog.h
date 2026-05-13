#ifndef VIEWRECIPEDIALOG_H
#define VIEWRECIPEDIALOG_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

class ViewRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewRecipeDialog(QVector<QString> &recipes, QWidget *parent = nullptr);
    ~ViewRecipeDialog();

private slots:
    void deleteRecipe(int index);

private:
    void refreshDisplay();

    QVector<QString> *recipes;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QVBoxLayout *scrollLayout;
};

#endif