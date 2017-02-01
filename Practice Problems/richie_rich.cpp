//Problem Link : https://www.hackerrank.com/challenges/richie-rich

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	string number;

	cin>>n>>k;

	cin>>number;

	int wrong = 0;	//Represents the number of non-palindromic characters

	set<int> present;
	vector<int> sequence;

	for(int i=0;i<=(n-1)/2;++i)
	{
		if(number[i] != number[n-1-i])
		{	
			sequence.push_back(i);
			wrong++;
		}
	}

	//cout<<sequence.size()<<"\n";


	if(wrong > k)
	{
		cout<<"-1\n";
	}    
	else
	{
		auto it = sequence.begin();

		while(it != sequence.end())
		{	
			char temp = max(number[*it],number[n-1-*it]);
			number[*it] = temp;
			number[n-1-*it] = temp;
			k--;
			if(temp != '9')
			{
				present.insert(*it);
			}
			it++;
		}

		//cout<<"Printing k : "<<k<<"\n";
		//cout<<number<<"\n";

		if(k > 0)
		{	
			int i = 0;
			if(n%2)
			{
				while((k > 0)&&(i<(n-1)/2))
				{
					if(number[i]!='9')
					{
						if(present.find(i) != present.end())
						{
							if(k >= 1)
							{
								k--;	
								number[i] = number[n-1-i] = '9';
							}
							
						}
						else
						{
							if(k >= 2)
							{
								k-=2;
								number[i] = number[n-1-i] = '9';
							}
						}
					}
					i++;
				}

				if((k > 0)&&(n%2))
				{
					number[n/2] = '9';
				}
			}
			else
			{
				while((k > 0)&&(i<=(n-1)/2))
				{
					if(number[i]!='9')
					{
						if(present.find(i) != present.end())
						{
							if(k >= 1)
							{
								k--;	
								number[i] = number[n-1-i] = '9';
							}
							
						}
						else
						{
							if(k >= 2)
							{
								k-=2;
								number[i] = number[n-1-i] = '9';
							}
						}
					}
					i++;
				}			
			}

		}

		cout<<number<<"\n";
	}
} 
