import java.util.*;
import java.io.*;

class Solution {
    public long solution(int[] sequence) {
        long answer = 0;
        
        //{1,-1,1,...} 곱한 경우
        long minSum = 0;
        long maxSum = 0;
        long[] temp1 = new long [sequence.length];
        temp1[0] = (long)sequence[0]*(-1);
        minSum = Math.min(minSum, temp1[0]);
        maxSum = Math.max(maxSum, temp1[0]);
        
        System.out.print(temp1[0]+" ");
        
        for(int i=1; i<sequence.length; i++){
            if(i%2==0){
                temp1[i] = (long)(sequence[i]*(-1)+temp1[i-1]);
            }
            else{
                temp1[i] = (long)(sequence[i]+temp1[i-1]);
            }
            
            minSum = Math.min(minSum, temp1[i]);
            maxSum = Math.max(maxSum, temp1[i]);
            System.out.print(temp1[i]+" ");
        }
        System.out.println(minSum + " " + maxSum);
        
        answer = Math.max(answer, maxSum-minSum);
        
        minSum = 0;
        maxSum = 0;
        long[] temp2 = new long [sequence.length];
        temp2[0] = (long) sequence[0];
        minSum = Math.min(minSum, temp2[0]);
        maxSum = Math.max(maxSum, temp2[0]);
        System.out.print(temp2[0]+" ");
        
        for(int i=1; i<sequence.length; i++){
            if(i%2==0){
                temp2[i] = (long)(sequence[i]+temp2[i-1]);
            }
            else{
                temp2[i] = (long)(sequence[i]*(-1)+temp2[i-1]);
            }
            
            minSum = Math.min(minSum, temp2[i]);
            maxSum = Math.max(maxSum, temp2[i]);
            System.out.print(temp2[i]+" ");
            
        }
        
        
        answer = Math.max(answer, maxSum - minSum);
        
        return answer;
    }
}