#include <graphics.h>
#include <conio.h>
#include <iostream.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int d;
    cout << "Enter delay time (ms): ";
    cin >> d;

    for (int i = 50; i < 500; i += 10) {
        cleardevice();
        circle(i, 200, 40);
        delay(d);
    }

    getch();
    closegraph();
    return 0;
}
