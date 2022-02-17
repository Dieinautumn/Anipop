#include "Widget.h"
#include "ui_widget.h"


//构造函数
Widget::Widget(QApplication &app)
{

    setAutoFillBackground(true);//设置背景图之前必须设置该属性
    setFixedSize(QSize(800,600));//设置固定大小
    SetBackground(QPixmap(":/Ui/ui/GameBackground.png"));//设置背景图片

    QPixmap TitlePicture=QPixmap(":/Ui/ui/Title.png").scaled(600,178);//缩放
    Title=new QLabel(this);
    Title->setPixmap(TitlePicture);//设置标题图片
    Title->setGeometry(QRect(110,-120,600,178));//设置布局结构
    Title->hide();//设置隐藏

    //对指针初始化
    //对窗口进行位置设置
     ClassicMode=new QLabel(this);
     ClassicMode->setPixmap(QPixmap(":/Ui/ui/ClassicGame.png"));
     ClassicMode->setGeometry(QRect(0,0,800,600));//对子窗体进行位置设置
     ClassicMode->hide();

     StartGame=new StartButton(this);
     StartGame->setGeometry(QRect(330,-40,140,40));

     GameHelp=new HelpButton(this);
     GameHelp->setGeometry(QRect(330,-40,140,40));

     ExitGame=new ExitButton(this);
     ExitGame->setGeometry(QRect(330,-40,140,40));

     ClassicGame = new ClassicModeButton(this);

     //开始界面动画
     Start();

     PauseGame=new PauseButton(this);
     PauseGame->setGeometry(QRect(940,470,140,40));
     PauseGame->hide();

     CGame=new Cui(this);
     CGame->setGeometry(QRect(-480,-480,480,480));
     CGame->hide();

     Scorebar=new QLabel(this);
     Scorebar->setPixmap(QPixmap(":/button/Button/SCORE.png"));
     Scorebar->hide();

     QFont font("Segoe UI",22,QFont::Bold);//字体，大小，加粗
     QPalette pa;//调控颜色
     pa.setColor(QPalette::WindowText,Qt::white);//白色字体

     theScore=new QLabel(this);
     theScore->setFont(font);
     theScore->setPalette(pa);

     timer1=new QTimer(this);
     timer1->start(200);

     theScore->hide();

     showTime=new QLabel(this);
     showTime->setPixmap(QPixmap(":/button/Button/TIME.png"));
     showTime->hide();

     theTime=new QLabel(this);
     theTime->setFont(font);
     theTime->setPalette(pa);

     timer2=new QTimer(this);
     theTime->hide();

     BlackM=new QLabel(this);
     BlackM->setPixmap(QPixmap(":/Ui/ui/black.png"));
     BlackM->setGeometry(QRect(0,0,800,600));
     BlackM->hide();

     Page=new QLabel(this);
     Page->hide();

     ClosePage=new CloseButton(this);
     ClosePage->setGeometry(QRect(940,470,30,30));
     ClosePage->hide();

     QFont font2("Segoe UI",40);

     QPalette pa2;
     pa2.setColor(QPalette::WindowText,Qt::white);

     showScore=new QLabel(this);
     showScore->setAlignment(Qt::AlignCenter);//设置文字对齐方式，中央对齐
     showScore->setFont(font2);
     showScore->setPalette(pa2);
     showScore->hide();

     RestartGame=new RestartButton(this);
     RestartGame->setGeometry(QRect(940,470,140,40));
     RestartGame->hide();

     Returnbutton=new ReturnButton(this);
     Returnbutton->setGeometry(QRect(940,470,140,40));
     Returnbutton->hide();


     Yesbutton=new YesButton(this);
     Yesbutton->setGeometry(QRect(940,470,140,40));
     Yesbutton->hide();

     Nobutton=new NoButton(this);
     Nobutton->setGeometry(QRect(940,470,140,40));
     Nobutton->hide();

     //连接函数
     connect(StartGame,SIGNAL(clicked()),this,SLOT(Select()));

     connect(GameHelp,SIGNAL(clicked()),this,SLOT(Help()));

     connect(ExitGame,SIGNAL(clicked()),this,SLOT(Exit()));

     connect(Yesbutton,SIGNAL(clicked()),this,SLOT(Close()));
     connect(Yesbutton,SIGNAL(clicked()),&app,SLOT(quit()));

     connect(Nobutton,SIGNAL(clicked()),this,SLOT(Close()));

     connect(ClassicGame,SIGNAL(clicked()),this,SLOT(Classic()));

     connect(PauseGame,SIGNAL(clicked()),this,SLOT(Pause()));

     connect(ClosePage,SIGNAL(clicked()),this,SLOT(Close()));
     connect(ClosePage,SIGNAL(clicked()),this,SLOT(ClosePause()));

     connect(Returnbutton,SIGNAL(clicked()),this,SLOT(Close()));
     connect(Returnbutton,SIGNAL(clicked()),this,SLOT(Return()));


     connect(RestartGame,SIGNAL(clicked()),this,SLOT(Close()));


}

