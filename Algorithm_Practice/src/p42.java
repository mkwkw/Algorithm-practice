//9012
//Ω∫≈√
import java.util.*;
import java.io.*;
public class p42 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String pa[] = new String [n];
		
		
		
		for(int i=0; i<n; i++) {
			pa[i]="YES";
			Stack <String> st = new Stack<String>();
		
			String arr[] = br.readLine().split("");
		
			for(int j=0; j<arr.length; j++) {
				if(arr[j].equals("("))
					st.push("(");
				else {
					if(!st.isEmpty())
						st.pop();
					else {
						pa[i]="NO";
						break;
					}
				}
				
			}
			
			if(!st.isEmpty()) {
				pa[i]="NO";
			}
			
			
		}
		
		for(int i=0; i<n; i++) {
			System.out.println(pa[i]);
		}
	}

}
