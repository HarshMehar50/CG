#include <graphics.h>
#include <conio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Control points
    int x0 = 50,  y0 = 200;
    int x1 = 150, y1 = 50;
    int x2 = 250, y2 = 350;
    int x3 = 350, y3 = 200;

    float t;
    int x, y;


    setcolor(RED);
    circle(x0, y0, 3);

    circle(x1, y1, 3);
    circle(x2, y2, 3);
    circle(x3, y3, 3);

    
    setcolor(WHITE);
    for (t = 0.0; t <= 1.0; t += 0.001) {
        x = pow(1 - t, 3) * x0 +
            3 * t * pow(1 - t, 2) * x1 + 3 * pow(t, 2) * (1 - t) * x2 + pow(t, 3) * x3;

        y = pow(1 - t, 3) * y0 +
            3 * t * pow(1 - t, 2) * y1 + 3 * pow(t, 2) * (1 - t) * y2 + pow(t, 3) * y3;
        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
}
