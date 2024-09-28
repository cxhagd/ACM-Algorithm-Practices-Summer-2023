#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size; 
    cin >> size;
    vector<vector<int>> square(size, vector<int>(size, 0)); 

    int row = 0, col = size / 2; 
    square[row][col] = 1;


    for (int num = 2; num <= size * size; num++) {
        int nextRow = (row == 0) ? size - 1 : row - 1;
        int nextCol = (col == size - 1) ? 0 : col + 1;

     
        if (square[nextRow][nextCol] != 0 || (row == 0 && col == size - 1)) {
            nextRow = row + 1;
            nextCol = col;
        }

        square[nextRow][nextCol] = num; 
        row = nextRow;
        col = nextCol; 
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}