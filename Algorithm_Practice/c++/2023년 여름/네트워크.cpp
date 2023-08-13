#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> networkHead; //network로 연결된 곳 중 가장 작은 노드를 가리키도록 하기

//dfs
//첫 번째 행부터 computers 배열 탐색하면서 1인 좌표 찾기
//1인 좌표의 컬럼의 networkHead가 row보다 작으면 갱신
//1인 좌표의 컬럼을 행으로 탐색 ([][c] -> [c][])
//쭉쭉 탐색하면서 computers 배열에서 1인 좌표 찾으면서 반복
void dfs(int r, int c, int head, vector<vector<int>> &computers){
    //cout<<"dfs"<<' '<<r<<' '<<c<<' '<<head<<'\n';
    if(head<networkHead[c]){
        networkHead[c] = head;
    }
    
    for(int j=0; j<computers.size(); j++){
        if(computers[c][j]==1 && head<networkHead[j]){
            networkHead[j] = head;
            dfs(c, j, head, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    set<int> networkNum;
    
    networkHead.assign(n,-1);
    
    //networkHead 초기값 설정
    for(int i=0; i<n; i++){
        networkHead[i] = i;
    }
    
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<n; j++){
            
            if(computers[i][j]==1  && i<j){
                //cout<<"dfs"<<' '<<i<<' '<<j<<' '<<i<<'\n';
                dfs(i, j, i, computers);
            }
        }
    }
   
    
    for(int i=0; i<n; i++){
        //cout<<networkHead[i]<<' ';
        networkNum.insert(networkHead[i]);
        
    }
    answer = networkNum.size();
    return answer;
}