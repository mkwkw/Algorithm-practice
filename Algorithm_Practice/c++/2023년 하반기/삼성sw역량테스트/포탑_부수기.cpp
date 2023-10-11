#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos{
    int r;
    int c;
    int cnt;
};
vector<vector<int>> board, attackTime;
vector<vector<bool>> victimOrNot, visited; //공격을 당했는지 여부, 방문 배열
queue<Pos> pos;
//우, 하, 좌, 상
int dr[8]={0,1,0,-1,1,1,-1,-1};
int dc[8]={1,0,-1,0,-1,1,-1,1};

bool comp1(const pair<int,int> &a, const pair<int,int> &b){
    if(attackTime[a.first][a.second]==attackTime[b.first][b.second]){
        if(a.first+a.second==b.first+b.second){
            return a.second>b.second;
        }
        return a.first+a.second>b.first+b.second;
    }
    return attackTime[a.first][a.second]>attackTime[b.first][b.second];
}

bool comp2(const pair<int,int> &a, const pair<int,int> &b){
    if(attackTime[a.first][a.second]==attackTime[b.first][b.second]){
        if(a.first+a.second==b.first+b.second){
            return a.second<b.second;
        }
        return a.first+a.second<b.first+b.second;
    }
    return attackTime[a.first][a.second]<attackTime[b.first][b.second];
}

//공격자 선정
pair<int,int> choiceAttacker(int n, int m){
    pair<int,int> pos;
    vector<pair<int,int>> candidate;
    int minAttack = 101; //가장 약한 포탑의 공격력
    
    //1. 가장 약한 포탑의 공격력 찾기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]>0)
                minAttack = min(minAttack, board[i][j]);
        }
    }

    //2. 가장 약한 공격력의 포탑의 좌표 찾기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==minAttack){
                candidate.push_back({i,j});
            }
        }
    }
     
    if(candidate.size()==1){ //후보탑 1개    
        return candidate[0];
    }
    
    //후보탑 여러개 - 정렬
    sort(candidate.begin(), candidate.end(), comp1);
    return candidate[0];
}

//공격대상 선정 - attacker 제외 가장 강한 포탑
pair<int,int> choiceVictim(int n, int m, pair<int,int> attackerPos){
    pair<int,int> pos;
    vector<pair<int,int>> candidate;
    int maxAttack = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==attackerPos.first && j==attackerPos.second){
                continue;
            }

            if(maxAttack<board[i][j]){
                maxAttack = board[i][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==attackerPos.first && j==attackerPos.second){
                continue;
            }

            if(maxAttack==board[i][j]){
                candidate.push_back({i,j});
            }
        }
    }

    if(candidate.size()==1){ //후보탑 1개    
        return candidate[0];
    }
    
    //후보탑 여러개 - 정렬
    sort(candidate.begin(), candidate.end(), comp2);
    return candidate[0];
}

vector<pair<int,int>> result;
void findVictim(int n, int m, int r, int c, pair<int,int> victim, vector<pair<int,int>> path){
    if(r==victim.first && c==victim.second){
        //cout<<"result size "<<result.size()<<" path size "<<path.size()<<'\n';
        if(result.size()==0 || path.size()<result.size()){
            result = {};
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(visited[i][j]){
                        result.push_back({i,j});
                    }
                }
            }
        }
           
        

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<visited[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }

        // for(int i=0; i<result.size(); i++){
        //     cout<<result[i].first<<' '<<result[i].second<<' ';
        // }
        // cout<<'\n';
        return;
    }

    for(int i=0; i<4; i++){
        int nextR = r+dr[i];
        int nextC = c+dc[i];

        if(nextR<0){
            nextR = (n+nextR)%n;
        }
        else if(nextR>=n){
            nextR = (nextR-n)%n;
        }

        if(nextC<0){
            nextC = (m+nextC)%m;
        }
        else if(nextC>=m){
            nextC = (nextC-m)%m;
        }

        //cout<<nextR<<' '<<nextC<<'\n';
        if(board[nextR][nextC]>0 && !visited[nextR][nextC]){
            visited[nextR][nextC] = true;
            path.push_back({nextR, nextC});
            findVictim(n, m, nextR, nextC, victim, path);
            visited[nextR][nextC] = false;
        }
    }
}

