#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n;
	
	cin>>n;	
	vector<int> v(n);
	
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	
	//�������� ���� 
	sort(v.begin(), v.end());
	
	int size = v.size();
	int sum=0;
	int result=0;
	
	//���� ū �� 3�� ��� �ﰢ�� ���� �����ϴ��� �Ǻ� 
	for(int i=size-1; i>1; i--){
		int c = v[i], b=v[i-1], a=v[i-2];
		if(c<a+b) {
			sum= a+b+c;
			break;
		}
		
	}
	
	if(sum==0) result=-1; //�ﰢ�� ���� �����ϴ� �� ���� �� 
	else result = sum; //�ﰢ�� ���� �����ϴ� �� ���� �� 
	
	cout<<result;

}
