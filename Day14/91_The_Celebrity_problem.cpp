// https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); returns "true" if the person having
	id 'A' know the person hav
    Function 'knows(A, B)' will ing id 'B' in the party, "false" otherwise.
*/
#include<queue>
int findCelebrity(int n) {
 	vector<int> visited(n, 0), popularity(n, 0), friends(n, 0);
    
//     for(int i =0 ;  i <n ;i++){ TLE T-T
//         for(int j = 0; j < n;j++){
//             if(i == j) continue;
//             if(knows(i, j)){
//                 hasVisited[i]++;
//                 isVisited[j]++;
//             }
//         }
//     }
    
    queue <int> q;
    q.push(0);
    visited[0]++;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(x == i) continue;
            if(knows(x, i) || knows(i, x)){
                if(visited[i]++ == 0){ q.push(i);}
                if(knows(i, x)){popularity[x]++;}
                if(knows(x, i)) {friends[x]++;}
            }
        }
    }
    
    for(int i = 0; i < n; i++){
//         cout<<isVisited[i]<<' '<<hasVisited[i]<<' ';
        if(popularity[i] == n - 1 && friends[i] == 0) return i;
    }
    
    return -1;
}