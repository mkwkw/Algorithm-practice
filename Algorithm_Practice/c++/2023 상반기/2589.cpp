#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//dfs�� Ǯ�� �ð� �ʰ� �߻�
//bfs�� Ǯ�� ���� - Ȯ���� �ӵ��鿡���� bfs�� ������!

struct Pos{
    int r; //�ش� ��ǥ�� ��
    int c; //�ش� ��ǥ�� ��
    int cnt; //�ش� ��ǥ������ �̵� �ð�
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

                        //�̹� �湮�� �� ��ǥ�� ���ؼ��� �ð� ���Ÿ� ����
                        if(visited[nextR][nextC]){
                            time[nextR][nextC] = min(cnt+1, time[nextR][nextC]);
                        }
                        else{ //�湮���� �ʾҴ� ��ǥ�� �ð� ���� �� ť�� �ְ� �湮 üũ
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