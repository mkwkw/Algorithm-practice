#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//bfs - 대체로 dfs보다 빠름
//인접 노드 리스트 사용
//최단 거리 연결 -> visited 배열 사용
int solution(int n, vector<vector<int>> edge) {
    queue<pair<int,int>> q; //노드 번호, 간선 개수    
    vector<vector<int>> adjacent(n+1); //인접 노드 리스트 - n이 2 이상 20000 이하이므로 n*n 인접행렬을 구현하기에는 너무 크다.
    vector<bool> visited;
    int answer = 0, maxEdgeCnt = 0;
    
    visited.assign(n+1, false);
    
    //양방향으로 연결된 노드 정보를 인접 리스트에 추가
    for(int i=0; i<edge.size(); i++){
        adjacent[edge[i][0]].push_back(edge[i][1]);
        adjacent[edge[i][1]].push_back(edge[i][0]);
    }
    
    //1번 노드에 직접 연결된 노드들 - 큐에 넣기
    visited[1] = true;
    for(int i=0; i<adjacent[1].size(); i++){
        q.push({adjacent[1][i], 1});
        visited[adjacent[1][i]] = true;
        maxEdgeCnt = 1;
        answer++;
    }
    
    //bfs
    while(!q.empty()){
        int node = q.front().first;
        int edgeCnt = q.front().second;
        
        //1번에서 가장 멀리 떨어진 경우
        if(maxEdgeCnt == edgeCnt){
            answer++;
        }
        else if(maxEdgeCnt < edgeCnt){
            maxEdgeCnt = edgeCnt;
            answer = 1;
        }
        
        //[이번 노드]에 연결된 노드 순회하며 방문하지 않은 노드를 큐에 넣기
        for(int i=0; i<adjacent[node].size(); i++){
            if(!visited[adjacent[node][i]]){ //최단 거리 연결 -> visited 배열 사용
                visited[adjacent[node][i]] = true;
                q.push({adjacent[node][i], edgeCnt+1}); //연결된 노드 큐에 넣기
            }
        }
        
        q.pop();
    }
    
    return answer;
}