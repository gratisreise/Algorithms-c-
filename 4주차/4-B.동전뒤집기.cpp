#include<bits/stdc++.h>
using namespace std;   
const int INF = 1e9;
int n, a[44], ret = INF;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1}; 
string s; 
void go(int here){
	if(here == n + 1){
		int sum = 0; 
		for(int i = 1; i <= (1 << (n - 1)); i *= 2){
			int cnt = 0; 
			for(int j = 1; j <= n; j++) if(a[j] & i)cnt++;
			sum += min(cnt, n - cnt); 
		}
		ret = min(ret, sum);
		return;
	}
	a[here] = ~a[here];
	go(here + 1); //안뒤집고
	a[here] = ~a[here]; //뒤집기
	go(here + 1);// 뒤집고
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	for(int i = 1; i <= n; i++){
		cin >> s; 
		int value = 1; 
		for(int j = 0; j < s.size(); j++){
			if(s[j] == 'T') a[i] |= value; //비트마스킹 쓰기위한 변환
			value *= 2;
		}
	}
	go(1);
	cout << ret << "\n";
    return 0;
}
/*
이 문제는 각 동전의 앞/뒤를 뒤집어서 같은 면으로 만들기 위한 최소 뒤집기 횟수를 구하는 
문제입니다.
해결 방법은 모든 동전의 앞/뒤를 뒤집어보면서, 각각의 경우에 대해 뒤집는 횟수를
 구하고, 이 중에서 최솟값을 구하는 것입니다.
먼저 입력받은 문자열을 이진수로 변환하여 각 동전의 앞/뒤 정보를 저장합니다. 그리고 
각 동전을 뒤집거나 뒤집지 않는 두 가지 경우를 모두 탐색하면서, 
각 경우에 대해 뒤집는 횟수를 구합니다.
이때, 뒤집는 횟수는 비트연산자를 이용하여 구할 수 있습니다. 예를 들어, 
2번째 비트를 뒤집는 경우에는 a[j] ^ (1 << 1)을 이용하면 됩니다.
마지막으로, 모든 경우에 대해 구한 뒤집는 횟수 중에서 최솟값을 구하면 정답이 됩니다.

변수 n은 총 동전의 수, a[]는 각 동전의 앞뒤 상태를 나타내는 변수입니다.
ret은 결과값으로, INF보다 작은 값으로 초기화됩니다.
함수 go()는 재귀함수로서 모든 경우의 수를 다 탐색합니다. 동전을 뒤집는 경우와 안뒤집는 
경우로 모두 재귀적으로 호출하여, 모든 동전을 뒤집거나 뒤집지 않은 경우의 수를 모두 탐색합니다.
이후, 각 동전의 앞뒤 상태를 이진수로 표현하고, 각 자리별로 뒷면의 개수를 셉니다. 
그리고 그 개수 중에서 작은 값을 골라 전체적으로 더하여 결과값을 도출합니다.
주어진 입력에 따라 각 동전의 앞뒤 상태를 입력받습니다. 
이진수로 표현된 문자열을 10진수 값으로 변환하여 저장합니다.
마지막으로 go() 함수를 호출하고, 결과값을 출력합니다.
*/