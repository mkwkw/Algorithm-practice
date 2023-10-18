#include <string>
#include <vector>
#include <queue>

using namespace std;

//bfs
//방향별 방문 배열
struct Pos{
    int r;
    int c;
    int cnt;
};
struct DirVisited{
    bool up;
    bool down;
    bool left;
    bool right;
};

int verify(int r, int c, int n, int m){
    if(r<0 || c<0 || r>=n || c>=m){
        return false;
    }
    return true;
}

int solution(vector<string> board) {
    queue<Pos> pos;
    vector<vector<DirVisited>> visited; //방향별 방문 배열 - 중복 방지
    int startR, startC, goalR, goalC;
    int answer = 0;
    
    visited.assign(board.size(), vector<DirVisited>(board[0].length(), {false, false, false, false}));
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].length(); j++){
            if(board[i][j]=='R'){
                startR = i;
                startC = j;
            }
            else if(board[i][j]=='G'){
                goalR = i;
                goalC = j;
            }
        }
    }
    
    pos.push({startR, startC, 0});
    while(!pos.empty()){
        int r = pos.front().r;
        int c = pos.front().c;
        int cnt = pos.front().cnt;
        
        if(board[r][c]=='G'){
            answer = cnt;
            break;
        }
        pos.pop();
        
        int nextR, nextC;
        //위쪽으로
        nextR = 0;
        nextC = c;
        for(int i=r; i>=0; i--){
            if(board[i][c]=='D'){
                nextR = i+1;
                break;
            }
        }
        if(!visited[nextR][nextC].up){
            pos.push({nextR, nextC, cnt+1});
            visited[nextR][nextC].up = true;            
        }
        
        //아래쪽으로 
        nextR = board.size()-1;
        nextC = c;
        for(int i=r; i<board.size(); i++){
            if(board[i][c]=='D'){
                nextR = i-1;
                break;
            }
        }
        if(!visited[nextR][nextC].down){
            pos.push({nextR, nextC, cnt+1});
            visited[nextR][nextC].down = true;            
        }
        
        //왼쪽으로
        nextR = r;
        nextC = 0;
        for(int i=c; i>=0; i--){
            if(board[r][i]=='D'){
                nextC = i+1;
                break;
            }
        }
        if(!visited[nextR][nextC].left){
            pos.push({nextR, nextC, cnt+1});
            visited[nextR][nextC].left = true;            
        }
        
        //오른쪽으로
        nextR = r;
        nextC = board[0].length()-1;
        for(int i=c; i<board[0].length(); i++){
            if(board[r][i]=='D'){
                nextC = i-1;
                break;
            }
        }
        if(!visited[nextR][nextC].right){
            pos.push({nextR, nextC, cnt+1});
            visited[nextR][nextC].right = true;            
        }
        
    }
    
    if(answer==0){
        answer = -1;
    }
    
    return answer;
}