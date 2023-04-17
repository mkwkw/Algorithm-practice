#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	bool flag1 = true, flag2 = true; //오름차순, 내림차순 판별
	int num, prev;
	cin>>prev;
	 
	for(int i=1; i<8; i++){
		cin>>num;

		if(prev+1 != num){
			flag1 = false;
		}

		if(prev-1 != num){
			flag2 = false;
		}

		prev = num;
	}

	if(flag1){
		cout<<"ascending";
	}
	else if(flag2){
		cout<<"descending";
	}
	else if(!flag1 && !flag2){
		cout<<"mixed";
	}

	return 0;
}