//
//  main.cpp
//  Advent of Code Day 2
//
//  Created by Chaos Zero on 12/2/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string word;
    string char1s;
    string password1;
    string sentence;
    vector<string> sentences;
    vector<string> char1;
    vector<string> passwords;
    
    freopen("enter your txt file directory here", "r", stdin);
    
    while (cin >> word) {
        cin >> char1s >> password1;
        sentence += word + " ";
        char1s.pop_back();
        char1.push_back(char1s);
        passwords.push_back(password1);
    }
    sentence += '/';
    
    int y = 0;
    string temp;
    while (sentence.at(y) != '/') {
        if (sentence.at(y) != ' ') {
            temp += sentence.at(y);
            y+=1;
        }
        else {
            sentences.push_back(temp);
            y+=1;
            temp.clear();
        }
    }
    
    for (int i = 0; i < sentences.size(); i++) {
        replace(sentences.at(i).begin(), sentences.at(i).end(), '-', ' ');
    }
    
    vector<int> limits;
    vector<int> lowerBound;
    vector<int> upperBound;
    for (int i = 0; i < 1000; i++) {
        int n;
        stringstream stream(sentences.at(i));
        while (stream >> n) {
            limits.push_back(n);
        }
    }
    
    for (int i = 0; i < limits.size(); i+=2) {
        lowerBound.push_back(limits.at(i));
    }
    
    for (int i = 1; i < limits.size(); i+=2) {
        upperBound.push_back(limits.at(i));
    }
    
    int count = 0;
    int numValid = 0;
    
    for (int i = 0; i < passwords.size(); i++) {
        count = 0;
        for (int j = 0; j < passwords[i].length(); j++) {
            if (passwords[i][j] == char1[i][0]) {
                count++;
            }
        }
        if (count >= lowerBound.at(i) && count <= upperBound.at(i)) {
            numValid += 1;
        }
    }
    
    cout << "Part 1 answer: " << numValid << endl;
    
    // Part 2
    
    int count1 = 0;
    int numValid1= 0;
    
    for (int i = 0; i < passwords.size(); i++) {
        count1 = 0;
        if (passwords[i][lowerBound.at(i) - 1] == char1[i][0]) {
            count1++;
        }
        if (passwords[i][upperBound.at(i) - 1] == char1[i][0]) {
            count1++;
        }
        if (count1 == 1) {
            numValid1 += 1;
        }
    }
    cout << "Part 2 answer: " << numValid1;
    
    return 0;
}
