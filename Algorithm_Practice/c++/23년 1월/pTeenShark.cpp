#include <iostream>
#include <vector>

using namespace std;

int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int dy[9]={0,0,-1,-1,-1,0,1,1,1};
int answer = 0;

struct Pos{
    //좌표
    int x;
    int y;
    //방향
    int direction;
};

vector<Pos> fish(17,{0,0,0}); //인덱스: 물고기 번호, 값: 좌표, 방향
vector<vector<bool>> visited;
vector<vector<int>> board; //각 위치의 물고기 번호

bool verify(int x, int y){
    if(x<0 || x>=4 || y<0 || y>=4){
        return false;
    }

    return true;
}

void moveFish(Pos shark){

    //이동 가능: 이동하려고 하는 곳에 물고기가 있는 경우, 빈 칸인 경우
    //이동 불가능: 상어가 있는 경우, 범위를 벗어나는 경우
    for(int i=1; i<=16; i++){
        if(fish[i].direction==-1){ //이미 물고기가 잡아먹힌 경우
            continue;
        }

        for(int j=1; j<=8; j++){

            bool flag = false;
            if(fish[i].direction==j){
                int nextX = fish[i].x+dx[j];
                int nextY = fish[i].y+dy[j];
                cout<<"x: "<<fish[i].x<<" dx[j]: "<<dx[j]<<"  y: "<<fish[i].y<<" dy[j]: "<<dy[j]<<"\n";
                //cout<<"board[fish[i].x][fish[i].y]: "<<board[fish[i].x][fish[i].y]<<" board[nextX][nextY]: "<<board[nextX][nextY]<<'\n';                
                cout<<verify(nextX, nextY)<<' '<< (nextX!=shark.x) <<' '<< (nextY!=shark.y)<<'\n';
                if(verify(nextX, nextY) && (nextX!=shark.x || nextY!=shark.y)){ //물고기가 이동할 수 있는 경우
                    cout<<"board[fish[i].x][fish[i].y]: "<<board[fish[i].x][fish[i].y]<<" board[nextX][nextY]: "<<board[nextX][nextY]<<'\n';
                    board[fish[i].x][fish[i].y]=board[nextX][nextY];
                    fish[board[nextX][nextY]].x = fish[i].x;
                    fish[board[nextX][nextY]].y = fish[i].y;
                    
                    fish[i].x = nextX;
                    fish[i].y = nextY;                
                    board[nextX][nextY]=i;
                    cout<<"fish x: "<<fish[i].x<<" y: "<<fish[i].y<<'\n';

                
                }
                else{
                    //45도 반시계 방향으로 회전
                    fish[i].direction = fish[i].direction%8 + 1;
                    j=1;
                }

                cout<<"i: "<<i<<" x: "<<fish[i].x<<" y: "<<fish[i].y<<" d: "<<fish[i].direction<<" nextX: "<<nextX<<" nextY: "<<nextY<<'\n';
                for(int a=0; a<4; a++){
                    for(int b=0; b<4; b++){
                        cout<<board[a][b]<<' ';
                    }
                    cout<<'\n';
                }

                cout<<'\n';
            }
        }
        
    }

}


int main(){

    
    board.assign(4, vector<int>(4,0));

    for(int i=0; i<4; i++){
        for(int j=0; j<8; j+=2){
            int a, b;
            cin>>a>>b;

            board[i][j/2]=a;
            fish[a] = {i, j/2, b};

        }
    }

    cout<<"fish\n";
    for(int i=1; i<=16; i++){
        cout<<"i: "<<i<<' '<<fish[i].x<<' '<<fish[i].y<<' '<<fish[i].direction<<'\n';
    }

    //상어 등장
    Pos shark = {0,0,fish[board[0][0]].direction}; //상어가 0,0 칸에 들어감
    fish[board[0][0]] = {0,0,-1}; //잡아먹힌 0,0칸 물고기
    board[0][0]=0;

    //물고기 이동
    moveFish(shark);

    
    
    //상어가 먹을 수 있는 물고기의 최댓값
    //물고기가 있는 칸으로만 이동 가능 1칸/2칸/3칸(최대) 어디까지 이동하고 물고기 먹을 것인가

    


    
}