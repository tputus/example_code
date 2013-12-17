"""
ass1.py
CE151 assignment 1 template
created by sands 30/10/10
modified by sands 28/10/11 - number of exercises changed
"""

def ex1() :
    '''
    Function to calculate the sum of all integers between m and n
    '''
    m=int(input('Please enter your lower value: '))
    n=int(input('Please enter your higher value: '))
    total=0
    total2=int((n+m)*(n-m+1)/2) #calculated with an arithmetic expression
    c=m
    while c<=n:
        total=total+c #add c to the total
        c=c+1 # increment c, adds each integer in range seperately
    print('The total is: ', total, ' This was calculated using a while loop')
    print('The total is: ', total2, ' This was calculated using the equation (n+m)×(n–m+1)/2 ')
    
def ex2() :
    '''
    Function to Calculate the hypotenuse and interior angles of a triangle
    '''
    from math import sqrt, atan, degrees
    height=float(input('Please enter the height in cm: '))
    width=float(input('Please enter the width in cm: '))
    hypotenuse=sqrt((width*width)+(height*height)) #Pythagoras Theorem
    radians=atan(height/width) #Trigonometry
    angle_one=degrees(radians) #Convert to degrees from radians
    angle_two=90-angle_one #Find second angle (180 degrees in a triangle)
    print('The hypotenuse is', hypotenuse, 'cm.\nThe interior angles are', round(angle_one, 2), 'degrees,', round(angle_two, 2), 'degrees and 90 degrees')
    
