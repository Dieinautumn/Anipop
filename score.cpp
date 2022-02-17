#include"score.h"

Score::Score()
{
    tscore=0;
    xscore=0;
}

void Score::retScore()
{
    tscore=0;
}

void Score::rexScore()
{
    xscore=0;
}

void Score::tScore()
{
    tscore+=xscore;//将统计完的小分数加入总分中
    xscore=0;//重置小分数为零
}

void Score::xScore(int x)
{
    xscore+=x;//统计小分数
}

void Score::setScore(int s)
{
    tscore=s;
}


int Score::getScore()
{
    return tscore;
}


