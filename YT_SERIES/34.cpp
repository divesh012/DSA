#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> linearSearch(int mat[][3], int rows, int cols, int key) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (mat[i][j] == key) {
        return {i, j};  // row and column
      }
    }
  }
  return {-1, -1};  // not found
}

int main() {
  int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {0, 11, 12}};  // 2d
                                                                      // array
  int key = 6;
  pair<int, int> result = linearSearch(matrix, 4, 3, key);

  if (result.first != -1) {
    cout << "Key is found at row: " << result.first
         << ",column: " << result.second << endl;
  } else {
    cout << "Key Not Found!!";
  }
  return 0;
}
// Max number Sum
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int getMaxsum(int mat[][3], int rows, int cols) {
  int maxRowSum = INT_MIN;
  for (int i = 0; i < rows; i++) {
    int rowSum = 0;
    for (int j = 0; j < cols; j++) {
      rowSum = rowSum + mat[i][j];
    }
    maxRowSum = max(maxRowSum, rowSum);
  }
  return maxRowSum;
}
int main() {
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};  // 2d array
  int rows = 3;
  int cols = 3;
  cout << getMaxsum(matrix, rows, cols) << endl;

  return 0;
}
