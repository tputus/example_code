'''
ex1.py
assignment 2- Program to import employee details from text file which can then be searched
E Putus 28/11/12
'''

import locale #Imports function to determine encoding of text file

class EmployeeException(Exception): pass #creates exception for when called, with output provided at call

class Employee(object):
    '''
    Employee class with a name(str), job (str), payroll number(int), salary(int)
    '''

    def __init__(self, name, payNum, job, salary): #initialises object attributes with inputted data
        
        if not isinstance(name, str) or \
           not isinstance(job, str) or \
           not isinstance(payNum, int) or \
           not isinstance(salary, int):
            raise EmployeeException('Invalid input') #Raises exception if any are incorrect types
        
        self.__name=name #initialises name as inputted name, double underscores make it private attribute
        self.__payNum=payNum #initialises payroll number as inputted number, double underscores make it private attribute
        self.__job=job #initialises job as inputted job, double underscores make it private attribute
        self.__salary=salary #initialises salary as inputted salary, double underscores make it private attribute
        last=name.split()
        self.__lastName=last[len(last)-1]

    
    def __str__(self):
        return self.__payNum+' '+self.__salary+' '+self.__job+' '+self.__name
    def name(self): #Function to return name as it is a private attribute
        return self.__name
    def job(self): #Function to return job title as it is a private attribute
        return self.__job
    def payNum(self): #Function to return payroll number as it is a private attribute
        return self.__payNum
    def salary(self): #Function to return salary as it is a private attribute
        return self.__salary
    def show(self): #Function to print all of an object's details, as they are private attributes
        print(self.__payNum, self.__salary, self.__job, self.__name, self.__name)
    def lastName(self): #Function to return name as it is a private attribute
        return self.__lastName



def CreateEmployee(text):
    '''
    Function that takes a line of text, splits it into seperate attributes, then creates an employee
    '''

    words=text.split() # Splits line into a list of words
    payNum=words[0] #payNum is first word in list
##    if len(payNum)!=5: #Checks that payroll number is correct length (5)
##        raise EmployeeException('Payroll Number has the wrong number of digits')
    payNum=int(payNum)
    salary=int(words[1]) #Salary is second in list, converted to integer for use in SalarySearch
    job=words[2] # Job is third in list
    name=words[3] # Name is fourth in list
    
    if len(words)>4: # If there are more than four words, it is assumed the others are part of the name
        for i in range(4, (len(words))):
            name=name+' '+words[i] # This concatenates the names into one name
    return Employee(name, payNum, job, salary) # Returns an employee object

def TitleSearch():
    '''
    Function to search list of employees by job title, then print any with title matching input
    '''
    title=input('Enter job title: ')
    x=0
    #people=[]
    for i in range(0, (len(employ)-1)):
        if employ[i].job()==title:
            print(employ[i].name())
            x=x+1
        #people.sort(key=lastName())
        #print(people)
    if x==0: print('No results found')


def PaySearch():
    '''
    Function to search list of employees by payroll number, then print any with payroll number matching input
    '''
    done=False
    while not done:
        try:
            num=int(input('Enter Payroll Number: '))
            done=True
        except Exception as e: print('Invalid input')
    x=0
    for i in range(0, (len(employ)-1)):
        if employ[i].payNum()==num:
            employ[i].show() # Shows employee with specified payroll number
            x=x+1
    if x==0: print('No results found')  

def SalarySearch():
    '''
    Function to search list of employees by pay, then print any within given salary range
    '''
    done=False
    while not done:
        try:
            low=int(input('Enter lower boundary: '))
            high=int(input('Enter upper boundary: '))
            done=True
        except Exception as e: print('Invalid input')
    x=0
    for i in range(0, (len(employ)-1)):
        if low<=employ[i].salary()<=high:
            employ[i].show() # Goes through employ list and prints details of employees in salary range
            x=x+1
    if x==0: print('No results found')
    
success=False
while not success:
    try:
        file = open(input('Please enter file name: '), encoding=locale.getpreferredencoding())# Opens specified file, auto finds encoding
        success=True
    except Exception as e:
        print('Invalid file name')
text= file.read() # Reads file
lines= text.splitlines() # Creates list containing each line
file.close() # Closes file to stop accidental file modification
employ=[] # Empty list to be filled with employee objects
for i in range(0, (len(lines)-1)):
    employ.append(CreateEmployee(lines[i])) # Calls employee function for every line, appends employ list
        
restart=1 #Sets restart to 1 before while loop
while restart==1:
    try:
        choice=int(input('1-Search by job title (names only)\n2-Search by payroll number\n3-Search by salary range\n4-Quit: '))
        while choice<=0 or 4<choice: choice=int(input('Invalid input, please reselect: ')) #Ensures choice is valid
    except Exception as e:
        print('Invalid input')
    if choice==4: restart=0 # If quit is selected, makes while loop stop
    elif choice==1: TitleSearch() # Calls appropriate function
    elif choice==2: PaySearch() # Calls appropriate function
    elif choice==3: SalarySearch() # Calls appropriate function

    

