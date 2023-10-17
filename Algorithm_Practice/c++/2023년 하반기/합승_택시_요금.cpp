#include <string>
#include <vector>
#include <map>
#include <iostream>
#define INF 1000000000

using namespace std;

//최단 거리 구하기
//양방향
//s->모든 노드 최단 거리
//a->모든 노드 최단 거리
//b->모든 노드 최단 거리

map<int, int> sToAll, aToAll, bToAll;
map<int, vector<pair<int,int>>> fareMap;
void findMinFareFromS(int n, int before, int start){
    cout<<before<<' '<<start<<'\n';
    for(int i=0; i<fareMap[start].size(); i++){
        if(sToAll[fareMap[start][i].first]>=sToAll[before]+fareMap[before][i].second){
            cout<<"["<<fareMap[start][i].first<<"] = "<<sToAll[before]<<" + "<<fareMap[before][i].second<<'\n';
            sToAll[fareMap[start][i].first] = sToAll[before]+fareMap[before][i].second;
            findMinFareFromS(n, start, fareMap[start][i].first);
        }
        
    }
       
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
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
        int x = min(fares[i][0], fares[i][1]);
        int y = max(fares[i][0], fares[i][1]);
        if(x==s || y==s){
            if(x==s){
                sToAll[y] = fares[i][2];
            }
            else{
                sToAll[x] = fares[i][2];
            }
        }
        
        if(x==a || y==a){
            if(x==a){
                aToAll[y] = fares[i][2];
            }
            else{
                aToAll[x] = fares[i][2];
            }
        }
        if(x==b || y==b){
            if(x==b){
                bToAll[y] = fares[i][2];
            }
            else{
                bToAll[x] = fares[i][2];
            }
        }
    
    }
    findMinFareFromS(n, s, s);
    
    for(auto m : fareMap){
        for(int i=0; i<m.second.size(); i++)
            cout<<m.first<<' '<<m.second[i].first<<' '<<m.second[i].second<<'\n';
    }
    
    for(auto m : sToAll){
        cout<<m.first<<' '<<m.second<<'\n';
    }
    
        
    return answer;
}