//
//  main.cpp
//  Advent of Code
//
//  Created by Chaos Zero on 12/1/20.
//

#include <iostream>
#include <vector>
using namespace std;



int main() {
    int sum = 2020;
    int value;
    vector<int> vect1;
    freopen("some input file directory", "r", stdin);
    int input;
    while (cin >> input) {
        vect1.push_back(input);
    }
    for (int i = 0; i < vect1.size(); i++) {
        for (int j = i + 1; j < vect1.size(); j++) {
            for (int k = j + 1; k < vect1.size(); k++) {
                if (vect1[i] + vect1[j] + vect1[k] == sum) {
                    value = vect1[i] * vect1[j] * vect1[k];
                }
                else continue;
            }
        }
    }
    cout << value;
    return 0;
}
