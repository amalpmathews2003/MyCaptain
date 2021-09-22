def freq(str):
	s=dict()
	for i in str:
		if i in s.keys():
			s[i]+=1
		else:
			s[i]=1
	return s

if __name__ == '__main__':
	f=freq("Mississippi")
	
	for i in f:
		print(i,f[i])
