#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int N; //���� K����, P�辿 ����, N�� �� �� ����?
	long long K, P, answer = 0;

	cin>>K>>P>>N;

	answer = K;

	for(int i=0; i<N; i++){
		answer = (answer*P)%1000000007;
	}

	cout<<answer;

	return 0;
}