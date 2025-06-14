#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here the Q was why static keyword is used in the mycomp function inside the class
// But when written outside the class, it is not required.

bool desc(const int& a, const int& b) {
    return a > b; // Sort in descending order
}

class Solution{
public:
    static bool mycomp(int a, int b) { 
        return a > b; // Sort in descending order
    }

    void sortArray(){
        vector<int> arr = {5, 2, 8, 1, 3};
    
        // Print the original array
        for(int i : arr) {
            cout << i << " ";
        }
        cout << endl;

        // Sort the array in descending order using mycomp
        // sort(arr.begin(), arr.end(), mycomp);
        sort(arr.begin(), arr.end(), desc); // Using the standalone function

        // Print the sorted array
        for(int i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    sol.sortArray();
    return 0;
}