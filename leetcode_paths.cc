#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>

using namespace std;

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         return explorePath(0, 0, m, n);
//     }
    
//     int explorePath(int row, int col, const int m, const int n){
//         if(row == m-1 && col == n-1){
//             return 1;    
//         }else{
//             int r = 0, d = 0;
//             if(row + 1 < m){
//                 r = explorePath(row + 1, col, m, n);
//             }
//             if(col + 1 < n){
//                 d = explorePath(row, col + 1, m, n);
//             }
//             return r + d;
//         }
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        return explorePath(m, n);
    }
    
    int explorePath(const int m, const int n){
        vector<pair<int, int> > queue;
        queue.push_back(pair<int, int>(0, 0));
        int paths = 0;
        int counter = 0;
        while(!queue.empty()){
        	cout << ++counter << endl;
        	// cout << "Here" << endl;
            pair<int, int> current = queue.front();
            queue.erase(queue.begin());
            if(current.first == m - 1 && current.second == n - 1){
                paths++;
            }else{
                if(current.first + 1 < m){
                    queue.push_back(pair<int, int>(current.first + 1, current.second));
                }
                if(current.second + 1 < n){
                    queue.push_back(pair<int, int>(current.first, current.second + 1));
                }
            }
        }
        return paths;
    }
};

int main(int argc, char **argv){
	Solution sol;
	int t = sol.uniquePaths(atoi(argv[1]), atoi(argv[2]));
	cout << t << endl;
	return t;
}