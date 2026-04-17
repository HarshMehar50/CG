#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx, dy, p, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    while (x <= x2) {
        putpixel(x, y, WHITE);

        if (p >= 0) {
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else {
            p = p + 2 * dy;
        }

        x = x + 1;
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    bresenhamLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
