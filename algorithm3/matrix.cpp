#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void showResult(const vector<int> &arr, int m, int n, const string &description) {
    cout << description << "\n";
    for (int i = 1; i < m * n + 1; i++) {
        if (i % n == 0) {
            cout << arr[i - 1] << "\n";
        } else {
            cout << arr[i - 1] << " ";
        }
    }
    cout << "\n";
}

void deleteRow(const vector<int> &arr, int m, int n, int rowToDelete) {
    vector<int> newMatrix;

    int deleteFrom = n * rowToDelete - n;
    int deleteTo = n * rowToDelete;

    for (int i: arr) {
        newMatrix.push_back(i);
    }

    newMatrix.erase(newMatrix.begin() + deleteFrom, newMatrix.begin() + deleteTo);
    showResult(newMatrix, m - 1, n, "The resulting matrix");
}

void createMatrix(int m, int n, int k) {
    vector<int> matrix;

    srand((unsigned) time(0));

    for (int i = 0; i < m * n; i++) {
        int randomNumber = (rand() % 100) + 1;
        matrix.push_back(randomNumber);
    }

    showResult(matrix, m, n, "The input matrix");
    deleteRow(matrix, m, n, k);
}

int main() {
    createMatrix(3, 4, 2);

    return 0;
}
