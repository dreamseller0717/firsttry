#include "viewrecipedialog.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

ViewRecipeDialog::ViewRecipeDialog(QVector<QString> &recipes, QWidget *parent)
    : QDialog(parent)
    , recipes(&recipes)
{
    setWindowTitle("查看食谱");
    resize(500, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    scrollArea = new QScrollArea(this);
    scrollWidget = new QWidget();
    scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout->setAlignment(Qt::AlignTop);

    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    mainLayout->addWidget(scrollArea);

    refreshDisplay();
}

ViewRecipeDialog::~ViewRecipeDialog()
{
}

void ViewRecipeDialog::refreshDisplay()
{
    QLayoutItem *item;
    while ((item = scrollLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < recipes->size(); ++i) {
        QWidget *rowWidget = new QWidget();
        QHBoxLayout *rowLayout = new QHBoxLayout(rowWidget);

        QLabel *numberLabel = new QLabel(QString::number(i + 1) + ".");
        numberLabel->setFixedWidth(30);

        QLabel *recipeLabel = new QLabel(recipes->at(i));
        recipeLabel->setWordWrap(true);
        recipeLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        QPushButton *deleteButton = new QPushButton("删除");
        deleteButton->setFixedWidth(60);
        deleteButton->setProperty("index", i);

        connect(deleteButton, &QPushButton::clicked, this, [this, i]() {
            deleteRecipe(i);
        });

        rowLayout->addWidget(numberLabel);
        rowLayout->addWidget(recipeLabel);
        rowLayout->addWidget(deleteButton);

        scrollLayout->addWidget(rowWidget);
    }
}

void ViewRecipeDialog::deleteRecipe(int index)
{
    int ret = QMessageBox::question(this, "确认删除",
                                    "确定要删除以下食谱吗？\n\n" + recipes->at(index),
                                    QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        recipes->remove(index);
        refreshDisplay();

        if (recipes->isEmpty()) {
            QMessageBox::information(this, "提示", "所有食谱已删除，窗口即将关闭");
            accept();
        }
    }
}