def ex3() :
    '''
    Function to check if a number is prime
    '''
    i=0
    n=int(input('Please enter an integer: '))
    if n==1 or n==0: print(n, ' is not a prime number') 
    if n==2: print('2 is a prime number')
    limit=n/2
    for x in range(3, (n//2), 2): #Range is between three and half the inputted value
            if n % x == 0:
                   i=1  #if the remainder of n/x is 0, set i to 1
    if i==1: print(n, 'is not a prime number')
    if i==0: print(n, 'is a prime number')
        
def ex4() :
    '''
    Function to produce a multiplication table
    '''
    from sys import stdout


    i=2
    rows=int(input('How many rows do you want? '))
    columns=int(input('How many columns do you want? '))
    columns_list=[]
    for x in range(1,(columns+1)):
        columns_list.append(x) #makes a list of column values
    for x in range(0, len(columns_list)):
        stdout.write(str(columns_list[x])); #prijnts out each number on same line
        if columns_list[x]<10: stdout.write("   ") #size of value dictates the spacing
        if 10<columns_list[x]<100: stdout.write(" ")
    print("\n")
   


    while i<=rows:
        row_list=[i] #gives value of row
        for x in range(1, len(columns_list)):
            row_list.append(i*columns_list[x]) #adds the product of row value and corresponding column value to list
        for x in range(0, len(columns_list)):
            stdout.write(str(row_list[x])) #prints the row, one at a time on the same line
            if row_list[x]<10: stdout.write("   ") #size of value dictates spacing
            if 10<=row_list[x]<100: stdout.write("  ")
        print("\n")
        i=i+1 #increment i and repeat for next row
    
def ex5() :
    '''
    ex5.py
    '''
    text=str(input('Enter your text: '))
    words=text.split() #splits text into words
    i=0

    shortest=text #Can't be longer than text, so any word in it is guaranteed to be shorter
    longest="" #Ampty string
    for word in words:
        if len(word)>len(longest): #if word is longer than stored string, replace it
            longest=word
        if len(word)<=len(shortest): #if word is shorter than stored string, replace it
            shortest=word

    print('The longest word is ', longest, 'and the shortest word is ', shortest)

    
def ex6() :
    '''
    Finds the most frequently occuring vowel in a string
    '''
    text=input('Enter your text: ')
    text_list=list(text)

    a=0
    e=0
    i=0
    o=0
    u=0

    for n in range(0, len(text_list)): #cycles through the list and adds whenever it sees a vowel
        if text_list[n]=="a" or text_list[n]=="A": a=a+1
        if text_list[n]=="e" or text_list[n]=="E": e=e+1
        if text_list[n]=="i" or text_list[n]=="I": i=i+1
        if text_list[n]=="o" or text_list[n]=="O": o=o+1
        if text_list[n]=="u" or text_list[n]=="U": u=u+1
    
    if a>=e and a>=i and a>=o and a>=u: #use comparisons to make it work when there are equal numbers of vowels
        print('A was the most frequently occuring vowel; it appeared ', a, 'times')
    if e>a and e>=i and e>=o and e>=u:
        print('E was the most frequently occuring vowel; it appeared ', e, 'times')
    if i>e and i>a and i>=o and i>=u:
        print('I was the most frequently occuring vowel; it appeared ', i, 'times')
    if o>a and o>i and o>e and o>=u:
        print('O was the most frequently occuring vowel; it appeared ', o, 'times')
    if u>a and u>i and u>o and u>e:
        print('U was the most frequently occuring vowel; it appeared ', u, 'times')

    
def ex7() :
    '''
    Bubble sort
    '''
    i=0
    stop=0
    num_list=[]
    number=int(input('Enter a value, enter a negative to indicate end of sequence: '))
    while number>=0:
        num_list.append(number) #add numbers to list, loop until negative is entered
        number=int(input('Next Value: '))
    print(num_list)

    while stop==0:
        stop=1 
        for x in range(0, (len(num_list)-1)):
                   if num_list[x]>num_list[x+1]:
                       num_list[x], num_list[x+1]=num_list[x+1], num_list[x] #swaps values
                       stop=0 #if any numbers have been swapped in for loop, stop is 0 so while loop can continue
                   i=i+1
        if stop ==0: print(num_list)
    
   
    
def ex8() :
    '''
    produces nested triangles
    '''

    c1=input('Enter first character: ')
    c2=input('Enter second character: ')
    size=int(input('Enter width of first triangle: '))
    while size%2==0: size=int(input('Value must be odd. Please enter width of first triangle: '))
    size2=(size*2)+1 #calculate the size of the bigger triangles
    size3=(size2*2)+1

    print('This is the first trangle: ')

    #First triangle
    i=size
    while i>=1:
             line=c1*i
             print(line.center(100)) #print each line centre aligned
             i=i-2

    print('This is the second trangle: ')

    # Second triangle
    b=1
    while b<=size:
        line=c2*b
        print(line.center(100))
        b=b+2
    a=size
    b=1
    while a>=1:
        line=(c2*b)+(c1*a)+(c2*b) #have to have a combination of symbols (just following pattern of the diagram provided)
        print(line.center(100))
        a=a-2
        b=b+2

    print('This is the third trangle: ')

    # Third triangle

    a=size2
    b=1
    while b<=size:
        line=(c1*a)+(c2*b)+(c1*a)
        print(line.center(100))
        a=a-2
        b=b+2
    b=1
    while a>=1:
        line=(c1*a)+(c2*b)+(c1*a)+(c2*b)+(c1*a)
        print(line.center(100))
        a=a-2
        b=b+2
    a=size2
    while a>=1:
        line=(c1*a)
        print(line.center(100))
        a=a-2

    print('This is the fourth triangle: ')

    #Fourth triangle

    a=1
    while a<=size3:
        line=(c2*a)
        print(line.center(100))
        a=a+2
    a=1
    b=size2
    while a<=size:
        line=(c2*a)+(c1*b)+(c2*a)+(c1*b)+(c2*a)
        print(line.center(100))
        a=a+2
        b=b-2
    c=1
    while c<=size:
        line=(c2*a)+(c1*b)+(c2*c)+(c1*b)+(c2*c)+(c1*b)+(c2*a)
        print(line.center(100))
        a=a+2
        b=b-2
        c=c+2
    b=size2
    while b>=1:
        line=(c2*a)+(c1*b)+(c2*a)
        print(line.center(100))
        a=a+2
        b=b-2


print("CE151 assignment 1 - Edward Putus")

# do not modify anything beneath this line
exlist = [None, ex1, ex2, ex3, ex4, ex5, ex6, ex7, ex8]
running = True
while running :
    line = input("Select exercise (0 to quit): ")
    if line == "0" : running = False
    elif len(line)==1 and "1"<=line<="8": exlist[int(line)]()
    else : print("Invalid input - try again")


