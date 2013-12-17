'''
ex6.py
'''
text=input('Enter your text: ')
text_list=list(text)



a=0
e=0
i=0
o=0
u=0

for n in range(0, len(text_list)):
    if text_list[n]=="a" or text_list[n]=="A": a=a+1
    if text_list[n]=="e" or text_list[n]=="E": e=e+1
    if text_list[n]=="i" or text_list[n]=="I": i=i+1
    if text_list[n]=="o" or text_list[n]=="O": o=o+1
    if text_list[n]=="u" or text_list[n]=="U": u=u+1


    
if a>=e and a>=i and a>=o and a>=u:
    print('A was the most frequently occuring vowel; it appeared ', a, 'times')
if e>a and e>=i and e>=o and e>=u:
    print('E was the most frequently occuring vowel; it appeared ', e, 'times')
if i>e and i>a and i>=o and i>=u:
    print('I was the most frequently occuring vowel; it appeared ', i, 'times')
if o>a and o>i and o>e and o>=u:
    print('O was the most frequently occuring vowel; it appeared ', o, 'times')
if u>a and u>i and u>o and u>e:
    print('U was the most frequently occuring vowel; it appeared ', u, 'times')


