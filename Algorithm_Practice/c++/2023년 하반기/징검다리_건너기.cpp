#include <string>
#include <vector>
#include <iostream>

using namespace std;

//while+for 반복문 - 3중 반복문 - 시간초과! (정확성 테스트케이스는 다 맞음)
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    while(true){
        int pos = -1; //시작 지점
        //cout<<pos<<' '<<stones.size()<<'\n';
        while(pos<(long long)stones.size()){
            cout<<"pos"<<pos<<'\n';
            bool flag = true;
            for(int j=1; j<=k; j++){
                if(pos+j<stones.size() && stones[pos+j]>0){
                    stones[pos+j] -= 1;
                    pos = pos+j;
                    flag = false;
                    break;
                }
                if(pos+j>=stones.size()){ //다리를 다 건넜을 때
                    pos = pos+j;
                    flag = false;
                    break;
                }
            }
            if(flag){
                return answer;
            }
        }
        answer++;
    }
    return answer;
}

int main(){
    int answer;
    vector<int> v = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    answer = solution(v,3);
    cout<<answer;
}