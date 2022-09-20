#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void showThatArr(const vector<int> &arr, const string &description) {
    cout << description << "\n";
    for (int n: arr) {
        cout << n << ", ";
    }
    cout << "\n\n";
}

void determineMinNumber(const vector<int> &arr) {
    int minNumber;

    for (int n: arr) {
        if (n >= 0 && n < minNumber) {
            minNumber = n;
        }
    }

    cout << "Min number is " << minNumber << "\n";
}

void createArrEvenNumbers(const vector<int> &arr) {
    vector<int> arrEvenNumbers;

    for (int n: arr) {
        if (n % 2 == 0) {
            arrEvenNumbers.push_back(n);
        }
    }

    showThatArr(arrEvenNumbers, "Array of even numbers");
}

void createArrRandomNumbers() {
    vector<int> arrRandomNumbers;

    srand((unsigned) time(0));
    for (int i = 0; i < 10; i++) {
        arrRandomNumbers.push_back((rand() % 240) - 140);
    }

    showThatArr(arrRandomNumbers, "Array of 10 random numbers");
    createArrEvenNumbers(arrRandomNumbers);
    determineMinNumber(arrRandomNumbers);
}

int main() {
    createArrRandomNumbers();

    return 0;
}