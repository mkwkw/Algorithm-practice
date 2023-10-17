#include <string>
#include <vector>
#include <map>
#include <iostream>
#define INF 100000000

using namespace std;

//다익스트라
//dfs -> 시간 초과
//최단 거리 구하기
//양방향
//s->모든 노드 최단 거리
//a->모든 노드 최단 거리
//b->모든 노드 최단 거리

map<int, int> sToAll, aToAll, bToAll;
map<int, vector<pair<int,int>>> fareMap;
void findMinFareFromS(int n, int start){
    //cout<<before<<' '<<start<<'\n';
    for(int i=0; i<fareMap[start].size(); i++){
        if(sToAll[fareMap[start][i].first]>=sToAll[start]+fareMap[start][i].second){
            //cout<<"["<<fareMap[start][i].first<<"] = "<<sToAll[start]<<" + "<<fareMap[start][i].second<<'\n';
            sToAll[fareMap[start][i].first] = sToAll[start]+fareMap[start][i].second;
            findMinFareFromS(n, fareMap[start][i].first);
        }
        
    }
    // for(auto m : sToAll){
    //     cout<<m.first<<' '<<m.second<<'\n';
    // }
    // cout<<'\n';
       
}

void findMinFareFromA(int n, int start){
    //cout<<before<<' '<<start<<'\n';
    for(int i=0; i<fareMap[start].size(); i++){
        if(aToAll[fareMap[start][i].first]>=aToAll[start]+fareMap[start][i].second){
            //cout<<"["<<fareMap[start][i].first<<"] = "<<sToAll[start]<<" + "<<fareMap[start][i].second<<'\n';
            aToAll[fareMap[start][i].first] = aToAll[start]+fareMap[start][i].second;
            findMinFareFromA(n, fareMap[start][i].first);
        }
        
    }
    // for(auto m : sToAll){
    //     cout<<m.first<<' '<<m.second<<'\n';
    // }
    // cout<<'\n';
       
}

void findMinFareFromB(int n, int start){
    //cout<<before<<' '<<start<<'\n';
    for(int i=0; i<fareMap[start].size(); i++){
        if(bToAll[fareMap[start][i].first]>=bToAll[start]+fareMap[start][i].second){
            //cout<<"["<<fareMap[start][i].first<<"] = "<<sToAll[start]<<" + "<<fareMap[start][i].second<<'\n';
            bToAll[fareMap[start][i].first] = bToAll[start]+fareMap[start][i].second;
            findMinFareFromB(n, fareMap[start][i].first);
        }
        
    }
    // for(auto m : sToAll){
    //     cout<<m.first<<' '<<m.second<<'\n';
    // }
    // cout<<'\n';
       
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1000000001;
    
    //초기화
    //s->모든 노드 최단 거리
    for(int i=1; i<=n; i++){
        sToAll[i] = INF;    
    }
    sToAll[s] = 0;
    
    //a->모든 노드 최단 거리
    for(int i=1; i<=n; i++){
        aToAll[i] = INF;    
    }
    aToAll[a] = 0;
    
    //b->모든 노드 최단 거리
    for(int i=1; i<=n; i++){
        bToAll[i] = INF;    
    }
    bToAll[b] = 0;
    
    //fareMap
    for(int i=0; i<fares.size(); i++){
        fareMap[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        fareMap[fares[i][1]].push_back({fares[i][0], fares[i][2]});    
    }
    findMinFareFromS(n, s);
    findMinFareFromA(n, a);
    findMinFareFromB(n, b);
    
    for(int i=1; i<=n; i++){
        
        answer = min(answer, sToAll[i]+bToAll[i]+aToAll[i]);
    }
    
    // for(auto m : fareMap){
    //     for(int i=0; i<m.second.size(); i++)
    //         cout<<m.first<<' '<<m.second[i].first<<' '<<m.second[i].second<<'\n';
    // }
    
    
    
        
    return answer;
}