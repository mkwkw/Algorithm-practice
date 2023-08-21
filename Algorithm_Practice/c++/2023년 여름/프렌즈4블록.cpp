#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//큐
//역시 한번에 모아서 처리할 때는 queue 사용하기!
struct Block{
    vector<pair<int,int>> pos; //r좌표, c좌표
};

int dr[3] = {0,1,1};
int dc[3] = {1,0,1};

bool verify(int r, int c, int m, int n){
    if(r>=m || c>=n || r<0 || c<0){
        return false;
    }
    
    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    queue<Block> eraseBlocks;
    queue<char> remainCharacter;
    
    while(true){
        
        //지울 블록 찾기
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]!=' '){

                    Block block;
                    block.pos.push_back({i,j});

                    bool flag = true;
                    for(int k=0; k<3; k++){
                        int nextR = i+dr[k];
                        int nextC = j+dc[k];

                        if(!(verify(nextR, nextC, m, n)&&board[nextR][nextC]==board[i][j])){
                            flag = false;
                            break;
                        }
                        else{
                            block.pos.push_back({nextR, nextC});
                        }
                    }

                    if(flag){
                        eraseBlocks.push(block);
                    }
                }        
            }
        }
        
        //게임 끝나는 조건
        if(eraseBlocks.empty()){
            break;
        }
        
        while(!eraseBlocks.empty()){
            int r1 = eraseBlocks.front().pos[0].first;
            int c1 = eraseBlocks.front().pos[0].second;
            int r2 = eraseBlocks.front().pos[1].first;
            int c2 = eraseBlocks.front().pos[1].second;
            int r3 = eraseBlocks.front().pos[2].first;
            int c3 = eraseBlocks.front().pos[2].second;
            int r4 = eraseBlocks.front().pos[3].first;
            int c4 = eraseBlocks.front().pos[3].second;
            
            board[r1][c1]=' ';
            board[r2][c2]=' ';
            board[r3][c3]=' ';
            board[r3][c3]=' ';
            board[r4][c4]=' ';
            board[r4][c4]=' ';
            

            eraseBlocks.pop();
        }
        
        // for(int a=0; a<m; a++){
        //     for(int b=0; b<n; b++){
        //         cout<<board[a][b];
        //     }
        //     cout<<'\n';
        // }
        
        //블록 떨어뜨리기
        for(int i=0; i<n; i++){
            for(int j=m-1; j>=0; j--){
                if(board[j][i]!=' '){
                    remainCharacter.push(board[j][i]);
                }
                board[j][i]=' '; //다시 빈칸으로 만들기
            }
            
            for(int j=m-1; j>=0; j--){
                if(remainCharacter.empty()){
                    break;
                }
                board[j][i]=remainCharacter.front();
                remainCharacter.pop();
            }
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            //cout<<board[i][j];
            if(board[i][j]==' '){
                answer++;
            }
        }
        //cout<<'\n';
    }
    
    return answer;
}