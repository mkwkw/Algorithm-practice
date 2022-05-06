#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, w, l;
    int weight=0, time=0; //현재 다리 위의 하중, 현재 시간 
    queue<int> bridge; //다리 위에 있는 트럭 무게
    vector<int> trucks; //대기 중인 트럭 무게

    cin>>n>>w>>l;

    trucks.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>trucks[i];
    }

    for(int i=0; i<n; i++){
        while(true){
            if(bridge.size()==w){
                weight -= bridge.front();
                bridge.pop();
            }

            if(weight + trucks[i] <= l){
                break;
            }

            bridge.push(0); //트럭의 무게가 l보다 크면 큐에 0을 채워서 큐의 크기가 앞의 트럭의 위치가 되도록 하기
            time++;
        }

        bridge.push(trucks[i]); //대기 중이던 트럭 들어감
        weight += trucks[i];
        time++;
    }

    time += w; //마지막 트럭 나오는 데 걸리는 시간
    cout<<time;
}