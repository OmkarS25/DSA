// Print all Prime no.s from 1 to N. (Book-1,Pg-9)

#include<iostream>
#include<vector>
using namespace std;

// Sieve of Eratosthenes
void checkPrime(vector<bool>& list, int n){
    list[0] = list[1] = false;
    for(int i=2; i<=n; i++){
        if(list[i]){
            for(int j=i+i; j<=n; j+=i){
                list[j] = false;
            }
        }
    }
}

//Normal Method
bool checkPrime(int n){
    if(n==0 || n==1) return false;
    for(int i=2; i<=n/2/*also can use sqrt(n)*/; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void printPrimeList(int n){
    vector<bool> primeList(n+1, true);
    cout<<"List of Prime's: ";
    checkPrime(primeList, n);
    // Sieve List
    // for(int i=1; i<=n; i++){
    //     if(primeList[i]){
    //         cout<<i<<" ";
    //     }
    // }
    //cout<<"\n\n\n\n";
    // Normal List
    for(int i=1; i<=n; i++){
        if(checkPrime(i)){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n = 10;
    printPrimeList(n);

    return 0;
}