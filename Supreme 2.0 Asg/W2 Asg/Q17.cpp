// Set the Kth bit (Book-1,Pg-9)
// GFG Q

class Solution{
public:
    int setKthBit(int N, int K){
        int num = 1;
        while(K){
            num = num << 1;
            K--;
        }
        return (N | num);
    }
};