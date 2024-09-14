#include "Window.hpp"
#include "ui_Window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButton_clicked()
{
    Database db;

    if (db.setupConnection()) {
        ui->label_2->setText("Connected");
        ui->label_2->setStyleSheet(
            "background: #00aa00;"
            "border-radius: 10px;"
            "border: 2px solid black;"

        );
    }

    db.disconnect();
}
