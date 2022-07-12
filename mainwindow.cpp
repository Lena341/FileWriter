#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    setFixedSize(500,300); 
    setWindowTitle("File Writer"); 
    mainWidget=new QWidget;
    setCentralWidget(mainWidget);
    mainWidget->setFixedSize(this->width(), this->height());
    mainLayout=new QVBoxLayout; 
    mainWidget->setLayout(mainLayout);

    QHBoxLayout *editLayout=new QHBoxLayout;
    mainLayout->addLayout(editLayout); 
    nameEdit=new QLineEdit;
    nameEdit->setPlaceholderText("Name");
    lastnameEdit=new QLineEdit;
    lastnameEdit->setPlaceholderText("Last name");
    ageEdit=new QLineEdit;
    ageEdit->setPlaceholderText("Age");
    editLayout->addWidget(nameEdit);
    editLayout->addWidget(lastnameEdit);
    editLayout->addWidget(ageEdit);

    QHBoxLayout *buttonLayout=new QHBoxLayout;
    mainLayout->addLayout(buttonLayout); 
    addButton=new QPushButton;
    addButton->setText("Add person");
    addButton->setFixedSize(90,30);
    buttonLayout->addWidget(addButton);
    saveButton=new QPushButton;
    saveButton->setText("Save file");
    saveButton->setFixedSize(90,30);
    buttonLayout->addWidget(saveButton);
    clearButton=new QPushButton;
    clearButton->setText("Clear");
    clearButton->setFixedSize(90,30);
    buttonLayout->addWidget(clearButton);
    exitButton=new QPushButton;
    exitButton->setText("Exit");
    exitButton->setFixedSize(90,30);
    buttonLayout->addWidget(exitButton);
    list=new QListWidget;
    mainLayout->addWidget(list);

    connect(addButton,SIGNAL(clicked(bool)),this,SLOT(addSlot())); 
    connect(saveButton,SIGNAL(clicked(bool)),this,SLOT(saveSlot()));
    connect(clearButton,SIGNAL(clicked(bool)),this,SLOT(clearSlot()));
    connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(exitSlot()));

}

void MainWindow::addSlot()
{
   if(nameEdit->text().isEmpty() || lastnameEdit->text().isEmpty())
        return;
   for(int i=0;i<people.size();i++)
   {
      Person p=people[i];
      if(p.getName()==nameEdit->text() && p.getLastName()==lastnameEdit->text() && p.getAge()==ageEdit->text().toInt())
      {
         QMessageBox::warning(this,"Information","This person already exists.");
         return;
      }
   }
   Person p(nameEdit->text(),lastnameEdit->text(),ageEdit->text().toInt());
   people.append(p); 
   list->addItem(people[people.size()-1].toString()); 
}

void MainWindow::saveSlot()
{
    QString filename="people.txt";
    if(filename.size()!=0)
    {
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"Info","File not found");
            return;
        }
      QTextStream stream(&filename);
      for(int i=0;i<people.size();i++)
          stream<<people[i].toString()<<'\n';
      file.close();
    }

}

void MainWindow::clearSlot()
{
    nameEdit->clear();
    lastnameEdit->clear();
    ageEdit->clear();
}

void MainWindow::exitSlot()
{
    QMessageBox::StandardButton exitButton;
    QMessageBox messageBox;
    exitButton=messageBox.question(this,"Confirm","Are you sure you want to leave?",QMessageBox::Yes|QMessageBox::No);
    if(exitButton==QMessageBox::Yes)
        close();
}
