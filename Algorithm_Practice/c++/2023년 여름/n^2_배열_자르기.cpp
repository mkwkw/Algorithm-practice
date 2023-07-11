#include <string>
#include <vector>
#include <iostream>

using namespace std;

//idx/n이 row, idx%n이 col, 들어가는 숫자는 max(row, col)+1
//left~right까지 인덱스 돌면서 /,%연산
//2중 for문 사용하면 시간초과
//left와 right가 long long이므로 주의!
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i=left; i<=right; i++){    
        answer.push_back(max(i/n,i%n)+1);
    }

    return answer;
}