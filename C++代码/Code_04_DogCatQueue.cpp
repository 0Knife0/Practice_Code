// class_03 DogCatQueue
#include <iostream>
#include <vector>

using namespace std;

void printEdge(const vector<vector<int>> matrix, int tR, int tC, int dR,
               int dC) {
    if (tR == dR) {
        for (int i = tC; i <= dC; i++) cout << matrix[tR][i] << " ";
    } else if (tC == dC) {
        for (int i = tR; i <= dR; i++) cout << matrix[i][tC] << " ";
    } else {
        int curR = tR;
        int curC = tC;
        while (curC != dC) cout << matrix[curR][curC++] << " ";
        while (curR != dR) cout << matrix[curR++][curC] << " ";
        while (curC != tC) cout << matrix[curR][curC--] << " ";
        while (curR != tR) cout << matrix[curR--][curC] << " ";
    }
}

void spiralOrderPrint(const vector<vector<int>> matrix) {
    int tR = 0;
    int tC = 0;
    int dR = matrix.size() - 1;
    int dC = matrix[0].size() - 1;
    while (tR <= dR && tC <= dC) {
        printEdge(matrix, tR++, tC++, dR--, dC--);
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    spiralOrderPrint(matrix);
}