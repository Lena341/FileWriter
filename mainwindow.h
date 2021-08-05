#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "person.h"
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QFile>
#include <QPushButton>
#include <QTextStream>
#include <QLineEdit>
#include <QListWidget>
#include <QVector>
#include <QFileDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void loadData();
private:
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;
    QPushButton *addButton, *saveButton, *clearButton, *exitButton;
    QLineEdit *nameEdit, *lastnameEdit, *ageEdit;
    QListWidget *list;
    QVector<Person> people;
public slots:
    void addSlot();
    void saveSlot();
    void clearSlot();
    void exitSlot();
};
#endif // MAINWINDOW_H
