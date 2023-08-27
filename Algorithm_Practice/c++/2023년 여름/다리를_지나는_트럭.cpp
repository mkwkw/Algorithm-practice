#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//큐
//while문 잘 사용하기 - 조건에 따라 잘 나누기
//조건에 따라 계속 넣고, 계속 빼고 
//empty 체크 후 front 조회, idx 범위 체크 후 vector 접근
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int answer = 0, currentWeight = 0, idx = 0;
    
    //일단 조건 만족하면 계속 넣기
    while(idx<truck_weights.size() && currentWeight+truck_weights[idx]<=weight && bridge.size()<bridge_length){
        currentWeight += truck_weights[idx];
        bridge.push(truck_weights[idx++]);
        answer++;
    }
    
    //다리를 바로 못들어가는 경우 - 0 넣어서 bridge 크기를 bridge_weight만큼 만든 다음에 빼야함.
    while(bridge.size()<bridge_length){
        bridge.push(0);
        answer++;
    }
    
    if(idx==truck_weights.size()){
        while(currentWeight>0){
            if(bridge.front()>0){
                currentWeight -= bridge.front();
            }
            bridge.pop();
            answer++;
        }
        
        return answer;
    }
    
    //무게
    while(idx<truck_weights.size()){
        
        //조건!!
        while(!bridge.empty() && idx<truck_weights.size() && currentWeight-bridge.front()+truck_weights[idx]>weight){
            currentWeight -= bridge.front();
            bridge.pop();
            if(currentWeight+truck_weights[idx]<=weight){
                bridge.push(truck_weights[idx]);
                currentWeight += truck_weights[idx++];
            }
            else{
                bridge.push(0);
            }

            answer++;
        }
        
        // currentWeight+truck_weights[idx]<=weight
        while(!bridge.empty() && idx<truck_weights.size() && currentWeight-bridge.front()+truck_weights[idx]<=weight){
            currentWeight -= bridge.front();
            bridge.pop();
            bridge.push(truck_weights[idx]);
            currentWeight += truck_weights[idx++];
            answer++;
        }
    }
    
    while(currentWeight>0){
        currentWeight -= bridge.front();
        bridge.pop();
        answer++;
    }
    
    return answer;
}