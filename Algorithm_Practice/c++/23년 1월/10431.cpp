#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int t, tc, height, cnt;
    
    cin>>t;

    for(int i=0; i<t; i++){
        cnt=0;
        vector<int> heights(20);
        
        cin>>tc;
        for(int j=0; j<20; j++){
            cin>>heights[j];
        }

        for(int j=0; j<20; j++){
            for(int k=0; k<j; k++){
                if(heights[k]>heights[j]){
                    cnt++;
                }
            }
        }
    
        cout<<tc<<' '<<cnt<<'\n';
    }

}

//과정
//1. 오름차순정렬이 필요할 것 같아서 set을 사용하여 학생들의 키를 넣고 키 입력이 들어올 때마다 크기 비교하여 결과 도출 - 틀렸습니다. & 너무 복잡
//2. 생각해보니 벡터에 넣고 자신의 앞에 있는 원소 중에 자신보다 작은 값인 것 개수 세서 더하면 됨. 