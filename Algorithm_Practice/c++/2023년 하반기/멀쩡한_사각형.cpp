#include <iostream>

using namespace std;

//수학
//직선 만들기: y = (h/w)x + h
//주의! 데이터형 변환
long long solution(int w,int h) {
    long long answer = 0;
    double slope = (double)h/w;
    
    for(int i=1; i<=w; i++){
        //모두 double로 바꾸어서 계산하고 마지막에 long long으로 형변환
        answer += (long long)((slope)*i*(-1)+(double)h); 
    }

    return answer*2;
}