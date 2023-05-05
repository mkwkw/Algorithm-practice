#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    vector<int> num;

    cin>>n>>s;

    num.assign(n, 0);
    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    int low = 0, high = 0, answer = 0;
    int tempSum = num[0];
    int tempLen = n+1;
    while(low<=high && high<n){
        if(tempSum>=s){ //길이 비교
            tempLen = min(tempLen, high-low+1);
            //cout<<high<<" "<<low<<' '<<tempSum<<'\n';
            tempSum -= num[low];
            ++low;
        }
        else{ //tempSum이 s보다 작으면 high를 높여서 원소를 하나 더 더함.
            ++high;
            tempSum += num[high];
        }
    }

    //부분합으로 s이상의 수를 만들 수 없는 경우
    if(tempLen<n+1){
        answer = tempLen;
    }

    cout<<answer;

}