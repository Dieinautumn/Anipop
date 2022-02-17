#ifndef CUI_H
#define CUI_H


#include<QtGui>
#include<Qpoint>
#include<Qlist>
#include<Qmap>
#include<QWidget>
#include <QMouseEvent>

#include"classic.h"
#include"score.h"
#include"cell.h"

class Cui:public QWidget//游戏界面
{
    Q_OBJECT

public:
    Cui(QWidget *parent=0);//构造函数
    ~Cui();//析构函数

    void Swap(Classic &x,Classic &y);//交换游戏块（在二维图组下操作）
    void Swaptemp(int &x,int &y);//交换游戏块（在二维数组下操作）

    Score GameScore;//游戏分数
    int GameTime;//游戏时间

    const static int SIZE1=8;//游戏界面大小
    const static int SIZE2=60;//游戏块大小

public slots://公有槽
    void restart();//游戏重新开始

protected:
    //创建链表，存储应该消去的块的坐标
    QList<QPoint> landscape;//横向链表
    QList<QPoint> portrait;//纵向链表

    Classic **Board;//游戏界面的二维图片组
    int **temp;//游戏界面的二维数组

    void SetUp();//设置游戏

    void paintEvent(QPaintEvent *event);//绘制游戏界面事件
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件

    void Clear();//清除游戏块

    bool scan1(int x,int y);//第一次扫描，看是否交换后消去了游戏块
                            //若有就将应该消去的方块的坐标存入列表中
    bool scan2();//第二次扫描，扫描整个游戏界面，看是否还可以消去游戏块
                 //若有就将应该消去的方块的坐标存入列表中
    bool scan3();//第三次扫描，看游戏是否能够继续进行下去

private:
    //设定中间坐标，方便鼠标点击新、旧坐标的转换
    int tempi=-1;
    int tempj=-1;
};

#endif // CUI_H
