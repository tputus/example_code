"""
rows1.py
program to display rows of characters
created by sands 23/10/10
"""

def printRow(c, length) :
    """
    print a row of identical characters
    arguments:
    c: string: character to be used
    length: int: length of row
    """
    line = c * length
    print(line)

printRow('=', 10)
printRow('*', 7)
myChar = input('Please enter a character to be printed: ')
myLen = int(input('Please enter a length: '))
printRow(myChar, myLen)
