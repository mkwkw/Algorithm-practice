#include <iostream>
#include <vector>

using namespace std;

bool allLightOn(vector<bool> &road){
    for(int i=0; i<road.size(); i++){
        if(!road[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> road;
    vector<int> pos; //가로등위치

    int n, m, x, h=100000, maxDist = 100000, prevPos = 0;

    cin>>n>>m;

    road.assign(n, false);
    pos.assign(m, 0);

    for(int i=0; i<m; i++){
        cin>>pos[i];
        //maxDist = max(maxDist, pos[i]-prevPos);
        //prevPos = pos[i];
    }

    int minH = 1;
    int maxH = maxDist;
    int midH = 0;
    
    //이분탐색
    while(minH<=maxH){
        midH = (minH+maxH)/2;

        bool canCover = true;

        //양 끝과 가로등 사이 커버 가능 조사
        if(pos[0]>midH){
            canCover = false;
        }
        if(n-pos[m-1]>midH){
            canCover = false;
        }

        for(int i=0; i<m-1; i++){
            if(pos[i+1]-pos[i]>midH*2){
                canCover = false;
                break;
            }
        }

        //빈 곳이 있다면 h증가 필요
        if(!canCover){
            minH = midH+1;
        }
        else{ //빈 곳이 없다면 h줄여도 되는지 조사 필요
            h = min(h, midH);
            maxH = midH-1;
        }
    }
    
    cout<<h;


}