//设置分数
void Widget::SetCScore()
{
    //字符串
    QString str=QString::number(CGame->GameScore.tscore,10);//显示内容，十进制
    theScore->setText(str);
}

//设置背景图片
void Widget::SetBackground(QPixmap Image)
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(Image));
    this->setPalette(palette);
}

//开始动画
void Widget::Start()
{

    ClassicMode->hide();
    ClassicGame->hide();
    group.clear();

    Title->show();//标题动画进入
    QPropertyAnimation *anime1;
    anime1=new QPropertyAnimation(Title,"geometry");//QT动画效果
    anime1->setDuration(600);//设置动画播放时长
    anime1->setStartValue(QRect(110,-120,600,178));//动画开始坐标
    anime1->setEndValue(QRect(110,120,600,178));//动画终止位置
    anime1->setEasingCurve(QEasingCurve::OutBack);//动画效果

    StartGame->show();//开始游戏动画进入
    QPropertyAnimation *anime2;
    anime2=new QPropertyAnimation(StartGame,"geometry");
    anime2->setDuration(600);
    anime2->setStartValue(QRect(330,-180,140,40));
    anime2->setEndValue(QRect(330,360,140,40));
    anime2->setEasingCurve(QEasingCurve::OutBack);

    GameHelp->show();//游戏说明动画进入
    QPropertyAnimation *anime3;
    anime3=new QPropertyAnimation(GameHelp,"geometry");
    anime3->setDuration(600);
    anime3->setStartValue(QRect(330,-120,140,40));
    anime3->setEndValue(QRect(330,420,140,40));
    anime3->setEasingCurve(QEasingCurve::OutBack);

    ExitGame->show();//退出游戏动画进入
    QPropertyAnimation *anime4;
    anime4=new QPropertyAnimation(ExitGame,"geometry");
    anime4->setDuration(600);
    anime4->setStartValue(QRect(330,-60,140,40));
    anime4->setEndValue(QRect(330,480,140,40));
    anime4->setEasingCurve(QEasingCurve::OutBack);


    //串联动画组
    group.addAnimation(anime1);//添加动画效果
    group.addAnimation(anime2);
    group.addAnimation(anime3);
    group.addAnimation(anime4);
    group.start();

}

//选择动画
void Widget::Select()
{
    group1.clear();
    group2.clear();
    QPropertyAnimation *anime11;//标题动画退出
    anime11=new QPropertyAnimation(Title,"geometry");
    anime11->setDuration(1000);
    anime11->setStartValue(QRect(110,120,600,178));
    anime11->setEndValue(QRect(110,-300,600,178));
    anime11->setEasingCurve(QEasingCurve::OutBack);

    StartGame->show();//开始游戏按钮动画退出
    QPropertyAnimation *anime21;
    anime21=new QPropertyAnimation(StartGame,"geometry");
    anime21->setDuration(600);
    anime21->setStartValue(QRect(330,360,140,40));
    anime21->setEndValue(QRect(330,740,140,40));
    anime21->setEasingCurve(QEasingCurve::OutBack);

    GameHelp->show();//游戏帮助按钮动画退出
    QPropertyAnimation *anime31;
    anime31=new QPropertyAnimation(GameHelp,"geometry");
    anime31->setDuration(600);
    anime31->setStartValue(QRect(330,420,140,40));
    anime31->setEndValue(QRect(330,740,140,40));
    anime31->setEasingCurve(QEasingCurve::OutBack);

    ExitGame->show();//退出游戏按钮动画退出
    QPropertyAnimation *anime41;
    anime41=new QPropertyAnimation(ExitGame,"geometry");
    anime41->setDuration(600);
    anime41->setStartValue(QRect(330,480,140,40));
    anime41->setEndValue(QRect(330,740,140,40));
    anime41->setEasingCurve(QEasingCurve::OutBack);

    group2.addAnimation(anime11);
    group2.addAnimation(anime21);
    group2.addAnimation(anime31);
    group2.addAnimation(anime41);

    ClassicGame->show();//游戏模式选项动画进入
    QPropertyAnimation *anime5;
    anime5=new QPropertyAnimation(ClassicGame, "geometry");
    anime5->setDuration(600);
    anime5->setStartValue(QRect(255, -204, 252,204));
    anime5->setEndValue(QRect(255, 198, 252,204));
    anime5->setEasingCurve(QEasingCurve::OutInBack);

    group1.addAnimation(anime5);

    group2.start();
    group1.start();
}

