#include <iostream>
#include <vector>

using namespace std;

//dfs - 시간초과
//bfs로 풀어보기!!

vector<vector<char>> board;
//vector<vector<bool>> visited;
//vector<vector<bool>> visited1;
//vector<vector<pair<int, int>>> point; // point.size(): 지역의 개수, point[i]: i번째 지역에 해당하는 육지의 좌표 배열
//vector<pair<int, int>> oneDistrict;
vector<vector<int>> dist;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int answer = 0;


bool verify(int r, int c, int n, int m){
    if(r<0 || r>=n || c<0 || c>=m){
        return false;
    }
    return true;
}

void findLand(int r, int c, int n, int m){
    
    if(/*visited[r][c] ||*/ board[r][c]=='W'){
        return;
    }

    //visited[r][c] = true;
    //oneDistrict.push_back({r,c});

    for(int i=0; i<4; i++){
        if(verify(r+dr[i], c+dc[i], n, m) && board[r+dr[i]][c+dc[i]]=='L' && dist[r][c]+1 < dist[r+dr[i]][c+dc[i]]/*!visited[r+dr[i]][c+dc[i]]*/){
            dist[r+dr[i]][c+dc[i]] = min(dist[r][c]+1, dist[r+dr[i]][c+dc[i]]);
            findLand(r+dr[i], c+dc[i], n, m);
        }
    }

}

/*
void shortestPath(int r, int c, int n, int m){
    
    //visited1[r][c] = true;

    for(int i=0; i<4; i++){
        //cout<<"p: "<<r+dr[i]<<' '<<c+dc[i]<<' '<<verify(r+dr[i], c+dc[i], n, m)<<"\n";
        if(verify(r+dr[i], c+dc[i], n, m) /*&& visited[r+dr[i]][c+dc[i]] && (!visited1[r+dr[i]][c+dc[i]] || (visited1[r+dr[i]][c+dc[i]] && (dist[r][c]+1 < dist[r+dr[i]][c+dc[i]])){
            dist[r+dr[i]][c+dc[i]] = min(dist[r][c]+1, dist[r+dr[i]][c+dc[i]]);
            
            //answer = max(answer, dist[r+dr[i]][c+dc[i]]);
            
            //cout<<"move: "<<r+dr[i]<<' '<<c+dc[i]<<' '<<dist[r+dr[i]][c+dc[i]]<<'\n';
            shortestPath(r+dr[i], c+dc[i], n, m);
        }
        else{
            continue;
        }
    }
    
}
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;
    
    cin>>n>>m;

    board.assign(n, vector<char>(m, ' '));
    dist.assign(n, vector<int>(m, 3000));

    string lw = "";
    for(int i=0; i<n; i++){
        cin>>lw;
        for(int j=0; j<m; j++){
            board[i][j] = lw[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='L'){
                dist.assign(n, vector<int>(m, 3000));
                dist[i][j]=0;

                findLand(i, j, n, m);
                
                for(int k=0; k<n; k++){
                    for(int h=0; h<m; h++){
                        cout<<dist[k][h]<<' ';
                        if(dist[k][h]>0 && dist[k][h]<3000){
                            answer = max(answer, dist[k][h]);
                        }
                    }
                    cout<<'\n';
                }
                
            }
        }
    }

    //각 지역의 가장 짧은 최단 거리 구하고, 지역끼리 가장 긴 최단 거리 비교
    //

    
    cout<<answer;
    

}