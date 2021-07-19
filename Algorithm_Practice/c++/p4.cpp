#include<iostream>
#include<algorithm>
#include<vector>
//boj #1448 통과
using namespace std;

int main(){
	int n;
	
	cin>>n;	
	vector<int> v(n);
	
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	
	//오름차순 정렬 
	sort(v.begin(), v.end());
	
	int size = v.size();
	int sum=0;
	int result=0;
	
	//제일 큰 변 3개 골라서 삼각형 조건 만족하는지 판별 
	for(int i=size-1; i>1; i--){
		int c = v[i], b=v[i-1], a=v[i-2];
		if(c<a+b) {
			sum= a+b+c;
			break;
		}
		
	}
	
	if(sum==0) result=-1; //삼각형 조건 만족하는 것 없을 때 
	else result = sum; //삼각형 조건 만족하는 것 있을 때 
	
	cout<<result;

}
