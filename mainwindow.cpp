#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_guardarPushButton_clicked()
{
    string nombre = "informacion.txt";
    ofstream myOFile;
    myOFile.open (nombre);
    myOFile << ui->contenidoPlainTextEdit->toPlainText().toStdString();
    myOFile.close();

}

void MainWindow::on_cargarPushButton_clicked()
{

    string nombre = "informacion.txt";
    ifstream myFile(nombre);
        if(myFile.fail()){
        }
        else
        {
            char cadena[1000];
            myFile.getline(cadena, 1000);
            ui->contenidoPlainTextEdit->clear();
            ui->contenidoPlainTextEdit->appendPlainText(QString::fromStdString(cadena));
        }
}
