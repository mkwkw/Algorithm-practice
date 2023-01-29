#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

vector<vector<vector<int>>> tomatoes;

struct position{
    int x; //가로
    int y; //세로
    int z; //높이
    int date; //일자
};

bool verify(int x, int y, int z, int m, int n, int h){
    if(x>=m || x<0){
        return false;
    }
    else if(y>=n || y<0){
        return false;
    }
    else if(z>=h || z<0){
        return false;
    }
    else if(tomatoes[z][y][x]==-1 || tomatoes[z][y][x]==1){
        return false;
    }
    
    return true;
}

int main(){
    int m,n,h, cnt=0, answer=0;
    
    cin>>m>>n>>h;

    tomatoes.assign(h, vector<vector<int>>(n, vector<int>(m,0))); //[높이][세로][가로]
    queue<position> ripe;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){

                cin>>tomatoes[i][j][k];

                if(tomatoes[i][j][k]==0){
                    cnt++;
                }
                else if(tomatoes[i][j][k]==1){
                    ripe.push(position{k,j,i,0});
                }
            }
        }
    }

    if(cnt==0){
        cout<<"0";
        return 0;
    }
    
    position pos;
    while(!ripe.empty()){
        
        pos = ripe.front();
        int date = pos.date+1;

        //큐의 맨 앞에 있는 익은 토마토 기준 6방향 탐색 & 기준에 부합되면 큐에 익을 토마토 넣기
        for(int i=0; i<6; i++){
            int x,y,z;
            x = pos.x+dx[i];
            y = pos.y+dy[i];
            z = pos.z+dz[i];

            if(verify(x, y, z, m, n, h)){
                tomatoes[z][y][x]=1;
                position newPos = {x, y, z, date};
                ripe.push(newPos);
            }
        }

        //기준 토마토 pop
        ripe.pop();
    }

    answer = pos.date;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(tomatoes[i][j][k]==0){
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }

    cout<<answer<<'\n';
    
}

//3차원 배열: [높이][세로(행)][가로(열)] ([h][n][m])
//큐 이용 - BFS
/**
 * 3차원 배열과 구조체와 큐(지금 날짜에서 익는 토마토 정보 들어감) 이용
 * 1. 안 익은 토마토가 있는가 체크 - 없으면 0 출력
 * 2. 익은 토마토(1)의 좌표와 (큐에 들어가는) 날짜 넣기
 * 3. 익은 토마토의 좌표 기준 6방향으로 이동할 수 있는지 범위 및 0인지 체크 & 3차원 벡터에서 1로 바꾸기 & 이동 가능한 position에는 date+1한 것으로 바꿔서 넣기
 * 4. 큐가 빌 때까지 반복
 * 5. 큐가 비었는데 3차원 벡터에 0인 토마토가 남았다면 -1 출력, 없다면 마지막 토마토의 date 출력
*/