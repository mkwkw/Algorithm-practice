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
			//���� ���
			Stack<String> st = new Stack<String>();
			
			for(int i=0; i<arr.length; i++) {
				//{�̸� ���ÿ� ����
				if(arr[i].equals("{")) {
					st.add("{");
				}
				else {
					//}�� �� ������ ������� �ʴٸ�({�� �ִٸ�) pop
					if(!st.isEmpty()) {
						st.pop();
					}
					else {
						//}�� �� ������ ����ִٸ� ���������� ���� ���ڿ� �̹Ƿ� {���� �ٲ��ְ� ���ÿ� �̰��� �־��ش�.
						arr[i]="{";
						st.add("{");
						result++; //�ٲ��� ���̹Ƿ� result++
						
					}
						
				}
				
				
			}
			
			if(!st.isEmpty()) { //{{�� �Է¹޾��� ������ {}�� �ϳ��� �ٲٸ� �ǹǷ� result�� size/2�� ���ϸ� �ȴ�. 
					result += st.size()/2;
				}
			
			System.out.println(idx+". "+result);
			idx++;
		}
		br.close();

	}

}
