/*myclickLabel.cpp*/
#include "myclicklabel.h"
#include <QDebug>
#include <QMoveEvent>
MyClickLabel::MyClickLabel(QWidget *parent):QLabel(parent)
{
    this->setMouseTracking(true);
    this->setWindowTitle("克己");
    this->setMaximumSize(300,400);                          //窗体最大尺寸
    this->setMinimumSize(300,400);                          //窗体最小尺寸
    this->setWindowIcon(QIcon(":/a2320426fbdb4c3b9f5123b23b07b709.png"));
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
}

//鼠标进入
void MyClickLabel::enterEvent(QEnterEvent *event)
{
    qDebug() << "提示：" << "鼠标进入";

}
//鼠离开
void MyClickLabel::leaveEvent(QEvent *event)
{
    qDebug() << "提示：" << "当鼠离开";

}
//鼠标按下
void MyClickLabel::mousePressEvent(QMouseEvent *event)
{
    QString  Str=QString("按下位置：X=%1 Y=%2").arg(event->x()).arg(event->y());

    //判断鼠标是按下左键还是右键
    if(event->button()==Qt::LeftButton){
        qDebug() << "提示：" << "鼠标按下左键"+Str;

        m_isDragging = true;
        m_dragStartPosition = event->globalPos() - frameGeometry().topLeft();

        emit myClicked();
        emit mousepress();
    }else{
        qDebug() << "提示：" << "鼠标按下右键"+Str;
    }

    QLabel::mousePressEvent(event);
}
//鼠标释放
void MyClickLabel::mouseReleaseEvent(QMouseEvent *event)
{
    //判断鼠标是按下左键还是右键
    if(event->button()==Qt::LeftButton){
        emit mouserelease();

         m_isDragging = false;

        qDebug() << "提示：" << "鼠标释放左键";
    }else{
        qDebug() << "提示：" << "鼠标释放右键";
    }

    QLabel::mouseReleaseEvent(event);
}
//鼠标移动
void MyClickLabel::mouseMoveEvent(QMouseEvent *event)
{
    //持续状态 需要用buttons 用与操作符 进行判断
    if(event->buttons()&Qt::LeftButton)
    {
        QString  Str=QString("按下位置：X=%1 Y=%2").arg(event->x()).arg(event->y());
        qDebug() << "提示：" << "鼠标移动"+Str;
    }

    if(m_isDragging &&(event->buttons()&Qt::LeftButton))
    {
        QPoint newPos = event->globalPos() - m_dragStartPosition;
        move(newPos);
    }

     QLabel::mouseMoveEvent(event);
}
//当鼠标双击的时候
void MyClickLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "提示：" << "当鼠标双击的时候，发出双击的信号";
    emit myDoubleClicked();
}