//레이저 공격
bool doLaserAttack(int n, int m, pair<int,int> attacker, pair<int,int> victim){
    //return - 공격자->공격 대상에 도달할 수 있는가
    //공격자->공격 대상 - 최단경로 찾기
    vector<pair<int,int>> path;
    findVictim(n,m,attacker.first, attacker.second, victim, path);
    // pos.push({attacker.first, attacker.second, 0});
    // while(!pos.empty()){
    //     int r = pos.front().r;
    //     int c = pos.front().c;
    //     int cnt = pos.front().cnt;

    //     visited[r][c] = true;

    //     for(int i=0; i<4; i++){
    //         int nextR = r+dr[i];
    //         int nextC = c+dc[i];

    //         if(nextR<0){
    //             nextR = (n+nextR)%n;
    //         }
    //         else if(nextR>=n){
    //             nextR = (nextR-n)%n;
    //         }

    //         if(nextC<0){
    //             nextC = (m+nextC)%m;
    //         }
    //         else if(nextC>=m){
    //             nextC = (nextC-m)%m;
    //         }

    //         if(board[nextR][nextC]>0 && !visited[nextR][nextC]){
    //             pos.push({nextR, nextC, cnt+1});
    //             if(nextR==victim.first && nextC==victim.second){
    //                 break;
    //             }
    //         }
    //     }
    //     pos.pop();
    // }
    if(result.size()>0){ //공격력 감소
    //cout<<"size "<<result.size()<<'\n';
        for(int i=1; i<result.size()-1; i++){
            //cout<<result[i].first<<' '<<result[i].second<<'\n';
            board[result[i].first][result[i].second] -= board[attacker.first][attacker.second]/2;
            victimOrNot[result[i].first][result[i].second] = true;
        }
        board[victim.first][victim.second] -= board[attacker.first][attacker.second];
        victimOrNot[victim.first][victim.second] = true;

        return true;
    }

    return false;
}

void doBombAttack(int n, int m, pair<int,int> attacker, pair<int,int> victim){

    for(int i=0; i<8; i++){
        int aroundR = victim.first+dr[i];
        int aroundC = victim.second+dc[i];

        if(aroundR==attacker.first && aroundC==attacker.second){
            continue;
        }

        if(aroundR<0){
            aroundR = (n+aroundR)%n;
        }
        else if(aroundR>=n){
            aroundR = (aroundR-n)%n;
        }

        if(aroundC<0){
            aroundC = (m+aroundC)%m;
        }
        else if(aroundC>=m){
            aroundC = (aroundC-m)%m;
        }

        victimOrNot[aroundR][aroundC] = true;
        board[aroundR][aroundC] -= board[attacker.first][attacker.second]/2;
    }
    victimOrNot[victim.first][victim.second] = true;
    board[victim.first][victim.second] -= board[attacker.first][attacker.second];
}

int main() {
    
    int n, m, k, attack, answer=0; //행, 열, k번 턴, 공격력

    cin>>n>>m>>k;

    board.assign(n, vector<int>(m, 0)); //포탑
    attackTime.assign(n, vector<int>(m,0)); //최근 공격한 시점

    attack = n+m; //공격력

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];    
        }
    }

    for(int t=0; t<k; t++){
        victimOrNot.assign(n, vector<bool>(n, false));
        visited.assign(n, vector<bool>(n, false));
        result = {};

        while(!pos.empty()){
            pos.pop();
        }

        pair<int,int> attacker, victim;
        //1. 공격자 선정
        attacker = choiceAttacker(n, m);
        //cout<<"attacker "<<attacker.first<<' '<<attacker.second<<'\n';
        board[attacker.first][attacker.second] += n+m; //공격력 증가
        attackTime[attacker.first][attacker.second] = t; //공격 시점 갱신

        //2. 공격자의 공격
        //2-1. 공격대상 선정 - 자신을 제외한 가장 강한 포탑
        victim = choiceVictim(n, m, attacker);
        //cout<<"victim "<<victim.first<<' '<<victim.second<<'\n';
        //2-2. 레이저 공격
        visited[attacker.first][attacker.second] = true;
        bool laser = doLaserAttack(n, m, attacker, victim);
        //2-3. 레이저 공격 안되면, 포탄 공격
        if(!laser){
            doBombAttack(n, m, attacker, victim);
        }

        //3. 포탑 부서짐
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]<0){
                    board[i][j]=0;
                }
            }
        }

        //4. 포탑 정비 - 공격자도 아니고, 공격받지도 않은 포탑 공격력+1 (부서진 것 제외)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]>0 && !(i==attacker.first&&j==attacker.second) && !victimOrNot[i][j]){
                    board[i][j] += 1;                    
                }
            }
        }

        //부서지지 않은 포탑이 1개면 중지
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //cout<<board[i][j]<<' ';
                if(board[i][j]>0){
                    cnt++;
                }
            }
            //cout<<'\n';
        }
        //cout<<'\n';

        

        if(cnt==1){
            break;
        }
    }
    
    //남아있는 포탑 중 가장 강한 포탑의 공격력을 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            answer = max(answer, board[i][j]);
        }
    }

    cout<<answer;

    return 0;
}