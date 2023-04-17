#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	map<string, int> roomNameAndNum; //회의실 이름, 인덱스
	map<int, string> time;
	vector<string> roomName;
	vector<vector<bool>> available;

	int n, m;

	cin>>n>>m;

	roomName.assign(n, " ");
	available.assign(n, vector<bool>(9,true));

	time[0] = "09-10";
	time[1] = "10-11";
	time[2] = "11-12";
	time[3] = "12-13";
	time[4] = "13-14";
	time[5] = "14-15";
	time[6] = "15-16";
	time[7] = "16-17";
	time[8] = "17-18";

	for(int i=0; i<n; i++){
		cin>>roomName[i];
	}

	sort(roomName.begin(), roomName.end());

	for(int i=0; i<n; i++){
		roomNameAndNum[roomName[i]] = i;
	}

	for(int i=0; i<m; i++){
		string room;
		int startTime, endTime;

		cin>>room>>startTime>>endTime;

		for(int j=startTime; j<endTime; j++){
			available[roomNameAndNum[room]][j-9] = false;
		}
	}

	for(int i=0; i<n; i++){
		bool flag = false; //빈 시간대 구간
		int cnt = 0;
		string availableTime = "";
		vector<string> availableTimeVec;

		//연속된 회의실 사용 시간 flag로 판별
		for(int j=0; j<9; j++){
			if(available[i][j]){

				if(!flag){
					cnt++;
					availableTime = time[j].substr(0,3);

					if(j==8){
						availableTime = time[8];
						availableTimeVec.push_back(availableTime);
						//cout<<roomName[i]<<' '<<availableTime<<'\n';
					}
				}
				
				if(j==8 && flag){
					availableTime.append(time[8].substr(3));
					availableTimeVec.push_back(availableTime);
					//cout<<roomName[i]<<' '<<availableTime<<'\n';
				}
				flag = true;
				
				//cout<<roomName[i]<<' '<<time[j]<<' ';

			}
			else{
				if(flag){
					availableTime.append(time[j-1].substr(3));
					availableTimeVec.push_back(availableTime);
					//cout<<roomName[i]<<' '<<availableTime<<'\n';
				}
				flag = false;
			}

			
		}
		cout<<"Room "<<roomName[i]<<":\n";

		if(availableTimeVec.size()==0){
			cout<<"Not available\n";	
		}
		else{
			cout<<availableTimeVec.size()<<" available:\n";
		}

		for(int j=0; j<availableTimeVec.size(); j++){
			cout<<availableTimeVec[j]<<'\n';
		}

		if(i<n-1){
			cout<<"-----\n";
		}
	}

	return 0;
}