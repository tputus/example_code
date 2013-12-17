#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//function prototypes
void showMenu();
void simSolve();
void quadSolve();
float getFloat(string message);

//run the program
int main(int argc, char *argv[])
{
    cout << "Welcome\n";
    showMenu();
    return EXIT_SUCCESS;
}


//function to show the start menu
void showMenu(){
     int choice;
     cout << "\n\\\\MENU\\\\\n1- Solve simultaneous equation\n2- Solve quadratic equation\n3- Quit program\n\nEnter option: ";
     cin  >> choice;
     cin.ignore(std::numeric_limits<int>::max(),'\n');
     
     if(cin.fail()){
         cin.clear();//clear the error status of cin
         cin.ignore(std::numeric_limits<int>::max(),'\n');//ignore remaining cin
         cout <<  "Invalid option, please try again\n\n";//output the error message
         showMenu();//ask for their input again
         return;
     }else{
         switch(choice){
            case 1:
                 simSolve();
                 break;
            case 2:
                 quadSolve();
                 break; 
            case 3:
                 return;
                 break;
            default:
                 cout << "Invalid option, please try again\n\n";
                 showMenu();
                 break;
         }
     }
}

void simSolve() {
     float a, b, c, d, e, f, x, y;
     string messages[6] = {"Enter a: ", "Enter b: ", "Enter c: ", "Enter d: ", "Enter e: ", "Enter f: "};
     float inputs[6];
     
     cout << "aX+bY=c\n\n" << "dX+eY=f\n\n";
     
     for(int i = 0; i < 6; i++){
         inputs[i] = getFloat(messages[i]);   
     }
     
     a = inputs[0], b = inputs[1], c = inputs[2], d = inputs[3], e = inputs[4], f = inputs[5];
     
     x= ((c*e)-(b*f))/((a*e)-(b*d));
     y= ((c*d)-(a*f))/((b*d)-(a*e));
     
     cout << "X= " << x << endl;
     cout << "Y= " << y << endl;
     
     system("PAUSE");
     
     showMenu();
}

void quadSolve() {
     float a, b, c, ans1, ans2;
     string messages[3] = {"Enter a: ", "Enter b: ", "Enter c: "};
     float inputs[3];
     
     cout << "aX^2+bX+c= 0\n\n";
     
     for(int i = 0; i < 3; i++){
         inputs[i] = getFloat(messages[i]);   
     }
     
     a = inputs[0], b = inputs[1], c = inputs[2];
          
     ans1 = (-b+sqrt((b*b)-4*a*c))/(2*a);
     ans2 = (-b-sqrt((b*b)-4*a*c))/(2*a);
     
     cout << "X= " << ans1 << " OR " << ans2 << endl;
     
     system("PAUSE");
     
     showMenu();
}

float getFloat(string message){
      float value;
      while(0!=1){
         cout << message;
         cin  >> value;
         if(cin.fail()){
             cin.clear();//clear the error status of cin
             cin.ignore(std::numeric_limits<int>::max(),'\n');//ignore remaining cin
             cout <<  "Invalid entry, please try again\n";//output the error message         
         }else{
             return value;      
         }
     }
}
