// class_03 RotateMatrix

#include <iostream>
#include <vector>

using namespace std;

void rotateEdge(vector<vector<int>> &matrix, int tR, int tC, int dR, int dC) {
    int times = dC - tC;
    for (int i = 0; i < times; i++) {
        int tmp = matrix[tR][tC + i];
        matrix[tR][tC + i] = matrix[dR - i][tC];
        matrix[dR - i][tC] = matrix[dR][dC - i];
        matrix[dR][dC - i] = matrix[tR + i][dC];
        matrix[tR + i][dC] = tmp;
    }
}

void rotate(vector<vector<int>> &matrix) {
    int tR = 0;
    int tC = 0;
    int dR = matrix.size() - 1;
    int dC = matrix[0].size() - 1;
    while (tR < dR && tC < dC) rotateEdge(matrix, tR++, tC++, dR--, dC--);
}

void printMatrix(const vector<vector<int>> matrix) {
    for (const auto m : matrix) {
        for (const auto n : m) cout << n << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    printMatrix(matrix);
    rotate(matrix);
    cout << "=========" << endl;
    printMatrix(matrix);
}