import math

primes = set([2])
def isPrime(n):
	if(n in primes):
		return True
	if n>2 and n%2!=0:
		for i in range(3,round(math.sqrt(n))+1, 2):
			if n%i==0:
				return False
		primes.add(n)
		return True
	return n==2;

def isPrimes(num_list):
	for n in num_list:
		if(not isPrime(n)):
			return False
	return True

def getNextPrime(n=1):
	n=n+1
	while(not isPrime(n)):
		n+=1
	return n

def right_trim(n):
	if n!=0 and n>9:
		return int(str(n)[1:])
	return 0

def left_trim(n):
	if n!=0 and n>9:
		return int(str(n)[:-1])
	return 0


def get_right_trimmed(n):
	trimmed = list()
	n = right_trim(n)
	while n!=0:
		trimmed.append(n)
		n = right_trim(n)
	return trimmed

def get_left_trimmed(n):
	trimmed = list()
	n = left_trim(n)
	while n!=0:
		trimmed.append(n)
		n = left_trim(n)
	return trimmed

def get_trimmed(num):
	trimmed = [num]
	trimmed+=get_left_trimmed(num)
	trimmed+=get_right_trimmed(num)
	return list(set(trimmed))

def get_truncable_primes(n):
	trunc_primes = list()
	num = 1
	while(len(trunc_primes)<n):
		num = getNextPrime(num)
		if (num>9):
			trimmed_numbers = get_trimmed(num)
			if isPrimes(trimmed_numbers):
				trunc_primes.append(num)
	return trunc_primes
	
if  __name__=='__main__':
	trunc_primes = get_truncable_primes(11)
	print("Sum=" + str(sum(trunc_primes)))
