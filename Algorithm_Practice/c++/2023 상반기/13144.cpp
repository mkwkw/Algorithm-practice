#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> num;
    int n;
    long long answer = 0;

    cin>>n;

    num.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    //투 포인터
    int low = 0;
    int high = 0;

    //중복이 발생하면 low를 증가
    set<int> beforeNum;
    while(low<=high && high<n){

        //중복이 발생한 경우
        if(beforeNum.find(num[high])!=beforeNum.end()){ //num[j]가 이전에 나왔던 숫자인 경우
            beforeNum.erase(num[high]);
            //왼쪽에서 중복되는 수의 인덱스를 찾아서 low에 중복인덱스+1해서 넣어야함
            for(int i=low; i<high; i++){
                if(num[i]==num[high]){
                    low = i+1;
                    break;
                }
            }
        }
        //low에서 high까지 경우의 수 더함 
        beforeNum.insert(num[high]);
        answer += (long long)(high-low+1);
        high++;
    }

// O(N^2) 즉 10^10이므로 제한 시간 1초를 넘는다.
/*
    for(int i=0; i<n; i++){
        set<int> beforeNum; //j 이전에 나왔던 수 담는 용도

        for(int j=i; j<n; j++){
            if(beforeNum.find(num[j])!=beforeNum.end()){ //num[j]가 이전에 나왔던 숫자인 경우
                break;
            }
            else{
                beforeNum.insert(num[j]);
                answer++;
            }
        }
    }
*/
    cout<<answer;

}