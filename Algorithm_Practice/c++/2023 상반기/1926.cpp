#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//같은 그림인지 탐색하는 방향 - 상하좌우
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

//범위 체크
bool verify(int x, int y, int r, int c){
    if(x<0 || x>=r || y<0 || y>=c){
        return false;
    }
    return true;
}

int main(){
    
    vector<vector<int>> paper;
    vector<vector<bool>> visited;
    queue<pair<int, int>> pos;
    
    int n, m;
    int cnt = 0;
    int maxSize = 0;
    
    cin>>n>>m;

    paper.assign(n, vector<int>(m,0));
    visited.assign(n, vector<bool>(m, true));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>paper[i][j];

            if(paper[i][j]==1){
                visited[i][j]=false;
            }
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int oneSize = 1;
            //하나의 그림 탐색
            if(paper[i][j]==1 && !visited[i][j]){
                pos.push({i,j});

                cnt++; //그림 개수 증가
                visited[i][j]=true;
                
                while(!pos.empty()){
                    for(int k=0; k<4; k++){
                        int nextR = pos.front().first+dr[k];
                        int nextC = pos.front().second+dc[k];
                        if(verify(nextR, nextC, n, m) && !visited[nextR][nextC]){
                            pos.push({nextR, nextC});
                            visited[nextR][nextC]=true;
                            oneSize++;
                        }
                    }
                    pos.pop();
                }

                maxSize = max(oneSize, maxSize); //최대 그림 크기 갱신
            }
        }
    }
    
    cout<<cnt<<'\n'<<maxSize;

}