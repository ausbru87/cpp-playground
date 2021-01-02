#include <iostream>
#include <vector>
using std::cout;
using std::vector;


// TODO: Add PrintBoard function here.
void PrintBoard(const vector<vector<int>> &b) {
  for (const vector<int> &v: b) {
    for (const int &i: v) {
      cout << i;
    }
    cout << "\n";
  }
}

int main() {
    vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0}};
    PrintBoard(board);
}
