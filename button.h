#ifndef BUTTON_H
#define BUTTON_H

#include<QtGui>
#include<QPushButton>

//开始按钮
class StartButton:public QPushButton
{
    Q_OBJECT
public:
    StartButton(QWidget *parent)
        :QPushButton(parent)
{
    //获取按钮原始状态时的图片
    buttonPicture=new QPixmap(":/button/Button/start.png");
    //获取按下按钮时按钮状态时的图片
    pressPicture=new QPixmap(":/button/Button/start2.png");
    //获取恢复按钮原始状态时的图片
    releasePicture=new QPixmap(":/button/Button/start.png");

    //关闭按钮的默认显示
    this->setFlat(true);
    //设定图标
    this->setIcon(QIcon(*buttonPicture));
    //设定图标大小
    this->setIconSize(QSize(140,40));
}

protected:
    //按下按钮
    void mousePressEvent(QMouseEvent *event)
{
    //设定按下按钮时按钮状态时的图片
    this->setIcon(QIcon(*pressPicture));
}
    //松开按钮
    void mouseReleaseEvent(QMouseEvent *event)
{
    //设定恢复按钮原始状态时的图片
    this->setIcon(QIcon(*releasePicture));
    //发出click信号
    emit clicked();
}

private:
    //按钮在不同状态时的图片
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//游戏说明按钮
class HelpButton:public QPushButton
{
    Q_OBJECT
public:
    HelpButton(QWidget *parent)
        :QPushButton(parent)
    {
        buttonPicture=new QPixmap(":/button/Button/help.png");//按钮原始状态
        pressPicture=new QPixmap(":/button/Button/help2.png");//按下按钮时按钮状态
        releasePicture=new QPixmap(":/button/Button/help.png");//恢复按钮原始状态

        this->setFlat(true);//关闭按钮的默认显示
        this->setIcon(QIcon(*buttonPicture));
        this->setIconSize(QSize(140,40));
    }

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        this->setIcon(QIcon(*pressPicture));
    }
    void mouseReleaseEvent(QMouseEvent *event)
    {
        this->setIcon(QIcon(*releasePicture));
        emit clicked();//发出click信号
    }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//退出按钮
class ExitButton:public QPushButton
{
    Q_OBJECT
public:
   ExitButton(QWidget *parent)
        :QPushButton(parent)
   {
       buttonPicture=new QPixmap(":/button/Button/exit.png");//按钮原始状态
       pressPicture=new QPixmap(":/button/Button/exit2.png");//按下按钮时按钮状态
       releasePicture=new QPixmap(":/button/Button/exit.png");//恢复按钮原始状态

       this->setFlat(true);//关闭按钮的默认显示
       this->setIcon(QIcon(*buttonPicture));
       this->setIconSize(QSize(140,40));
   }

protected:
   void mousePressEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*pressPicture));
   }
   void mouseReleaseEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*releasePicture));
       emit clicked();//发出click信号
   }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//关闭按钮
class CloseButton:public QPushButton
{
    Q_OBJECT
public:
   CloseButton(QWidget *parent)
        :QPushButton(parent)
   {
       buttonPicture=new QPixmap(":/button/Button/close.png");//按钮原始状态
       pressPicture=new QPixmap(":/button/Button/close2.png");//按下按钮时按钮状态
       releasePicture=new QPixmap(":/button/Button/close.png");//恢复按钮原始状态

       this->setFlat(true);//关闭按钮的默认显示
       this->setIcon(QIcon(*buttonPicture));
       this->setIconSize(QSize(140,40));
   }


protected:
   void mousePressEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*pressPicture));
   }
   void mouseReleaseEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*releasePicture));
       emit clicked();//发出click信号
   }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//重新开始按钮
class RestartButton:public QPushButton
{
    Q_OBJECT
public:
   RestartButton(QWidget *parent)
        :QPushButton(parent)
   {
       buttonPicture=new QPixmap(":/button/Button/restart.png");//按钮原始状态
       pressPicture=new QPixmap(":/button/Button/restart2.png");//按下按钮时按钮状态
       releasePicture=new QPixmap(":/button/Button/restart.png");//恢复按钮原始状态

       this->setFlat(true);//关闭按钮的默认显示
       this->setIcon(QIcon(*buttonPicture));
       this->setIconSize(QSize(140,40));
   }

protected:
   void mousePressEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*pressPicture));
   }
   void mouseReleaseEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*releasePicture));
       emit clicked();//发出click信号
   }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//返回按钮
