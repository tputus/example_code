'''
ex7.py
'''
i=0
num_list=[]
number=int(input('Enter a value, enter a negative to indicate end of sequence: '))
while number>=0:
    num_list.append(number)
    number=int(input('Next Value: '))
print(num_list)

for x in range(0, (len(num_list)-1)):
               if num_list[x]>num_list[x+1]: num_list[x], num_list[x+1]=num_list[x+1], num_list[x]
               i=i+1
             



print(num_list)
