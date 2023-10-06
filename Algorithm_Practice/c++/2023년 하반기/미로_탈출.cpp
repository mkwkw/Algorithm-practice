#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//bfs
//주의! 시간초과
//갈 수 있는 방향 체크하는 for문 안에서 visited[nextR][nextC]=true로 바꿔주기
struct Pos{
    int r;
    int c;
    int time;
};

bool verify(int nextR, int nextC, int r, int c){
    if(nextR<0 || nextR>=r || nextC<0 || nextC>=c){
        return false;
    }
    return true;
}

int solution(vector<string> maps) {
    queue<Pos> pos;
    int sR, sC, eR, eC, lR, lC;
    int answer = 0;
    bool flag = false; //레버를 당겼는가
    vector<vector<bool>> visited;
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    
    visited.assign(maps.size(), vector<bool>(maps[0].length(), false));
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].length(); j++){
            if(maps[i][j]=='S'){
                sR = i;
                sC = j;
            }
            else if(maps[i][j]=='E'){
                eR = i;
                eC = j;
            }
            else if(maps[i][j]=='L'){
                lR = i;
                lC = j;
            }
        }
    }
    
    pos.push({sR, sC, 0});
    visited[sR][sC] = true;
    
    //레버 찾으러 가기
    while(!pos.empty()){
        int r = pos.front().r;
        int c = pos.front().c;
        int time = pos.front().time;
        
        for(int i=0; i<4; i++){
            int nextR = r+dr[i];
            int nextC = c+dc[i];
            
            if(verify(nextR, nextC, maps.size(), maps[0].length()) 
               && maps[nextR][nextC]!='X' 
               && !visited[nextR][nextC]){
                
                if(maps[nextR][nextC]=='L'){
                    answer += time+1;
                    break;
                }
                visited[nextR][nextC] = true;
                pos.push({nextR, nextC, time+1});
            }
        }
        
        if(answer>0){
            break;
        }
        pos.pop();
    }
    
    while(!pos.empty()){
        pos.pop();
    }
    //cout<<"lever "<<answer<<'\n';
    if(answer == 0){
        return -1;
    }
    
    //레버에서 출구 찾아가기
    visited.assign(maps.size(), vector<bool>(maps[0].length(), false));
    
    pos.push({lR, lC, 0});
    visited[lR][lC] = true;
    
    while(!pos.empty()){
        int r = pos.front().r;
        int c = pos.front().c;
        int time = pos.front().time;

        for(int i=0; i<4; i++){
            int nextR = r+dr[i];
            int nextC = c+dc[i];
            
            if(verify(nextR, nextC, maps.size(), maps[0].length()) 
               && maps[nextR][nextC]!='X' 
               && !visited[nextR][nextC]){
                if(maps[nextR][nextC]=='E'){
                    flag = true;
                    answer += time+1;
                    break;
                }
                
                visited[nextR][nextC] = true;
                pos.push({nextR, nextC, time+1});
            }
        }
        
        if(flag){
            break;
        }
        pos.pop();
    }
    
    if(answer == 0 || !flag){
        return -1;
    }

    return answer;
}