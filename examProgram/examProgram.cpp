#include <iostream>

using namespace std;

int getNumberOfOddElements(int firstNumber, int secondNumber) {
    int numberOfOddElements = 0;
    for (int i = firstNumber + 1; i < secondNumber; ++i) {
        if (i % 2 != 0) numberOfOddElements++;
    }
    return numberOfOddElements;
}

int main() {
    int firstNumber = 1000;
    int secondNumber = 10000;
    cout << getNumberOfOddElements(firstNumber, secondNumber);
    return 0;
}