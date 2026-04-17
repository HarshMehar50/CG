#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to plot all 8 symmetric points
void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void bresenhamCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;   // decision parameter

    while (x <= y) {
        drawCircle(xc, yc, x, y);

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center of circle (xc, yc): ");
    scanf("%d %d", &xc, &yc);

  // cout<<"Enter center of circle (xc, yc): ";
  // cin>>xc>>yc;

    printf("Enter radius: ");
    scanf("%d", &r);

    bresenhamCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
