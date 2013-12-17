'''
ex2.py
'''
from math import sqrt, atan, degrees
height=float(input('Please enter the height in cm: '))
width=float(input('Please enter the width in cm: '))
hypotenuse=sqrt((width*width)+(height*height))
radians=atan(height/width)
angle_one=degrees(radians)
angle_two=90-angle_one
print('The hypotenuse is', hypotenuse, 'cm.\nThe interior angles are', round(angle_one, 2), 'degrees and', round(angle_two, 2), 'degrees')

