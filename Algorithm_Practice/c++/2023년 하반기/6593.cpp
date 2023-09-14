#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//bfs
//테스트 케이스 여러 개일 때, 꼭 큐도 매번 비우기!
struct Pos{
    int l;
    int r;
    int c;
    int time;
};

bool verify(int l, int r, int c, int L, int R, int C){
    if(l<0 || r<0 || c<0 || l>=L || r>=R || c>=C){
        return false;
    }

    return true;
}

int main(){
    queue<Pos> pos;
    vector<vector<vector<char>>> building;
    vector<vector<vector<bool>>> visited;
    int l, r, c, exitL, exitR, exitC;
    int dl[6]={0,0,0,0,1,-1};
    int dr[6]={0,0,1,-1,0,0};
    int dc[6]={1,-1,0,0,0,0};

    while(cin>>l>>r>>c){
        if(l==0 && r==0 && c==0){
            return 0;
        }

        //초기화 - 큐도 꼭 비우기!
        while(!pos.empty()){
            pos.pop();
        }

        building.assign(l, vector<vector<char>>(r, vector<char>(c, ' ')));
        visited.assign(l, vector<vector<bool>>(r, vector<bool>(c, false)));

        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    cin>>building[i][j][k];
                    //cout<<building[i][j][k]<<' '<<i<<' '<<j<<' '<<k<<'\n';

                    if(building[i][j][k]=='S'){
                        pos.push({i,j,k,0});
                    }
                    else if(building[i][j][k]=='E'){
                        exitL = i;
                        exitR = j;
                        exitC = k;
                    }
                }
            }
        }

        bool flag = false;
        while(!pos.empty()){
            //cout<<pos.front().l<<' '<<pos.front().r<<' '<<pos.front().c<<' '<<pos.front().time<<'\n';
            if(pos.front().l==exitL && pos.front().r==exitR && pos.front().c==exitC){
                cout<<"Escaped in "<<pos.front().time<<" minute(s).\n";
                flag = true;
                break;
            }

            for(int i=0; i<6; i++){
                int nextL = pos.front().l+dl[i];
                int nextR = pos.front().r+dr[i];
                int nextC = pos.front().c+dc[i];
                int nextTime = pos.front().time+1;

                if(verify(nextL, nextR, nextC, l, r, c) && !visited[nextL][nextR][nextC] && building[nextL][nextR][nextC]!='#'){
                //cout<<"next "<<nextL<<' '<<nextR<<' '<<nextC<<'\n';
                    
                    visited[nextL][nextR][nextC] = true;
                    pos.push({nextL, nextR, nextC, nextTime});
                }
            }

            pos.pop();    
        }

        if(!flag){
            cout<<"Trapped!\n";
        }
    }

}