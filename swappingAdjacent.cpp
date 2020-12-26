/*
given a string obtain the alphabetically smallest string 
possible by swapping either adjacent a and b characters or 
adjacent b and c characters any number of times
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	stack <char> s;
	int n = str.length()-1;
	for(int i=n; i>=0 ;i--){
	    s.push(str[i]);
	}
	stack<char> p;
	
	p.push(s.top());
	s.pop();
	while(!s.empty()){
	    if ((p.top() == 'b' && s.top() =='a') || (p.top() == 'c' && s.top() =='b')){
	        char sTop = s.top();
	        s.pop();
	        s.push(p.top());
	        p.pop();
	        while(!p.empty() && ((sTop == 'a' && p.top() == 'b')) || (sTop == 'b' && p.top() == 'c')) {
	            s.push(p.top());
	            p.pop();
	        }
	        p.push(sTop);
	    } else{
	        p.push(s.top());
	        s.pop();
	    }
	}
	while(!p.empty()) {
	    str[n] = p.top();
	    p.pop();
	    n--;
	}
	cout <<str <<endl;
	return 0;
}

/*
E.g: 1
input : abaacbac
output: aaabbcac

E.g: 2
input : baacba
output: aabbca

E.g: 3
input : ababbaab
output: aaaabbbb
*/