#include<iostream>
#include<time.h>

using namespace std;

/**
  计时器类，计算从调用start开始到调用printSeconds所花销的时间
  */
class Timer{
public:
    Timer(){
        startTime = clock();
    }
    void restart(){
        startTime = clock();
    }
    void printSeconds(){
       double totaltime;
       finishTime=clock();
       totaltime=(double)(finishTime-startTime)/CLOCKS_PER_SEC;
       cout<<"\n此部分程序的运行时间为"<<totaltime<<"秒！"<<endl;
    }
    void printSecondsAndExit(){
       printSeconds();
       exit(0);
    }
private:
    clock_t startTime;
    clock_t finishTime;
};
