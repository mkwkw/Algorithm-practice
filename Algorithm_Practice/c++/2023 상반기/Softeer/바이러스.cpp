#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int N; //원래 K마리, P배씩 증가, N초 후 몇 마리?
	long long K, P, answer = 0;

	cin>>K>>P>>N;

	answer = K;

	for(int i=0; i<N; i++){
		answer = (answer*P)%1000000007;
	}

	cout<<answer;

	return 0;
}