#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int size = num.size();
        map<int, vector<vector<int> > > sums;
        
        for(int i = 0; i< size; i++){
            for(int j = i + 1; j < size; j++){
                int sum = num[i] + num[j];
                if(!sums.count(sum)){
                    vector<vector<int> > p;
                    sums[sum] = p;
                }
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                sums[sum].push_back(temp);
            }
        }
        vector<vector<int> > res;
        for(int i = 0; i < size; i++){
            if(sums.count(-1*num[i])){
                for(auto it = sums[-1*num[i]].begin(); it != sums[-1*num[i]].end(); it++){
                    if(i != (*it)[0] && i != (*it)[1]){
                        vector<int> temp(*it);
                        temp.push_back(i);
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
	vector<int> r;
	r.push_back(-1);
	r.push_back(0);
	r.push_back(1);
	r.push_back(2);
	r.push_back(-1);
	r.push_back(-4);

	Solution sol;
	vector<vector<int> > res = sol.threeSum(r);
	for(auto it = res.begin(); it != res.end(); it++){
		for(auto ti = (*it).begin(); ti != (*it).end(); ti++){
			cout << (*ti);
		}
		cout << endl;
	}
}