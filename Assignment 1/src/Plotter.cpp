#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    PenStyle style = { 1, "black" };
        double x0 = 0, y0 = 0, x1, y1;
        /* INFO: 0 - raised above the page; 1 - pressed onto the page */
        int penState = 0;
        for (string line; getline(input, line); ) {
            Vector<string> commands = stringSplit(line, " ");
            string command = toLowerCase(commands[0]);
            if (startsWith(command, "penup")) {
                penState = 0;
            } else if (startsWith(command, "pendown")) {
                penState = 1;
            } else if (startsWith(command, "moveabs")) {
                if (penState == 1) {
                    x1 = stringToReal(commands[1]);
                    y1 = stringToReal(commands[2]);
                    drawLine(x0, y0, x1, y1, style);
                }
                x0 = stringToReal(commands[1]);
                y0 = stringToReal(commands[2]);
            } else if (startsWith(command, "moverel")) {
                if (penState == 1) {
                    x1 = x0 + stringToReal(commands[1]);
                    y1 = y0 + stringToReal(commands[2]);
                    drawLine(x0, y0, x1, y1, style);
                }
                x0 = x0 + stringToReal(commands[1]);
                y0 = y0 + stringToReal(commands[2]);
            } else if (startsWith(command, "penwidth")) {
                style.width = stringToReal(commands[1]);
            } else if (startsWith(command, "pencolor")) {
                style.color = commands[1];
            }
        }
    }
