#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string printNum(int num){
        if(num == 1) return "One";
        else if(num == 2) return "Two";
        else if(num == 3) return "Three";
        else if(num == 4) return "Four";
        else if(num == 5) return "Five";
        else if(num == 6) return "Six";
        else if(num == 7) return "Seven";
        else if(num == 8) return "Eight";
        else if(num == 9) return "Nine";
        else if(num == 10) return "Ten";
        else if(num == 11) return "Eleven";
        else if(num == 12) return "Twelve";
        else if(num == 13) return "Thirteen";
        else if(num == 14) return "Fourteen";
        else if(num == 15) return "Fifteen";
        else if(num == 16) return "Sixteen";
        else if(num == 17) return "Seventeen";
        else if(num == 18) return "Eighteen";
        else if(num == 19) return "Nineteen";
        else if(num == 20) return "Twenty";
        else if(num == 30) return "Thirty";
        else if(num == 40) return "Forty";
        else if(num == 50) return "Fifty";
        else if(num == 60) return "Sixty";
        else if(num == 70) return "Seventy";
        else if(num == 80) return "Eighty";
        else if(num == 90) return "Ninety";
        else if(num == 100) return "Hundred";
        else if(num == 1000) return "Thousand";
        else if(num == 1000000) return "Million";
        else if(num == 1000000000) return "Billion";
        else return ""; // Add this line
    }
    string numberToWords(int num) {
        string res;
        if(num == 0) return "Zero";
        if(num < 20) return printNum(num);
        if(num < 100) {
            return printNum((num / 10) * 10) + " " + printNum(num % 10);
        }
        if(num < 1000) {
            return printNum(num / 100) + " Hundred " + numberToWords(num % 100);
        }
        if(num < 1000000) {
            return numberToWords(num / 1000) + " Thousand " + numberToWords(num % 1000);
        }
        if(num < 1000000000) {
            return numberToWords(num / 1000000) + " Million " + numberToWords(num % 1000000);
        }
        return numberToWords(num / 1000000000) + " Billion " + numberToWords(num % 1000000000);
    }
};

int main(){
    int num = 100000;
    Solution sol;
    cout << num <<" = "<< sol.numberToWords(num) << endl;
    return 0;
}