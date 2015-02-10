#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

using namespace std;

string count_and_say(int n){
        int counter = 1;
        string res("1");
        int count = 0;
        string say("0");

        while(counter < n){
            string temp("");
            int i = 0;
            count = 0;
            say = res[i++];
            count++;
            while(i < res.size()){
                if(say[0] == res[i]){
                    count++;
                    i++;
                }else{
                    string count_str = std::to_string(count);
                    temp = temp + count_str + say;
                    say = res[i++];
                    count = 1;
                }
            }
            if(count > 0){
                string count_str = to_string(count);
                temp = temp + count_str + say;
            }
            res = temp;
            counter++;
        }
        return res;
    }

int main(int argc, char **argv){

    cout << count_and_say(atoi(argv[1])) << endl;

}



