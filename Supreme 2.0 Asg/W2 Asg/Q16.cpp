// Reverse Integer (Book-1,Pg-9)
// Leetcode Q-7

#include<limits.h>
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x){
            res = res*10 + x%10;
            x = x/10;
        }
        if(res < INT_MIN || res > INT_MAX) return 0;
        return int(res);
    }
};