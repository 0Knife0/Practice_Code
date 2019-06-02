// class_03
#include <iostream>
#include <vector>

using namespace std;

void printLevel(const vector<vector<int>> m, int tR, int tC, int dR, int dC,
                bool flag) {
    if (flag) {
        while (tR != dR + 1) cout << m[tR++][tC--] << " ";
    } else {
        while (dR != tR - 1) cout << m[dR--][dC++] << " ";
    }
}

void printMatrixZigZag(const vector<vector<int>> matrix) {
    int tR = 0;
    int tC = 0;
    int dR = 0;
    int dC = 0;
    int rSize = matrix.size() - 1;
    int cSize = matrix[0].size() - 1;
    bool flag = false;
    while (tR != rSize + 1) {
        printLevel(matrix, tR, tC, dR, dC, flag);
        tR = tC == cSize ? tR + 1 : tR;
        tC = tC == cSize ? tC : tC + 1;
        dC = dR == rSize ? dC + 1 : dC;
        dR = dR == rSize ? dR : dR + 1;
        flag = !flag;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printMatrixZigZag(matrix);
}