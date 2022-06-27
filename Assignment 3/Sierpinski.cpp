#include "Sierpinski.h"
#include "error.h"
using namespace std;

/**
 * Draws a triangle with the specified corners in the specified window. Feel free
 * to edit this function as you see fit to change things like color, fill style,
 * etc. in whatever way you'd like!
 *
 * @param window The window in which to draw the triangle.
 * @param x0 y0 The first corner of the triangle.
 * @param x1 y1 The second corner of the triangle.
 * @param x2 y2 The third corner of the triangle.
 */
void drawTriangle(GWindow& window,
                  double x0, double y0,
                  double x1, double y1,
                  double x2, double y2) {
    window.setColor("black");
    window.fillPolygon({ x0, y0, x1, y1, x2, y2 });
}


void drawSierpinskiTriangle(GWindow& window,
                            double x0, double y0,
                            double x1, double y1,
                            double x2, double y2,
                            int order) {
     if(order < 0){
         error("order can't be negative");
     }
     //base case
     else if(order == 0){
         drawTriangle(window, x0, y0, x1, y1, x2, y2);
     }
     //recursive case
     else{
         drawSierpinskiTriangle(window, x0, y0, (x0 + x1) / 2, (y0 + y1) / 2,
                      (x0 + x2) / 2, (y0 + y2) / 2, order - 1);
         drawSierpinskiTriangle(window, x1, y1, (x0 + x1) / 2, (y0 + y1) / 2,
                      (x1 + x2) / 2, (y1 + y2) / 2, order - 1);
         drawSierpinskiTriangle(window, x2, y2, (x2 + x1) / 2, (y2 + y1) / 2,
                      (x0 + x2) / 2, (y0 + y2) / 2, order - 1);
     }
}