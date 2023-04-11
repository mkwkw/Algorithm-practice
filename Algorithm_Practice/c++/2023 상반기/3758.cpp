#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team{
    int teamId;
    int totalScore;
    int submitCnt;
    int lastSubmitTime;
};

//정렬 기준 설정
bool comp(const Team &t1, const Team &t2){
    if(t1.totalScore>t2.totalScore){
        return true;
    }
    else if(t1.totalScore==t2.totalScore){
        if(t1.submitCnt<t2.submitCnt){
            return true;
        }
        else if(t1.submitCnt==t2.submitCnt){
            if(t1.lastSubmitTime<t2.lastSubmitTime){
                return true;
            }
        }
    }

    return false;
}

int main(){
    vector<vector<int>> score; //[팀id][문제번호] = 점수
    vector<Team> teams;

    int t, n, k, myTeamId, m, id, num, s;
    cin>>t;

    for(int tc=0; tc<t; tc++){

        cin>>n>>k>>myTeamId>>m;
        score.assign(n+1, vector<int>(k+1,0));
        teams.assign(n, {0,0,0,0});
        
        for(int i=0; i<n; i++){
            teams[i]={i+1,0,0,0};
        }

        for(int i=0; i<m; i++){
            cin>>id>>num>>s;

            score[id][num] = max(score[id][num], s);
            teams[id-1].lastSubmitTime = i;
            teams[id-1].submitCnt += 1;
        }

        for(int i=1; i<=n; i++){
            int teamSum = 0;
            int lastSubmitTime = 0;
            for(int j=1; j<=k; j++){
                //cout<<score[i][j]<<' ';
                teamSum += score[i][j];
                //lastSubmitTime = max(lastSubmitTime, score[i][j].second);
            }
            //cout<<'\n';
            teams[i-1].totalScore = teamSum;
            //cout<<"teamId: "<<i<<" teamSum: "<<teamSum<<" lastSubmitTime: "<<lastSubmitTime<<'\n';  
        }

        sort(teams.begin(), teams.end(), comp);

        // for(int i=0; i<n; i++){
        //     cout<<teams[i].teamId<<' '<<teams[i].totalScore<<' '<<teams[i].submitCnt<<' '<<teams[i].lastSubmitTime<<'\n';
        // }

        for(int i=0; i<n; i++){
            if(myTeamId==teams[i].teamId){
                cout<<i+1<<'\n';
                break;
            }
        }
    }

}