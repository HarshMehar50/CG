#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
    float dx, dy, steps, xInc, yInc;
    float x, y;
    int i;

    // Input coordinates
    printf("Enter x1, y1: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%f %f", &x2, &y2);

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Calculate dx and dy
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine number of steps
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    // Calculate increments
    xInc = dx / steps;
    yInc = dy / steps;

    // Starting point
    x = x1;
    y = y1;

    // Plot first point
    putpixel(round(x), round(y), WHITE);

    // Generate points
    for (i = 0; i < steps; i++) {
        x = x + xInc;
        y = y + yInc;
        putpixel(round(x), round(y), WHITE);
        // putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
    }

    getch();
    closegraph();
}
