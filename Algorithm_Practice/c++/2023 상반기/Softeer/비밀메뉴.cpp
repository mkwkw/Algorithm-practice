#include <iostream>
#include <string>


using namespace std;

int main(int argc, char** argv)
{
	int m, n, k;
	string secretNum = "", inputNum = "";
	string num;

	cin>>m>>n>>k;

	for(int i=0; i<m; i++){
		cin>>num;
		secretNum.append(num);
	}

	for(int i=0; i<n; i++){
		cin>>num;
		inputNum.append(num);
	}

	if(inputNum.find(secretNum)!=string::npos){
		cout<<"secret";
	}
	else{
		cout<<"normal";
	}

	return 0;
}