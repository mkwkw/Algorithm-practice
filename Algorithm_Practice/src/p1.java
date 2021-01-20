//백준 15663
//백트래킹
//참고: https://hidelookit.tistory.com/70
//예
//9 7 9 1
//출력
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
			//ArrayList이용
			ArrayList <Integer> list = new ArrayList <Integer>();
			
			for(int i=0; i<arr.length; i++) {
				
				if(!visited[i]) {//방문하지 않았던 수
					
					int count = 0;
					//중복 검사 //예: 1 7 9 9 
					for(int j=0; j<list.size(); j++) {
						//중복되는 것 있으면 count증가
						if(arr[i]==list.get(j))
							count++; 
					}
					
					//처음 or 중복되는 것 없음
					if(count==0) {
						
						visited[i]= true; //해당 숫자 방문 표시
						ans[start] = arr[i]; //처음: ans[0] = 1
						list.add(arr[i]); //1을 list추가
						func(start+1, sb); //func(1,sb) 재귀 이용
						visited[i] = false; //다음 숫자로 넘어감
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
		
		arr = new int [n]; //n개 숫자 저장
		ans = new int [m]; //출력할 배열
		visited = new boolean [n]; //n개 숫자 각각 방문 여부 확인
		
		//n개 숫자 저장
		for(int i=0; i<n; i++) {
			arr[i]=sc.nextInt();
		}
		
		//초기화
		for(int i=0; i<m; i++) {
			ans[i]=0;
		}
		
		//정렬
		Arrays.sort(arr);
		
		StringBuilder sb = new StringBuilder();
		
		func(0, sb);
		
		System.out.print(sb);
		sc.close();
	}

}
