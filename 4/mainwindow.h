#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindows;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void addrows();
    void  addcolunm();
    void deleterows();
    void load();
    void clearcontends();
    void showit() {
        show();
    }
    void hideit(){
        hide();
    }


private:
    Ui::MainWindows *ui;

};
#endif // MAINWINDOW_H
