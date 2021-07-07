/***********************************************************
CSCI 340 - Assignment 3 - Fall 2020

Progammer: Jonathan Chavez
Z-ID: z1866268
Section: 1
Date Due: September 30, 2020

Purpose: C++ program to find and print all prime numbers, 
which are less than or equal to a given value of n, 
using the algorithm known as the Sieve of Eratosthenes. 
************************************************************/ 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>

using namespace std;

int NO_ITEMS = 16;
int ITEM_W = 5;
/***************************************************************
sieve(set<int>& s, int n)

Use: This function implements the Sieve of Eratosthenes 
  algorithm and this removes all non prime numbers. 
 
Parameters: 
	1.) set<int>& s
	2.) int n
Returns: nothing
***************************************************************/

void sieve(set<int>& s, int n)
{
	for(int i = 2; i <= n; i++) // This initializes the set until upper_bound is reached
                s.insert(i);

	for(int i = 2; i < n; i++) 
	{
		for(int m = i; m <= n; m++)
			s.erase(i * m); //Erases element from set 
	}
}

/***************************************************************
print_primes(const set<int>& s)

Use: This routine can be used to print the elements in the integer 
set s
 
Parameters: 
        1.) const set<int>& s
Returns: nothing
***************************************************************/

void print_primes(const set<int>& s)
{
	int count = 0;
	for(auto i = s.begin(); i != s.end(); i++)
	{
		cout << setw(ITEM_W) << *i;

		count++;

		if(count == NO_ITEMS) // Sixteen numbers per line
		{
			cout << endl;
			count = 0;
		}
	}

	cout << endl;
}

int main()
{
	//This is done to grab the greatest value.
	int upper_bound;
	
	// A set full of integers
	set<int> numList;
	
	// User decides upper bound value
	cout << "What is your upperbound value: ";
	cin >> upper_bound;


	cout << "Upper limit for the set of primes: ";
	cout << upper_bound << endl;
	cout << endl;

	// This calls the function that performs our sieve algorithm
	sieve(numList, upper_bound);

	//Print the contents of the set
	print_primes(numList);

	return 0;
}
