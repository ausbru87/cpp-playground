#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout;
using std::vector;

// enumerate cell states
enum class State {kEmpty, kObstacle};

// TODO: Add the ParseLine function here.
vector<State> ParseLine(std::string line) {
    std::istringstream line_stream(line);
    vector<State> row;
    int n;
    char c;
    while (line_stream >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

// TODO: Add the ReadBoardFile function here.
vector<vector<State>> ReadBoardFile(std::string path) {
  std::ifstream board_file(path);
  // add empty board vector
  vector<vector<State>> board{};
  if (board_file) {
    std::string line;
    while (getline(board_file, line)) {
        // load each line into 2D board vector
        vector<State> row = ParseLine(line);
        board.push_back(row);
    }
  }
  return board;
}

// TODO: Write the Search function stub here.
vector<vector<State>> Search(vector<vector<State>> board, int init[2], int goal[2]) {
  vector<vector<State>> path{};
  cout << "No path found!" << "\n";
  return path;
}

std::string CellString(State cell) {
  switch(cell) {
    case State::kObstacle : return "⛰️   ";
    default : return "0   ";
  }
}


// TODO: Add PrintBoard function here.
void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      // TODO: Modify the line below to call CellString
      // on each element of the board before streaming to cout.
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}
/*
void PrintBoard(const vector<vector<int>> &b) {
  for (const vector<State> &v: b) {
    for (const int &i: v) {
      cout << CellString(i);
    }
    cout << "\n";
  }
}
*/

int main() {
  // TODO: Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
  vector<vector<State>> solution = Search(board, init, goal);
  // TODO: Change the following line to pass "solution" to PrintBoard.
  PrintBoard(solution);
}
