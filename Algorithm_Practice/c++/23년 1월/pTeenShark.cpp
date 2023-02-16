#include <iostream>
#include <vector>

using namespace std;

int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int dy[9]={0,0,-1,-1,-1,0,1,1,1};
int answer = 0;

struct Pos{
    //��ǥ
    int x;
    int y;
    //����
    int direction;
};

vector<Pos> fish(17,{0,0,0}); //�ε���: ����� ��ȣ, ��: ��ǥ, ����
vector<vector<bool>> visited;
vector<vector<int>> board; //�� ��ġ�� ����� ��ȣ

bool verify(int x, int y){
    if(x<0 || x>=4 || y<0 || y>=4){
        return false;
    }

    return true;
}

void moveFish(Pos shark){

    //�̵� ����: �̵��Ϸ��� �ϴ� ���� ����Ⱑ �ִ� ���, �� ĭ�� ���
    //�̵� �Ұ���: �� �ִ� ���, ������ ����� ���
    for(int i=1; i<=16; i++){
        if(fish[i].direction==-1){ //�̹� ����Ⱑ ��Ƹ��� ���
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
                if(verify(nextX, nextY) && (nextX!=shark.x || nextY!=shark.y)){ //����Ⱑ �̵��� �� �ִ� ���
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
                    //45�� �ݽð� �������� ȸ��
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

    //��� ����
    Pos shark = {0,0,fish[board[0][0]].direction}; //�� 0,0 ĭ�� ��
    fish[board[0][0]] = {0,0,-1}; //��Ƹ��� 0,0ĭ �����
    board[0][0]=0;

    //����� �̵�
    moveFish(shark);

    
    
    //�� ���� �� �ִ� ������� �ִ�
    //����Ⱑ �ִ� ĭ���θ� �̵� ���� 1ĭ/2ĭ/3ĭ(�ִ�) ������ �̵��ϰ� ����� ���� ���ΰ�

    


    
}