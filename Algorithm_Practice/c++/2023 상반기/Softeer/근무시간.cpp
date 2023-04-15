#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(int argc, char** argv)
{
	vector<int> work;
	string start, end;
	int answer = 0;
	work.assign(5, 0);

	for(int i=0; i<5; i++){
		cin>>start>>end;

		string startH = start.substr(0,2);
		string startM = start.substr(3,2);
		int startTime = stoi(startH)*60 + stoi(startM);

		string endH = end.substr(0,2);
		string endM = end.substr(3,2);
		int endTime = stoi(endH)*60 + stoi(endM);

		answer += (endTime-startTime);

	}

	cout<<answer;

	return 0;
}