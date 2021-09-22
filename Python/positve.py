li=list(input("Enter the numbers seperated by a space ").split(' '))

pos=[]
for i in li:
	if int(i)>0:
		pos.append(i)

print(f"List of positve number is ",*pos)
