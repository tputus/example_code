'''
ex4.py
'''
from sys import stdout


i=2
rows=int(input('How many rows do you want? '))
columns=int(input('How many columns do you want? '))
columns_list=[]
for x in range(1,(columns+1)):
    columns_list.append(x)
for x in range(0, len(columns_list)):
    stdout.write(str(columns_list[x]));
    if columns_list[x]<10: stdout.write("  ")
    if 10<columns_list[x]<100: stdout.write("")
print("\n")
   


while i<=rows:
    row_list=[i]
    for x in range(1, len(columns_list)):
        row_list.append(i*columns_list[x])
    for x in range(0, len(columns_list)):
        stdout.write(str(row_list[x]))
        if row_list[x]<10: stdout.write("  ")
        if 10<=row_list[x]<100: stdout.write(" ")
    print("\n")
    i=i+1
        

