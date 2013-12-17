"""
average.py
program to calculate average of a series of exam marks
created by sands 23/10/10
"""

# initialise total and counter
total = 0.0
count = 0

print("Enter marks one per line")
print("Use a negative number to end")

# get first mark
mark = float(input("Mark: "))
maxi= mark
mini= mark

# process mark and get next one
# continue until negative number entered
while mark >= 0 :
    total = total + mark
    count = count + 1
    mark = float(input("Mark: "))
    if 0 <=mark> maxi: maxi= mark
    elif 0 <=mark< mini : mini= mark

# output average
print("The average mark is", round(total/count, 2))
print("The highest mark was", maxi, "and the lowest mark was ", mini)
