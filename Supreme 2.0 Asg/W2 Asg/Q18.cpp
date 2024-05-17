// Convert the Temperature (Book-1,Pg-10)
// Leetcode Q-2469

#include<vector>
using namespace std;
class Solution {
public:
    vector<double> convertTemperature(double c) {
        return {c + 273.15, c * 1.80 + 32.00};
    }
};