//关闭暂停界面
void Widget::ClosePause()
{
    //继续计时
    timer2->start();
    disconnect(ClosePage,SIGNAL(clicked()),this,SLOT(ClosePause()));
    //中断连接
}


void Widget::Pause()//暂停按钮
{
    connect(ClosePage,SIGNAL(clicked()),this,SLOT(ClosePause()));
    timer2->stop();//停止计时
    group4.clear();
    BlackM->show();

    Page->setPixmap(QPixmap(":/button/Button/PausePage.png"));//设置暂停界面
    Page->show();

    QPropertyAnimation *anime1;
    QPropertyAnimation *anime2;
    QPropertyAnimation *anime3;
    QPropertyAnimation *anime4;

    anime1=new QPropertyAnimation(Page,"geometry");//暂停页面进入动画
    anime1->setDuration(200);
    anime1->setStartValue(QRect(213,-300,350,220));
    anime1->setEndValue(QRect(213,170,350,220));
    anime1->setEasingCurve(QEasingCurve::OutExpo);

    ClosePage->setFocusPolicy(Qt::StrongFocus);//设置窗口/控件的聚焦策略
    //接受Tab键和鼠标单击做焦点

    ClosePage->show();//关闭页面进入动画
    anime2=new QPropertyAnimation(ClosePage,"geometry");
    anime2->setDuration(200);
    anime2->setStartValue(QRect(511,-315,30,30));
    anime2->setEndValue(QRect(511,185,30,30));
    anime2->setEasingCurve(QEasingCurve::OutExpo);

    RestartGame->show();//重新开始游戏进入动画
    anime3=new QPropertyAnimation(RestartGame,"geometry");
    anime3->setDuration(200);
    anime3->setStartValue(QRect(233,-145,140,40));
    anime3->setEndValue(QRect(233,325,140,40));
    anime3->setEasingCurve(QEasingCurve::OutExpo);

    Returnbutton->show();//返回按钮进入动画
    anime4=new QPropertyAnimation(Returnbutton,"geometry");
    anime4->setDuration(200);
    anime4->setStartValue(QRect(397,-145,140,40));
    anime4->setEndValue(QRect(397,325,140,40));
    anime4->setEasingCurve(QEasingCurve::OutExpo);

    group4.addAnimation(anime1);
    group4.addAnimation(anime2);
    group4.addAnimation(anime3);
    group4.addAnimation(anime4);
    group4.start();
}

void Widget::Help()//帮助按钮链接
{
    group4.clear();
    BlackM->show();
    Page->setPixmap(QPixmap(":/button/Button/HelpText.png"));
    Page->show();

    QPropertyAnimation *anime1;
    QPropertyAnimation *anime2;

    anime1=new QPropertyAnimation(Page,"geometry");//帮助界面进入动画
    anime1->setDuration(200);
    anime1->setStartValue(QRect(187,-303,400,300));
    anime1->setEndValue(QRect(187,173,400,300));
    anime1->setEasingCurve(QEasingCurve::OutExpo);

    ClosePage->setFocusPolicy(Qt::StrongFocus);
    ClosePage->show();//关闭按钮进入动画
    anime2=new QPropertyAnimation(ClosePage,"geometry");
    anime2->setDuration(200);
    anime2->setStartValue(QRect(557,-300,30,30));
    anime2->setEndValue(QRect(557,170,30,30));
    anime2->setEasingCurve(QEasingCurve::OutExpo);

    group4.addAnimation(anime1);
    group4.addAnimation(anime2);
    group4.start();
}

