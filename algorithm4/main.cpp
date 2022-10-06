#include <iostream>

using namespace std;

void showArray(int array[], int numberElements, const string &description = "") {
    cout << description << "\n";
    for (int i = 0; i < numberElements; i++) {
        cout << array[i] << ", ";
    }
    cout << "\n\n";
}

void linerSearch(const int array[], int numberElements, int numbersForSearch) {
    for (int j = 1; j < numbersForSearch + 1; ++j) {
        int numberComparisons = 1;

        for (int i = 0; i < numberElements; ++i) {
            if (array[i] == j) {
                break;
            } else {
                numberComparisons++;
            }
        }

        if (numberComparisons - 1 == numberElements) {
            cout << "Number " << j << " is not in the array" << "\n";
        } else {
            cout << "Number of comparisons for " << j << ": " << numberComparisons << "\n";
        }
    }

    cout << "\n";
}

void binarySearch(const int array[], int numberElements, int numbersForSearch) {
    int sortedArray[numberElements];

    for (int i = 0; i < numberElements; i++) {
        sortedArray[i] = array[i];
    }

    int len = sizeof(sortedArray) / sizeof(sortedArray[0]);
    sort(sortedArray, sortedArray + len);

    showArray(sortedArray, numberElements, "Sorted array");

    for (int i = 1; i < numbersForSearch + 1; ++i) {
        int low = 0;
        int high = len;
        int numberComparisons = 1;
        int isDefined = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            int guess = sortedArray[mid];

            if (guess == i) {
                cout << "Number of comparisons for " << i << ": " << numberComparisons << "\n";
                isDefined++;
                break;
            } else if (guess > i) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            numberComparisons++;
        }

        if (!isDefined) {
            cout << "Number " << i << " is not in the array" << "\n";
        }
    }
}

int main() {
    const int numberElements = 20;
    int numbersForSearch = 30;
    int array[numberElements];

    srand((unsigned) time(0));

    for (int i = 0; i < numberElements; i++) {
        int randomNumber = (rand() % 30) + 1;
        array[i] = randomNumber;
    }

    showArray(array, numberElements, "No sorted array");
    linerSearch(array, numberElements, numbersForSearch);
    binarySearch(array, numberElements, numbersForSearch);

    return 0;
}