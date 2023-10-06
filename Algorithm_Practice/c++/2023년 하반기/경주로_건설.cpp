#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//bfs
//주의! 경로 유무를 찾거나 최단 "거리"를 찾는 것이 목적이 아니므로, visited배열은 쓸 수 없다. - 쓰려면 3차원배열로 사용해야함
//visited 대신 최소 비용을 저장하는 2차원 배열을 선언
//주의! 한 곳에서 직선으로 나가고, 코너로 나가는 경우가 있다.
//1 0 0
//0 0 1
//1 0 출구
//- 최소 비용 하나만 저장하는 것도 안된다. - 코너와 직선도로의 비용이 다르기 때문에 들어올 때의 비용이 더 커도 직선으로 나가는 것이 꺾어서 나가는 것보다 비용이 작을 수 있다.
//- 따라서 가장 작은 비용 2개를 저장해서 비교
struct Pos{
    int prevR;
    int prevC;
    int r;
    int c;
    int straightCnt;
    int cornerCnt;
};

bool verify(int r, int c, int n){
    if(r<0 || c<0 || r>=n || c>=n){
        return false;
    }
    return true;
}

int solution(vector<vector<int>> board) {
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    queue<Pos> pos;
    vector<vector<bool>> visited;
    vector<vector<pair<int,int>>> cost; //방향별 최소비용
    int answer = 1000000000;
    int n = board.size();
    
    cost.assign(n,vector<pair<int,int>>(n, {1000000000,1000000000})); //각 위치별 최소비용 2개씩
    pos.push({0,0,0,0,0,0}); //시작점

    cost[0][0] = {0,0};
    
    while(!pos.empty()){
        int prevR = pos.front().prevR;
        int prevC = pos.front().prevC;
        int r = pos.front().r;
        int c = pos.front().c;
        int straightCnt = pos.front().straightCnt;
        int cornerCnt = pos.front().cornerCnt;
        //cout<<prevR<<' '<<prevC<<' '<<r<<' '<<c<<' '<<straightCnt<<' '<<cornerCnt<<'\n';
        
        if(r==n-1&&c==n-1){
            answer = min(answer, cost[r][c].first); //가장 작은 값 리턴
            pos.pop();
            continue;
        }
        
        for(int i=0; i<4; i++){
            int nextR = r+dr[i];
            int nextC = c+dc[i];
            int nextStraightCnt = straightCnt;
            int nextCornerCnt = cornerCnt;
            
            
            if(verify(nextR, nextC, n) && board[nextR][nextC]==0){
                
                if(prevR==nextR || prevC==nextC){ //직선
                    nextStraightCnt += 1;        
                }
                else{//코너
                    nextCornerCnt += 1;
                    nextStraightCnt += 1;
                    
                }
               
                //값 2개 중에 갱신된다면 
                if(nextStraightCnt*100+nextCornerCnt*500<=max(cost[nextR][nextC].first,cost[nextR][nextC].second)){
                    //가장 작은 값 갱신 - first
                    if(nextStraightCnt*100+nextCornerCnt*500<=cost[nextR][nextC].first){
                        cost[nextR][nextC].second = cost[nextR][nextC].first;
                        cost[nextR][nextC].first = nextStraightCnt*100+nextCornerCnt*500;
                    }
                    //두 번째로 작은 값 갱신 - second  
                    else if(cost[nextR][nextC].first<nextStraightCnt*100+nextCornerCnt*500
                           &&nextStraightCnt*100+nextCornerCnt*500<=cost[nextR][nextC].second){
                        cost[nextR][nextC].second = nextStraightCnt*100+nextCornerCnt*500;
                    }
                    pos.push({r, c, nextR, nextC, nextStraightCnt, nextCornerCnt});
                }
                
            }
        }
        pos.pop();
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<'{'<<cost[i][j].first<<' '<<cost[i][j].second<<'}';
    //     }
    //     cout<<'\n';
    // }
    
    return answer;
}