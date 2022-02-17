#ifndef SCORE_H
#define SCORE_H

class Score//分数类
{

public:
    Score();//构造函数

    void tScore();//计算总分数
    void xScore(int x);//计算小分数

    void retScore();//重置总分数为零
    void rexScore();//重置小分数为零

    void setScore(int s);//设置总分
    int getScore();//获得总分

    int tscore;//总分数
    int xscore;//小分数
};


#endif // SCORE_H
