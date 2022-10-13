#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    trans = new QTranslator(this);
    QFile file("D:/Qt/Project/lab2/eng.txt");
    QByteArray block;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()){
        block = file.readLine();
        ui->comboBox->addItems(QStringList() << block);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file3("D:/Qt/Project/lab2/eng.txt");
    QByteArray block3;
    QByteArray block4;
    bool flag = true;
    if (!file3.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    int count3 = 0;
    while (!file3.atEnd()){
        block3 = file3.readLine();
        count3++;
        if (ui->lineEdit->text() + '\n' == block3){
            flag = false;
            break;
        }
    }
    if (flag){
        ui->label->setText("Такого слова в словаре нет");
    }
    else {
        int count4 = 0;
        QFile file4("D:/Qt/Project/lab2/rus.txt");
        if (!file4.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        while (!file4.atEnd()){
            block4 = file4.readLine();
            count4++;
            if (count3 == count4){
                ui->label->setText(block4);
                break;
            }
        }
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QFile file1("D:/Qt/Project/lab2/eng.txt");
    QByteArray block1;
    QByteArray block2;
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    int count = 0;
    while (!file1.atEnd()){
        block1 = file1.readLine();
        count++;
        if (block1 == arg1){
            break;
        }
    }
    int count2 = 0;
    QFile file2("D:/Qt/Project/lab2/rus.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file2.atEnd()){
        block2 = file2.readLine();
        count2++;
        if (count == count2){
            ui->label->setText(block2);
        }
    }
}

