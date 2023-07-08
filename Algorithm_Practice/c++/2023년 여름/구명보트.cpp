#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//정렬 필요!
//이중 for문 -> 시간초과 - 앞에서부터 탐색 for문 & 뒤에서부터 탐색 for문
//투 포인터로 while문 한 번만 -> 통과 - left는 0부터, right는 people.size()-1부터

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0, right = people.size()-1;
    
    sort(people.begin(), people.end());
    
    while(left<right){
        if(people[left]+people[right]<=limit){
            people[left] = -1;
            people[right] = -1;
            answer++;
            
            left++;
            right--;
        }
        else{
            right--;
        }
    }
    
    for(int i=0; i<people.size(); i++){
        if(people[i]!=-1){
            answer++;
        }
    }
    return answer;
}