#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using std::abs;

// enumerate cell states
enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream bfile(path);
  // add empty board vector
  vector<vector<State>> board{};
  if (bfile) {
    string line;
    while (getline(bfile, line)) {
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
  return abs(x1 - x2) + abs(y1 - y2);
}

/**
 * Compare the F values of two cells.
 */
bool Compare(const vector<int> node1, const vector<int> node2) {
  int f1 = node1[2] + node1[3];
  int f2 = node2[2] + node2[3];
  return f1 > f2;
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

/**
 * Verify the cell is empty and on the grid
 
bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  if (x <= grid.size() && y <= grid[1].size()) {
   return grid[x][y] == State::kEmpty; 
  }
}
*/
bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;
  return false;
}

void ExpandNeighbors(const vector<int> &current, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  //current node data
  int x = current[0];
  int y = current[1];
  int g = current[2];

  // potential neighbors to current node
  for (int i = 0; i < 4; i++) {
    // Use deltas to find potential new neighbors
    int x2 = x + delta[i][0];
    int y2 = y + delta[i][1];

    // check if neighbor is a valid cell
    if (CheckValidCell(x2, y2, grid)) {
      // increment g value
      int g2 = g + 1;
      // calculate new heuristic
      int h2 = Heuristic(x2, y2, goal[0], goal[1]);
      // add new neighbor to open vector
      AddToOpen(x2, y2, g2, h2, openlist, grid);
    }
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
      grid[x][y] = State::kFinish;
      grid[init[0]][init[1]] = State::kStart;
      return grid;
    }

    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current, goal, open, grid);
  }
  
  cout << "No path found!" << "\n";
  return vector<vector<State>>{};
}

/**
 * Format the string/output 
*/
string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦 ";
    case State::kFinish: return "🏁 ";
    default: return "0   "; 
  }
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
}
