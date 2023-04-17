#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int n, cnt = 2, answer = 0;
	cin>>n;

	for(int i=0; i<n; i++){
		cnt = cnt+(cnt-1);
		answer = cnt*cnt;
	}

	cout<<answer;

	return 0;
}