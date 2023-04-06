#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> num;
    int t, n;

    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n;

        num.assign(n, " ");

        for(int j=0; j<n; j++){
            cin>>num[j];
        }

        sort(num.begin(), num.end()); //string ���� ���� �ڿ����� ���� ������� "119", "91" [0]��° ���� �������, [1]��° ���� �������,, ����

        bool flag = true;
        for(int j=0; j<n-1; j++){

            if(num[j].length()>num[j+1].length()){
                continue;
            }

            if(num[j] == num[j+1].substr(0, num[j].length())){
                flag = false;
                break;
            }
           
        }

        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
}