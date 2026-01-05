# 이중배열 선언 -> vector 로 선언하는 방법
## n행 m열의 벡터를 만드는 방식 -> 이중배열.
vector<vector<int>> arr(n, vector<int>(m));

## 크기가 m 인 1차원 벡터를 만드는 방법.
vector<int> v(m);
