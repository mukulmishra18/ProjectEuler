import sys 

pan4 = []
pan5 = []
pan6 = []
pan7 = []
pan8 = []
pan9 = []

def ispandigit(n):
	flag = 1
	a = [0]
	a = a*11

	for i in range(0, len(n)):
		a[int(n[i])]+=1
	
	if a[0] == 0:
		j = 1
		while a[j] == 1 and j<10:
			j+=1
		while j<10:
			if a[j] > 0:
				flag = 0
			j+=1
	else:
		flag = 0

	if flag == 1:
		return True
	else:
		return False

def pre():
	for i in range(2, 100):
		for j in range(2, 10000//i):
			pro = i*j
			temp = str(i)+str(j)+str(pro)

			if ispandigit(temp):
				if len(temp) == 4:
					pan4.append(pro)
				if len(temp) == 5:
					pan5.append(pro)
				if len(temp) == 6:
					pan6.append(pro)
				if len(temp) == 7:
					pan7.append(pro)
				if len(temp) == 8:
					pan8.append(pro)
				if len(temp) == 9:
					pan9.append(pro)
				

def main():
	pre()
	#print(pan4, pan5, pan6, pan7, pan8, pan9)

	n = int(input())
	ans = 0

	if n == 4:
		for value in set(pan4):
			ans += value
	if n == 5:
		for value in set(pan5):
			ans += value
	if n == 6:
		for value in set(pan6):
			ans += value
	if n == 7:
		for value in set(pan7):
			ans += value
	if n == 8:
		for value in set(pan8):
			ans += value
	if n == 9:
		for value in set(pan9):
			ans += value				

	print(ans)


if __name__ == '__main__':
	main()
