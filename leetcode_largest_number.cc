#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static bool compare(int i, int j){
		long long num_i = i;
		long long num_j = j;

		int _i = i;
		do{
			num_j *= 10;
			_i /= 10;
		}while(_i != 0);
		num_j += i;

		int _j = j;
		do{
			num_i *= 10;
			_j /= 10;
		}while(_j != 0);
		num_i += j;
		return (num_i < num_j);
	}
        
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), compare);
        string res = to_string(num.front());
        if(num.back() == 0){
            return "0";
        }
        for(auto it = num.begin() + 1; it != num.end(); it++){
        	res = to_string(*it) + res;
        	// cout << *it;
        }
        return res;
	}
};

int main(){
	vector<int> temp{3, 30, 34, 5, 9};
	Solution sol;
	cout << sol.largestNumber(temp) << endl;
	return 0;
}