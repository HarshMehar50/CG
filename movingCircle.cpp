#include <graphics.h>
#include <conio.h>
#include <dos.h>   

int main() {
    int gd = DETECT, gm;
    int x = 50, y = 200;   
    int radius = 30;
    int i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    
    for (i = 0; i < 400; i++) {
        cleardevice();              
        circle(x + i, y, radius);   
        delay(20);                  
    }

    getch();
    closegraph();
    return 0;
}
