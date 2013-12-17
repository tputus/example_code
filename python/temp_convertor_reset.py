'''
Temp_convertor.py
Created by Teddy Putus 16/10/2012
Modified by Teddy Putus 17/10/2012
     - Added reset
     - Added Error checking for type input/output
'''

#Allows for restart
restart=int('1')
while restart==1:

#Find input type
     print("Welcome to the celsius-farenheit-kelvin convertor")
     select=input('Please select input type\n 1-Celsius\n 2-Farenheit\n 3-Kelvin\n')

#Check they have entered a correct choice
     while select!= str('1') and select!=str('2') and select!=str('3'):
               select=input('That is not a valid choice, please enter a digit between 1 and 3\n')

#Find output type
     select2=input('Please select output type\n 1-Celsius\n 2-Farenheit\n 3-Kelvin\n')

#Check they have entered a correct choice
     while select2!= str('1') and select2!=str('2') and select2!=str('3'):
               select2=input('That is not a valid choice, please enter a digit between 1 and 3\n')

#Convert to integers and see if there's a point to the calculation
     sel_in=int(select)
     sel_in_2=int(select2)
     while sel_in==sel_in_2:
          select=input('That value does not need converting, please select another input type\n 1-Celsius\n 2-Farenheit\n 3-Kelvin\n')
          select2=input('Please select another output type\n 1-Celsius\n 2-Farenheit\n 3-Kelvin\n')

#Convert as appropriate
     if sel_in==1:
         temp=input('Enter your temperature in celsius: ')
         temp_int=float(temp)
         if sel_in_2==2:
             result=(temp_int*1.8)+32
             print(temp_int,'celsius is', result, 'farenheit')
         else:
             if sel_in_2==3:
                 result=temp_int+273.15
                 print(temp_int, 'celsius is', result, 'kelvin')

     if sel_in==2:
         temp=input('Enter your temperature in farenheit: ')
         temp_int=float(temp)
         if sel_in_2==1:
             result=(temp_int-32)/1.8
             print(temp_int,'farenheit is', result, 'celsius')
         else:
             if sel_in_2==3:
                 result=((temp_int-32)/1.8)+273.15
                 print(temp_int, 'farenheit is', result, 'kelvin')

     if sel_in==3:
         temp=input('Enter your temperature in kelvin: ')
         temp_int=float(temp)
         if sel_in_2==1:
             result=temp_int-273.15
             print(temp_int,'kelvin is', result, 'celsius')
         else:
             if sel_in_2==2:
                 result=((temp_int-273.15)*1.8)+32
                 print(temp_int, 'kelvin is', result, 'farenheit')
#Restart choice
     restart_choice=input('Would you like to convert again? y/n')
     if restart_choice==str('y') or restart_choice==str('Y'):
          restart=int('1')
     else:
          if restart_choice==str('n') or restart_choice==str('N'):
               restart=int('0')
          else:
               while restart_choice!=str('y') and restart_choice!=str('Y') and restart_choice!=str('n') and restart_choice!=str('N'):
                     restart_choice=input("That wasn't a valid choice, please select y/n")
