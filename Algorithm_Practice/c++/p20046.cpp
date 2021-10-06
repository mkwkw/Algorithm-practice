#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int row;
    int col;
    int cost;
};
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.cost > b.cost;
    }
};

priority_queue<Node, vector<Node>, cmp> pq; //다익스트라 구현할 우선순위 큐
vector<pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0}};//상,하,좌,우
vector<vector<int>> v;
vector<vector<bool>> visited;

int routeChecking(vector<vector<int>> &v, int n, int m){
    //맨 왼쪽 위 -1 또는 맨 오른쪽 아래 -1 -> 불가능
    if(v[0][0]==-1 || v[n-1][m-1]==-1)
        return -1;

    //하나의 열 또는 하나의 행 전체가 -1 -> 불가능
    //하나의 행 체크
    bool check1;
    for(int i=0; i<n; i++){
        check1=false;
        for(int j=0; j<m; j++){
            if(v[i][j]!=-1){
                check1=true;
                break;
            }
        }
        if(!check1)
            break;
    }
    //cout<<check1<<'\n';
    if(!check1){
        return -1;
    }
    //하나의 열 체크
    bool check2;
    for(int i=0; i<m; i++){
        check2=false;
        for(int j=0; j<n; j++){
            if(v[j][i]!=-1){
                check2=true;
                break;
            }
        }
        if(!check2)
            break;
    }
    //cout<<check2<<'\n';
    if(!check2){
        return -1;
    }

    return 1; //가능
}
/*다익스트라-나중에 방문한 노드의 간선의 가중치가 더 작을 수 있기 때문에 우선순위 큐 이용
 * 우선순위 큐에 노드와 비용을 묶어서 저장
 * 1. 출발 노드 설정
 * 2. 출발 노드를 기준으로 각 노드의 최소 비용 저장
 * 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드 선택
 * 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용 갱신
 * 5. 3-4번 반복 - 우선순위 큐에서는 가장 비용이 적은 노드 선택하는 것과 최소 비용 갱신하는 것을 빠르게 할 수 있다.
*/

int routeFinding(vector<vector<bool>> &visited, int n, int m){
    while(!pq.empty()){
        Node node = pq.top(); //출발 노드 설정 - 우선순위 큐에서 top노드
        int row = node.row;
        int col = node.col;
        int cost = node.cost;

        if(row==n-1 && col==m-1)
            return cost;

        pq.pop(); //우선순위 큐에서 pop
        visited[row][col]=true; //pq의 top노드 방문함 체크
        for(int i=0; i<4; i++){
            int nrow = row + dir[i].first; //이동할 행
            int ncol = col + dir[i].second; //이동할 열

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){ //이동 시, 범위 초과 안하는지 확인
                if(v[nrow][ncol]!=-1 && !visited[nrow][ncol]) //이동 가능한지, 방문하지 않은 노드인지 확인하고
                    pq.push({nrow, ncol, cost+v[nrow][ncol]});
                //우선순위 큐에 삽입 - 자동으로 비용이 최소인 노드를 top에 배치해준다. -최솟값 갱신
            }
        }
    }
    return -1; //사방이 -1로 둘러싸여있으면 불가능하다. 이런 경우 return
}
int main(){
    int n,m;
    cin>>n>>m;
    v.assign(n,vector<int>(m,0));
    visited.assign(n,vector<bool>(m,false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    int answer = routeChecking(v,n,m); //일단 간단한 경우 예외 처리
    if(answer==-1) {
        cout << answer;
        return 0;
    }
    else{
        pq.push({0,0,v[0][0]}); //우선순위 큐에 시작 노드 push
        cout<<routeFinding(visited, n,m); //최소 비용 찾기, 불가능하다면 -1 출력
    }
    return 0;
}