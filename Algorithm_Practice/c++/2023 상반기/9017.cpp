#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int t, n;

    cin>>t;

    for(int i=0; i<t; i++){      
        vector<queue<int>> teams(201); //팀별로 순위를 큐에 저장해놓는 용도
        vector<int> ranking;
        vector<int> newRanking;
        int minSum = 4000;
        int minTeamNum = 0;
        int minTeamFive = 1000;

        cin>>n;

        ranking.assign(n, 0);
        
        for(int j=0; j<n; j++){
            cin>>ranking[j];
            teams[ranking[j]].push(j);
        }

        //선수 인원이 6명보다 적은 팀을 순위에서 빼야한다.
        //순위를 다시 매겨야한다.
        
        for(int j=0; j<201; j++){
            for(int k=0; k<n; k++){
                if(teams[j].size()<6){
                    if(ranking[k]==j){
                        ranking[k]=0;
                    } 
                }
            }

            while(!teams[j].empty()){
                teams[j].pop();
            }
        }

        for(int j=0; j<n; j++){
            if(ranking[j]!=0){
                newRanking.push_back(ranking[j]);
            }
        }

        for(int j=0; j<newRanking.size(); j++){
            teams[newRanking[j]].push(j);
        }

        for(int j=0; j<201; j++){
            int tempSum = 0;
            if(!teams[j].empty()){

                //상위 4명 순위 합
                for(int k=0; k<4; k++){
                    tempSum += teams[j].front();
                    teams[j].pop();
                }
                //우승 팀 바뀌는 경우
                if(minSum>tempSum){
                    minSum = tempSum;
                    minTeamNum = j;
                    minTeamFive = teams[j].front();
                }
                else if(minSum==tempSum){
                    if(minTeamFive>teams[j].front()){
                        minSum = tempSum;
                        minTeamNum = j;
                        minTeamFive = teams[j].front();
                    }
                }

            }
        }

        cout<<minTeamNum<<'\n';
    }
}