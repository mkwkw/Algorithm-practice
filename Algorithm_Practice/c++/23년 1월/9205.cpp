#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        queue<pair<int, int>> q; //갈 수 있는 편의점 담는 큐
        vector<pair<int, int>> conv; //편의점 좌표 담는 벡터
        vector<bool> visited; //방문 체크 - 방문 체크하지 않으면 메모리 초과 발생(큐에 너무 많은 원소가 들어감)

        int n, houseX, houseY, festivalX, festivalY;
        cin>>n>>houseX>>houseY;

        for(int j=0; j<n; j++){
            int convX, convY;
            cin>>convX>>convY;
            conv.push_back({convX, convY});    
        }

        cin>>festivalX>>festivalY;

        //예외처리: 무조건 결과가 happy인 경우, sad인 경우
        if(abs(houseX-festivalX)+abs(houseY-festivalY)<=1000){
            cout<<"happy\n";
            continue;
        }
        else if(abs(houseX-festivalX)+abs(houseY-festivalY)>1000 && n==0){
            cout<<"sad\n";
            continue;
        }
        
        if(conv.size()==0){
            cout<<"sad\n";
            continue;
        }

        q.push({houseX, houseY});

        visited.assign(conv.size(), false);

        bool flag = false; //페스티벌 장소에 갈 수 있으면 while문 진행하면서 true로 바뀌어서 나옴
        
        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;

            //페스티벌 장소에 갈 수 있는가 - 갈 수 있으면 flag를 true로 바꾸고 break
            if(abs(x-festivalX)+abs(y-festivalY)<=1000){
                flag = true;
                break;
            }

            //현재 위치에서 1000m 이내에 있고 방문하지 않은 편의점으로 전진 - 반복
            for(int j=0; j<n; j++){    
                if(!visited[j] && abs(x-conv[j].first)+abs(y-conv[j].second)>0 && abs(x-conv[j].first)+abs(y-conv[j].second)<=1000){
                    q.push({conv[j].first, conv[j].second});
                    visited[j]=true;
                }
            }

            q.pop();

        }

        //while문 이후에 flag 값이 true라면 페스티벌 장소에 갈 수 있고, false라면 페스티벌 장소에 갈 수 없는 것이다.
        if(flag){
            cout<<"happy\n";
        }
        else{
            cout<<"sad\n";
        }
    }
}