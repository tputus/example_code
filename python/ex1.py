m=int(input('Please enter your lower value: '))

while m!= int:
    m=int(input('That is not a valid choice, please enter an integer: '))

n=int(input('Please enter your higher value: '))
total=0
total2=int((n+m)*(n-m+1)/2)
c=m
while c<=n:
    total=total+c
    c=c+1
print('The total is: ', total, ' This was calculated using a while loop')
print('The total is: ', total2, ' This was calculated using the equation (n+m)×(n–m+1)/2 ')


