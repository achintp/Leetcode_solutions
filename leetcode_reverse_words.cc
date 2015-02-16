#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string str = "";
        bool moreSpace = true;
        for(auto it = s.begin(); it != s.end(); it++){
            if(*it == ' '){
                if(moreSpace){
                    continue;
                }else{
                    str += *it;
                    moreSpace = true;
                }
            }else{
                str += *it;
                moreSpace = false;
            }
        }
        
        auto at = str.rbegin();
        for(auto it = str.begin(); it != str.end(); it++, at++){
            swap(*it, *at);
        }
        
        for(auto it = str.begin(); it != str.end(); it++){
            auto runner = it;
            auto forward = it;
            while(runner != str.end()){
                runner++;
            }
            it = runner--;
            while(forward > runner){
                char temp = *forward;
                *forward =  *runner;
                *runner = temp;
                forward++;
                runner--;
            }
        }
    	cout << str << endl;    
        s = str;
    }
};

int main(){
	string s("a");
	Solution sol;
	sol.reverseWords(s);
}