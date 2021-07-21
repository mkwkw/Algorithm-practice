#include <iostream>
#include <algorithm>
#define SWAP(x,y) {int t; t=x; x=y; y=t;};
using namespace std;
//boj 10804

int main(){
	int a,b;
	int arr[21];
	int j,k;
	for(int i=1; i<=20; i++){
		arr[i]=i;
	}
	
	for(int i=0; i<10; i++){
		cin>>a>>b;
		
		//reverse(arr+a, arr+b+1);
		for(j=a;j<=(a+b)/2; j++){
			SWAP(arr[j],arr[(a+b)-j]);
		}
	}
		for(int i=1; i<=20; i++) cout<< arr[i]<<" ";
		//cout<<"\n";
	
}
