#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(100, 100, 200, 200);   // Square
    circle(300, 150, 50);            // Circle
    line(50, 300, 200, 350);         // Line
    ellipse(400, 300, 0, 360, 60, 30);

    getch();
    closegraph();
    return 0;
}
