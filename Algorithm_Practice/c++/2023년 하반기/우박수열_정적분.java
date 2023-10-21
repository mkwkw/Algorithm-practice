import java.util.*;

class Solution {
    class Num{
        private int num;
        private int now;
        private ArrayList<Integer> nums;
        
        public Num(int num, int now, ArrayList<Integer> nums){
            this.num = num;
            this.now = now;
            this.nums = nums;
        }
    }
    
    public double[] solution(int k, int[][] ranges) {
        double[] answer = {};
        Queue<Num> q = new LinkedList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(k);
        
        q.offer(new Num(k, k, temp));
        while(q.peek().now!=1){
            
            Num n = q.poll();
            int num = n.num;
            int now = n.now;
            ArrayList<Integer> nums = n.nums;
            
            if(now%2==0){
                nums.add(now/2);
                q.offer(new Num(k, now/2,nums));
            }
            else{
                nums.add(now*3+1);
                q.offer(new Num(k, now*3+1, nums));
            }
        }
        
        Num n = q.poll();
        int num1 = n.num;
        ArrayList<Integer> nums1 = n.nums;
        ArrayList<Double> results1 = new ArrayList<>();
        results1.add(0.0);
        for(int i=1; i<nums1.size(); i++){
            Double result = results1.get(i-1)+Double.valueOf((nums1.get(i-1)+nums1.get(i))/2);
            results1.add(result);
        }
        
        ArrayList<Double> answerList = new ArrayList<>();
        for(int i=0; i<ranges.length; i++){
             int x1 = ranges[i][0];
             int x2 = nums1.size()+ranges[i][1];
             //Double result = results1.get(x2)-results1.get(x1);
             //answerList.add(result);
        }
        //Double[] arr = answerList.toArray(new Double[answerList.size()]);
        //answer = new double[arr.length];
        
        // for(int i=0; i<arr.length; i++){
        //     answer[i] = arr[i];
        // }
        return answer;
    }
}