/*
 * Given an integer n, return the number of trailing zeroes in n!.

 * Note: Your solution should be in logarithmic time complexity.
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int trailingZeros(int n){
    int zeros = 0;
    int power = 1;
    while(1){
        int fives = n/pow(5, power++);
        if(fives){
            zeros += fives;
        }else{
            return zeros;
        }
    }
}

int main(int argc, char **argv){
    int n = atoi(argv[1]);
    cout << trailingZeros(n) << endl;
    return 0;
}




