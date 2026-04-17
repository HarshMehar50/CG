#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main(){
  int gd = DETECT , gm;
int x , y;
initgraph(&gd , &gm , "C:\\TURBOC3\\bgi");
cin>>x>>y;
putpixel(x , y , WHITE);
outtextxy(x+5 , y+5 , "Point");
getch();
closegraph();
return 0;
}
