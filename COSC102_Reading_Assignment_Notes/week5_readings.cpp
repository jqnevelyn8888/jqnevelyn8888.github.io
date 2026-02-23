#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

    // FILE OUTPUT
    /*
        ofstream is used for writing files.
        We'll make a file called sample.txt
    */
    ofstream outf = ofstream("sample.txt");

    // Checks if we couldn't open the output file stream for writing
    if (!outf) {
        cerr << "sample.txt could not be opened for writing. \n";
        return 1;
    } // cerr is a C++ output stream used to display error messages to the standard error output, separate from normal program output.
    
    /*
        A stream in C++ is a flow of data between your program and something else, like the screen.
        std::cout is a stream used for normal program output (expected results).
        std::cerr is a separate stream used for error messages.
        They are kept separate so errors can be handled or redirected differently from normal output.
    */

    // writing two lines into this file:
    outf << "This is line 1 \n";
    outf << "This is line 2 \n";

    outf.close();

    /*
        std::ifstream → read only
        std::ofstream → write only
        std::fstream → read and write
    */

    // reading sample.txt
    ifstream inf;
    inf.open("sample.txt");

    if (!inf) {
        cerr << "sample.txt cannot be opened for reading.";
        return 1;
    }

    string strInput{};
    while (inf >> strInput) {
        std::cout << strInput << '\n';
    }
    // inf >> strInput reads one word at a time (stopping at whitespace), while std::getline(inf, strInput) reads an entire line including spaces until a newline.
    //strInput is taking elements from inf, while strInput can take elements, the while loop goes on and the element strInput gets is printed. When strInput cannot get anymore elements, the loop stops.

    inf.clear(); // clears the EOF flag so we can read again. 
    inf.seekg(0); // move back to start of file

    // the extraction operator breaks on whitespace. In order to read in entire lines, we'll have to use the getline() function.
    string lines;
    std::cout << "Reading line by line: \n";
    while (getline(inf, lines)) {
        std::cout << lines << '\n';
    }
    inf.close();

    /* file mode
        ios::app --> Opens the file in append mode
        ios::ate --> Seeks to the end of the file before reading/writing
        ios::binary --> Opens the file in binary mode (instead of text mode)
        ios::in --> Opens the file in read mode (default for ifstream)
        ios::out --> Opens the file in write mode (default for ofstream)
        ios::trunc --> Erases the file if it already exists
    */

    ofstream outf2;
    outf2.open("sample.txt", ios::app);

    if (!outf2) {
        cerr << "File cannot be read";
        return 1;
    }

    outf2 << "Another line \n";
    outf2 << "A new line \n";

    outf2.close();

    ifstream read;
    read.open("sample.txt");

    std::cout << "New lines: \n";
    string line;
    while (getline(read, line)) {
        std::cout << line << '\n';
    }

    std::cout << "Ran successfully";
    return 0;
}