#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTextCodec>
#include <QBitArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img("extract-archive.jpg");
    qDebug() << img.color(10);

    QByteArray ba = "Привет Игорек :)";

    QByteArray aBase64 = ba.toBase64();
    qDebug() << "QByteArray :" << aBase64;
    ui->label->setText(QByteArray::fromBase64(aBase64));

    QBitArray bits(aBase64.count()*8);
    // Convert from QByteArray to QBitArray
    for(int i = 0; i < aBase64.count(); ++i) {
        for(int b = 0; b < 8; ++b) {
            bits.setBit( i*8+b, aBase64.at(i)&(1<<(7-b)) );
        }
        qApp->processEvents();
    }
    qDebug() << "QBitArray : " << bits;
}

MainWindow::~MainWindow()
{
    delete ui;
}
