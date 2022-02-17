#include"cui.h"
#include<QDebug>
#include<ctime>

//构造函数
Cui::Cui(QWidget *parent):QWidget(parent)
{
    qsrand(time(0));//随机数
    SetUp();//设置游戏
    GameTime=180;
    GameScore.retScore();//重置总分数
    GameScore.rexScore();//重置小分数
}

//析构函数
Cui::~Cui()
{
    //删除内存

    //删除二维图片组
    for(int i=0;i<SIZE1;++i)
        delete []Board[i];
    delete []Board;

    //删除二维数组
    for(int i=0;i<SIZE1;++i)
        delete []temp[i];
    delete []temp;
}


//设置游戏
void Cui::SetUp()
{
    Board=new Classic *[8];
    temp=new int *[8];

    //初始化游戏棋盘数组每一行
    for(int i=0;i<8;++i)
    {
        Board[i]=new Classic[8];
        temp[i]=new int[8];
    }

    //初始化游戏棋盘数组
    for(int i=0;i<SIZE1;++i)
    for(int j=0;j<SIZE1;++j)
    {
        //随机图片填充
        int te=qrand()%Classic::getNumOfType(6);
        Board[i][j]=Classic(Classic::TYPE(te));
        temp[i][j]=te;
    }

    //当游戏中有可以直接消去的方块时
    while(scan2())
    {
          //重置小分数
          GameScore.rexScore();
    }
    update();//更新组件

    //当判定游戏不能继续进行的时候
    while(!scan3())
    {
        //重新设置游戏
        SetUp();
    }
    GameScore.retScore();//重置总分数
    update();//更新组件
}


void Cui::Swap(Classic &x, Classic &y)//在方块图片组中交换方块
{
    Classic z=x;
    x.replace(y);
    y.replace(z);
}

void Cui::Swaptemp(int &x,int &y)//在整数数组中交换方块
{
    int t=x;
    x=y;
    y=t;
}

void Cui::paintEvent(QPaintEvent* event)//绘制游戏界面事件
{
    QPainter Painter(this);
    //绘制游戏界面每一格方块
    for(int i=0;i<SIZE1;++i)
        for(int j=0;j<SIZE1;++j)
    {
        int te=temp[i][j];
        Board[i][j].Paint(Painter,j*60,i*60,te);
    }

}

void Cui::mousePressEvent(QMouseEvent *event)//鼠标点击事件
{

    qDebug() << event->pos();//返回坐标

    //都选中空处

    //新的一步的x,y坐标
    static int Newi=-1;
    static int Newj=-1;
    //上一步的x,y坐标
    static int Oldi=-1;
    static int Oldj=-1;

   //将返回坐标返回为X行X列
   Newi=event->y()/60;//相对于部件返回鼠标指针的y位置
   Newj=event->x()/60;//相对于部件返回鼠标指针的x位置

if(tempi!=-1&&tempj!=-1)//假如刚才走过的不是第一步
{

    if(Newi==tempi&&Newj==tempj)//假如新走的一步和上一步相同
   {
       Newi=event->y()/60;
       Newj=event->x()/60;//新走一步

       Oldi=tempi;
       Oldj=tempj;//并记录下上一步
   }
   else//假如两步不同
   {
      Oldi=tempi;
      Oldj=tempj;//记录下上一步

      tempi=Newi;
      tempj=Newj;//记录下这一步

   }

}
else//假如是第一步
{
  //记录下上一步
  tempi=Newi;
  tempj=Newj;
  return;//返回继续走
}


    if(Oldi==Newi&&Oldj+1==Newj
       ||Oldi==Newi&&Oldj-1==Newj
       ||Oldi-1==Newi&&Oldj==Newj
       ||Oldi+1==Newi&&Oldj==Newj)//假如上一步与下一步相邻
    {
        Swap(Board[Newi][Newj],Board[Oldi][Oldj]);
        Swaptemp(temp[Newi][Newj],temp[Oldi][Oldj]);//交换位置

        //清除链表
        landscape.clear();
        portrait.clear();

        int x=Oldi;
        int y=Oldj;
        int X=Newi;
        int Y=Newj;

        //保证新走的一步在上侧
        if(Oldi>Newi)
       {
           X=Oldi;
           Y=Oldj;
           x=Newi;
           y=Newj;
       }

        bool SCAN1=scan1(x,y);//扫描能否消除
        bool SCAN2=scan1(X,Y);

        if(SCAN1||SCAN2)//能够消去游戏块
        {
            Clear();//清除
            GameScore.tScore();//计算总分

            while(scan2())//还有能消除的
            {
                GameScore.tScore();//计算总分
            }

            while(!scan3())//不能继续游戏
            {
                //记录下分数，在重构界面后设置分数
                int t=GameScore.getScore();
                SetUp();//重构界面
                GameScore.setScore(t);
            }

            update();//更新组件
        }
        else
            {
            Swap(Board[Newi][Newj],Board[Oldi][Oldj]);
            Swaptemp(temp[Newi][Newj],temp[Oldi][Oldj]);
            }//不能消去再换回来
    }
    //坐标回到默认位置，等待下一次游戏
    Oldi=-1;
    Oldj=-1;
    tempi=-1;
    tempj=-1;
    Newi=-1;
    Newj=-1;
}