void Widget::Close()//关闭按钮
{
    showScore->hide();
    BlackM->hide();
    Page->hide();
    ClosePage->hide();
    Returnbutton->hide();
    RestartGame->hide();
    Yesbutton->hide();
    Nobutton->hide();
    timer2->start();
}

void Widget::Return()//返回按钮
{

    disconnect(timer2,SIGNAL(timeout()),this,SLOT(CountTimeC()));
    //停止计时
    timer2->stop();

    CGame->GameScore.retScore();
    CGame->GameScore.rexScore();

    group5.clear();

    PauseGame->show();
    QPropertyAnimation *anime7;
    anime7=new QPropertyAnimation(PauseGame, "geometry");
    anime7->setDuration(600);
    anime7->setStartValue(QRect(577, 390, 140, 40));
    anime7->setEndValue(QRect(940, 390, 140, 40));
    anime7->setEasingCurve(QEasingCurve::InOutCirc);

    ExitGame->show();
    QPropertyAnimation *anime8;
    anime8=new QPropertyAnimation(ExitGame, "geometry");
    anime8->setDuration(600);
    anime8->setStartValue(QRect(577, 460, 140, 40));
    anime8->setEndValue(QRect(940, 460, 140, 40));
    anime8->setEasingCurve(QEasingCurve::InOutCirc);

    Scorebar->show();
    QPropertyAnimation *anime9;
    anime9=new QPropertyAnimation(Scorebar, "geometry");
    anime9->setDuration(400);
    anime9->setStartValue(QRect(500,5,188,42));
    anime9->setEndValue(QRect(500,-42,188,42));
    anime9->setEasingCurve(QEasingCurve::InOutBack);

    theScore->show();
    QPropertyAnimation *anime10;
    anime10=new QPropertyAnimation(theScore, "geometry");
    anime10->setDuration(400);
    anime10->setStartValue(QRect(400, 5, 120, 35));
    anime10->setEndValue(QRect(400, -42, 120, 35));
    anime10->setEasingCurve(QEasingCurve::InOutBack);

    group5.addAnimation(anime7);
    group5.addAnimation(anime8);
    group5.addAnimation(anime9);
    group5.addAnimation(anime10);
    group5.start();
    HideTime();

    Start();
}

void Widget::HideCScore()
{
    CGame->show();

    QPropertyAnimation *anime11;
    anime11=new QPropertyAnimation(CGame, "geometry");
    anime11->setDuration(600);
    anime11->setStartValue(QRect(40, 70, 500,500));
    anime11->setEndValue(QRect(-550,0, 500,500));
    anime11->setEasingCurve(QEasingCurve::InOutCirc);
    anime11->start();
}

void Widget::Exit()//退出游戏页面，
{
    connect(ClosePage,SIGNAL(clicked()),this,SLOT(ClosePause()));
    timer2->stop();
    BlackM->show();
    group4.clear();

    Page->setPixmap(QPixmap(":/button/Button/exitPage.png"));
    Page->show();

    QPropertyAnimation *anime1;
    QPropertyAnimation *anime2;
    QPropertyAnimation *anime3;
    QPropertyAnimation *anime4;

    anime1=new QPropertyAnimation(Page, "geometry");
    anime1->setDuration(200);
    anime1->setStartValue(QRect(213, -300, 350,220));
    anime1->setEndValue(QRect(213,170, 350,220));
    anime1->setEasingCurve(QEasingCurve::OutExpo);

    ClosePage->setFocusPolicy(Qt::StrongFocus);
    ClosePage->show();

    anime2=new QPropertyAnimation(ClosePage, "geometry");
    anime2->setDuration(200);
    anime2->setStartValue(QRect(511, -315, 30,30));
    anime2->setEndValue(QRect(511,185, 30,30));
    anime2->setEasingCurve(QEasingCurve::OutExpo);

    Yesbutton->show();
    anime3=new QPropertyAnimation(Yesbutton, "geometry");
    anime3->setDuration(200);
    anime3->setStartValue(QRect(233,-145,140,40));
    anime3->setEndValue(QRect(233,325,140,40));
    anime3->setEasingCurve(QEasingCurve::OutExpo);

    Nobutton->show();
    anime4=new QPropertyAnimation(Nobutton, "geometry");
    anime4->setDuration(200);
    anime4->setStartValue(QRect(397,-145,140,40));
    anime4->setEndValue(QRect(397,325,140,40));
    anime4->setEasingCurve(QEasingCurve::OutExpo);

    group4.addAnimation(anime1);
    group4.addAnimation(anime2);
    group4.addAnimation(anime3);
    group4.addAnimation(anime4);

    group4.start();

}

