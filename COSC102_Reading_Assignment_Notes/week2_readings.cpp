#include <iostream>
using namespace std;

int main() {
    cout << "Hello World C++\n";

    // **---Initialization---** //

    int a; // default-initialization

    // Traditional initialization forms: 
    int b = 5; // copy-initialization
    int c ( 6 ); // direct-initialization

    // Modern initialization forms:
    int d { 7 }; // direct-list-initialization
    int e {}; // value initialization

    cout << a << b << c << d << e << "\n";

    // Default-initialization --> When know initializer is provided, this is called default-initialization. 
    // In many cases, default-initialization performs no initialization, and leaves the variable with an indeterminate value.

    // List-initialization disallows narrowing conversions --> If you try to list-initialize a variable using a value that the vairable 
    // cannot safely hold, the compiler is required to produce a diagnostic to notify you.
    // int w1 {4.5}; // compile error: list-init does not allow narrow conversion
    int w2 = 4.5; // compiles: w2 copy-initialized to value 4
    int w3 (4.5); // compiles: w3 direct-initialized to value 4

    cout << "w2: " << w2 << "\n";
    cout << "w3: " << w3 << "\n";

    // Value-initialization and zero-initialization
    // When a variable is initialized using an empty set of braces, a special form of list-initialization called value-initialization takes place.
    // In most cases, value-initialization will implicitly initialize the variable to zero (or whatever value is closest to zero for a given type). 
    // In cases where zeroing occurs, this is called zero-initialization.

    int width {};
    cout << "width: " << width;

    // List initialization is the preferred form of initialization in modern C++

    // Instantiation: The term instantiation is a fancy word that means a variable has been created and initialized (this includes default initialization).
    // An instantiated object is sometimes called an instance.

    int ex1, ex2; // creates variables a and b, but do not initializa them

    // You can initializa multiple variables defined on the same line:
    int ex3 = 5, ex4 = 6; // copy-initialization
    int ex5 ( 7 ), ex6 ( 8 ); // direct-initilization
    int ex7 { 9 }, ex8 { 10 }; // direct-list-initialization
    int ex9 {}, ex10 {}; // value-initialization

    // Unused initialized variables warnings --> modern compilers will typically generate warnings if a variable is initialized but not used (since it's rarely desirable).
    // [[maybe_unused]] attribute --> allows us to tell the compiler that we're okay with a variable being unused. 
    [[maybe_unused]] double pi { 3.14159 };



    return 0;
}