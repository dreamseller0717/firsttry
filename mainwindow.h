#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddRecipeClicked();
    void onViewRecipesClicked();
    void onRandomRecipeClicked();

private:
    void loadRecipes();
    void saveRecipes();
    QString getDataFilePath();

    QVector<QString> recipes;
    QLabel *welcomeLabel;
    QPushButton *addButton;
    QPushButton *viewButton;
    QPushButton *randomButton;
};

#endif