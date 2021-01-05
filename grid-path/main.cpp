#include <algorithm> // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::vector;

// enumerate cell states
enum class State {kEmpty, kObstacle, kClosed, kPath};

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

/** 
 * Add a node to the open list and mark it as open. 
 */
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  openlist.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}

int Heuristic(int x1, int y1, int x2, int y2) {
  return std::abs(x1 - x2) + std::abs(y1 - y2);
}

/**
 * Compare the F values of two cells.
 */
bool Compare(vector<int> node1, vector<int> node2) {
  int f1 = node1[2] + node1[3];
  int f2 = node2[2] + node2[3];
  return f1 > f2;
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  std::sort(v->begin(), v->end(), Compare);
}

/**
 * Verify the cell is empty and on the grid
 */
bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  if (x <= grid.size() && y <= grid[1].size()) {
   return grid[x][y] == State::kEmpty; 
  }
}

/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open{};
  
  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  // Use AddToOpen to add the starting node to the open vector.
  AddToOpen(x, y, g, h, open, grid);

  // while open vector is not empty
  while (open.size() > 0) {
    // Sort the open list using CellSort, and get the current node.
    CellSort(&open);
    // access last added, AddToOpen() adds to back
    auto current = open.back();
    // remove last element
    open.pop_back();
    int x = current[0];
    int y = current[1];
    grid[x][y] = State::kPath;
    if (x == goal[0] && y == goal[1]) {
      return grid;
    }
  }
  
  cout << "No path found!" << "\n";
  return vector<vector<State>>{};
}

/**
 * Format the string/output 
*/
std::string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    default: return "0   "; 
  }
}

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

int main() {
  // Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  // Call Search with "board", "init", and "goal". Store the results in the variable "solution".
  vector<vector<State>> solution = Search(board, init, goal);
  PrintBoard(solution);
}