//该游戏模式重新开始
void Widget::CRestart()
{
    CGame->GameTime=180;
    timer2->start();
    group.clear();
    CGame->show();

    //游戏界面退出再重新进入
    QPropertyAnimation *anime5;
    anime5=new QPropertyAnimation(CGame, "geometry");
    anime5->setDuration(300);
    anime5->setStartValue(QRect(20,81,480,480));
    anime5->setEndValue(QRect(-550,81,480,480));
    anime5->setEasingCurve(QEasingCurve::InOutCirc);

    PauseGame->show();//显示停止游戏按钮

    CGame->show();
    QPropertyAnimation *anime6;
    anime6=new QPropertyAnimation(CGame, "geometry");
    anime6->setDuration(300);
    anime6->setStartValue(QRect(-550,81,480,480));
    anime6->setEndValue(QRect(20,81,480,480));
    anime6->setEasingCurve(QEasingCurve::InOutCirc);

    group.addAnimation(anime5);
    group.addAnimation(anime6);
    group.start();

}

//游戏模式开始
void Widget::Classic()
{
    connect(Returnbutton,SIGNAL(clicked()),this,SLOT(HideCScore()));

    connect(RestartGame,SIGNAL(clicked()),CGame,SLOT(restart()));
    connect(RestartGame,SIGNAL(clicked()),this,SLOT(CRestart()));

    connect(timer1,SIGNAL(timeout()),this,SLOT(SetCScore()));

    connect(timer2,SIGNAL(timeout()),this,SLOT(CountTimeC()));

    CGame->GameTime=180;
    timer2->start(1000);

    ClassicMode->show();
    Time();


/////////////////////////////////////////////////////////////////////

    group6.clear();

    StartGame->hide();
    ExitGame->hide();
    GameHelp->hide();

    ClassicGame->show();
    QPropertyAnimation *anime8;//经典游戏按钮退出
    anime8=new QPropertyAnimation(ClassicGame, "geometry");
    anime8->setDuration(600);
    anime8->setStartValue(QRect(255, 198, 252,204));
    anime8->setEndValue(QRect(255, -204, 252,204));
    anime8->setEasingCurve(QEasingCurve::InOutCirc);

    PauseGame->show();//暂停游戏
    QPropertyAnimation *anime9;
    anime9=new QPropertyAnimation(PauseGame, "geometry");
    anime9->setDuration(600);
    anime9->setStartValue(QRect(940,390,140,40));
    anime9->setEndValue(QRect(577,390,140,40));
    anime9->setEasingCurve(QEasingCurve::InOutCirc);

    ExitGame->show();//退出游戏
    QPropertyAnimation *anime10;
    anime10=new QPropertyAnimation(ExitGame, "geometry");
    anime10->setDuration(600);
    anime10->setStartValue(QRect(940,390,140,40));
    anime10->setEndValue(QRect(577,460,140,40));
    anime10->setEasingCurve(QEasingCurve::InOutCirc);

    Scorebar->show();
    QPropertyAnimation *anime11;
    anime11=new QPropertyAnimation(Scorebar, "geometry");
    anime11->setDuration(400);
    anime11->setStartValue(QRect(400,-42,188, 42));
    anime11->setEndValue(QRect(400,5,188, 42));
    anime11->setEasingCurve(QEasingCurve::InOutBack);

    theScore->show();
    QPropertyAnimation *anime12;
    anime12=new QPropertyAnimation(theScore, "geometry");
    anime12->setDuration(400);
    anime12->setStartValue(QRect(500,-42,120,35));
    anime12->setEndValue(QRect(500,5,120,35));
    anime12->setEasingCurve(QEasingCurve::InOutBack);

    group6.addAnimation(anime8);
    group6.addAnimation(anime9);
    group6.addAnimation(anime10);
    group6.addAnimation(anime11);
    group6.addAnimation(anime12);

    group6.start();

////////////////////////////////////////////////////////////////////////

    CGame->show();

    QPropertyAnimation *anime7;//游戏棋盘
    anime7=new QPropertyAnimation(CGame, "geometry");
    anime7->setDuration(600);
    anime7->setStartValue(QRect(-550,81,480,480));
    anime7->setEndValue(QRect(20,81,480,480));
    anime7->setEasingCurve(QEasingCurve::InOutCirc);

    anime7->start();

}


