#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//bfs, 다익스트라
//1. 자기 자신도 정답에 포함시켜야한다.
//2. n의 개수가 50이하로 충분히 작으므로 인접 행렬로 구현 - 1000000000으로 초기화
//2+. 1번 마을과 연결된 마을 큐에 넣기
//3. 1번 마을에서 i번 마을까지 가는 경로가 새로 생긴 경우(k시간 이하), 원래 있었는데 더 적은 시간이 걸리는 경로(k시간 이하)가 생긴 경우 - 값 갱신 & 큐에 넣기
//  adjacent[1][i] = min(adjacent[1][i], adjacent[1][node]+adjacent[node][i]);
//4. 1번 마을과 연결된 마을 중 걸리는 시간이 k시간 이하인 경우만 개수 세기

struct Node{
    int beforeNode; //이전 노드
    int node; //현재 노드
    int time; //1~node까지의 시간
};

int solution(int n, vector<vector<int>> road, int k) {
    vector<vector<int>> adjacent; //인접 행렬 - n이 50이하이므로 충분히 작음
    queue<Node> q; //마을 번호, 시간
    int answer = 0;
    
    //마을이 1개만 주어질 때
    if(n==1){
        return 1;
    }
    
    adjacent.assign(n+1, vector<int>(n+1, 1000000000)); //인접행렬은 1000000000으로 초기화
    
    //자기 자신 - 갈 수 있는 마을에 포함됨.
    for(int i=1; i<=n; i++){
        adjacent[i][i] = 0;
    }
    
    //인접 행렬
    for(int i=0; i<road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int time = road[i][2];
        
        adjacent[a][b] = min(adjacent[a][b], time);
        adjacent[b][a] = min(adjacent[b][a], time);
    }
    
    //1번 마을과 연결된 마을
    for(int i=2; i<=n; i++){
        if(adjacent[1][i]<=k){
            q.push({1,i,adjacent[1][i]});
        }
    }
    
    while(!q.empty()){
        int beforeNode = q.front().beforeNode; //이전 노드
        int node = q.front().node; //현재 노드
        int time = q.front().time; //1~node까지의 시간
        
        for(int i=1; i<=n; i++){
            //되돌아가는 것X, 자기 자신 노드X, 1~i노드까지 걸리는 시간<=k인 경우
            if(i!=beforeNode && i!=node && time+adjacent[node][i]<=k){
                //1~i까지 가는 새로운 경로를 탐색한 경우 || 이미 경로가 있지만 더 적은 시간으로 걸리는 경로를 찾은 경우
                if(adjacent[1][i]==1000000000 || adjacent[1][i]<1000000000&&adjacent[1][i]>time+adjacent[node][i]){
                    adjacent[1][i] = time+adjacent[node][i]; //최소 시간 갱신
                    q.push({node, i, adjacent[1][i]});
                }
            }
        }
        
        q.pop();
    }
    
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<adjacent[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    //1번 마을에서 가는 시간이 k이하인 마을 개수 세기
    for(int i=1; i<=n; i++){
        if(adjacent[1][i]<=k){
            answer++;
        }
    }

    return answer;
}