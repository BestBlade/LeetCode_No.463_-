/* ------------------------------------------------------------------|
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

 

示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16

解释: 它的周长是下面图片中的 16 个黄色的边：

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/island-perimeter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	遍历法
*
*	执行用时：232 ms, 在所有 C++ 提交中击败了22.52%的用户
*	内存消耗：94.3 MB, 在所有 C++ 提交中击败了8.78%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> findStart(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                return { i,j };
            }
        }
    }
    return { -1,-1 };
}
int islandPerimeter(vector<vector<int>>& grid) {
    int cnt = 0;
    int adj = 0;
    int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
    int rows = grid.size() - 1;
    int cols = grid[0].size() - 1;
    
    pair<int, int> start = findStart(grid);
    stack<pair<int, int>> pointstk;
    pointstk.push(start);
    while (!pointstk.empty()) {
        pair<int, int> nowpoint = pointstk.top();
        pointstk.pop();
        if (grid[nowpoint.first][nowpoint.second] == 1) {
            grid[nowpoint.first][nowpoint.second] = 2;
            cnt++;

            for (int k = 0; k < 4; k++) {
                int dx = nowpoint.first + dir[k][0];
                int dy = nowpoint.second + dir[k][1];
                if (dx < 0 || dy < 0 || dx > rows || dy > cols) {
                    continue;
                }
                else {
                    if (grid[dx][dy] >= 1) {
                        adj++;
                        if (grid[dx][dy] == 1) {
                            pointstk.push({ dx,dy });
                        }
                    }
                }
            }
        }
    }
    return 4 * cnt -  adj;
}

int main() {
    vector<vector<int>> grid = { {1,1} };


    int res = islandPerimeter(grid);

}