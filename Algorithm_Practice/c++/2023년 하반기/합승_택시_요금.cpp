#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#define INF 100000000

using namespace std;

//다익스트라
//1. dfs -> 시간 초과
//2. bfs - 큐 -> 효율성 테스트 케이스 7,8만 시간초과

//최단 거리 구하기
//양방향
//s->모든 노드 최단 거리
//a->모든 노드 최단 거리
//b->모든 노드 최단 거리


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    map<int, int> sToAll, aToAll, bToAll;
    map<int, vector<pair<int,int>>> fareMap;

    int answer = 1000000001;
    queue<int> sQ, aQ, bQ; //노드 번호

    //초기화
    //s,a,b->모든 노드 최단 거리
    for(int i=1; i<=n; i++){
        sToAll[i] = INF;    
        aToAll[i] = INF;    
        bToAll[i] = INF;    
    }
    sToAll[s] = 0;
    aToAll[a] = 0;
    bToAll[b] = 0;
    
    //fareMap
    for(int i=0; i<fares.size(); i++){
        fareMap[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        fareMap[fares[i][1]].push_back({fares[i][0], fares[i][2]});    
    }
    
    aQ.push(a);
    while(!aQ.empty()){
        int num = aQ.front();
        //cout<<num<<'\n';
        for(int i=0; i<fareMap[num].size(); i++){
            if(aToAll[fareMap[num][i].first]>aToAll[num]+fareMap[num][i].second){
                aToAll[fareMap[num][i].first] = aToAll[num]+fareMap[num][i].second;
                aQ.push(fareMap[num][i].first);    
            }
        }
        
        aQ.pop();
    }
    
    bQ.push(b);
    while(!bQ.empty()){
        int num = bQ.front();
        //cout<<num<<'\n';
        for(int i=0; i<fareMap[num].size(); i++){
            if(bToAll[fareMap[num][i].first]>bToAll[num]+fareMap[num][i].second){
                bToAll[fareMap[num][i].first] = bToAll[num]+fareMap[num][i].second;
                bQ.push(fareMap[num][i].first);    
            }
        }
        
        bQ.pop();
    }
    
    sQ.push(s);
    while(!sQ.empty()){
        int num = sQ.front();
        //cout<<num<<'\n';    
        for(int i=0; i<fareMap[num].size(); i++){
            if(sToAll[fareMap[num][i].first]>sToAll[num]+fareMap[num][i].second){
                sToAll[fareMap[num][i].first] = sToAll[num]+fareMap[num][i].second;
                
                sQ.push(fareMap[num][i].first);    
            }
            answer = min(answer, sToAll[fareMap[num][i].first]+bToAll[fareMap[num][i].first]+aToAll[fareMap[num][i].first]);
        }
        
        sQ.pop();
    }
  
    // for(int i=1; i<=n; i++){    
    //     answer = min(answer, sToAll[i]+bToAll[i]+aToAll[i]);
    // }
     
    // for(auto m : sToAll){
    //     cout<<m.first<<' '<<m.second<<'\n';
    // }
    return answer;
}