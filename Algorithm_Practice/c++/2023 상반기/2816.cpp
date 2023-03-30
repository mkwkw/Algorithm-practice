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

    //KBS1 ���� ã�� swap, �״����� KBS2 ã�� swap(���ص� ��¿��� �������)
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