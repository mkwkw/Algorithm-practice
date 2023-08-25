#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//가장 나중에 넣은 박스를 가장 먼저 뺀다. -> LIFO - STACK
int solution(vector<int> order) {
    stack<int> tempVelt;
    int answer = 0, boxNum = 1;
    
    for(int i=0; i<order.size(); i++){
        while(boxNum<order[i]){
            //cout<<boxNum;
            tempVelt.push(boxNum++);
        }
        
        if(boxNum==order[i]){
            answer++;
            boxNum++;
            continue;
        }
        //cout<<tempVelt.top()<<'\n';
        if(!tempVelt.empty()&&tempVelt.top()==order[i]){
            
            answer++;
            tempVelt.pop();
            continue;
        }
        else{
            break;
        }
    }
    return answer;
}