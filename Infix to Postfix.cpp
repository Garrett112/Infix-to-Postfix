#include "InfixToPostfix.h"
#include <fstream>

using namespace std;

int main() {
    cout << "–" << endl << "-" << endl;
    InfixToPostfix converter;
    string equation;
    ifstream infile("InfixData.txt");
    while (getline(infile, equation)) {
        cout << "Infix Expression: " << equation << endl;
        converter.Convert(equation);
        cout << "Postfix Expression: " << converter.postfix << endl;
    }
    infile.close();
}