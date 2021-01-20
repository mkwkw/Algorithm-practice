//���� 15663
//��Ʈ��ŷ
//����: https://hidelookit.tistory.com/70
//��
//9 7 9 1
//���
//1 7
//1 9
//7 1
//7 9
//9 1
//9 7
//9 9
import java.util.*;
public class p1 {
	private static int n;
	private static int m;
	private static int arr[];
	private static int ans[];
	private static boolean visited[];
	
	
	private static void func(int start, StringBuilder sb) {
		
		if(start == m) {
			for(int i=0; i<m; i++) {
				sb.append(ans[i]+" ");
			}
			sb.append("\n");
		}
		else {
			//ArrayList�̿�
			ArrayList <Integer> list = new ArrayList <Integer>();
			
			for(int i=0; i<arr.length; i++) {
				
				if(!visited[i]) {//�湮���� �ʾҴ� ��
					
					int count = 0;
					//�ߺ� �˻� //��: 1 7 9 9 
					for(int j=0; j<list.size(); j++) {
						//�ߺ��Ǵ� �� ������ count����
						if(arr[i]==list.get(j))
							count++; 
					}
					
					//ó�� or �ߺ��Ǵ� �� ����
					if(count==0) {
						
						visited[i]= true; //�ش� ���� �湮 ǥ��
						ans[start] = arr[i]; //ó��: ans[0] = 1
						list.add(arr[i]); //1�� list�߰�
						func(start+1, sb); //func(1,sb) ��� �̿�
						visited[i] = false; //���� ���ڷ� �Ѿ
					}
					else {
						continue;
					}
				}
			
			}
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		arr = new int [n]; //n�� ���� ����
		ans = new int [m]; //����� �迭
		visited = new boolean [n]; //n�� ���� ���� �湮 ���� Ȯ��
		
		//n�� ���� ����
		for(int i=0; i<n; i++) {
			arr[i]=sc.nextInt();
		}
		
		//�ʱ�ȭ
		for(int i=0; i<m; i++) {
			ans[i]=0;
		}
		
		//����
		Arrays.sort(arr);
		
		StringBuilder sb = new StringBuilder();
		
		func(0, sb);
		
		System.out.print(sb);
		sc.close();
	}

}
