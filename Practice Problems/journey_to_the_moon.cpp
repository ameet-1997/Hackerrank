//Problem link : https://www.hackerrank.com/challenges/journey-to-the-moon

#include <bits/stdc++.h>

using namespace std;
#define pb push_back


vector< vector<long long> > graph(100000);
vector<long long> visited(100000);

int main()
{	
	long long dfs(long long);
	long long n;
	cin>>n;

	long long number;
	cin>>number;

	fill(visited.begin(),visited.begin()+n,0);

	long long x,y;

	for(long long i=0;i<number;++i)
	{
		cin>>x>>y;

		graph[x].pb(y);
		graph[y].pb(x);
	}

	for(long long i=0;i<n;++i)
	{
		if(visited[i] == 0)
		{
			visited[i] = -dfs(i);
		}
	}

	vector<long long> final_answer;

	long long number_of_astro = 0;

	long long s = 0;
	long long square = 0;

	for(long long i=0;i<n;++i)
	{
		if(visited[i] < 0)
		{
			final_answer.pb(-visited[i]);
			s = s - visited[i];
			square = square + visited[i]*visited[i];
		}
	}

	cout<<(s*s- square)/2<<"\n";


} 


long long dfs(long long current)
{
	visited[current] = 1;
	long long answer = 1;

	auto it = graph[current].begin();

	while(it != graph[current].end())
	{
		if(visited[*it] == 0)
		{
			answer = answer + dfs(*it);	
		}
		it++;
		
	}

	return answer;
}
