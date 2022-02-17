#ifndef WIDGET_H
#define WIDGET_H
//游戏UI界面
#include <QWidget>

#include<QtGui>
#include<QPropertyAnimation>
#include<QLabel>

#include"button.h"
#include"cui.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QApplication &app);//ui构造函数，用于构造界面

    void SetBackground(QPixmap Image);//设置游戏背景
    void Start();//设置开头动画

    void Time();//设置时间显示动画
    void Score();//设置分数显示动画
    void Cscore();//设置经典模式分数
    void HideTime();//隐藏时间动画

protected slots:
    void Help();//游戏帮助
    void Select();//选择
    void Pause();//暂停
    void Return();//返回主页
    void Exit();//退出游戏

    void CRestart();//重新开始经典模式
    void Classic();//选择经典模式动画

    void Close();//关闭页面
    void ClosePause();//关闭暂停页面

    void SetCScore();//设置经典模式分数动画
    void HideCScore();//隐藏经典模式分数
    void CountTimeC();//经典模式倒计时

protected:
    //标签指针
    QLabel *Title;
    QLabel *HelpPage;
    QLabel *Page;
    QLabel *Scorebar;
    QLabel *theScore;
    QLabel *theTime;
    QLabel *showTime;
    QLabel *showScore;
    QLabel *ClassicMode;
    QLabel *BlackM;
    //按钮指针
    StartButton *StartGame;
    HelpButton *GameHelp;
    ExitButton *ExitGame;
    CloseButton *ClosePage;
    RestartButton *RestartGame;
    ReturnButton *Returnbutton;
    PauseButton *PauseGame;
    YesButton *Yesbutton;
    NoButton *Nobutton;
    ClassicModeButton *ClassicGame;


    Cui *CGame;//经典模式棋盘
    QImage MainBackground;//主要背景图片

    QSequentialAnimationGroup group; //串联动画组
    QParallelAnimationGroup group1; //并联动画组
    QParallelAnimationGroup group2;
    QParallelAnimationGroup group3;
    QParallelAnimationGroup group4;
    QParallelAnimationGroup group5;
    QParallelAnimationGroup group6;

    QTimer *timer1;//QTimer类，发送时间信号
    QTimer *timer2;

private:
    Ui::Widget *ui;
};

#endif
