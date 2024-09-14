#include "Window.hpp"
#include "ui_Window.h"
#include <QPixmap>
#include <QDebug>
#include <QDir>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    //ty le logo an le izy.......................................................
    QPixmap pixmap("..\\GUI\\res\\cop_logo.png");

    if(pixmap.isNull()){
        qDebug() <<"erreur";
    }
    ui->label->setPixmap(pixmap);

    //ty le logo faharoa eo @ le accueil...............
    QPixmap pixel("..\\GUI\\res\\home.svg");
    ui->label_4->setPixmap(pixel);

    //logo fahatelo eo @ le nouveau.............................
    QPixmap pixmap2("..\\GUI\\res\\user-plus.svg");
    ui->label_8->setPixmap(pixmap2);

    //logo fahaefatra eo @ le liste...................................
    QPixmap pixel2("..\\GUI\\res\\list.svg");
    ui->label_10->setPixmap(pixel2);

    //logo eo @le recherche.............
    QPixmap pixmapsearch("../GUI/res/search.svg");
    ui->label_26->setPixmap(pixmapsearch);


    //sary eo @le page d'accueil juste noforoporoniko fotsiny.....
    QPixmap schema1("../GUI/res/sary1.jpg");
   QPixmap schema1scaled = schema1.scaled(800, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_5->setPixmap(schema1scaled);

    //..
    QPixmap schema2("../GUI/res/sary3.jpg");
   QPixmap schema2scaled = schema2.scaled(800, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_7->setPixmap(schema2scaled);

    //..
    QPixmap schema3("../GUI/res/sary2.jpg");
   QPixmap schema3scaled = schema3.scaled(800, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_9->setPixmap(schema3scaled);

    //...
    QPixmap schema4("../GUI/res/sary5.jpg");
   QPixmap schema4scaled = schema4.scaled(800, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_25->setPixmap(schema4scaled);

    //....
    QPixmap schema5("../GUI/res/sary6.png");
    QPixmap schema5scaled = schema5.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_29->setPixmap(schema5scaled);







}

Window::~Window()
{
    delete ui;
}



void Window::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Window::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Window::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
