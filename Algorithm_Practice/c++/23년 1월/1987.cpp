#include <iostream>
#include <vector>
//#include <set>
using namespace std;

vector<vector<char>> board;
vector<bool> visited;
//set<char> pass;
int answer = 0;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool verify(int x, int y, int r, int c){
    if(x<0 || x>=r || y<0 || y>=c){
        return false;
    }
    return true;
}

void dfs(int x, int y, int r, int c, int cnt){

    answer = max(answer, cnt);

    for(int i=0; i<4; i++){
        if(verify(x+dx[i], y+dy[i], r, c)){
            char a = board[x+dx[i]][y+dy[i]];
            
            //set을 사용하면 시간초과 발생 
            // if(pass.find(a)==pass.end()){
            //     pass.insert(a);
            //     dfs(x+dx[i], y+dy[i], r, c, cnt+1);
            //     pass.erase(a);
            // }

            //알파벳 방문배열 사용하면 시간초과 발생하지 않음!
            if(!visited[a -'A']){
                visited[a -'A']=true;
                dfs(x+dx[i], y+dy[i], r, c, cnt+1);
                visited[a -'A']=false;
            }

        }
           
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    
    cin>>r>>c;

    board.assign(r, vector<char>(c,'0'));
    visited.assign(26, false);

    for(int i=0; i<r; i++){
        string line;
        cin>>line;
        for(int j=0; j<c; j++){
            board[i][j] = line[j];
        }
    }

    //pass.insert(board[0][0]);
    visited[board[0][0]-'A']=true;
    dfs(0,0,r,c,1);

    cout<<answer;
}