#include"classic.h"
#include"cell.h"
//游戏界面类

//构造函数
Classic::Classic(Classic::TYPE type)
    :CellType(type)//初始化
{
    //设置游戏方块图片
    setImage(CellType);
}

//析构函数
Classic::~Classic()
{

}


//获取方块类型
Classic::TYPE Classic::getType() const
{
    return CellType;
}


//设置空游戏块
 void Classic::setblank()
 {
     Image=Cell::BuildCell()->GetPixmap(7);//调用方块类中函数，设置空游戏块
 }

 //设置方块图片
 void Classic::setImage(Classic::TYPE type)
 {
     //数字对应图片类型
     int num;
     if(type==bear)
         num=0;
     if(type==fox)
         num=1;
     if(type==frog)
         num=2;
     if(type==chicken)
         num=3;
     if(type==hippo)
         num=4;
     if(type==Devilfish)
         num=5;
     if(type==owl)
         num=6;
     if(type==Blank)
         num=7;

     Image=Cell::BuildCell()->GetPixmap(num);//调用方块类中函数，设置游戏块图片
 }

 //重建游戏块，随机形成
void  Classic::rebuild(int x)
 {
     int t=qrand()%x;//随机数
     tempnumber=t;
     CellType=Classic::TYPE(getTempNumber());//随机生成/设定游戏块图片
     setImage(CellType);
 }


//替代游戏块
void Classic::replace(const Classic& New)
{
    Image=New.Image;//游戏块图片替代
    CellType=New.CellType;//游戏块类型替代
}

//画出游戏方块
void Classic::Paint(QPainter &Painter,int x,int y,int te)
{
       //设置每一个方块的背景
       QColor BackgroundColor;
       BackgroundColor = QColor(135,55,55,100);//设置背景颜色
       Painter.fillRect(QRectF(x,y,60,60),BackgroundColor);
       //画出方块
       Cell c;
       Image=c.GetPixmap(te);//获取方块类型
       Painter.drawPixmap(x,y,60,60,*Image);//调用drawPixmap函数画出方块
}


//重载==符号，判断两方块类型是否相等
bool Classic::operator ==(const Classic& NewCell) const
{
    return CellType==NewCell.CellType;
}

//获取图片类型的数目
int Classic::getNumOfType(int x)
{
    return x;
}

//获取中间值
int Classic::getTempNumber()
{
    return tempnumber;
}
