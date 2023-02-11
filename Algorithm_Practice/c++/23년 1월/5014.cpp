#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int>path(1000001, 0), dx(2);
vector<bool>visited(1000001, false);
queue<int> q;

//각 위치 기준으로 +u, -d 하는 두 가지 경우를 모두 따져야하고, 최소한의 계산 횟수를 구해야하므로
//방문 배열과 큐를 이용한 BFS를 이용한다.
void BFS(int f, int s, int g, int u, int d){
    visited[s] = true; //현재 위치 방문 표시
    q.push(s); //현재 위치 큐에 넣음

    while(!q.empty()){
        s = q.front(); //큐의 맨앞 원소: 현재 위치
        q.pop();
        for(int i=0; i<2; i++){
            int nextS = s+dx[i]; //+u, -1

            if(0<nextS && nextS<=f){ //범위 체크
                if(!visited[nextS]){ //방문했었는지 확인
                    visited[nextS] = true; //방문 체크
                    q.push(nextS); //미방문이었던 원소 큐에 넣기
                    path[nextS] = path[s]+1; //계산 횟수 +1
                }
            }
        }
    }
}



int main(){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;

    dx[0]=u;
    dx[1]=d*(-1);

    BFS(f,s,g,u,d);

    if(visited[g]){
        cout<<path[g];
    }
    else{
        cout<<"use the stairs";
    }
}