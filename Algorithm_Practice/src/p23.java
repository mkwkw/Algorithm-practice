//백준 17299
//오등큰수
//스택
import java.io.*;
import java.util.*;
public class p23 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		
		String brr[] = br.readLine().split(" ");
		int num[] = new int[n];
		int f[] = new int [1000001];
		int ngf[] = new int [n];
		for(int i=0; i<n; i++) {
			num[i] = Integer.parseInt(brr[i]);
			f[num[i]]++;
			
		}
		
		Stack<Integer>stack = new Stack<Integer>();
		
		stack.push(0);
		//인덱스를 담음
		for(int i=1; i<n; i++) {
			if(stack.isEmpty())
				stack.push(i);
			
			//개수 비교
			while(!stack.isEmpty()&&f[num[i]]>f[num[stack.peek()]]) {
			
				ngf[stack.pop()]=num[i];
			}
			stack.push(i);
		}
		
		while(!stack.isEmpty()) {
			ngf[stack.pop()]--;
		}
		
		for(int i=0; i<n; i++) {
			sb.append(ngf[i]+" ");
			
		}
		System.out.print(sb);
		br.close();
	}

}
