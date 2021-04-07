import java.io.*;
import java.util.*;
public class p4889 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int idx=1;
		while(true) {
			
			String arr[] = br.readLine().split("");
			
			if(arr[0].equals("-"))
				break;
			
			int sum=0;
			int result=0;
			//스택 사용
			Stack<String> st = new Stack<String>();
			
			for(int i=0; i<arr.length; i++) {
				//{이면 스택에 저장
				if(arr[i].equals("{")) {
					st.add("{");
				}
				else {
					//}일 때 스택이 비어있지 않다면({이 있다면) pop
					if(!st.isEmpty()) {
						st.pop();
					}
					else {
						//}일 때 스택이 비어있다면 안정적이지 않은 문자열 이므로 {으로 바꿔주고 스택에 이것을 넣어준다.
						arr[i]="{";
						st.add("{");
						result++; //바꿔준 것이므로 result++
						
					}
						
				}
				
				
			}
			
			if(!st.isEmpty()) { //{{을 입력받았을 때에도 {}로 하나만 바꾸면 되므로 result에 size/2를 더하면 된다. 
					result += st.size()/2;
				}
			
			System.out.println(idx+". "+result);
			idx++;
		}
		br.close();

	}

}
