#include<iostream>


using namespace std;

int main(int argc, char** argv)
{

	int A, B;
	cin>>A>>B;

	if(A==B){
		cout<<"same";
	}
	else if(A<B){
		cout<<"B";
	}
	else{
		cout<<"A";
	}
	
	return 0;
}