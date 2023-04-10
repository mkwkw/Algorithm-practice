#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> money;
    int n, sum = 0, total;
    cin>>n;

    money.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>money[i];
        sum += money[i];
    }

    sort(money.begin(), money.end());

    cin>>total;

    //1. ������ �־��� ���� ������ ���
    //2. ������ �־��� ���� �ʰ��� ���
    if(total>=sum){
        cout<<money[n-1];
    }
    else{ //���Ѿ� ã�ƾ���

        //�̺� Ž��
        /**
         * left:1, right: money[n-1]
         * mid = (left+right)/2
         * if(mid*n>total){
         *      right = mid-1;
         * }
         * else if(mid*n<total){
         *      left = mid+1;
         * }
         * 
        */

        int left = 1;
        int right = money[n-1];
        int mid;
        int tempSum;

        while(left<right){
            mid = (left+right)/2;
            tempSum = 0;

            for(int i=0; i<n; i++){
                if(money[i]<mid){
                    tempSum += money[i];
                }
                else{
                    tempSum += mid;
                }
            }

            //cout<<"left: "<<left<<" right: "<<right<<" mid: "<<mid<<" tempSum: "<<tempSum<<'\n';

            if(tempSum>total){
                right = mid-1;
            }
            else if(tempSum<total){
                left = mid+1;
            }
            else{
                break;
            }
        }

        if(tempSum<total){
            while(tempSum<total){
                mid++;
                tempSum = 0;
                for(int i=0; i<n; i++){
                    if(money[i]<mid){
                        tempSum += money[i];
                    }
                    else{
                        tempSum += mid;
                    }
                }

                //���� while������ tempSum�� total���� Ŀ���� ������ ��, �ٽ� mid�� �ٿ��� tempSum�� total���� �۾����� �������Ѵ�.
                if(tempSum>total){
                    mid--;
                    break;
                }
            }
        }
        else if(tempSum>total){
            while(tempSum>total){
                mid--;
                tempSum = 0;
                for(int i=0; i<n; i++){
                    if(money[i]<mid){
                        tempSum += money[i];
                    }
                    else{
                        tempSum += mid;
                    }
                }
            }
        }


        cout<<mid;
        
    }


    

}