#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int numDistinct(string s, string t) {
        unsigned long long int nums_subs = pow(2,s.size()),count = 0, n=0;
        for(n=0; n<nums_subs; n++){
            string out;
            unsigned long long int num = n, i=0;
            while(num){
                int b=(num&1);
                if(b) out.push_back(s[i]);
                i++;
                num >>=1;
            }
            if(out==t) count ++;
        }
        return int(count);
    }
int main()
{
    string s ="bccbcdcabadab";
    string t ="bccbbdc";
    int n = numDistinct(s,t);
    cout << n;
    return 0;
}
