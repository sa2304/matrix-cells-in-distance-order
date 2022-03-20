#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using Cell = vector<int>;

class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    // FIXME
    return {};
  }
};

void TestAllCellsDistOrder() {
  Solution s;
  {
    vector<Cell> expected{{0, 0}, {0, 1}};
    assert(expected == s.allCellsDistOrder(1, 3, 0, 0));
  }
  {
    vector<Cell> expected{{0, 1}, {0, 0}, {1, 1}, {1, 0}};
    assert(expected == s.allCellsDistOrder(2, 2, 0, 1));
  }
  {
    vector<Cell> expected{{1, 2}, {0, 2}, {1, 1}, {0, 1}, {1, 0}, {0, 0}};
    assert(expected == s.allCellsDistOrder(2, 3, 1, 2));
  }
}

int main() {
  TestAllCellsDistOrder();
  std::cout << "Ok!" << std::endl;
  return 0;
}
