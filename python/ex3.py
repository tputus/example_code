'''
ex3.py
'''

n=int(input('Please enter an integer: '))
if n==1: print('1 is not a prime number');
limit=n/2
for x in range(2, limit):
        if n%x==0:
                print(n, 'is not a prime number')
        else:
                print(n, 'is a prime number')
