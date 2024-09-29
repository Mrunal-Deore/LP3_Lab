//Write a program to calculate Fibonacci numbers and find its step count
// 0,1,1,2,3,5,8,13,....  (sum of first two numbers is the next number)

#include <iostream>
using namespace std;

// Recursive function
int fiboRecursive(int n) {
    if (n <= 1)
        return n;
    return fiboRecursive(n - 1) + fiboRecursive(n - 2);
}

// Non-recursive function
void fiboNonRecursive(int n) {
    int a = 0, b = 1, next;

    cout << "Fibonacci Series: " << a << ", " << b;

    for (int i = 2; i < n; i++) {
        next = a + b;
        cout << ", " << next;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int n;
    int choice;

    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;
    
    cout<<"1. Recursive function\n";
    cout<<"2. Non-recursive function\n";

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
       
         cout<<"\nEnter your choice : ";
         cin>>choice;
        
         switch(choice){
            case 1 : cout<<"Using Recursive function \n";
                     cout << "Fibonacci Series : ";
                     for (int i = 0; i < n; i++) {
                     cout << fiboRecursive(i);
                     if (i < n - 1) cout << ", ";
                     }
                     break;
            case 2 : cout<<"Using Recursive function \n";
                     cout << "Fibonacci Series: ";
                     fiboRecursive(n);
                     break;
            default : cout<<"Enter valid choice..";
                     exit(0);
         }
      }

cout<<endl;

return 0;
}


/*Output : 
Enter the number of terms in the Fibonacci series: 5
1. Recursive function
2. Non-recursive function

Enter your choice : 1
Using Recursive function
Fibonacci Series : 0, 1, 1, 2, 3 
*/