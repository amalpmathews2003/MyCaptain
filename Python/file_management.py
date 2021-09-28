import csv

def write_to_csv(info_list):
	with open('student_info.csv','a',newline='') as csvfile:
		writer=csv.writer(csvfile)
		if csvfile.tell()==0:
			writer.writerow(["id","Name","Age",'Phone',"Email"])
		writer.writerow(info_list)

def is_valid():
	return

if __name__ == '__main__':
	condition=True
	id=1
	while (condition):
		name=input("Enter student name:")
		age=input("Enter student age:")
		number=input("Enter student phone-number:")
		email=input("Enter student email-id:")
		print(f"{name} {age} {number} {email}")
		check=input('is info correct? (y/n)')
		if check=="y":
			write_to_csv([id,name,age,number,email])
			id+=1

		condition_check=input('Enter y to repeat else enter any other key: ')

		if condition_check!="y":
			condition=False

