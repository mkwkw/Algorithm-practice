import java.util.*;
import java.io.*;

//풍선 기준 왼쪽에서 가장 작은 값과 오른쪽에서 가장 작은 값 각각 비교
//rightMin==a[i]일 때, i+1부터 끝까지 배열 잘라서 정렬하는 식
//시간초과 - 8/15 테스트케이스
class Solution {
    class numAndIdx{
        int num;
        int idx;
        
        public numAndIdx(int num, int idx){
            this.num = num;
            this.idx = idx;
        }
    }
    
    public int solution(int[] a) {
        int answer = 0;
        int leftMin = -1000000001;
        int rightMin = -1000000001;
        int[] temp = Arrays.copyOf(a, a.length);
        
        //a의 길이가 1이나 2일 때
        if(a.length==1 || a.length==2){
            return a.length;
        }
        
        //a의 길이가 3이상일 때
        Arrays.sort(temp, 2, temp.length); //인덱스 2부터 끝까지 정렬
        answer = 2; //맨 처음과 맨 끝은 항상 가능
        rightMin = temp[2];
        leftMin = temp[0];
        
        for(int i=1; i<a.length-1; i++){
            
            if(rightMin == a[i]){
                temp = Arrays.copyOfRange(a, i+1, a.length);
                Arrays.sort(temp);
                // for(int j=0; j<temp.length; j++){
                //     System.out.print(temp[j]+" ");
                // }
                rightMin = temp[0];
                
            }
            
            //System.out.println("leftMin "+leftMin+" "+a[i]+" rightMin "+rightMin);
            if(leftMin<a[i] && rightMin<a[i]){
                continue;
            }
            answer++;
            
            if(leftMin>a[i]){
                leftMin = a[i];
            }
        }
        
        return answer;
    }
}