void Cui::Clear()
{

    //将要被消去的方块设为空块
    //横行设置空块
    for(int i=0;i<landscape.size();++i)
    {
        QPoint T=landscape.at(i);//第i个项目
        Board[T.x()][T.y()].setblank();
        temp[T.x()][T.y()]=7;
        update();
    }

    //竖行设置空块
    for(int i=0;i<portrait.size();++i)
    {
        QPoint T=portrait.at(i);
        Board[T.x()][T.y()].setblank();
        temp[T.x()][T.y()]=7;
        update();
    }
    update();

    if(landscape.size()>0)//横行若有消去的游戏块
    {
        int x1=landscape.at(0).x();
        int x2=landscape.at(landscape.size()-1).x();
        int y=landscape.at(0).y();
        int x3=x2-x1+1;

        for(int i=x1-1;i>=0;i--)
        {
            //被消去的方块被上侧方块替代
            Board[x3+1][y].replace(Board[i][y]);
            temp[x3+1][y]=temp[i][y];               //方块代替
            update();
        }
        for(int i=x2-x1;i>=0;--i)
        {
            //最上侧随机重建
            Board[i][y].rebuild(6);
            temp[i][y]=Board[i][y].getTempNumber();      //该行随机重建
            update();
        }

    }


    if(portrait.size()>0)            //总行若有消去的游戏块
    {
        for(int i=0;i<portrait.size();++i)
        {
            QPoint T=portrait.at(i);
            for(int j=T.x();j>0;--j)
            {
                //块被上方的块代替
                Board[j][T.y()].replace(Board[j-1][T.y()]);
                temp[j][T.y()]=temp[j-1][T.y()];
            }
            //到最上侧的方块就随机重建
            Board[0][T.y()].rebuild(6);
            temp[0][T.y()]=Board[0][T.y()].getTempNumber();

        }

    }
     //根据消去的游戏块积小分数
    GameScore.xScore(landscape.size()+portrait.size());
}


