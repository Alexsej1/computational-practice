//
// Created by Alex on 04.07.2023.
//

#ifndef FINAL_NINTH_H
#define FINAL_NINTH_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

const int N = 20;
const char* DESCRIPTIONS[] = { "text1","text2","text3","text4","text5","text6" };
const char* DISEASE[] = { "Flu","ARI","Cancer","Tonsillitis","HIV","Measles" };
const char* NAMES[] = { "Ats","Paracetamol","Penicillin","Hematogen","Activated Carbon" };

struct Medicine {
    string name;
    string description;
    int price = 0;
    string disease;
};

void initMedicine(Medicine& a) {
    a.name = NAMES[rand() % 5];
    a.description = DESCRIPTIONS[rand() % 6];
    a.disease = DISEASE[rand() % 6];
    a.price = 100 + rand() % 900;
}

void print(const Medicine& a) {
    cout << "Medicine Name: " << a.name << endl;
    cout << "Disease Name: " << a.disease << endl;
    cout << "Indications: " << a.description << endl;
    cout << "Price: " << a.price << endl;
    cout << endl;
}

int ninth() {
    setlocale(LC_ALL, "en_US.UTF-8");
    srand(time(NULL));
    Medicine medicine[N];
    for (int i = 0; i < N; i++) {
        initMedicine(medicine[i]);
    }
    string filename = "output.bin";
    for (int i = 0; i < N; i++) {
        print(medicine[i]);
    }
    cout << "--------------Medicines for Flu and ARI--------------\n";
    ofstream fout(filename, ios::binary);
    if (!fout.is_open()) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }
    fout.write(reinterpret_cast<const char*>(medicine), sizeof(medicine));
    fout.close();
    ifstream fin(filename, ios::binary);
    if (!fin.is_open()) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }
    Medicine m[N];
    fin.read(reinterpret_cast<char*>(m), sizeof(m));
    fin.close();
    for (int i = 0; i < N; i++) {
        if (m[i].disease == "ARI" || m[i].disease == "Flu") {
            print(m[i]);
        }
    }
    return 0;
}
#endif //FINAL_NINTH_H
