#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

//구현
//조건 잘 따지기
struct Fireball{
    int r;
    int c;
    int m;
    int s;
    int d;
};

//이동한 위치 - 상하/좌우 연결 고려
Fireball moveFireball(int n, int r, int c, int m, int s, int d){
    //cout<<"위치 "<<r<<' '<<c<<' '<<m<<' '<<s<<' '<<d<<'\n';
    int nextR = r, nextC = c;
    if(1<=r && r<=n){
        nextR = r;
    }
    else{
        if(r<=0){
            //nextR = r;
            while(nextR<=0){
                nextR += n;
            }
        }
        else{
            //nextR = r%n;
            while(nextR>n){
                nextR -= n;
            }  
        }
    }

    if(1<=c && c<=n){
        nextC = c;
    }
    else{ 
        if(c<=0){
            //nextC = c;
            while(nextC<=0){
                nextC += n;
            }
        }
        else{
            //nextC = c%n; - 만약 c=14인 경우, nextC가 0이 됨.
            while(nextC>n){
                nextC -= n;
            } 
        }
    }

    return {nextR, nextC, m, s, d};
}

int main(){
    int n, m, k, r, c, mass, s, d, answer = 0;
    map<pair<int,int>, vector<Fireball>> fireballMap;
    queue<Fireball> fireballQ;
    int dr[8]={-1,-1,0,1,1,1,0,-1};
    int dc[8]={0,1,1,1,0,-1,-1,-1};
    
    cin>>n>>m>>k;

    if(m==0){
        cout<<0;
        return 0;
    }

    //초기 상태
    for(int i=0; i<m; i++){
        cin>>r>>c>>mass>>s>>d;
        
        fireballQ.push({r,c,mass,s,d});
        //fireballMap[{r,c}].push_back({r,c,m,s,d});    
    }

    //파이어볼 이동 시작
    for(int i=0; i<k; i++){
        //파이어볼 실제 이동 (r, c) 변화
        while(!fireballQ.empty()){
            Fireball fireball = moveFireball(n, fireballQ.front().r+dr[fireballQ.front().d]*fireballQ.front().s, fireballQ.front().c+dc[fireballQ.front().d]*fireballQ.front().s, fireballQ.front().m, fireballQ.front().s, fireballQ.front().d);
            
            if(fireballQ.front().m>0){ //0인 파이어볼 빼기
                fireballMap[{fireball.r, fireball.c}].push_back(fireball);
            }
            fireballQ.pop();
        }

        //{좌표} : 해당 좌표에 해당하는 파이어볼 배열
        //한 칸에 여러개의 파이어볼이 있다면 나누기(r, c 변화는 없고 질량, 속도, 방향 변화만)
        for(auto fm : fireballMap){
            if(fm.second.size()>=2){ //한 칸에 여러 개 있을 때, 나뉘어짐
                int newM=0, newS=0, newD=0, firstD = fm.second[0].d%2; //firstD - 첫 번째 파이어볼 방향 홀수인지 짝수인지 저장
                bool flag = true;

                //모두 방향이 홀수/짝수인가 아닌가 판단
                for(int j=0; j<fm.second.size(); j++){
                    newM += fm.second[j].m;
                    newS += fm.second[j].s;
                    if(fm.second[j].d%2!=firstD){
                        flag = false;
                    }
                }

                if(flag){//모두 방향이 홀수/짝수일 때
                    Fireball fireball1 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 0};
                    Fireball fireball2 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 2};
                    Fireball fireball3 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 4};
                    Fireball fireball4 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 6};

                    fireballQ.push(fireball1);
                    fireballQ.push(fireball2);
                    fireballQ.push(fireball3);
                    fireballQ.push(fireball4);
                }
                else{//방향이 홀수/짝수 섞여있을 때
                    Fireball fireball1 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 1};
                    Fireball fireball2 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 3};
                    Fireball fireball3 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 5};
                    Fireball fireball4 = {fm.first.first, fm.first.second, newM/5, newS/fm.second.size(), 7};

                    fireballQ.push(fireball1);
                    fireballQ.push(fireball2);
                    fireballQ.push(fireball3);
                    fireballQ.push(fireball4);
                }
            }
            else{//다음으로 이동
                Fireball fireball = moveFireball(n, fm.second[0].r, fm.second[0].c, fm.second[0].m, fm.second[0].s, fm.second[0].d);
                fireballQ.push(fireball);
            }
        }

        fireballMap.clear();
    }

    //남아있는 파이어볼 질량 합하기
    while(!fireballQ.empty()){
        //cout<<fireballQ.front().r<<' '<<fireballQ.front().c<<' '<<fireballQ.front().m<<' '<<fireballQ.front().s<<' '<<fireballQ.front().d<<'\n';
        answer += fireballQ.front().m;
        fireballQ.pop();
    }

    cout<<answer;
}