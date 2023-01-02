#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, x;
    long long answer=0, temp=0;
    vector<long long> visitors;
    map<long long, int> subsum;

    cin>>n>>x;

    for(int i=0; i<n; i++){
        long long num;
        cin>>num;
        visitors.push_back(num);
    }

    //맨앞 구간 합
    for(int i=0; i<x; i++){
        answer += visitors[i];
    }

    subsum.insert({answer, 1});

    temp = answer;

    for(int i=1; i<=n-x; i++){
        temp -= visitors[i-1];
        temp += visitors[i+x-1];
        if(temp>=answer){
            answer = temp;
            if(subsum.find(answer)==subsum.end()){
                subsum.insert({answer, 1});
            }
            else{
                subsum[answer]++;
            }
        }
    }

    if(answer!=0){
        cout<<answer<<'\n';
        cout<<subsum[answer];
    }
    else{
        cout<<"SAD";
    }
}

//슬라이딩 윈도우
//과정
//1. 방문자 수 저장할 벡터 필요
//2. 슬라이딩 윈도우 이용 - 처음 값(인덱스 0~x-1) 저장
//3. 하나씩 이동하면서 맨앞에 값 빼고 맨뒤에 값 더하면서 진행 - 최댓값 얻기
//4. 최댓값이 나타나는 횟수도 구해야하므로 map {방문자수 누적합, 해당 누적합인 기간 개수} 만들어서 사용
 