#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int N, M;
char maze[2001][2001];
int visited[2001][2001];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //up, down, left, right check.

queue<pair<int,int>> q;

void bfs(){
    // 최단 거리 탐색
    int curX, curY, nextX,nextY;
    int finX, finY;
    while(!q.empty()){
        curX = q.front().first;
        curY = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            nextX = curX + dir[i][1];
            nextY = curY + dir[i][0];

            if(nextX<M && nextX >=0 && nextY<N && nextY>=0 && visited[nextY][nextX]==0 && maze[nextY][nextX]=='.'){
                visited[nextY][nextX]=visited[curY][curX]+1;
                q.push(make_pair(nextX,nextY));
                finX = nextX; finY = nextY;
            }
        }
    }
    //cout<<"\n"<<finX << ' '<<finY<<'\n';
    
    // 도착 지점에서 역순으로 최단거리 탐색
    q.push(make_pair(finX,finY));

    int finXY=-1, finX, finY;
    for(int i=0; i<N; i++){
        if(visited[0][i]>finXY){
            finXY = visited[0][i];
            finX=0;
            finY=i;
        }
    }

    for(int i=0; i<M; i++){
        if(visited[i][0]>finXY){
            finXY = visited[i][0];
            finX=i;
            finY=0;
        }
    }

    maze[finY][finX]='&';
    curX = finX;
    curY = finY;
    int goal = visited[finY][finX];
    while(visited[curY][curX]>=1){
        for(int i=0;i<4;i++){
            nextX = curX + dir[i][1];
            nextY = curY + dir[i][0];

            if(nextX<M && nextX >=0 && nextY<N && nextY>=0 && visited[nextY][nextX] == goal-1){
                maze[nextY][nextX]='&';
            }
        }
    }
//연주 코드 수정하다가 말았음.
//반례
// 5 5
// +.+.+
// +...+
// +...+
// +...+
// +++++
//입구, 출구가 위, 아래 가장 자리에 있는 경우
//가장 자리 중에 가장 큰 수 갖는 곳에서부터 하나씩 감소하도록 이동한다.
// -1 1 -1 5 -1 
// -1 2 3 4 -1
// -1 3 4 5 -1
// -1 4 5 6 -1
// -1 -1 -1 -1 -1
//5->4->3->2->1 
//+.+.+
//+...+
//+@@@+
//+@@@+
//+++++
//이 나와야함.
}

int main(){
    cin >> N >> M;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            char c;
            cin >> c;
            maze[y][x]= c;
            if(c=='+'){
                visited[y][x]=-1;
            }
            else if(c=='.' && (x==0||x==M-1 || y==0 || y==N-1) && q.empty()){
                q.push(make_pair(x,y));
                visited[y][x]=1;
            }
        }
    }
    bfs();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << visited[i][j]<< ' ';
        }
        cout <<'\n';
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(maze[i][j]=='&')cout << '.';
            else if(maze[i][j]=='.') cout<<'@';
            else cout << maze[i][j];
        }
        cout <<'\n';
    }
}