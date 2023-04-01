#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//dfs로 풀면 시간 초과 발생
//bfs로 풀면 성공 - 확실히 속도면에서는 bfs가 빠르다!

struct Pos{
    int r; //해당 좌표의 행
    int c; //해당 좌표의 열
    int cnt; //해당 좌표까지의 이동 시간
};

int main(){
    int n, m, answer=0;
    vector<string> board;
    vector<vector<int>> time;
    vector<vector<bool>> visited;
    queue<Pos> q;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};

    cin>>n>>m;

    board.assign(n,"");

    for(int i=0; i<n; i++){
        cin>>board[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='L'){
                time.assign(n, vector<int>(m, 3000));
                visited.assign(n, vector<bool>(m, false));
                
                time[i][j]=0;
                visited[i][j]=true;
                q.push({i,j,0});

                while(!q.empty()){
                    int r = q.front().r;
                    int c = q.front().c;
                    int cnt = q.front().cnt;

                    for(int k=0; k<4; k++){
                        int nextR = r+dr[k];
                        int nextC = c+dc[k];

                        if(nextR<0 || nextR>=n || nextC<0 || nextC>=m){
                            continue;
                        }
                        
                        if(board[nextR][nextC]=='W'){
                            continue;
                        }

                        //이미 방문을 한 좌표에 대해서는 시간 갱신만 진행
                        if(visited[nextR][nextC]){
                            time[nextR][nextC] = min(cnt+1, time[nextR][nextC]);
                        }
                        else{ //방문하지 않았던 좌표는 시간 갱신 및 큐에 넣고 방문 체크
                            time[nextR][nextC] = cnt+1;
                            q.push({nextR, nextC, time[nextR][nextC]});
                            visited[nextR][nextC]=true;
                        }

                        answer = max(answer, time[nextR][nextC]);
                    }
                    q.pop();
                }

            }
        }
    }

    cout<<answer;
}