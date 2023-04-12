#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<long long> price;
    int t;

    cin>>t;

    for(int tc=0; tc<t; tc++){
        long long profit = 0; //갖고 있는 주식, 얻는 이익
        long long maxPrice = 0;
        int n;

        cin>>n;

        price.assign(n, 0);

        for(int i=0; i<n; i++){
            cin>>price[i];
        }

        //역으로 탐색 - 2중 for문으로 하면 시간초과 발생
        for(int i=n-1; i>=0; i--){

            if(price[i]>=maxPrice){
                //maxPrice 다시 설정
                maxPrice = price[i];
            }
            else{
                profit += maxPrice-price[i];
            }
        }

        cout<<profit<<'\n';
    }
}