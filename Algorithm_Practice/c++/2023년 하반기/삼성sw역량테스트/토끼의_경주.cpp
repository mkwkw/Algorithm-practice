#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


struct Rabbit{
    int pid;
    int dist;
    int r;
    int c;
    int jumpCnt;
    int score;
};

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
vector<int> rabbits; //pid
map<int, Rabbit> pidAndInfo;

bool verify(int r, int c, int n, int m){
    if(r<0 || c<0 || r>=n || c>=m){
        return false;
    }
    return true;
}

//토끼 우선순위
bool comp1(const int &pidA, const int &pidB){
    Rabbit a = pidAndInfo[pidA];
    Rabbit b = pidAndInfo[pidB];

    if(a.jumpCnt == b.jumpCnt){
        if(a.r+a.c==b.r+b.c){
            if(a.r==b.r){
                if(a.c==b.c){
                    return a.pid<b.pid;
                }
                return a.c<b.c;
            }
            return a.r<b.r;
        }
        return a.r+a.c<b.r+b.c;
    }
    return a.jumpCnt<b.jumpCnt;
}

bool comp2(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first+a.second==b.first+b.second){
        if(a.first == b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
    return a.first+a.second>b.first+b.second;
}

bool comp3(const int &pidA, const int &pidB){
    Rabbit a = pidAndInfo[pidA];
    Rabbit b = pidAndInfo[pidB];

    if(a.r+a.c==b.r+b.c){
        if(a.r == b.r){
            if(a.c == b.c){
                return a.pid>b.pid;
            }
            return a.c>b.c;
        }
        return a.r>b.r;
    }
    return a.r+a.c>b.r+b.c;
}



int main() {
    // 여기에 코드를 작성해주세요.
    
    int q, n, m, p, pid, d, k, s, l, answer = 0;

    cin>>q;

    for(int i=0; i<q; i++){
        int cmd;

        cin>>cmd;

        if(cmd==400){
            break;
        }
        else if(cmd==100){
            //경주 시작 준비
            cin>>n>>m>>p;

            for(int j=0; j<p; j++){
                cin>>pid>>d;
                pidAndInfo[pid] = {pid, d, 0, 0, 0, 0};
                rabbits.push_back(pid);
            }
            continue;
        }

        switch(cmd){
            case 200: {//경주 진행
                cin>>k>>s;
                
                set<int> selectedRabbitPid;
                //k라운드
                for(int j=0; j<k; j++){
                    cout<<"k "<<j+1<<'\n';
                    //우선 순위 기준에 따라 정렬
                    sort(rabbits.begin(), rabbits.end(), comp1);
                    for(int d=0; d<rabbits.size(); d++){
                        
                        cout<<"rabbit pid "<<pidAndInfo[rabbits[d]].pid<<' '<<pidAndInfo[rabbits[d]].dist<<' '<<pidAndInfo[rabbits[d]].r<<' '<<pidAndInfo[rabbits[d]].c<<' '<<pidAndInfo[rabbits[d]].jumpCnt<<' '<<pidAndInfo[rabbits[d]].score<<'\n';
                    }

                    Rabbit rabbit = pidAndInfo[rabbits[0]]; //보낼 토끼 선정
                    int r = rabbit.r;
                    int c = rabbit.c;
                    int dist = rabbit.dist;
                    selectedRabbitPid.insert(rabbit.pid);
                    cout<<"pid "<<rabbit.pid<<'\n';
                    cout<<"r "<<r<<" c "<<c<<'\n';
                    //움직일 위치 정하기
                    vector<pair<int,int>> candidate;
                    for(int d=0; d<4; d++){
                        int nextR = r+dr[d]*dist;
                        int nextC = c+dc[d]*dist;

                        while(nextR<0 || nextR>=n){
                            if(nextR<0){
                                nextR = abs(nextR)-1;
                            }
                            else{
                                nextR = n-2-(nextR-n);
                            }
                        }
                        
                        while(nextC<0 || nextC>=m){
                            if(nextC<0){
                                nextC = abs(nextC)-1;
                            }
                            else{
                                nextC = m-2-(nextC-m);
                            }
                        }                        

                        //cout<<"nextR "<<nextR<<" nextC "<<nextC<<'\n';
                        candidate.push_back({nextR, nextC});
                    }

                    //가장 우선순위 높은 위치 뽑기
                    sort(candidate.begin(), candidate.end(), comp2);
                    
                    //토끼 이동
                    pidAndInfo[rabbits[0]].r = candidate[0].first;
                    pidAndInfo[rabbits[0]].c = candidate[0].second;
                    pidAndInfo[rabbits[0]].jumpCnt++;
                    cout<<"finalR "<<candidate[0].first<<" finalC "<<candidate[0].second<<'\n';
                    //뽑힌 토끼 제외, 점수 획득
                    for(int d = 1; d<rabbits.size(); d++){
                        pidAndInfo[rabbits[d]].score += (candidate[0].first+candidate[0].second);
                    }
                }

                //k라운드 이후
                //한 번이라도 뽑힌 토끼 중에 점수 s 더할 토끼 찾기
                vector<int> temp;
                for(auto s : selectedRabbitPid){
                    temp.push_back(s);
                }
                sort(temp.begin(), temp.end(), comp3);
                pidAndInfo[temp[0]].score += s;

                break;
            }
            case 300: {//이동거리 변경
                cin>>pid>>l;

                pidAndInfo[pid].dist *= l; 

                break;
            }
        }

    }

    for(auto m : pidAndInfo){
        answer = max(answer, m.second.score);
    }

    cout<<answer;

    return 0;
}