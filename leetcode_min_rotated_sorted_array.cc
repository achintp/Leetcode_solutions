#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        
        if(size == 0){
            return 0;
        }
        int left = 0;
        int right = size - 1;
        int mid = (left + right)/2;
        
        while(left <= right){
            if(num[(mid - 1 + size)%size] >= num[mid] && num[(mid + 1)%size] >= num[mid]){
                return num[mid];
            }else{
                if(num[right] < num[mid]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
                mid  = (left + right)/2;
            }
        }
      
    }
};

int main(){
	vector<int> num;
	num.push_back();
	num.push_back();
	num.push_back();
	num.push_back();
	num.push_back();
	num.push_back();
	num.push_back();
	sol = Solution;
	cout << sol.findMin(num);
	return 0;
}