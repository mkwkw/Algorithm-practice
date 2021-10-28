#include <cstdio> 
#include <vector>
#include <cmath>

using namespace std;

//소수점 넷째자리에서 반올림하는 것 나오므로 iostream보다 cstdio 사용해서 .3lf하는 것이 편하다.

int main(){

    vector<double> v; //자기자신보다 누적곱 값이 크면 저장, 아니면 자기자신 저장
    int n;
    double res=0;

    scanf("%d", &n);
    v.assign(n,0);

    for(int i=0; i<n; i++){
        scanf("%lf", &v[i]); //초기화
        res = max(res, v[i]); //제일 큰 원소 저장
    }

    for(int i=1; i<n; i++){
        v[i]=max(v[i], v[i]*v[i-1]); //자기 자신보다 곱이 크면 곱 저장 아니면 자기 자신 저장
        res = max(res, v[i]);
    }

    printf("%.3lf",res);

}