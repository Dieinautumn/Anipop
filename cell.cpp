#include"cell.h"
//构造函数
Cell::Cell()
{

}

//默认新方块为空
Cell* Cell::NewCell=0;

//创建新方块
Cell* Cell::BuildCell()
{
    if(NewCell==0)//假如没有Cell类
        NewCell= new Cell;//新建一个Cell
    return NewCell;
}


//获取方块对应图片
QPixmap* Cell::GetPixmap(int num)
{
    Images[0]=new QPixmap(":/cell/Cell/bear.png");
    Images[1]=new QPixmap(":/cell/Cell/fox.png");
    Images[2]=new QPixmap(":/cell/Cell/frog.png");
    Images[3]=new QPixmap(":/cell/Cell/chicken.png");
    Images[4]=new QPixmap(":/cell/Cell/hippo.png");
    Images[5]=new QPixmap(":/cell/Cell/Devilfish.png");
    Images[6]=new QPixmap(":/cell/Cell/owl.png");
    Images[7]=new QPixmap("");
    return Images[num];
}


