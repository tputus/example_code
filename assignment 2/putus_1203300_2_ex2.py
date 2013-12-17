'''
ex2.py
E Putus 2/12/12
'''

import locale

def WordSearch(word, lines):
    '''
    Function that takes two arguments, a word to search and a grid in which to find it
    '''

    wordRev=rev(word) #calls rev function to get reverse of word to be searched
    for i in range(0, len(lines)-1): #Goes one line at a time
        if lines[i].find(word)!=-1: #If the word is present in the line
            location=(i+1, lines[i].find(word)+1, i+1, lines[i].rfind(word)+len(word)) #co-ordinates of the word
            return location #return the location
    for i in range(0, len(lines)-1):
        if lines[i].find(wordRev)!=-1: #This is identical to above, but with the reversed word
            location=(i+1, lines[i].rfind(wordRev)+len(word), i+1, lines[i].find(wordRev)+1) #have reverse co-ords as te word is backward
            return location
    
    rows=len(lines)-1 #number of rows
    repeats=len(lines[i]) #number of clumns
    vertLine='' #creates empty string
    vertLines=[] #creates empty list
    for i in range (0, repeats):
        for x in range (0, rows):
            current=lines[x] #gets each row in turn
            vertLine=vertLine+current[i] #takes the same number letter from each row and adds to the certical line
        vertLines.append(vertLine) #creates a list of the columns
        vertLine='' #resets to an empty string
        

    for i in range(0, len(vertLines)-1):
        if vertLines[i].find(word)!=-1: #if the word is present
            location=(vertLines[i].find(word)+1+len(word), i+1, vertLines[i].find(word)+len(word), i+1) 
            return location #return co-ordinates
    for i in range(0, len(vertLines)-1):
        if vertLines[i].find(wordRev)!=-1:
            location=(vertLines[i].find(wordRev)+len(wordRev), i+1, vertLines[i].find(wordRev)+1, i+1)
            return location #Same as above but for the reversed word
    #letter=0
    #x=word.split()
    #for i in range(0, len(lines)-1):
       # for z in range (0, len(lines[i])-1):
            #for n in range (0, len(word)-1):
                #if(lines[i+n][z+n])==x[n]: letter=letter+1
            #if letter==len(word):
                #location=(i+1, z+1, i+len(word), z+len(word))
                #return location
            #letter=0
       return None

                
def rev(s): return s[::-1] #Siple function to reverse the order of letters of a string


file = open(input('Please enter file name: '), encoding=locale.getpreferredencoding())# Opens specified file, auto finds encoding
text= file.read() # Reads file
lines= text.splitlines() # Creates list containing each line
file.close() # Closes file to stop accidental file modification
for i in range(0, len(lines)-1):
    print(lines[i])

file = open(input('Please enter file name for words: '), encoding=locale.getpreferredencoding())# Opens specified file, auto finds encoding
file.read() # Reads file
words=text.split() #Creates List containing each word
file.close() # Closes file to stop accidental file modification
for i in range(0, len(words)-1): 
    if WordSearch(words[i], lines)!=None: print(words[i]+': '+WordSearch(words[i], lines)) #Calls wordsearch function with a different word each time
    else: print(words[i]+': Not Found!') #Prints not found, or the co-ordinates of the word as appropriate

