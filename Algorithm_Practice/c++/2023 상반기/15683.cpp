#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct CCTV{
    int num; //cctv 번호
    //cctv 좌표
    int r; 
    int c;
};

vector<vector<vector<int>>> cctvDir(5);
vector<CCTV> pos;
int answer = 64;

//모든 경우의 수 고려해봐야함. - 백트래킹 사용
//2번 cctv가 <-->일 때, 1번 cctv가 ->인 경우, <-인 경우, 위를 가리키는 경우, 아래를 가리키는 경우 모두 고려해봐야함.
void backtracking(vector<vector<int>> board, int cnt, int k){
    /*
    cout<<"cnt: "<<cnt<<" k: "<<k<<'\n';
    for(int a=0; a<board.size(); a++){
        for(int b=0; b<board[0].size(); b++){
            cout<<board[a][b]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    */
    
    if(cnt==k){
        int temp = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==0){
                    temp++;
                }
            }
        }
        //cout<<"temp: "<<temp<<'\n';
        answer = min(answer, temp);
        return;
    }

    int num = pos[cnt].num;
    int r = pos[cnt].r;
    int c = pos[cnt].c;
     vector<vector<int>> board1 = board; //-1로 바꾸기 전 상태 저장

    for(int i=0; i<cctvDir[num-1].size(); i++){
        for(int j=0; j<cctvDir[num-1][i].size(); j++){
            //범위를 벗어나는 경우 continue로 처리
            if(r==0 && cctvDir[num-1][i][j]==1){
                continue;
            }
            else if(c==0 && cctvDir[num-1][i][j]==3){
                continue;
            }
            else if(r==board.size()-1 && cctvDir[num-1][i][j]==2){
                continue;
            }
            else if(c==board[0].size()-1 && cctvDir[num-1][i][j]==4){
                continue;
            }
                
            switch(cctvDir[num-1][i][j]){
                //상
                case 1:
                    for(int k=r-1; k>=0; k--){
                        if(board[k][c]==6){
                            break;
                        }
                        else if(board[k][c]==0){
                            board[k][c]=-1;
                        }
                    }
                    break;
                //하
                case 2:
                    for(int k=r+1; k<board.size(); k++){
                        if(board[k][c]==6){
                            break;
                        }
                        else if(board[k][c]==0){
                            board[k][c]=-1;
                        }
                    }
                    break;
                //좌
                case 3:
                    for(int k=c-1; k>=0; k--){
                        if(board[r][k]==6){
                            break;
                        }
                        else if(board[r][k]==0){
                            board[r][k]=-1;
                        }
                    }
                    break;
                //우
                case 4:
                    for(int k=c+1; k<board[0].size(); k++){
                        if(board[r][k]==6){
                            break;
                        }
                        else if(board[r][k]==0){
                            board[r][k]=-1;
                        }
                    }
                    break;
            }
        }

        backtracking(board, cnt+1, k); 
        board = board1; //-1 바꾸기 전 상태로 돌려놓기
    }
}

bool verify(int r, int c, int n, int m){
    if(r<0 || c<0 || r>=n || c>=m){
        return false;
    }
    return true;
}

int main(){
    vector<vector<int>> board;
    int n, m;

    //상:1, 하:2, 좌:3, 우:4
    cctvDir[0]={{1}, {2}, {3}, {4}};
    cctvDir[1]={{1,2}, {3,4}};
    cctvDir[2]={{1,4}, {1,3}, {2,4}, {2,3}};;
    cctvDir[3]={{3,4,1}, {3,4,2}, {1,2,3}, {1,2,4}};
    cctvDir[4]={{1,2,3,4}};

    cin>>n>>m;

    board.assign(n,vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]>0 && board[i][j]<6){
                pos.push_back({board[i][j], i, j});
            }
        }
    }

    backtracking(board, 0, pos.size());

    cout<<answer;
}