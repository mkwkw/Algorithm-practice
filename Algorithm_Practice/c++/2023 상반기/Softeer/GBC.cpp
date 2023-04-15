#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int n, m, answer = 0;
	vector<pair<int, int>> speed; //力茄 加档, 角力 加档

	cin>>n>>m;

	speed.assign(100, {0,0}); //[0]: 0m~1m, [1]: 1m~2m, ... , [99]: 99m~100m

	int startPos = 0;
	for(int i=0; i<n; i++){
		int dist, limit;
		cin>>dist>>limit;

		for(int j=startPos; j<startPos+dist; j++){
			speed[j].first = limit;
		}
		
		startPos = startPos+dist;
	}

	int startPos1 = 0;
	for(int i=0; i<n; i++){
		int dist1, real;
		cin>>dist1>>real;

		for(int j=startPos1; j<startPos1+dist1; j++){
			speed[j].second = real;
		}
		
		startPos1 = startPos1+dist1;
	}

	for(int i=0; i<100; i++){
		//cout<<i<<"m limit:"<<speed[i].first<<" real: "<<speed[i].second<<'\n';
		if(speed[i].first<speed[i].second){
			answer = max(answer, speed[i].second-speed[i].first);
		}
	}

	cout<<answer;

	return 0;
}