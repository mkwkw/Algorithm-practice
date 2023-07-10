#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//fixed와 precision
//소수 표현의 오차 보정-+0.00000001 
int main(){
    int n, k;
    double partSum = 0, answer1, answer2;
    vector<double> score;

    cin>>n>>k;

    score.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>score[i];    
    }

    sort(score.begin(), score.end());

    //절사 평균
    for(int i=k; i<n-k; i++){
        partSum += score[i];
    }

    answer1 = partSum/(double)(n-2*k)+0.00000001; //round(2.3)->2.0
    
    //보정 평균
    answer2 = (partSum+k*score[k]+k*score[n-k-1])/(double)(n)+0.00000001;
    
    //소수점 아래 셋째자리에서 반올림 & 소수점 아래 둘째자리까지 나타내기
    cout<<fixed;
    cout.precision(2);
    cout<<answer1<<'\n'<<answer2;
}