#include "mainwindow.h"
#include "myclicklabel.h"

#include<QMenu>
#include <QApplication>
#include <QSystemTrayIcon>


QApplication *app;
QSystemTrayIcon *trayIcon;

void exitApplication()
{
    // 在这里添加退出应用程序的逻辑
    trayIcon->hide();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(QIcon(":/a2320426fbdb4c3b9f5123b23b07b709.png"), app);
    QMenu *trayMenu = new QMenu();

    QAction *exitAction = new QAction("Exit", trayMenu);

    MainWindow::connect(exitAction, &QAction::triggered, exitApplication);

    trayMenu->addAction(exitAction);


    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    QPixmap pixmap(":/R-C.jpg");





    MyClickLabel *label=new MyClickLabel();
    label->setFixedSize(50, 25);

    label->setPixmap(pixmap);

    label->show();

    QObject::connect(label, SIGNAL( mousepress()), &w, SLOT(showit()));
    QObject::connect(label, SIGNAL(  myDoubleClicked()), &w, SLOT(hideit()));


    return a.exec();
}
