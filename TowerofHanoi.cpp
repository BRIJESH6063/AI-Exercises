#include<bits/stdc++.h>
using namespace std ;

void TowerofHanoi(int n, char from, char to, char aux)
{
	if(n == 0 ) return ;
	TowerofHanoi(n-1, from, aux, to) ;
	cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl ;
	TowerofHanoi(n-1, aux, to, from) ;
}   

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL) ;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
	#endif 
	
	int n ; cin >> n ;
	TowerofHanoi(n, 'A', 'B', 'C') ;

	return 0 ;
}
