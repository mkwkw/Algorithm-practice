#include <string>
#include <vector>
#include <iostream>

using namespace std;

//numbers의 각 원소에 -붙여서 계산해보고 안붙여서 계산해보고 다 해봐야함
//dfs
int answer = 0;

void dfs(int temp, int target, int idx, int size, vector<int>&numbers){
    //cout<<temp<<' '<<target<<' '<<idx<<' '<<size<<'\n';
    if(idx==size){
        if(temp == target){
            answer++;
        }
        return;
    }
    
    dfs(temp+numbers[idx], target, idx+1, size, numbers);
    dfs(temp+numbers[idx]*(-1), target, idx+1, size, numbers);
}

int solution(vector<int> numbers, int target) {
    int temp = 0;

    dfs(numbers[0], target, 1, numbers.size(), numbers);
    dfs(numbers[0]*(-1), target, 1, numbers.size(), numbers);
    
    return answer;
}