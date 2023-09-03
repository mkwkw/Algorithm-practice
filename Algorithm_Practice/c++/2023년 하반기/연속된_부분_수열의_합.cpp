#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//투 포인터
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer, partSum;
    int left = 0, right = partSum.size()-1, mid;
    
    answer.assign(2,0);
    partSum.assign(sequence.size()+1, 0);
    
    sort(sequence.begin(), sequence.end());
    
    answer[0]=0;
    answer[1]=partSum.size()-1;
    
    partSum[1] = sequence[0];
    
    for(int i=2; i<partSum.size(); i++){
        partSum[i] = partSum[i-1]+sequence[i-1];
    }
    
    for(int i=0; i<partSum.size(); i++){
        cout<<partSum[i]<<' ';
    }
    
    
    // while(left<right){
    //     if(partSum[right]-partSum[left]>=k){ //범위를 좁혀야함
    //         if(partSum[right]-partSum[left]==k){
    //             answer[0] = left;
    //             answer[1] = right-1;
    //         }
    //         right--;
    //     }
    //     else{ //범위를 늘려야함
    //         left++;
    //     }
    // }
    
    //이분탐색?
    for(int i=0; i<partSum.size(); i++){
        left = i;
        right = partSum.size()-1;
        while(left<right){
            cout<<"left "<<left<<" right "<<right<<" mid "<<mid<<'\n';
            mid = (left+right)/2;
            if(partSum[mid]-partSum[left]>=k){
                right = mid-1;
                if(partSum[mid]-partSum[left]==k && mid-1-left<=answer[1]-answer[0]){
                    answer[0] = left;
                    answer[1] = mid-1;
                    cout<<answer[0]<<' '<<answer[1]<<'\n';
                }
            }
        }
    }
    
    return answer;
}

int main(){
    vector<int> answer;

    answer = solution({1,2,3,4,5}, 7);

    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<'\n';
    }
}