# Dynamic Programming
A.K.A. 동적 계획법  
메모이제이션 잘 하는 방법을 알고싶었지만 천재가 아닌 이상 문제 많이 풀어보고 고이는 수밖에 없는 듯 하다...  
입력이 매트릭스라서 2차원 배열 만들었는데 알고보니 1차원이 답일때 너무 슬프고 억울함😡
## 문제 리스트
|문제|&nbsp;&nbsp;코드&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;풀이&nbsp;&nbsp;&nbsp;&nbsp;|
|:---|:---:|:---:|
|[가장 큰 정사각형](https://www.acmicpc.net/problem/1915)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_1915_가장%20큰%20정사각형.cpp)| [➡️](#boj-1915-가장-큰-정사각형) |
## 문제 상세
#### BOJ 1915 가장 큰 정사각형
memo[i][j]: 해당 칸을 최우하단으로 하는 가장 큰 정사각형의 **한 변 길이**  

![dp](https://github.com/gwame/hello_world/assets/39578124/669eb2b2-67e7-4de9-a1a8-63d78212bd4d)