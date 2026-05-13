#include "mainwindow.h"
#include "addrecipedialog.h"
#include "viewrecipedialog.h"
#include "randomrecipedialog.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>
#include <QStandardPaths>
#include <QCoreApplication>

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

    loadRecipes();
}

MainWindow::~MainWindow()
{
    saveRecipes();
}

QString MainWindow::getDataFilePath()
{
    QString appPath = QCoreApplication::applicationDirPath();
    return appPath + "/recipes.json";
}
void MainWindow::loadRecipes()
{
    QString filePath = getDataFilePath();
    QFile file(filePath);

    if (!file.exists()) {
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", "无法读取食谱数据文件！");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        return;
    }

    QJsonArray array = doc.array();
    recipes.clear();
    for (int i = 0; i < array.size(); ++i) {
        recipes.append(array[i].toString());
    }
}

void MainWindow::saveRecipes()
{
    QString filePath = getDataFilePath();
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "错误", "无法保存食谱数据！");
        return;
    }

    QJsonArray array;
    for (int i = 0; i < recipes.size(); ++i) {
        const QString &recipe = recipes[i];
    }

    QJsonDocument doc(array);
    file.write(doc.toJson());
    file.close();
}

void MainWindow::onAddRecipeClicked()
{
    AddRecipeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString newRecipe = dialog.getRecipeText();
        if (!newRecipe.isEmpty()) {
            recipes.append(newRecipe);
            saveRecipes();
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
    saveRecipes();
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