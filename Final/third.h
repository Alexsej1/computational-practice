//
// Created by Alex on 04.07.2023.
//

#ifndef FINAL_THIRD_H
#define FINAL_THIRD_H
#include <iostream>
#include <cmath>

using namespace std;
//Я пытался вынести схожие вычисления в функции, но код стал только длиннее, так как каждая точка имеет свои координаты и для вычисления в зависимости от изначального угла используются разные входные данные и из-за этого намного больше строчек, но если нужно могу добавить
int third() {
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter the coordinates of the triangle vertices (x1 y1 x2 y2 x3 y3):";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)) {
        cout << "Error: Two or more vertices have the same coordinates. And it's not a triangle anymore" << endl;
        return 1;
    }
    int vertex;
    cout << "Select a vertex (1, 2, or 3) from which the median, bisector, and height will come out:";
    cin >> vertex;
    double x_vertex, y_vertex;

    switch (vertex) {
        case 1:
            x_vertex = x1;
            y_vertex = y1;
            break;
        case 2:
            x_vertex = x2;
            y_vertex = y2;
            break;
        case 3:
            x_vertex = x3;
            y_vertex = y3;
            break;
        default:
            cout << "Error: incorrect vertex selection.";
            return 1;
    }
    double a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double d, x_bisector, y_bisector, x_height, y_height, k1, k2,b1,b2,x_median, y_median;
    if(vertex == 1){
        x_median = (x3+x2)/2;
        y_median = (y3+y2)/2;

        d = b/c;
        x_bisector = (x3 + d*x2)/(1+d);
        y_bisector = (y3 + d*y2)/(1+d);

        k1 = (y2-y3)/(x2-x3);
        b1 = y2-k1*x2;
        k2 = -1/k1;
        b2 = y1-x1*k2;
        x_height = (b2-b1)/(k1-k2);
        y_height = k1*x_height + b1;
    } else if(vertex == 2 ){
        x_median = (x3+x1)/2;
        y_median = (y3+y1)/2;

        d = c/a;
        x_bisector = (x1 + d*x3)/(1+d);
        y_bisector = (y1 + d*y3)/(1+d);

        k1 = (y1-y3)/(x1-x3);
        b1 = y1-k1*x1;
        k2 = -1/k1;
        b2 = y2-x2*k2;
        x_height = (b2-b1)/(k1-k2);
        y_height = k1*x_height + b1;
    } else{
        x_median = (x1+x2)/2;
        y_median = (y1+y2)/2;

        d = b/a;
        x_bisector = (x1 + d*x2)/(1+d);
        y_bisector = (y1 + d*y2)/(1+d);

        k1 = (y1-y2)/(x1-x2);
        b1 = y1-k1*x1;
        k2 = -1/k1;
        b2 = y3-x3*k2;
        x_height = (b2-b1)/(k1-k2);
        y_height = k1*x_height + b1;
    }
    cout << "Coordinates of the beginning of the median: (" << x_vertex << "," << y_vertex << ")" << endl;
    cout << "Coordinates of the end of the median:(" << x_median << "," << y_median << ")" << endl;
    cout << "Coordinates of the beginning of the bisector: (" << x_vertex << "," << y_vertex << ")" << endl;
    cout << "Coordinates of the end of the bisector: (" << x_bisector << "," << y_bisector << ")" << endl;
    cout << "Coordinates of the beginning of the height:(" << x_vertex << "," << y_vertex << ")" << endl;
    cout << "Coordinates of the end of the height:(" << x_height << "," << y_height << ")" << endl;

    return 0;
}
#endif //FINAL_THIRD_H
