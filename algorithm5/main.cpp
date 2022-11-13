#include <iostream>

using namespace std;

void printArray(int *arr, int n, const string &description) {
    cout << description << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << "\n\n";
}

int *bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
    return array;
}

int *shellSort(int array[], int numberElements) {
    for (int gap = numberElements / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < numberElements; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];
            array[j] = temp;
        }
    }
    return array;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

int *hoareSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        hoareSort(arr, low, pi);
        hoareSort(arr, pi + 1, high);
    }
    return arr;
}

int *generateArray() {
    const int numberElements = 1000;
    static int array[numberElements];

    srand((unsigned) time(0));
    for (int i = 0; i < numberElements; ++i) {
        array[i] = (rand() % 1000) + 1;
    }

    return array;
}

int main() {
    const int numberElements = 1000;
    int *array = generateArray();
    printArray(array, numberElements, "No sorted array: ");

    int *shellSorted = shellSort(array, numberElements);
    printArray(shellSorted, numberElements, "Shell sorted array:");

    int *array1 = generateArray();

    int *bobbleSorted = bubbleSort(array1, numberElements);
    printArray(bobbleSorted, numberElements, "Bobble sorted array: ");

    int *array2 = generateArray();

    int *hoareSorted = hoareSort(array2, 0, numberElements - 1);
    printArray(hoareSorted, numberElements, "Hoare sorted array: ");
    return 0;
}