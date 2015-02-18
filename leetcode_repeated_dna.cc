#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

class Solution{
public:
	vector<string> findRepeatedDnaSequences(string s){
		vector<string> res;
		if(s.length() <= 10){
			return res;
		}
		unordered_map<bitset<20>, bool> seen;
		for(auto it = s.begin(); it != s.end() - 10; it++){
			string temp(it, it + 10);
			bitset<20> b_temp= set_bits(temp);
			if(seen.count(b_temp)){
				if(seen[b_temp]){
					continue;
				}else{
					res.push_back(temp);
					seen[b_temp] = true;
				}
			}else{
				seen[b_temp] = false;
			}
		}
		return res;
	}

	bitset<20> set_bits(string s){
		bitset<20> res;
		for(int it = 0; it < 10; it++){
			if(s[it] == 'A'){
				res[2*it] = 0;
				res[2*it + 1] = 0;
			}
			if(s[it] == 'T'){
				res[2*it] = 0;
				res[2*it + 1] = 1;
			}
			if(s[it] == 'G'){
				res[2*it] = 1;
				res[2*it + 1] = 0;
			}
			if(s[it] == 'C'){
				res[2*it] = 1;
				res[2*it + 1] = 1;
			}
		}
		return res;
	}
};

int main(){
	string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	Solution sol;
	vector<string> t = sol.findRepeatedDnaSequences(s);
	for(string i: t){
		cout << i << endl;
	}
	return 0;
}