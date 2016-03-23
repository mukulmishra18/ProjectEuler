'''
For a given number k, you are first supposed to find its factorial representation,
which then easily gives the required permutation (actually, (k+1)-st permutation).

An example for k=5 and numbers {1,2,3}:

5 = 2*2! + 1*1! + 0*0! = (210)_!

so the factorial representation of 5 is 210. Let's now map that representation into the permutation.
We start with the ordered list (1,2,3). The leftmost digit in our factorial representation is 2,
so we are looking for the element in the list at the index 2, which is 3 (list is zero-indexed).
Now we are left with the list (1,2) and continue the procedure. The leftmost digit in our factorial representation,
after removing 2, is 1, so we get the element at the index 1, which is 2. 
Finally, we are left with 1, so the (k+1)-st (6th) permutation of {1,2,3} is {3,2,1}.

'''

from math import factorial

def gen(n):
	word = list('abcdefghijklm')
	ans = []

	for i in range(1, 14):
		f = factorial(13-i)
		d = n // f
		ans.append(word[d])
		word.remove(word[d])

		n = n%f
	return ans


t = int(input())
while t>0:
	n = int(input())

	print(''.join(gen(n-1)))
	t-=1
