# Two Pointers
$O(N²)$ 걸릴걸 리니어하게 바꿔주는 매직  
슬라이딩 윈도우와의 차이점은 범위 크기가 고정적이냐 가변적이냐 정도인 것 같다  
코드가 길진 않지만 반복문과 안의 조건문들을 세심하게 짜지 않으면 포인터가 꼬이거나 인덱스 에러의 대환장파티가 펼쳐짐  
## 문제 리스트
|문제|&nbsp;&nbsp;코드&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;풀이&nbsp;&nbsp;&nbsp;&nbsp;|
|:---|:---:|:---:|
|[고냥이](https://www.acmicpc.net/problem/16472)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_16472_고냥이.cpp)| [➡️](#boj-16472-고냥이) |
## 문제 상세
#### BOJ 16472 고냥이
$abbcaccba$라는 문자열을 `pair<char,int>` 배열에 $a1\ b2\ c1\ a1\ c2\ b1\ a1$ 식으로 압축함  
그리고 포함한 문자 종류 관리를 위해 `map<char, int>` 사용  
원래 `set`을 썼는데 이러면 $cacc$같은 케이스에서 왼쪽 포인터 옮기면서 c를 다 제거한걸로 인식되니까 개수도 같이 관리하기 위해 맵을 썼다  
(문자 자체가 몇 자 들어있는지 쓸 필욘 없고 pair덩어리 개수를 넣으면 됨)  
$map.size() == N$을 유지하면서 투포인터를 돌리고 가장 긴 길이 저장하기
