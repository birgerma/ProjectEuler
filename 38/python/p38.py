
def num_len(num):
	return len(str(num))

def concat_num(n1, n2):
	return int(str(n1)+str(n2))

def compute_max_conc_prod(n, max_len=9):
	prod = n;
	for i in range(2,max_len+1):
		p = n*i
		if num_len(prod)+num_len(p) > max_len:
			return prod
		prod = concat_num(prod, p)
	return prod

def is1To9Num(num):
	num_set = set([ char for char in str(num)])
	correct = set([ char for char in '123456789'])
	return num_set==correct

max_num = 0

for i in range(1, 10000):
	prod = compute_max_conc_prod(i)
	if is1To9Num(prod) and prod>max_num:
		max_num=prod

print(max_num)
