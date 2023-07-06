#include <string>
#include <vector>

using namespace std;

//n보다 큰 자연수
//이진수 -> 1의 개수 같은 경우
//정확한 이진수를 구하려면 stack 사용 
//but, 이 문제에서는 "이진수"가 중요한 게 아니라, 1의 개수가 중요
//stack 사용할 필요 없음

//이진수에서 1의 개수 구하기
int countOneCnt(int num){
    int nextDec = num, oneCnt=0;
    
    while(nextDec>0){
        if(nextDec%2==1){
            oneCnt++;
        }
        nextDec /= 2;
    }
    
    return oneCnt;
}

int solution(int n) {
    int answer = 0;
    int nOneCnt = 0;
    
    nOneCnt = countOneCnt(n);
    
    for(int i=n+1; i<=1000000; i++){
        if(countOneCnt(i)==nOneCnt){
            answer = i;
            break;
        }
    }
    return answer;
}