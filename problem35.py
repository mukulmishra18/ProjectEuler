import sys

a = [0]*1000100
ans = []

def mark(i):
	j = 2
	while (i*j) <= 1000000:
		a[i*j] = 1
		j+=1

def sieve():
	for i in range(2, 1001):
		if a[i] == 0:
			mark(i)

def pre():
	sieve()
	ans.append(2)
	ans.append(3)
	ans.append(5)
	ans.append(7)
	ans.append(11)
	ans.append(13)
	ans.append(17)

	for i in range(31, 1000001):
		flag = 1
		if a[i] == 0:
			temp = str(i)
			temp = list(temp)
			for j in range(0, len(temp)):
				temp.append(temp[0])
				temp.remove(temp[0])
				x = ''.join(temp)
				if a[int(x)] == 1:
					flag = 0
			if flag == 1:
				ans.append(i)



def main():
	pre()
	sol = 0
	n = int(input())
	for i in range(2, n):
		if i in ans:
			sol += i
	print(sol)

if __name__ == '__main__':
	main()
