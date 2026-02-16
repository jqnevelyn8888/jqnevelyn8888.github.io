#include <iostream>
#include <vector>

using namespace std;

void list_int_elements(vector<int> list) {
    for (int i = 0; i<list.size(); i++) {
        cout << list[i] << " ";
    }
}

int add(int x, int y) // <-- function 1
{
    int z{ x + y }; // z is a local variable

    return z;
}

int main(void) {

    vector<int> empty{}; // vector containing 0 int elements
    vector<int> primes{2, 3, 5, 7};
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    cout << "The first prime is: " << primes[0];

    /* 
        Arrays are one of the few container types that allow for random access,
    meaning any element in the container can be accessed directly 
    (as opposed to sequential access, where elements must be accessed in a 
    particular order). Random access to array elements is typically efficient,
    and makes arrays very easy to use. This is a primary reason why arrays 
    are often preferred over other containers.
    */

    // How to construct a vector of a specific length:
    vector<int> initiate10( 10 );
    cout << "\nSize of initiate10: " << initiate10.size();

    // Practice
    vector<int> squarenum{1, 4, 9, 16, 25};
    vector<double> temperature(365);
    vector<int> to_sum(3);
    cout << "\nEnter 3 integers: ";
    cin >> to_sum[0] >> to_sum[1] >> to_sum[2];
    cout << "\nThe sum is: " << to_sum[0]+to_sum[1]+to_sum[2];
    cout << "\nThe product is : " << to_sum[0]*to_sum[1]*to_sum[2];
    cout << "\n Displaying input integers... ";
    list_int_elements(to_sum);

    // ------------ LOCAL SCOPE ----------------- //

    /*  Local variables:
            - Variables defined inside the body of a function are called local variables
            - function 1: functions parameters x and y are local variables. z is a local variable.
            - Local variables are destroyed at the end of the set of curly braces in which it is defined.

        Local scope:
            - an identifier's scope determines where the identifier can be seen and used within the source code. 
            - When an identifier can be seen and used, we say it is in scope.
            - When an identifier cannot be seen, we cannot use it and it is out of scope.
            - An identifier of a local variable has a local scope which is usable within the block 
            (between the pairs of curly braces where it is defined). 

        Lifetime is a runtime property and scope is a compile-time property.
            
    */

    cout << "\n Code ran.";
    return 0;
}