bool Cui::scan1(int x, int y)//扫描该方块周围有无能被消去的方块
{
    int i=x;
    int j=x;
    bool l=false;
    //向上找有无相同的方块
    while(i>0&&Board[i-1][y]==Board[x][y]&&temp[i-1][y]==temp[x][y])
    {
         i--;
    }
    //向下找有无相同的方块
    while(j<SIZE1-1&&Board[j+1][y]==Board[x][y]&&temp[j+1][y]==temp[x][y])
    {
        j++;
    }

    if(j-i>=2)//能消去（三个以及以上相同）
    {
        if(Board[x][y].getType()==Classic::TYPE(5)&&temp[x][y]==5)//假如能整排消去
        {
            for(int k=0;k<SIZE1;++k)
            {
                QPoint T(k,y);
                //假如链表中没有该游戏块
                if(!portrait.contains(T)&&!landscape.contains(T))
                    {
                        portrait.append(T);//将游戏块加入链表
                    }
            }
        }

         else//假如不能整块消去
        {

            for(int k=i;k<=j;++k)
            {
               QPoint T(k,y);
               if(!landscape.contains(T)&&!portrait.contains(T))
               {
                portrait.append(T);//将该消去的游戏块加入链表
               }
            }
        }
        l=true;
    }

    i=y;
    j=y;
    //向左找有无相同方块
    while(i>0&&Board[x][i-1]==Board[x][y]&&temp[x][i-1]==temp[x][y])
    {
        --i;
    }
    //向右找有无相同方块
    while(j<SIZE1-1&&Board[x][j+1]==Board[x][y]&&temp[x][j+1]==temp[x][y])
    {
        ++j;
    }

    if(j-i>=2)//若有三个以上相同的方块（可消去）
    {
        if(Board[x][y].getType()==Classic::TYPE(5)&&temp[x][y]==5)//当能够整排消去的时候
        {
            for(int k=0;k<=SIZE1;++k)
            {
                QPoint T(x,k);
                if(!landscape.contains(T)&&!portrait.contains(T))
                {
                    portrait.append(T);
                }
            }
        }
        else
        {
            for(int k=i;k<=j;++k)
            {
                QPoint T(x,k);
                if(!portrait.contains(T)&&!landscape.contains(T))
                  {
                    portrait.append(T);
                  }
            }
        }
       l=true;
    }
    return l;
}

bool Cui::scan2()//扫描全局是否有其他可消去的方块
{
    //清除链表
    landscape.clear();
    portrait.clear();

    bool l=false;
    for(int i=0;i<SIZE1;++i)
        for(int j=0;j<SIZE1-1;++j)
        {
            landscape.clear();
            portrait.clear();
            if(scan1(i,j)||scan1(i,j+1))//扫描互换后能否消去
            {
                Clear();//消去
                l=true;
            }
        }

    for(int i=0;i<SIZE1-1;++i)
        for(int j=0;j<SIZE1;++j)
        {
            landscape.clear();
            portrait.clear();
            if(scan1(i,j)||scan1(i+1,j))//扫描互换后能否消去
            {
                Clear();//消去
                l=true;
            }
        }
    return l;
}


bool Cui::scan3()//判断游戏能否继续进行
{
   bool l=false;
   for(int i=0;i<SIZE1-1;++i)
   for(int j=0;j<SIZE1;++j)
    {
       Swap(Board[i][j],Board[i+1][j]);
       Swaptemp(temp[i][j],temp[i+1][j]);//上下交换

       if(scan1(i,j)||scan1(i+1,j))//扫描是否交换后有消去
        {
           Swap(Board[i][j],Board[i+1][j]);
           Swaptemp(temp[i][j],temp[i+1][j]);//交换回来

           l=true;
           break;
        }
        else
        {
           Swap(Board[i][j],Board[i+1][j]) ;
           Swaptemp(temp[i][j],temp[i+1][j]);//交换回来
        }

    }

   for(int i=0;i<SIZE1;++i)
   for(int j=0;j<SIZE1-1;++j)
    {
       Swap(Board[i][j],Board[i][j+1]);
       Swaptemp(temp[i][j],temp[i][j+1]);//左右交换

       if(scan1(i,j)||scan1(i,j+1))//扫描是否交换后有可消去的方块
        {
           Swap(Board[i][j],Board[i][j+1]);
           Swaptemp(temp[i][j],temp[i][j+1]);

           l=true;
           break;
        }
        else
        {
           Swap(Board[i][j],Board[i][j+1]);
           Swaptemp(temp[i][j],temp[i][j+1]);
        }

    }
    return l;
}


void Cui::restart()//重新开始
{
    SetUp();
    GameScore.rexScore();
    GameScore.retScore();
    update();
}