//最终显示分数界面，隐藏其他按钮
void Widget::Score()
{
    group4.clear();
    BlackM->show();
    Page->setPixmap(QPixmap(":/button/Button/ScorePage.png"));

    Page->show();

    QPropertyAnimation *anime1;
    anime1=new QPropertyAnimation(Page, "geometry");
    anime1->setDuration(200);
    anime1->setStartValue(QRect(213,-300,350,220));
    anime1->setEndValue(QRect(213,170,350,220));
    anime1->setEasingCurve(QEasingCurve::InExpo);

    RestartGame->show();
    QPropertyAnimation *anime2;
    anime2=new QPropertyAnimation(RestartGame, "geometry");
    anime2->setDuration(200);
    anime2->setStartValue(QRect(233,-145,140,40));
    anime2->setEndValue(QRect(233,325,140,40));
    anime2->setEasingCurve(QEasingCurve::InExpo);

    Returnbutton->show();
    QPropertyAnimation *anime3;
    anime3=new QPropertyAnimation(Returnbutton, "geometry");
    anime3->setDuration(200);
    anime3->setStartValue(QRect(397,-145,140,40));
    anime3->setEndValue(QRect(397,325,140,40));
    anime3->setEasingCurve(QEasingCurve::InExpo);

    group4.addAnimation(anime1);
    group4.addAnimation(anime2);
    group4.addAnimation(anime3);
    group4.start();
}

//最终显示分数界面
void Widget::Cscore()
{
    showScore->setText(QString::number(CGame->GameScore.tscore,10));
    showScore->show();
    QPropertyAnimation *anime4;
    anime4=new QPropertyAnimation(showScore, "geometry");
    anime4->setDuration(200);
    anime4->setStartValue(QRect(309,-250,150,60));
    anime4->setEndValue(QRect(309,240,150,60));
    anime4->setEasingCurve(QEasingCurve::InExpo);
    anime4->start();
}

//显示计时动画
void Widget::Time()
{
    group4.clear();

    showTime->show();
    QPropertyAnimation *anime11;
    QPropertyAnimation *anime12;

    //游戏计时方块动画出现
    anime11=new QPropertyAnimation(showTime, "geometry");
    anime11->setDuration(400);
    anime11->setStartValue(QRect(90, -42, 188, 42));
    anime11->setEndValue(QRect(90, 5, 188, 42));
    anime11->setEasingCurve(QEasingCurve::InOutBack);

    //游戏计时动画出现
    theTime->show();
    anime12=new QPropertyAnimation(theTime, "geometry");
    anime12->setDuration(400);
    anime12->setStartValue(QRect(190,-35, 120, 35));
    anime12->setEndValue(QRect(190, 5, 120, 35));
    anime12->setEasingCurve(QEasingCurve::InOutBack);

    group4.addAnimation(anime11);
    group4.addAnimation(anime12);
    group4.start();
}

//隐藏时间动画
void Widget::HideTime()
{
    group4.clear();
    showTime->show();

    QPropertyAnimation *anime11;//游戏计时方块动画退出
    anime11=new QPropertyAnimation(showTime, "geometry");
    anime11->setDuration(400);
    anime11->setStartValue(QRect(90, 5, 188, 42));
    anime11->setEndValue(QRect(90, -42, 188, 42));
    anime11->setEasingCurve(QEasingCurve::InOutBack);

    theTime->show();
    QPropertyAnimation *anime12;//游戏计时动画退出
    anime12=new QPropertyAnimation(theTime, "geometry");
    anime12->setDuration(400);
    anime12->setStartValue(QRect(190, 5, 120, 35));
    anime12->setEndValue(QRect(190,-35, 120, 35));
    anime12->setEasingCurve(QEasingCurve::InOutBack);

    group4.addAnimation(anime11);
    group4.addAnimation(anime12);
    group4.start();
}

//计时策略
void Widget::CountTimeC()
{
    QString str=QString::number(CGame->GameTime,10);
    theTime->setText(str);
    CGame->GameTime--;

    if(CGame->GameTime==-1)
    {
        timer2->stop();
        Score();
        Cscore();
        CGame->GameTime=180;
    }
}
