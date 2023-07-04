//
// Created by Alex on 04.07.2023.
//

#ifndef FINAL_SIXTH_H
#define FINAL_SIXTH_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int sixth() {
    std::ifstream infile("input.txt");
    std::ofstream outfile("output6.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        std::cout << "Error opening file(s)" << std::endl;
        return 1;
    }

    std::string text;
    std::getline(infile, text);

    std::vector<std::string> sentences;
    std::string delimiters = ".!";
    size_t start = 0;
    size_t end = text.find_first_of(delimiters);

    while (end != std::string::npos) {
        sentences.push_back(text.substr(start, end - start + 1));
        start = end + 1;
        end = text.find_first_of(delimiters, start);
    }

    if (start < text.length()) {
        sentences.push_back(text.substr(start));
    }

    for (const auto& sentence : sentences) {
        std::vector<std::string> words;
        std::string delimiter = " ";
        size_t pos = 0;
        size_t last_pos = 0;

        while ((pos = sentence.find(delimiter, last_pos)) != std::string::npos) {
            std::string word = sentence.substr(last_pos, pos - last_pos);
            words.push_back(word);
            last_pos = pos + delimiter.length();
        }

        std::string last_word = sentence.substr(last_pos);
        words.push_back(last_word);

        std::string longest_word = "";
        for (const auto& word : words) {
            if (word.length() > longest_word.length()) {
                longest_word = word;
            }
        }

        outfile << longest_word << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
#endif //FINAL_SIXTH_H
