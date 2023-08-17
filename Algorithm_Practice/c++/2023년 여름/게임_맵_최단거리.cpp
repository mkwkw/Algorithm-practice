#include <vector>
#include <queue>

using namespace std;

//bfs
//이동거리
//방문 배열
//시간 초과 해결 - visited[nextR][nextC]=true 변경해서 큐에 넣기
struct Pos{
    int r;
    int c;
    int cnt;
};

bool verify(int r, int c, int n, int m){
    if(r<0 || c<0 || r>=n || c>=m){
        return false;
    }
    return true;
}

int solution(vector<vector<int>> maps)
{
    queue<Pos> pos;
    vector<vector<bool>> visited;
    int answer = -1, goalR = maps.size()-1, goalC = maps[0].size()-1;
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    
    visited.assign(maps.size(), vector<bool>(maps[0].size(), false));
    
    pos.push({0,0,1}); //처음 위치도 이동 거리에 포함
    visited[0][0] = true;
    
    while(!pos.empty()){
        
        int r = pos.front().r;
        int c = pos.front().c;
        int cnt = pos.front().cnt;
        
        if(r==goalR && c==goalC){
            return cnt;
        }
        
        for(int i=0; i<4; i++){
            int nextR = r+dr[i];
            int nextC = c+dc[i];
            
            if(verify(nextR, nextC, goalR+1, goalC+1) && maps[nextR][nextC]==1 && !visited[nextR][nextC]){
                if(nextR==goalR && nextC==goalC){
                    return cnt+1;
                }
                
                visited[nextR][nextC] = true; //여기에서 방문 체크 해야 시간 초과 발생X
                pos.push({nextR, nextC, cnt+1});
            }
        }
        
        pos.pop();
    }
    
    return answer;
}