#include "qwidgetdraw.h"
#include <QPaintEvent>
#include <QPainter>

QWidgetDraw::QWidgetDraw(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("哈尔滨吴彦组");
    this->resize(660+100,440+100);
    //todo屏幕上显示团队信息，个人信息
    //todo界面上显示时间
    //拓展：时间显示用lcdnumber控件替代QLabel
}


void QWidgetDraw::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter();
    painter->begin(this);
    this->draw(painter);
    painter->end();

}
void QWidgetDraw::draw(QPainter *painter)
{
    int step;
    painter->setPen(QPen(Qt::black,Qt::DashLine));
//    painter->setBrush(QBrush(Qt::red,Qt::SolidPattern));
//    painter->drawLine(10,10,100,100);
    painter->drawRect(50,50,660,440);   //国旗外框
    //水平垂直二等分
    this->drawDivide(painter,50,50,660,440,2,2);

//    painter->drawLine(50,50+440/2,660+50,50+440/2);   //横线
//    painter->drawLine(50+660/2,50,50+660/2,50+440);   //竖线
    //左上角10x15等分
    this->drawDivide(painter,50,50,660/2,440/2,15,10);
    //绘制圆
    step = 330/15;
    painter->drawEllipse(50 + step*2, 50 + step*2, step*6, step*6);//大圆
    //小圆
    painter->drawEllipse(50 + step*9, 50 + step*1, step*2, step*2);
    painter->drawEllipse(50 + step*11, 50 + step*3, step*2, step*2);
    painter->drawEllipse(50 + step*11, 50 + step*6, step*2, step*2);
    painter->drawEllipse(50 + step*9, 50 + step*8, step*2, step*2);
}

void QWidgetDraw::drawDivide(QPainter *painter, int startX, int startY, int width, int hight, int wCnt, int hCnt)
{
    int step = width/wCnt;
    int cnt = 0;
    //水平方向等分
    for(cnt=0; cnt < wCnt; cnt++)
        painter->drawLine(startX+step*cnt,startY,startX+step*cnt,startY+hight);
    //垂直方向等分
    step = hight/hCnt;
    for(cnt = 0; cnt < hCnt; cnt++)
        painter->drawLine(startX,startY+step*cnt,startX+width,startY+step*cnt);
}
