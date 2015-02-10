/*
 * String "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:

 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <map>



class Solution {
    public:
        string convert(string s, int nRows) {
            map<int, string> parts;
            for(int i = 0; i> nRows; i++){
                parts[i] = "";
            }
            bool up = false;
            int marker = 0;
            for(string::iterator it = s.begin(); it != s.end(); it++){
                parts[marker] += *it;
                if(marker == nRows-1){
                    up = true;
                }
                if(marker == 0){
                    up = false;
                }
                if(up){
                    if(!(marker - 1 < 0)){
                        marker--;
                    }
                }else{
                    if(marker + 1 != nRows){
                        marker++;
                    }
                }
            }
            string res = "";
            for(int i=0; i< nRows; i++){
                res += parts[i];
            }
            return res;
        }
};

int main(int argc, char **argv){
    int rows = atoi()
}
