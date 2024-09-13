#include "Window.hpp"
#include "ui_Window.h"
#include <QPixmap>
#include <QDebug>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    //ty le logo an le izy.......................................................
    QPixmap pixmap("D:\\tuto\\ProjetL1-main\\GUI\\res\\cop_logo.png");

    if(pixmap.isNull()){
        qDebug() <<"erreur";
    }
    ui->label->setPixmap(pixmap);

    //ty le logo faharoa eo @ le accueil...............
    QPixmap pixel("D:\\tuto\\ProjetL1-main\\GUI\\res\\home.svg");
    ui->label_4->setPixmap(pixel);

    //logo fahatelo eo @ le nouveau.............................
    QPixmap pixmap2("D:\\tuto\\ProjetL1-main\\GUI\\res\\user-plus.svg");
    ui->label_8->setPixmap(pixmap2);

    //logo fahaefatra eo @ le liste...................................
    QPixmap pixel2("D:\\tuto\\ProjetL1-main\\GUI\\res\\list.svg");
    ui->label_10->setPixmap(pixel2);

    //logo eo @le recherche.............
    QPixmap pixmapsearch("D:\\tuto\\ProjetL1-main\\GUI\\res\\search.svg");
    ui->label_26->setPixmap(pixmapsearch);

    //sary eo @le page d'accueil juste noforoporoniko fotsiny.....
    QPixmap schema1("D:\\tuto\\ProjetL1-main\\GUI\\res\\sary1.jpg");
    QPixmap schema2("D:\\tuto\\ProjetL1-main\\GUI\\res\\sary2.jpg");
    ui->label_29->setPixmap(schema1);



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
