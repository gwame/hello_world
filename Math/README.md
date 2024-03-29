# Math
수포자는 수학 문제가 싫다  
대부분 정수론 문제를 올릴 예정  
이 카테고리에서는 파이썬이 유리할지도?  
```cpp
// 유클리드 호제법으로 최대공약수 구하는 사골코드
int gcd(int a, int b) {
	if (a < b) { int tmp = a;  a = b;  b = tmp; }
	while (b) { int r = a % b;  a = b;  b = r; }
	return a;
}
```

## 문제 리스트
|문제|&nbsp;&nbsp;코드&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;풀이&nbsp;&nbsp;&nbsp;&nbsp;|
|:---|:---:|:---:|
|[창문 닫기](https://www.acmicpc.net/problem/13909)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_13909_창문%20닫기.cpp)| [➡️](#boj-13909-창문-닫기) |

## 문제 상세
#### BOJ 13909 창문 닫기
$i$번 창문의 개폐 횟수는 약수 개수에 의해 결정됨. 즉 홀짝만 판별하면 ㅇㅋ  
약수 개수의 홀짝 판정은? 오직 완전제곱수만 홀수개 약수를 가진다 {1, 제곱근, 자기자신}  
따라서 1부터 ${i}$까지가 완전제곱수를 몇 개 포함하는지 카운트하면 됨  
이 때 $N$이 최대 21억이므로 $O(N)$은 1초 넘어감. 루트 $N$까지만 헤아리자