#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1; //만나는 라운드
    int smaller = min(a,b);
    int bigger = max(a,b);
        
    while(bigger/2+bigger%2 != smaller/2+smaller%2){
        bigger = bigger/2+bigger%2;
        smaller = smaller/2+smaller%2;
        answer++;
    }

    return answer;
}