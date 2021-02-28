//1번
//이상한 하노이 탑
//시도
import java.io.*;
import java.util.*;
public class p45 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		Stack <Integer> st1 = new Stack<Integer>(); //첫 번째 바
		Stack <Integer> st2 = new Stack<Integer>(); //두 번째 바
		Stack <Integer> st3 = new Stack<Integer>(); //세 번째 바
		
		int count = 0; //횟수
		int n = Integer.parseInt(br.readLine());
		
		String brr[] = br.readLine().split(" ");
		
		for(int i=0; i<n; i++) {
			
			st1.push(Integer.parseInt(brr[i]));
		}
		
		int i=n;
		while(i>=1) {
//			
//			
//			for(int j=0; j<st1.size(); j++) {
//				if(st1.peek()==i) {
//					st3.push(st1.pop());
//					count++;
//					i--;
//				}
//				else {
//					st2.push(st1.pop());
//					count++;
//					
//				}
//			}
//			
//			for(int j=0; j<st2.size(); j++) {
//				if(st2.peek()==i) {
//					st3.push(st2.pop());
//					count++;
//					i--;
//				}
//				else {
//					st1.push(st2.pop());
//					count++;
//				}
//			}
//			
			
			for(int k=0; k<12345; k++) {
				if((!st1.isEmpty() && st1.peek()==i) || (!st2.isEmpty() && st2.peek()==i)) {
					if(st1.peek()==i)
						st3.push(st1.pop());
					else
						st3.push(st2.pop());
				}
				
//				else {
//					st1.pop();
//				}
		
				
				if(st1.isEmpty() && !st2.isEmpty()) {
					st1.push(st2.pop());
					count++;
				}
				else if(!st1.isEmpty() && st2.isEmpty()) {
					st2.push(st1.pop());
					count++;
				}
				
				if(st1.isEmpty() && st2.isEmpty())
					break;	
					
			}
			
			
			if(st1.isEmpty() && st2.isEmpty())
				break;
			
		}
		
		System.out.println(count);
		
	}

}
