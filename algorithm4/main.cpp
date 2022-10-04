#include <iostream>

using namespace std;

void showArray(int array[], int numberElements, const string &description = "") {
    cout << description << "\n";
    for (int i = 0; i < numberElements; i++) {
        cout << array[i] << ", ";
    }
    cout << "\n\n";
}

void linerSearch(const int array[], int numberElements, int numberToSearch) {
    int numberComparisons = 0;

    for (int i = 0; i < numberElements; ++i) {
        if (array[i] == numberToSearch) {
            break;
        } else {
            numberComparisons++;
        }
    }

    if (numberComparisons == numberElements) {
        cout << "No such number in array " << "\n\n";
    } else {
        cout << "Number of comparisons: " << numberComparisons << "\n\n";
    }
}

void binarySearch(const int array[], int numberElements, int numberToSearch) {
    int newArray[numberElements];

    for (int i = 0; i < numberElements; i++) {
        newArray[i] = array[i];
    }

    int len = sizeof(newArray) / sizeof(newArray[0]);
    sort(newArray, newArray + len);

    showArray(newArray, numberElements, "Sorted array");

    int low = 0;
    int high = numberElements;
    int numberComparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = newArray[mid];

        if (guess == numberToSearch) {
            cout << "Element found at " << mid << " th index" << "\n";
            cout << "Number of comparisons: " << numberComparisons;
            return;
        } else if (guess > numberToSearch) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        numberComparisons++;
    }
    cout << "Element not found" << "\n";
}

int main() {
    const int numberElements = 500;
    int numberToSearch = 435;
    int array[numberElements];

    srand((unsigned) time(0));

    for (int i = 0; i < numberElements; i++) {
        int randomNumber = (rand() % 1000) + 1;
        array[i] = randomNumber;
    }

    showArray(array, numberElements, "No sorted array");
    linerSearch(array, numberElements, numberToSearch);
    binarySearch(array, numberElements, numberToSearch);

    return 0;
}