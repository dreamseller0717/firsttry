#include "mainwindow.h"
#include "addrecipedialog.h"
#include "viewrecipedialog.h"
#include "randomrecipedialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("食谱管理器");
    resize(400, 200);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    welcomeLabel = new QLabel("今天想吃点什么？", this);
    welcomeLabel->setAlignment(Qt::AlignCenter);

    addButton = new QPushButton("添加食谱", this);
    viewButton = new QPushButton("查看食谱", this);
    randomButton = new QPushButton("随机食谱", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(viewButton);
    buttonLayout->addWidget(randomButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(welcomeLabel);
    mainLayout->addLayout(buttonLayout);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddRecipeClicked);
    connect(viewButton, &QPushButton::clicked, this, &MainWindow::onViewRecipesClicked);
    connect(randomButton, &QPushButton::clicked, this, &MainWindow::onRandomRecipeClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onAddRecipeClicked()
{
    AddRecipeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString newRecipe = dialog.getRecipeText();
        if (!newRecipe.isEmpty()) {
            recipes.append(newRecipe);
        } else {
            QMessageBox::warning(this, "警告", "食谱内容不能为空！");
        }
    }
}

void MainWindow::onViewRecipesClicked()
{
    if (recipes.isEmpty()) {
        QMessageBox::information(this, "提示", "还没有添加任何食谱，请先添加！");
        return;
    }
    ViewRecipeDialog dialog(recipes, this);
    dialog.exec();
}

void MainWindow::onRandomRecipeClicked()
{
    if (recipes.isEmpty()) {
        QMessageBox::information(this, "提示", "还没有添加任何食谱，请先添加！");
        return;
    }
    RandomRecipeDialog dialog(recipes, this);
    dialog.exec();
}