class ReturnButton:public QPushButton
{
    Q_OBJECT
public:
   ReturnButton(QWidget *parent)
        :QPushButton(parent)
   {
       buttonPicture=new QPixmap(":/button/Button/return.png");//按钮原始状态
       pressPicture=new QPixmap(":/button/Button/return2.png");//按下按钮时按钮状态
       releasePicture=new QPixmap(":/button/Button/return.png");//恢复按钮原始状态

       this->setFlat(true);//关闭按钮的默认显示
       this->setIcon(QIcon(*buttonPicture));
       this->setIconSize(QSize(140,40));
   }

protected:
   void mousePressEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*pressPicture));
   }
   void mouseReleaseEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*releasePicture));
       emit clicked();//发出click信号
   }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//暂停按钮
class PauseButton:public QPushButton
{
    Q_OBJECT
public:
   PauseButton(QWidget *parent)
        :QPushButton(parent)
   {
       buttonPicture=new QPixmap(":/button/Button/pause.png");//按钮原始状态
       pressPicture=new QPixmap(":/button/Button/pause2.png");//按下按钮时按钮状态
       releasePicture=new QPixmap(":/button/Button/pause.png");//恢复按钮原始状态

       this->setFlat(true);//关闭按钮的默认显示
       this->setIcon(QIcon(*buttonPicture));
       this->setIconSize(QSize(140,40));
   }

protected:
   void mousePressEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*pressPicture));
   }
   void mouseReleaseEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*releasePicture));
       emit clicked();//发出click信号
   }
private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//是按钮
class YesButton:public QPushButton
{
    Q_OBJECT
public:
   YesButton(QWidget *parent)
        :QPushButton(parent)
   {
       buttonPicture=new QPixmap(":/button/Button/yes.png");//按钮原始状态
       pressPicture=new QPixmap(":/button/Button/yes2.png");//按下按钮时按钮状态
       releasePicture=new QPixmap(":/button/Button/yes.png");//恢复按钮原始状态

       this->setFlat(true);//关闭按钮的默认显示
       this->setIcon(QIcon(*buttonPicture));
       this->setIconSize(QSize(140,40));
   }

protected:
   void mousePressEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*pressPicture));
   }
   void mouseReleaseEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*releasePicture));
       emit clicked();//发出click信号
   }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//否按钮
class NoButton:public QPushButton
{
    Q_OBJECT
public:
   NoButton(QWidget *parent)
        :QPushButton(parent)
   {
       buttonPicture=new QPixmap(":/button/Button/no.png");//按钮原始状态
       pressPicture=new QPixmap(":/button/Button/no2.png");//按下按钮时按钮状态
       releasePicture=new QPixmap(":/button/Button/no.png");//恢复按钮原始状态

       this->setFlat(true);//关闭按钮的默认显示
       this->setIcon(QIcon(*buttonPicture));
       this->setIconSize(QSize(140,40));
   }

protected:
   void mousePressEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*pressPicture));
   }
   void mouseReleaseEvent(QMouseEvent *event)
   {
       this->setIcon(QIcon(*releasePicture));
       emit clicked();//发出click信号
   }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

//经典模式
class ClassicModeButton:public QPushButton
{
    Q_OBJECT
 public:
    ClassicModeButton(QWidget *parent)
        :QPushButton(parent)
    {
        buttonPicture=new QPixmap(":/button/Button/Classic.png");//按钮原始状态
        pressPicture=new QPixmap(":/button/Button/Classic2.png");//按下按钮时按钮状态
        releasePicture=new QPixmap(":/button/Button/Classic.png");//恢复按钮原始状态

        this->setFlat(true);//关闭按钮的默认显示
        this->setIcon(QIcon(*buttonPicture));
        this->setIconSize(QSize(252,204));
    }

protected:
    void mousePressEvent(QMouseEvent *event)//按下按钮
    {
        this->setIcon(QIcon(*pressPicture));
    }
    void mouseReleaseEvent(QMouseEvent *event)//松开按钮
    {
        this->setIcon(QIcon(*releasePicture));
        emit clicked();//发出click信号
    }

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};



#endif // BUTTON_H
