#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    string answer = "";
    vector<string> channel;

    cin>>n;

    channel.assign(n,"");

    for(int i=0; i<n; i++){
        cin>>channel[i];
    }

    //KBS1 먼저 찾고 swap, 그다음에 KBS2 찾고 swap(안해도 출력에는 상관없음)
    for(int i=0; i<n; i++){
        if(channel[i]=="KBS1"){
            for(int j=0; j<i; j++){
                answer += "1";
            }
            for(int j=i-1; j>=0; j--){
                answer += "4";
                swap(channel[j], channel[j+1]);
            }

            break;
        }
    }

    for(int i=0; i<n; i++){
        if(channel[i]=="KBS2"){
            for(int j=0; j<i; j++){
                answer += "1";
            }
            for(int j=i-1; j>=1; j--){
                answer += "4";
                swap(channel[j], channel[j+1]);
            }

            break;
        }

    }

    cout<<answer;
}