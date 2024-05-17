#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int printNum(vector<int> vect, int size, int index){
	if(index >= size) return 0;
	int ans = printNum(vect,size,index);
	return ((vect[index]) * (pow(10,size-1))) + ans;
}
// void solve(int num,vector<int>&vect){
// 	if(num==0)return;
// 	solve(num/10,vect);
// 	vect.push_back(num%10);
// }
// void solve(int arr[], int size, int index, vector<int>&vect){
// 	if(index>=size) return;
// 	if(arr[index]%2==0)
// 	vect.push_back(arr[index]);
// 	solve(arr,size,index+1,vect);
// }
// int solve(int n){
//     if(n>1)
//     n = n *solve(n-1);
//     return n;
// }	

int main(){
	int num=0;
	vector<int>vect;
	vect.push_back(4);
	vect.push_back(2);
	vect.push_back(1);
	vect.push_back(7);
	int size = 4;
	int index=0;
	cout<<"Hello\n";
	num = printNum(vect,size,index);
	cout<<"The ans is: "<<num;
	// solve(num,vect);
	// for(int num:vect){
	// 	cout<<num<<" ";
	// }
	// int arr[]= {11,12,13,14,25,2,3,6,8,70};
	// int size = 10;
	// int index=0;
	// vector <int> vect;
	// solve(arr,size,index,vect);
	// cout<<vect[0]<<" ";
	// cout<<vect[1]<<" ";
	// cout<<vect[2]<<" ";
	// cout<<vect[3]<<" ";
	// cout<<vect[4]<<" ";
	// cout<<vect[5]<<" ";
	// int arr[5] = {1,2,3,4,5};
	// int (*ptr)[5] = &arr;
	// cout<<(ptr)[0]<<endl;
	// cout<<(*ptr)[0]<<endl;
	// int a;
	// cin>>a;
	// cout<<"Here is the value"<<a<<endl;
	// int n;
	// cin>>n;
	// unsigned int long long  a = solve(n);
	// cout<<"Number: "<<a;
	return 0;
}