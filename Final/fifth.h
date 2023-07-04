//
// Created by Alex on 04.07.2023.
//

#ifndef FINAL_FIFTH_H
#define FINAL_FIFTH_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int fifth() {
    srand(time(0));

    int arr_size;
    cout << "Enter the size of the binary sequence: ";
    cin >> arr_size;

    if (arr_size <= 0) {
        cout << "Error: the size of the binary sequence must be a positive integer." << endl;
        return 1;
    }

    int* binary_arr = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        binary_arr[i] = rand() % 2;
    }


    cout << "Binary sequence: ";
    for (int i = 0; i < arr_size; i++) {
        cout << binary_arr[i];
    }
    cout << endl;


    int decimal_num = 0;
    for (int i = 0; i < arr_size; i++) {
        decimal_num += binary_arr[i] * pow(2, arr_size - i - 1);
    }


    cout << "Decimal number: " << decimal_num << endl;

    ofstream outfile("output5.txt");
    outfile << decimal_num;
    outfile.close();

    delete[] binary_arr;

    return 0;
}
#endif //FINAL_FIFTH_H
