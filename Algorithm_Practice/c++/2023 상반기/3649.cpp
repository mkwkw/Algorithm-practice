#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    vector<long long> lego;
    long long x, xNm, l1, l2, tempSum;
    int n, left, right, mid;
    
    //�̺�Ž������ �������� ���� - ���� �ð�
    //�Է� ������ �־����� ���� ����
    while(cin>>x>>n){

        xNm = x*10000000;

        lego.assign(n, 0);

        for(int i=0; i<n; i++){
            cin>>lego[i];
        }

        sort(lego.begin(), lego.end());
    
        l1 = 0;
        l2 = 0;
        
        left = 0;
        right = n-1;

        while(left<right){
            mid = (left+right)/2;
            tempSum = lego[left]+lego[right];
                
            if(tempSum==xNm){
                l1 = lego[left];
                l2 = lego[right];
                break;
            }

            if(tempSum>xNm){
                right--;
            }
            else{
                left++;
            }
        }

        if(l1!=0 && l2!=0){
            cout<<"yes "<<l1<<' '<<l2<<'\n';
        }
        else{
            cout<<"danger\n";
        }
    }

}