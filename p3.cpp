#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;
//#boj 10825 
//구조체에 속성들 다 넣기 
struct student{
	string name;
	int kor, eng, math;
};

//정렬 기준 설정-sort함수에 사용 
bool compare(student a, student b){
	if(a.kor==b.kor&&a.eng==b.eng&&a.math==b.math) return a.name<b.name;
	if(a.kor==b.kor&&a.eng==b.eng)return a.math>b.math;
	if(a.kor==b.kor) return a.eng<b.eng;
	return a.kor>b.kor;
}

int main(){
	int n;
	
	cin>>n;
	vector<student> v(n); //student객체 벡터 느낌 
	
	for(int i=0; i<n; i++){
		cin>>v[i].name>>v[i].kor>>v[i].eng>>v[i].math;	
	}
	
	sort(v.begin(), v.end(), compare); //벡터의 처음부터 끝까지 compare기준으로 정렬 
	
	for(int i=0; i<n; i++){
		cout<<v[i].name<<"\n";
	}
		
}
