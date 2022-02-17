#ifndef CLASSIC_H
#define CLASSIC_H

//游戏界面类
#include<QPainter>
#include<QPixmap>
#include <QPaintEvent>

class Classic
{
public:
    //设定方块种类
    enum TYPE{bear=0,fox,frog,chicken,hippo,Devilfish,owl,Blank};

    //构造函数
    Classic(){}
    //构造函数
    Classic(Classic::TYPE type);

    //析构函数
    virtual ~Classic();

//获取游戏块
    //获取游戏块类型的数字标号
    static int getNumOfType(int x);
    //获取游戏块元素的种类
    Classic::TYPE getType() const;

    //设置空块
    void setblank();
    //重建游戏方块
    void rebuild(int x);
    //替代游戏方块
    void replace(const Classic& New);
    //绘制游戏方块
    void Paint(QPainter &Painter,int x,int y,int te);

    //重载==，判断游戏块是否相同
    bool operator==(const Classic& NewCell) const;

    //返回中间数，方便二维图片组和二维数组之间的转化相关函数的使用
    int getTempNumber();

 protected:
    //设置图片
    void setImage(Classic::TYPE type);
    //游戏块的类型
    Classic::TYPE CellType;
    //游戏块图片组
    QPixmap *Image;

    //设定一个中间数，方便二维图片组和二维数组之间的转化和相关函数的使用
    int tempnumber;

};


#endif // CLASSIC_H
