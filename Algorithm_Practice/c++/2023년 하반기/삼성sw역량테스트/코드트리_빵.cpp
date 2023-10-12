#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos{
    int r;
    int c;
    int d;
};
struct PosDir{
    int r;
    int c;
    int dist;
    int dir;
};

bool verify(int r, int c, int n){
    if(r<0 || c<0 || r>=n || c>=n){
        return false;
    }
    return true;
}

int dr[4] = {-1,0,0,1};
int dc[4] = {0,-1,1,0};

bool comp(const Pos &a, const Pos &b){
    if(a.d==b.d){
        if(a.r==b.r){
            return a.c<b.c;
        }
        return a.r<b.r;
    }
    return a.d<b.d;
}

int main() {
    int n, m, time=0;
    vector<vector<int>> board; //0: 빈 칸, 1: 베이스 캠프, 2: 편의점, -1: 사람, -2: 지나가지 못하는 곳 - 베이스캠프에 사람 있음, 편의점에 사람 있음
    vector<pair<int,int>> storePos, humanPos, campPos;
    vector<vector<bool>> visited;
    queue<Pos> pos;

    cin>>n>>m;

    board.assign(n, vector<int>(n,0));
    storePos.assign(m, {0,0});
    humanPos.assign(m, {-1,-1});

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==1){
                campPos.push_back({i,j});
            }
        }
    }

    for(int i=0; i<m; i++){
        int r, c;
        cin>>r>>c;
        storePos[i].first = r-1;
        storePos[i].second = c-1;
    }

    //
    while(true){
        
        //board에서의 편의점 위치가 모두 -2인 경우 - 사람들이 모두 편의점에 도착한 경우 - 종료
        bool flag = true;
        for(int i=0; i<m; i++){
            if(board[storePos[i].first][storePos[i].second]!=-2){
                flag = false;
                break;
            }
        }
        if(flag){
            break;
        }

        //1. 사람이 board에 있으며, 움직일 수 있을 때(편의점에 도달X), 해당 사람~그 사람이 가고싶어하는 편의점 최단 거리로 한 칸 이동
        bool moveFlag = false;
        for(int i=0; i<m; i++){
            int nextR, nextC, nextDir;
            if(humanPos[i].first!=-1 && humanPos[i].second!=-1 && !(humanPos[i].first==storePos[i].first && humanPos[i].second==storePos[i].second)){
                //최단 거리로 이동하는 다음 좌표 구하기
                visited.assign(n, vector<bool>(n, false));
                queue<PosDir> pos1;

                pos1.push({humanPos[i].first, humanPos[i].second, 0, -1});
                visited[humanPos[i].first][humanPos[i].second] = true;
                int storeR = storePos[i].first;
                int storeC = storePos[i].second;

                while(!pos1.empty()){
                    int r = pos1.front().r;
                    int c = pos1.front().c;
                    int dist = pos1.front().dist;
                    int dir = pos1.front().dir;

                    if(r==storeR && c==storeC){
                        nextDir = dir;
                        break;      
                    }

                    for(int k=0; k<4; k++){
                        int nextR = r+dr[k];
                        int nextC = c+dc[k];
                        int nextDist = dist+1;
                        int newDir;
                        if(verify(nextR, nextC, n) && !visited[nextR][nextC] && board[nextR][nextC]!=-2){
                            if(dir==-1){
                                newDir = k;
                            }
                            pos1.push({nextR, nextC, nextDist, newDir});
                            visited[nextR][nextC] = true;
                        }
                    }

                    pos1.pop();
                }

                nextR = humanPos[i].first+dr[nextDir];
                nextC = humanPos[i].second+dc[nextDir];

                //한 칸 이동
                board[humanPos[i].first][humanPos[i].second] = 0;
                humanPos[i] = {nextR, nextC};
                board[nextR][nextC] = -1;
                moveFlag = true;
            }
        }
        
        if(moveFlag){
            //2. 모두 이동을 마치고, 편의점 위치에 사람이 있다면 지나가지 못하게 바꿈.
            for(int i=0; i<m; i++){
                if(humanPos[i].first==storePos[i].first && humanPos[i].second==storePos[i].second){
                    board[humanPos[i].first][humanPos[i].second] = -2;
                }
            }
        }


        //3. 시간<=m이라면, m번째 사람을 해당 사람이 가고싶어하는 편의점에 가장 가까운 베이스캠프에 위치시키기
        if(time<m){
            
            //해당 사람이 가고싶어하는 편의점에 가장 가까운 베이스캠프 구하기
            int storeR = storePos[time].first;
            int storeC = storePos[time].second;
            int minDist = n*n+1;
            vector<Pos> candidate;

            for(int i=0; i<campPos.size(); i++){
                visited.assign(n, vector<bool>(n, false));
                
                pos.push({campPos[i].first, campPos[i].second, 0});
                visited[campPos[i].first][campPos[i].second] = true;

                while(!pos.empty()){
                    int r = pos.front().r;
                    int c = pos.front().c;
                    int d = pos.front().d;

                    if(r==storeR && c==storeC){
                        if(minDist>=d){
                            minDist = d;
                            candidate.push_back({campPos[i].first, campPos[i].second, d});
                            pos.pop();
                            continue;
                        }    
                    }

                    for(int k=0; k<4; k++){
                        int nextR = r+dr[k];
                        int nextC = c+dc[k];
                        int nextD = d+1;

                        if(verify(nextR, nextC, n) && !visited[nextR][nextC] && board[nextR][nextC]!=-2){
                            pos.push({nextR, nextC, nextD});
                            visited[nextR][nextC] = true;
                        }
                    }

                    pos.pop();
                }
            }

            if(candidate.size()>1){
                sort(candidate.begin(), candidate.end(), comp);
            }

            //사람 위치 이동
            humanPos[time] = {candidate[0].r, candidate[0].c}; 
        }
        //3-1. 해당 베이스캠프 위치를 지나갈 수 없도록 바꿈.
        for(int i=0; i<m; i++){
            if(humanPos[i].first==campPos[i].first && humanPos[i].second==campPos[i].second){
                board[humanPos[i].first][humanPos[i].second] = -2;
            }
        }
        time++;
    }

    cout<<time;


    
    
    return 0;
}