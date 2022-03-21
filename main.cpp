#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using Cell = vector<int>;

class Solution {
  struct Pos {
    int row;
    int column;

    Pos &operator+=(const Pos &pos) {
      row += pos.row;
      column += pos.column;
      return *this;
    }
  };

  bool in(int x, int start, int end) {
    return start <= x && x < end;
  }

  void drawLine(Pos &pos, Pos step, int length, int rows, int cols, vector<Cell> &out) {
    for (int i = 0; i < length; ++i, pos += step) {
      if (in(pos.row, 0, rows) && in(pos.column, 0, cols)) {
        out.push_back({pos.row, pos.column});
      }
    }
  }

 public:
  vector<Cell> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    Pos pos{rCenter, cCenter};
    vector<Cell> result{{pos.row, pos.column}};
    const Pos step_up{-1, 1}, step_right{1, 1}, step_down{1, -1}, step_left{-1, -1};
    const int N = rows + cols;
    for (int n = 1; n < N; ++n) {
      pos += {0, -1};
      drawLine(pos, step_up, n, rows, cols, result);
      drawLine(pos, step_right, n, rows, cols, result);
      drawLine(pos, step_down, n, rows, cols, result);
      drawLine(pos, step_left, n, rows, cols, result);
    }

    return result;
  }
};

void TestAllCellsDistOrder() {
  Solution s;
  {
    vector<Cell> expected{{0, 0}, {0, 1}};
    assert(expected == s.allCellsDistOrder(1, 2, 0, 0));
  }
  {
    vector<Cell> expected{{0, 1}, {0, 0}, {1, 1}, {1, 0}};
    assert(expected == s.allCellsDistOrder(2, 2, 0, 1));
  }
  {
    vector<Cell> expected{{1, 2}, {1, 1}, {0, 2}, {1, 0}, {0, 1}, {0, 0}};
    assert(expected == s.allCellsDistOrder(2, 3, 1, 2));
  }
}

int main() {
  TestAllCellsDistOrder();
  std::cout << "Ok!" << std::endl;
  return 0;
}
