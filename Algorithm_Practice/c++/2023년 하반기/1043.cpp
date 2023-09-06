#include <iostream>
#include <vector>
#include <map>

using namespace std;

//dfs, map
//변수명을 명확하게 짓는 것이 필요할 것 같다.
int n, m, trueCnt, partyCnt, peopleCnt, peopleIdx;
vector<bool> truePeople; //true이면 과장 가능(진실 모름), false이면 과장 불가(진실 앎)
vector<bool> trueParty; //true이면 과장 가능(진실 모름), false이면 과장 불가(진실 앎)
map<int, vector<int>> personAndParty; //사람 인덱스 : 이 사람이 참여한 파티들

void dfs(int truePersonIdx, vector<vector<int>> &network){

    truePeople[truePersonIdx] = false;

    for(int i=0; i<network[truePersonIdx].size(); i++){
        if(truePeople[network[truePersonIdx][i]]){
            //cout<<"new "<<network[truePersonIdx][i]<<'\n';
            dfs(network[truePersonIdx][i], network);
        }
    }
}

int main(){
    int answer = 0;
    cin>>n>>m>>trueCnt;

    vector<vector<int>> network(n+1); //인접 사람
    truePeople.assign(n+1, true);
    trueParty.assign(m+1, true);
    vector<int> truePeopleIdx; //진실을 아는 사람 인덱스

    for(int i=0; i<trueCnt; i++){
        int idx;
        cin>>idx;
        truePeople[idx] = false; //진실 아는 사람
        truePeopleIdx.push_back(idx);
    }

    for(int i=1; i<=m; i++){
        vector<int> samePartyPeople;
        cin>>peopleCnt;
        for(int j=0; j<peopleCnt; j++){
            cin>>peopleIdx;
            //해당 사람이 참여한 파티 map으로 정리
            personAndParty[peopleIdx].push_back(i);
            samePartyPeople.push_back(peopleIdx);
        }

        for(int j=0; j<samePartyPeople.size(); j++){
            for(int k=j+1; k<samePartyPeople.size(); k++){
                network[samePartyPeople[j]].push_back(samePartyPeople[k]);
                network[samePartyPeople[k]].push_back(samePartyPeople[j]);
            }
        }
    }

    //진실을 아는 사람이 없는 경우
    if(trueCnt==0){
        cout<<m;
        return 0;
    }

    for(int i=1; i<truePeople.size(); i++){
        if(!truePeople[i]){
            dfs(i, network);
        }   
    }

    // cout<<"과장";
    // for(int i=1; i<=n; i++){
    //     cout<<truePeople[i]<<' ';
    // }
    // cout<<'\n';

   
    //     for(auto m : personAndParty){
    //         cout<<"p "<<m.first<<'\n';
    //         for(int j=0; j<m.second.size(); j++){
    //             cout<<m.second[j]<<' ';
    //         }
    //         cout<<'\n';
    //     }
        
    

    for(int i=1; i<=n; i++){
        if(!truePeople[i]){
            for(int j=0; j<personAndParty[i].size(); j++){
                trueParty[personAndParty[i][j]] = false;
            }
        }
    }

    // for(int i=1; i<=m; i++){
    //     cout<<trueParty[i]<<' ';
    // }

    // cout<<'\n';
    for(int i=1; i<=m; i++){
        if(trueParty[i]){
            answer++;
        }
    }

    cout<<answer;

    // //진실을 아는 사람이 있는 경우
    // dfs(0);

    // for(int i=0; i<m; i++){
    //     for(int j=1; j<=n; j++){

    //     }
    //     if(party[i].find())
    // }

    
}