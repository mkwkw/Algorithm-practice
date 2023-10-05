#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
map<string, vector<string>> startTo;
map<string, vector<bool>> visited;
//백트래킹, dfs - 방문배열 이용 - 방문체크되어있지 않은 티켓 방문 후, result의 크기와 ticketCnt 비교
void travel(string to, vector<string> result, int ticketCnt){
        
    //알파벳 순서가 앞서는 경로를 return 해야하므로, 이미 answer에 원소가 있다면 더 이상 체크x
    if(answer.size()>0){
        return;
    }
    
    result.push_back(to); //현재 지나온 공항들에 추가
    
    bool flag = true; //start에서 갈 수 있는 공항(방문하지 않은)있는지 체크하는 용도
    for(int i=0; i<startTo[to].size(); i++){
        if(visited[to][i]){
            continue;
        }

        flag = false;

        visited[to][i] = true; //방문 체크
        travel(startTo[to][i], result, ticketCnt); //다음 공항으로 이동
        visited[to][i] = false; //방문 체크 해제
    }
    
    if(flag){ //start에서 방문할 수 있는 공항이 없을 때 - 답인지 아닌지 체크
        if(result.size()==ticketCnt+1){
            answer = result;    
        }
        return;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    //[출발 공항] : {목적지1, 목적지2, ...}
    for(int i=0; i<tickets.size(); i++){
        startTo[tickets[i][0]].push_back(tickets[i][1]);
        visited[tickets[i][0]].push_back(false);
    }
    
    //가능한 경로가 2개 이상일 경우, 알파벳 순서가 앞서는 경로를 리턴해야하므로 정렬
    //m.second를 정렬한 경우, 이후에 다시 원래대로 순서가 돌아가 있는 경우가 있기에 직접 저장을 해준다.
    for(auto m : startTo){
        sort(m.second.begin(), m.second.end());
        startTo[m.first] = m.second;
    }
    
    //ICN에서 출발
    for(int i=0; i<startTo["ICN"].size(); i++){
        visited["ICN"][i] = true; //방문 체크 - ICN으로 다시 돌아올 수 있음
        travel(startTo["ICN"][i], {"ICN"}, tickets.size());
        visited["ICN"][i] = false; //방문 체크 해제
    }
    
    return answer;
}