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
vector<vector<int>> ReadBoardFile(string path) {
  std::ifstream board_file(path);
  // add empty board vector
  vector<vector<int>> board;
  if (board_file) {
    string line;
    while (getline(board_file, line)) {
        // load each line into 2D board vector
        board.push_back(ParseLine(line));
    }
  }
  return board;
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
    vector<vector<int>> board = ReadBoardFile("1.board");
    PrintBoard(board);
}
