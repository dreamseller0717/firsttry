#ifndef ADDRECIPEDIALOG_H
#define ADDRECIPEDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>

class AddRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipeDialog(QWidget *parent = nullptr);
    ~AddRecipeDialog();
    QString getRecipeText() const;

private slots:
    void onAccepted();

private:
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;
    QString recipeText;
};

#endif