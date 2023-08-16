#include <string>
#include <set>

using namespace std;

//set - 중복 제거!!
//방문 체크 - set<set<pair<int,int>>> - set<pair<int,int>>
//(r1,c1)->(r,c)와 (r,c)->(r1,c1)은 같은 길을 지나는 것이므로 set을 이용해서 동일하게 판별 
//각 경로를 set에 저장해서 중복 경로 없게 저장
//범위 체크 - verify - r과 c가 각각 -5, 5를 넘지 않도록 판별
bool verify(int r, int c){
    if(r<-5 || c<-5 || r>5 || c>5){
        return false;
    }
    return true;
}

int solution(string dirs) {
    int answer = 0, r = 0, c = 0, r1 = 0, c1 = 0;
    set<set<pair<int,int>>> path;
    set<pair<int,int>> move;
    
    for(int i=0; i<dirs.length(); i++){
        r1 = r;
        c1 = c;
        switch(dirs[i]){
            case 'U':
                if(verify(r+1,c)){
                    r += 1;
                }
                break;
            case 'D':
                if(verify(r-1,c)){
                    r -= 1;
                }
                break;
            case 'L':
                if(verify(r,c-1)){
                    c -= 1;
                }
                break;
            case 'R':
                if(verify(r,c+1)){
                    c += 1;
                }
                break;
        }
        
        if(!(r1==r&&c1==c)){
            move.insert({r1,c1});
            move.insert({r,c});
            path.insert(move);
        }
        
        move.clear();
    }
    
    answer = path.size();
    return answer;
}