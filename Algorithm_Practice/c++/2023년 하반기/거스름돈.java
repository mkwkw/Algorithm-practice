import java.util.*;
import java.io.*;
//dp
//money에 있는 화폐 단위 - 경우의 수
//총 합계 금액 중심으로 dp -> 중복 거르기 힘듦
//화폐 단위 중심으로 dp!
class Solution {
    public int solution(int n, int[] money) {
        int answer = 0;
        int[] way = new int[100001];
        
        way[0] = 1;
        
        //dp - 화폐 단위 중심으로 순회
        //화폐 단위로 한 층씩 쌓는 느낌
        //전 것을 한 묶음으로 갖고와서 붙이는 느낌
        //         (0)+2,   (1)+2, (1+1)+2, (2)+2
        //  (0)+1, 1+1,     1+1+1, 1+1+1+1
        //0
        for(int i=0; i<money.length; i++){
            for(int j=money[i]; j<=100000; j++){
                way[j] += way[j-money[i]];
                way[j] %= 1000000007;
            }
        }
        
        answer = way[n];
       
        return answer;
    }
}