# Dynamic Programming
A.K.A. 동적 계획법  
메모이제이션 잘 하는 방법을 알고싶었지만 천재가 아닌 이상 문제 많이 풀어보고 고이는 수밖에 없는 듯 하다...  
입력이 매트릭스라서 2차원 배열 만들었는데 알고보니 1차원이 답일때 너무 슬프고 억울함😡
## 문제 리스트
|문제|&nbsp;&nbsp;코드&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;풀이&nbsp;&nbsp;&nbsp;&nbsp;|
|:---|:---:|:---:|
|[가장 큰 정사각형](https://www.acmicpc.net/problem/1915)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_1915_가장%20큰%20정사각형.cpp)| [➡️](#boj-1915-가장-큰-정사각형) |
|[출근 경로](https://www.acmicpc.net/problem/5569)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_5569_출근%20경로.cpp)| [➡️](#boj-5569-출근-경로) |
## 문제 상세
#### BOJ 1915 가장 큰 정사각형
`memo[i][j]`: 해당 칸을 최우하단으로 하는 가장 큰 정사각형의 **한 변 길이**  

<img src="https://github.com/gwame/hello_world/assets/39578124/669eb2b2-67e7-4de9-a1a8-63d78212bd4d" width="60%"/>

#### BOJ 5569 출근 경로
$(w-1)$개의 $e$와 $(h-1)$ 개의 $n$을 배치하되, `ene` 또는 `nen` 패턴이 포함되지 않도록 하는 경우의 수
<details>
<summary>
처음엔 재귀함수로 접근했으나 역시나 시간초과
</summary>
<div markdown="1">

```cpp
void sol(string cur, int ecnt, int ncnt) {
	int len = ecnt + ncnt;
	if (len == w + h - 2) {
		ans = (ans + 1) % d;
		return;
	}
	if (ecnt < w - 1) {
		if (len >= 2 && (cur[len - 2] == 'e' && cur[len - 1] == 'n')) {}
		else {
			sol(cur + 'e', ecnt + 1, ncnt);
		}
	}
	if (ncnt < h - 1) {
		if (len >= 2 && (cur[len - 2] == 'n' && cur[len - 1] == 'e')) {}
		else {
			sol(cur + 'n', ecnt, ncnt + 1);
		}
	}
}

sol("", 0, 0);
```

</div>
</details>

$(w, h)$일때 답은 한 행 or 열을 제거했을 때, 즉 $(w-1, h)$와 $(w, h-1)$로부터 구할 수 있음  
이때 2연꺾 제한을 피하기 위해 **경로의 마지막 2방향을 저장**해서 다음 무브가 유효할지 판정한다  
`dp[i][j][k]`: $(i, j)$ 지점까지 이동했고 마지막 2무브가 $k$일때 유효한 경로의 수  
(`ee`, `en`, `nn`, `ne` 가 각각 $k$의 값 $0, 1, 2, 3$에 대응한다)

```cpp
dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][3]) % d;
dp[i][j][1] = dp[i][j - 1][0]; // 앞에서 'ne'로 끝났으면 지금 'en'이 불가
dp[i][j][2] = (dp[i][j - 1][1] + dp[i][j - 1][2]) % d;
dp[i][j][3] = dp[i - 1][j][2]; // 앞에서 'en'으로 끝났으면 지금 'ne'가 불가
```
추가로 $(i, j)$의 답과 $(j, i)$의 답이 동일하므로 (대각선 대칭) dp배열에서 $i≤j$인 경우만 참조하도록 했음  