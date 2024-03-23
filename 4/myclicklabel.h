/*myclickLabel.h*/
#ifndef MYCLICKLABEL_H
#define MYCLICKLABEL_H
#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QEvent>
#include <QMouseEvent>
class MyClickLabel : public QLabel
{
    Q_OBJECT    // must include this if you use Qt signals/slots
public:
    explicit MyClickLabel(QWidget *parent = 0);

signals:
    void myClicked();                    // 单击产生的信号
    void myDoubleClicked();              // 双击产生的信号
    void mousepress();
    void mouserelease();

private:
    void enterEvent(QEnterEvent* event);// 鼠标进入事件
    void leaveEvent(QEvent *event);//当鼠离开
    void mousePressEvent(QMouseEvent* event); //鼠标按下
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseDoubleClickEvent(QMouseEvent *event);// 鼠标双击事件

private:
    bool m_isDragging;
    QPoint m_dragStartPosition;
};

#endif // MYCLICKLABEL_H
