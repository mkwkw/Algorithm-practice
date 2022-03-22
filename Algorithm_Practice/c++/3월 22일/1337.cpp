#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinCnt(vector<int> &v, int n){
    int cnt=0, min_cnt=5, left, right;
    vector<int> five(4); //v[i] 이후 연속된 숫자 4개 저장할 배열
    sort(v.begin(), v.end()); //오름차순 정렬

    //투 포인터 - left는 v[i] 가리키고, right는 맨 끝 v[n-1] 가리키게 한 다음
    //v[right]가 5개의 연속 숫자 중 제일 큰 것보다 크고 left가 right보다 작을 동안 right 줄이기
    //이렇게 하면 5개의 숫자에 해당하는 숫자들만 left~right 범위에 들어온다.
    //v = {5, 7, 9, 8492, 8493, 192398} 이면 left가 0일 때, right는 2 즉, v[right]=9를 가리킨다.
    for(int i=0; i<n; i++){
        left = i;
        right = n-1;

        for(int j=1; j<5; j++){
            five[j]=v[i]+j;
        }

        while(v[right]>five[4] && left<right){
            right--;
        }

        cnt = right-left+1;
        
        //최소한 필요한 숫자 개수 판별
        if(min_cnt>(5-cnt)){
            min_cnt=5-cnt;
        }
    }

    return min_cnt;
}

int main(){
    vector<int> v; //입력 들어온 수
    int n, answer; //투 포인터 사용
    
    cin>>n;

    v.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];    
    }   

    answer = findMinCnt(v, n);

    cout<<answer;
}