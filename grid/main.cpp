#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout;
using std::string;
using std::vector;
using std::istringstream;

// TODO: Add the ParseLine function here.
vector<int> ParseLine(string line) {
    istringstream line_stream(line);
    vector<int> v;
    int n;
    char c;
    while (line_stream >> n >> c) {
        v.push_back(n);
    }
    return v;
}

// TODO: Add the ReadBoardFile function here.
void ReadBoardFile(string path) {
  std::ifstream board_file(path);
  if (board_file) {
    string line;
    while (getline(board_file, line)) {
    	cout << line << "\n";
    }
  }
}


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
    ReadBoardFile("1.board");
    PrintBoard(board);
}
