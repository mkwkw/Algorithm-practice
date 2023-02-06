#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> cnt(9,0);
    string num;
    int answer=0;
    cin>>num;

    for(int i=0; i<num.length(); i++){
        if(num[i]-'0' == 9){
            cnt[6]++;
        }
        else{
            cnt[num[i]-'0']++;
        }
    }

    if(cnt[6]%2==1){
        cnt[6] /= 2;
        cnt[6] += 1;
    }
    else{
        cnt[6] /= 2;
    }

    for(int i=0; i<9; i++){
        answer = max(answer, cnt[i]);
    }

    cout<<answer;

}

//±¸Çö - Á¶°Ç - È¦¼ö/Â¦¼ö