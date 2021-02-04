//백준 4949
//균형잡힌 세상
//스택
import java.util.*;
import java.io.*;
public class p26 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String ans[] = new String [1000001];
		int idx=0;
		while(true) {
			boolean flag = true;
			String s = br.readLine();
			if(s.equals("."))
				break;
			
			char brr[] = s.toCharArray();
			
			
			Stack<Character> st = new Stack<Character>();
			
			if(brr[0]=='.' && brr.length==1)
				break;
			
			for(int i=0; i<brr.length; i++) {

				if(brr[i]=='(')
					st.push('(');
				
				else if(brr[i]=='[')
					st.push('[');
				
				else if(brr[i]==']') {
					if(!st.isEmpty() && st.peek()=='[') {
						
							st.pop();
					}
					else {
						flag = false;
						break;
					}

				}
				else if(brr[i]==')') {
					if(!st.isEmpty() && st.peek()=='(') {
						
							st.pop();
					}
					
					else {
						flag = false;
						break;
					}

				}
				
			}	
			if(st.isEmpty() && flag)
				ans[idx]="yes";
			else 
				ans[idx]="no";	
			
			idx++;
			
		}
		
		for(int i=0; i<idx; i++) {
			System.out.println(ans[i]);
		}
		
	}

}
