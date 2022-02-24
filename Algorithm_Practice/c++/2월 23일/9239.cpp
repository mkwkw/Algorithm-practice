#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double x;
    int cnt=0;
    cin>>x;

    for(int i=1; i<100000000; i++){
        string str;
        str = to_string(i);
        int str_size = str.size()-1;
        int str_size1 = pow(10, str_size);
        int b = (i%(str_size1))*10+i/(str_size1);

        if(x==(double)b/(double)i){
            cout<<i<<'\n';
            cnt++;
        } 
         

        // string str_num = str.substr(1, str.size()-1)+str[0];
        // int num = stoi(str_num);
        
        // if(x*i==num){
        //     cout<<i<<'\n';
        //     cnt++;
        // }
    }

    if(cnt==0){
        cout<<"No solution";
    }
}