#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int answer = 0, currentLength = 0, currentWeight = 0, idx = 0;
    
    //처음 넣었을 때
    bridge.push(truck_weights[0]);
    answer = 1;
    currentLength = 1;
    currentWeight = truck_weights[0];
    idx++;
    
    while(!bridge.empty()&&idx<truck_weights.size()){
        while(currentWeight+truck_weights[idx]>weight){ //큐에 0 계속 넣어서 currentWeight+truck_weights[idx]가 weight보다 작거나 같을 때까지 앞에 거 나오도록 하기
            //0 넣기
            while(bridge.size()<bridge_length){
                bridge.push(0);
                answer++;
            }
            //하나빼고
            if(bridge.front()>0){
                currentLength--;
            }
            currentWeight -= bridge.front();
            bridge.pop();
        }
        
        currentWeight += truck_weights[idx];
        bridge.push(truck_weights[idx]);
        answer++;
        currentLength++;
    }
    
    while(currentLength>0){
        bridge.push(0);
        if(bridge.front()>0){
            currentLength--;
        }
        bridge.pop();
        answer++;
    }
    
    return answer;
}

int main(){
    cout<<solution(2, 10, {7,4,5,6});
}