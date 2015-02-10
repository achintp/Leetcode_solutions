#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    public:
        void push(int x) {
            if(stack.empty()){
                stack.push_back(x);
                minPos = 0;
            }else{
                stack.push_back(x);
                if(x < stack.at(minPos)){
                    minPos = stack.size() - 1;
                }
            }
        }

        void pop() {
            stack.pop_back();
            if(minPos == stack.size()){
                if(stack.empty()){
                    minPos = -1;
                    return;
                }
                int min = stack.front();
                int counter = 0;
                minPos = counter;
                for(auto it = stack.begin(); it != stack.end(); it++, counter++){
                    if(min > *it){
                        min = *it;
                        minPos = counter;
                    }
                }
                cout << "minPos is" << minPos << endl;
            }
        }

        int top() {
            int res = stack.back();
            return res;
        }

        int getMin() {
            cout << "getMin" << minPos << endl;
            int res = stack.at(minPos);
            return res;
        }

        vector<int> stack;
        int minPos;
};

int main(){

    MinStack m;
    m.push(2);
    m.push(0);
    m.push(3);
    m.push(0);

    cout << m.getMin() << m.stack.size() << endl;
    m.pop();
    cout << m.getMin() << m.stack.size() << endl;
    m.pop();
    cout << m.getMin() << m.stack.size() << endl;
    m.pop();
    cout << m.getMin() << m.stack.size() << endl;
    m.pop();
}
