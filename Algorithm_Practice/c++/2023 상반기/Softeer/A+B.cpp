#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int T, A, B;
	cin>>T;
	for(int i=0; i<T; i++){
		cin>>A>>B;
		cout<<"Case #"<<i+1<<": "<<A+B<<'\n';
	}

	return 0;
}