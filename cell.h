#ifndef CELL_H
#define CELL_H
//游戏方块类
#include<QtGui>
#include<QMap>
#include<QPixmap>

//设定方块图宽为60
const int IMAGESIZE=60;

class Cell
{
public:

    //构造函数
    Cell();

    //新的Cell
    static Cell *NewCell;

    //检测存不存在Cell类，没有Cell则新建Cell
    static Cell* BuildCell();

    //获取数组中的图片
    QPixmap* GetPixmap(int num);

    //一维图片组
    QMap<int,QPixmap*> Images;

};


#endif // CELL_H
