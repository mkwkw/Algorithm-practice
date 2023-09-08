#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

//해당 위치에 불이 붙는 시간과 해당 위치에 상근이가 도달하는 시간 비교하기
bool verify(int h, int w, int r, int c){
    if(r<0 || c<0 || r>=h || c>=w){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, w, h, cnt=0, time=0; //가로, 세로, 벽을 제외한 공간의 개수
    bool flag;
    vector<vector<char>> board;
    //vector<vector<bool>> visitedS;
    queue<pair<int,int>> firePos, sPos; //불 위치 큐, 상근 위치 큐
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    cin>>t;

    for(int tc=0; tc<t; tc++){
        cin>>w>>h;

        while(!firePos.empty()){
            firePos.pop();
        }
        while(!sPos.empty()){
            sPos.pop();
        }

        board.assign(h, vector<char>(w, ' '));
        //visitedFire.assign(h, vector<bool>(w, false));
        //visitedS.assign(h, vector<bool>(w, false));
        time = 0;
        flag = false;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>board[i][j];
                if(board[i][j]=='@'){
                    sPos.push({i,j});
                    //visitedS[i][j] = true;
                }
                else if(board[i][j]=='*'){
                    firePos.push({i,j});
                    //visitedFire[i][j] = true;
                }

                //if(board[i][j]=='@' || board[i][j]=='.'){
                //    cnt++;
                //}
            }
        }

        while(!sPos.empty()){
            time++;
            
            //불 이동
            set<pair<int,int>> fireTempPos;
            while(!firePos.empty()){
                //cout<<"fr "<<firePos.front().first<<" fc "<<firePos.front().second<<'\n';
                for(int i=0; i<4; i++){
                    int nextR = firePos.front().first+dr[i];
                    int nextC = firePos.front().second+dc[i];

                    if(verify(h, w, nextR, nextC) && board[nextR][nextC]!='*' && board[nextR][nextC]!='#'){
                        //cout<<nextR<<' '<<nextC<<'\n';
                        fireTempPos.insert({nextR, nextC});
                        board[nextR][nextC] = '*';
                    }
                }
                firePos.pop();
            }

            //cout<<"FT "<<fireTempPos.size()<<'\n';
            for(auto s: fireTempPos){
                firePos.push(s);
            }

//            for(int i=0; i<h; i++){
//                for(int j=0; j<w; j++){
//                    cout<<board[i][j]<<' ';
//                }
//                cout<<'\n';
//            }
//            cout<<'\n';

            //상근 이동
            set<pair<int,int>> sTempPos;
            while(!sPos.empty()){
                for(int i=0; i<4; i++){
                    int nextR = sPos.front().first + dr[i];
                    int nextC = sPos.front().second + dc[i];

                    if(!verify(h, w, nextR, nextC)){//상근 탈출
                        cout<<time<<'\n';
                        flag = true;
                        break;
                    }

                    if(verify(h, w, nextR, nextC) && board[nextR][nextC]!='*' && board[nextR][nextC]!='#'){
                        sTempPos.insert({nextR, nextC});
                        //board[nextR][nextC]='@';
                    }
                }

                if(flag){
                    break;
                }

                sPos.pop();
            }

            if(flag){
                break;
            }

            //cout<<"ST "<<sTempPos.size()<<'\n';
            for(auto s : sTempPos){
                //cout<<sTempPos[i].first<<' '<<sTempPos[i].second<<'\n';
                sPos.push(s);
            }
        }

        if(flag){
            continue;
        }

        cout<<"IMPOSSIBLE\n";

    }

}