#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QFileDialog>
#include<QDateTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindows)
{

    this->setMouseTracking(true);

    this->setWindowTitle("克己");

    this->setWindowIcon(QIcon(":/a2320426fbdb4c3b9f5123b23b07b709.png"));
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);


    ui->setupUi(this);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<< "当前时间" << "计划" << "状态"<<"截至时间");

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeStr = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    for (int row = 0; row <ui->tableWidget ->rowCount(); ++row) {
        QTableWidgetItem *item = new QTableWidgetItem(currentDateTimeStr);
        ui->tableWidget->setItem(row, 0, item);
    }

    // 设置最后一列为判断格式
    for (int row = 0; row <  ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(row, 2, item);
    }




    connect(ui->addrows, SIGNAL(triggered()), this,SLOT(addrows()));
    connect(ui->delete1, SIGNAL(triggered()), this,SLOT(deleterows()));
    connect(ui->Clear, SIGNAL(triggered()), this,SLOT(clearcontends()));
    connect(ui->load, SIGNAL(triggered()), this,SLOT(load()));
    connect(ui->addcolunms, SIGNAL(triggered()), this,SLOT(addcolunm()));







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addrows()
{
    int row=ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeStr = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    QTableWidgetItem *item1 = new QTableWidgetItem(currentDateTimeStr);
    ui->tableWidget->setItem(row, 0, item1);



    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    ui->tableWidget->setItem(row, 2, item);
}
void MainWindow::addcolunm()
{
    int columnCount = ui->tableWidget->columnCount();
    ui->tableWidget->setColumnCount(columnCount + 1);
}
void MainWindow::deleterows()
{
    int  row=ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row-1);
}
void MainWindow::clearcontends()
{
    ui->tableWidget->clearContents();
}
void MainWindow::load()
{
    QString selectedFilePath=QFileDialog::getOpenFileName();

    if (!selectedFilePath.isEmpty())
    {
        qDebug() << "Selected file: " << selectedFilePath;

        // 创建QFile对象并打开文件，如果文件不存在则创建一个新文件
        QFile file(selectedFilePath);

        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            // 将一些文本写入文件中


             QTextStream stream(&file);


            for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
            {
                for (int column = 0; column < ui->tableWidget->columnCount(); ++column)
                {
                    QTableWidgetItem* item = ui->tableWidget->item(row, column);
                    if (item)
                    {
                        stream <<item->text() ;
                    }

                    // 添加逗号分隔符
                    if (column < ui->tableWidget->columnCount() - 1)
                    {
                        stream <<tr("|");
                    }
                }

                // 添加换行符
                stream << "\n";
            }

            // 关闭文件
            file.close();
        }
    }

}
