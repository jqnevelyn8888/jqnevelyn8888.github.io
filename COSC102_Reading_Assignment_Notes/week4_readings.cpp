#include <iostream>
#include <iomanip>
// <iostream> is a C++ standard library header that defines objects and functions used for input and output through streams, such as cin and cout.

using namespace std;

int main() {

    // endl: A new line is an OS-specific character or sequence of characters that moves the cursor to the start of the next line.
    cout << "Hi!" << endl;
    cout << "My name is Evelyn." << endl;

    // \n is usually better than std::endl because it adds a newline without flushing the output buffer, making it more efficient and faster than std::endl, which both inserts a newline and forces a slow buffer flush.
    cout << "This does \n";
    cout << "the same thing.\n";

    // The insertion operator(<<) is used to put information into an output stream. 
    
    // Two ways to change formatting options: flags, and manipulators.
    // Flags: Like boolean varia.bles that can be turned on and off
    // Manipulators: objects placed in a stream that affect the way things are input and output

    // To switch flag on, use setf()
    cout.setf(ios::showpos);
    cout << 27 << '\n'; // shows 27 is a positive number. 
    // you can turn on multiple ios flags at once using the Bitwise OR (|) operator:
    cout.setf(ios::showpos | ios::uppercase);
    cout << 1234567.89f << '\n';
    // to turn the flag off, use the unsetf() function.
    cout.unsetf(ios::showpos | ios::uppercase);
    cout << 1234567.89f << '\n';
    // there is a simpler way to turn the flags on and off -- using manipulators: 
    cout << hex << 27 << '\n'; // print 27 in hex
    cout << 28 << '\n'; // we're still in hex
    cout << dec << 29 << '\n'; // back to decimal

    // ---- USEFUL FORMATTERS ---- // 

    // FLAG : std::ios::boolalpha --> If set, booleans print "true" or "false". If not set, booleans print 0 or 1.
        // MANIPULATOR: std::boolalpha --> Booleans print "true" or "false"
        // MANIPULATOR: std::noboolalpha --> Booleans print 0 or 1 (default)
    cout << "\n|--- boolalpha ---|" << '\n';
    cout << "DEFAULT: " << true << ' ' << false << '\n';
    cout.setf(ios::boolalpha);
    cout << "FLAG: " << true << ' ' << false << '\n';
    cout << "MANIPULATOR --> noboolalpha: " << noboolalpha << true << ' ' << false << '\n';
    cout << "MANIPULATOR --> boolalpha: " << boolalpha << true << ' ' << false << '\n';

    // FLAG: std::ios::showpos --> If set, prefix positive numbers with a +
        // MANIPULATOR: std::showpos --> Prefixes positive numbers with a +
        // MANIPULATOR: std::noshowpos --> Doesn’t prefix positive numbers with a +
    cout << "\n|--- showpos ---|\n";
    cout.setf(ios::showpos);
    cout << "FLAG: " << 5 << '\n';
    cout << noshowpos << "MANIPULATOR --> noshowpos: " << 5 << '\n';
    cout << showpos << "MANIPULATOR --> showpos: " << 5 << '\n';
    cout.unsetf(ios::showpos);

    // FLAG: std::ios::uppercase --> If set, uses upper case letters
        // MANIPULATOR: std::uppercase --> Uses upper case letters
        // MANIPULATOR: std::nouppercase --> Uses lower case letters
    // uppercase affects the characters in floating-point and hexadecimal integer output. 
    cout << "\n|---uppercase---|\n";
    cout.setf(ios::uppercase);
    cout << "FLAG: " << 1e-10 << '\n';
    cout << nouppercase << "MANIPULATOR --> nouppercase: " << 1e-10 << '\n';
    cout << uppercase << "MANIPULATOR --> uppercase: " << 1e-10 << '\n';
    cout.unsetf(ios::uppercase);

    // GROUP: std::ios::basefield
        // FLAG: std::ios::dec --> Prints values in decimal (default)
	    // FLAG: std::ios::hex --> Prints values in hexadecimal
        // FLAG: std::ios::oct	--> Prints values in octal
        // FLAG: (none)	--> Prints values according to leading characters of value

        // MANIPULATOR: std::dec --> Prints values in decimal
        // MANIPULATOR: std::hex --> Prints values in hexadecimal
        // MANIPULATOR: std::oct --> Prints values in octal
    cout << "\n|---Basefield---|\n";
    cout.setf(ios::dec, ios::basefield);
    cout << "FLAG --> ios::dec: " << 27 << '\n';
    cout.unsetf(ios::dec);
    cout.setf(ios::hex, ios::basefield);
    cout << "FLAG --> ios::hex: " << 27 << '\n';
    cout.unsetf(ios::hex);
    cout.setf(ios::oct, ios::basefield);
    cout << "FLAG --> ios::oct: " << 27 << '\n';
    cout.unsetf(ios::oct);
    cout << dec << "MANIPULATOR --> dec: " << 27 << '\n';
    cout << hex << "MANIPULATOR --> hex: " << 27 << '\n';
    cout << oct << "MANIPULATOR --> oct: " << 27 << '\n';
    cout << dec;
    cout.unsetf(ios::uppercase);

    // GROUP: std::ios::floatfield
        // FLAG: std::ios::fixed --> Uses decimal notation for floating-point numbers
        // FLAG: std::ios::scientific --> Uses scientific notation for floating-point numbers
        // FLAG: (none) --> Uses fixed for numbers with few digits, scientific otherwise
    // FLAG: std::ios::showpoint --> Always show a decimal point and trailing 0’s for floating-point values
    // MANIPULATOR: fixed --> Use decimal notaion for values
    // MANIPULATOR: scientific --> User scientific notaion for values
    // MANIPULATOR: showpoint --> show a decimal point and trailing 0's for floating point values
    // MANIPULATOR: noshowpoint --> Don't show a decimal point and trailing 0's for floating point values
    // MANIPULATOR: setprecision(int)--> Sets the precision of floating point numbers (defined in iomanip header)
    cout << "\n|---floatfield---|\n";
    printf("DEFAULT: %f\n", 123.456);
    cout.setf(ios::fixed, ios::floatfield);
    cout << "FLAG: --> ios::fixed: " << 123.45 << '\n';
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific, ios::floatfield);
    cout << "FLAG --> scientific: " << 123.45 << '\n';
    cout.unsetf(ios::scientific);
    cout.setf(ios::showpoint);
    cout << "FLAG --> showpoint: " << 123.45 << '\n';
    cout.unsetf(ios::showpoint); 
    cout << "MANIPULATOR --> fixed: " << fixed << 123.45 << '\n';
    cout << defaultfloat;
    cout << "MANIPULATOR --> scientific: " << scientific << 123.45 << '\n';
    cout << defaultfloat;
    cout << "MANIPULATOR --> showpoint: " << showpoint << 123.45 << '\n';
    cout << defaultfloat;
    cout << "MANIPULATOR --> setprecision(2): " << setprecision(2) << 123.45 << '\n';

    // GROUP: std::ios::adjustfield
        // FLAG --> std::ios::internal: Left-justifies the sign of the number, and right-justifies the value
        // FLAG --> std::ios::left: Left-justifies the sign and value
        // FLAG --> std::ios::right: Right-justifies the sign and value (default)
    // MANIPULATOR --> internal: Left-justifies the sign of the number, and right-justifies the value
    // MANIPULATOR --> std::left: Left-justifies the sign and value
    // MANIPULATOR --> std::right: Right-justifies the sign and value
    // MANIPULATOR --> std::setfill(char): Sets the parameter as the fill character (defined in the iomanip header)
    // MANIPULATOR --> std::setw(int): Sets the field width for input and output to the parameter (defined in the iomanip header)
    // Member function: 
        // std::basic_ostream::fill(): Returns the current fill character
        // std::basic_ostream::fill(char): Sets the fill character and returns the old fill character
        // std::ios_base::width(): Returns the current field width
        // std::ios_base::width(int): Sets the current field width and returns old field width

    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::left << std::setw(10) << -12345 << '\n'; // print left justified
    std::cout << std::right << std::setw(10) << -12345 << '\n'; // print right justified
    std::cout << std::internal << std::setw(10) << -12345 << '\n'; // print internally justified

    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified





    return 0;

}