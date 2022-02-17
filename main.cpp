#include "Widget.h"
#include <QApplication>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8")) ;//可输出中文
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":\ico.ico"));//设置游戏图标

    Widget Game(a);
    Game.setWindowTitle(QObject::tr("开心消消乐").toLocal8Bit());//设置窗口显示的游戏名称
    Game.show();


    return a.exec();

}
