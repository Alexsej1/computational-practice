//
// Created by Alex on 04.07.2023.
//

#ifndef FINAL_FIRST_H
#define FINAL_FIRST_H


#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int first() {
    float time, bacteria = 1;

    cout << "Number of minutes: ";
    cin >> time;
    if (time <= 0) {
        cout << "Error: The entered time must be greater than zero" << endl;
        return 1;
    }

    int full_minutes = floor(time);
    for (int i = 0; i < full_minutes; i++) {
        bacteria *= 2;
    }


    cout <<"After " << time << " minit: " << bacteria <<" bacteria"<< endl;

    ofstream output_file("output.txt");
    if (output_file.is_open()) {
        output_file << bacteria << endl;
        output_file.close();
        cout << "The results are recorded in a file output.txt" << endl;
    } else {
        cout << "Failed to write the results to a file" << endl;
    }

    return 0;
}
#endif //FINAL_FIRST_H
