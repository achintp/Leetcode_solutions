#include <iostream>
#include <math.h>
#include <vector>
#include <string>

struct rc_pair {
	int row;
	int col;
	rc_pair(int r, int c): row(r), col(c){};
};

using namespace std;

class Solution{
public:
	bool exist(vector<vector<char> > grid, string word){
		int rows = grid.size();
		int cols = grid[0].size();

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				// cout << grid[i][j] << endl;
				if(_find(i, j, grid, rows, cols, word)){
					return true;
				}
			}
		}
		return false;
	}

private:
	bool _find(int m, int n, vector<vector<char> > &grid, int rows, int cols, string &match){
		vector<rc_pair> stack;
		vector<vector<bool> > visited;
		for(auto outer = grid.begin(); outer != grid.end(); outer++){
			vector<bool> temp;
			for(auto inner = (*outer).begin(); inner != (*outer).end(); inner++){
				temp.push_back(false);
			}
			visited.push_back(temp);
		}
		int string_counter = 0;
		rc_pair first(m, n);
		stack.push_back(first);
		while(!stack.empty()){
			rc_pair current = stack.back();
			stack.pop_back();
			visited[current.row][current.col] = true;
			if(match[string_counter] == grid[current.row][current.col]){
				cout << grid[current.row][current.col] << endl;
				string_counter++;
				if(string_counter == match.length()){
					return true;
				}
				if(current.row - 1 >=0){
					if(!visited[current.row - 1][current.col]){
						rc_pair temp(current.row - 1, current.col);
						stack.push_back(temp);
					}	
				}
				if(current.row + 1 > rows){
					if(!visited[current.row + 1][current.col]){
						rc_pair temp(current.row + 1, current.col);
						stack.push_back(temp);
					}
				}
				if(current.col - 1 >= 0){
					if(!visited[current.row][current.col - 1]){
						rc_pair temp(current.row, current.col - 1);
						stack.push_back(temp);
					}
				}
				if(current.col + 1 < cols){
					if(!visited[current.row][current.col + 1]){
						rc_pair temp(current.row, current.col + 1);
						stack.push_back(temp);
					}
				}
				continue;
			}else{
				visited[current.row][current.col] = false;
				continue;
			}
		}
		return false;
	}
};

int main(){
	vector<vector<char> > grid;
	vector<char> temp;
	temp.push_back('A');
	temp.push_back('B');
	temp.push_back('C');
	temp.push_back('E');
	grid.push_back(temp);
	vector<char> temp2;
	temp2.push_back('S');
	temp2.push_back('F');
	temp2.push_back('C');
	temp2.push_back('S');
	grid.push_back(temp2);
	vector<char> temp3;
	temp3.push_back('A');
	temp3.push_back('D');
	temp3.push_back('E');
	temp3.push_back('E');
	grid.push_back(temp3);

	string match("ABCCED");

	Solution sol;
	if(sol.exist(grid, match)){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}

	return 0;
}