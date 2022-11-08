#include "simplevm/simplevm.hpp"
#include <iostream>
#include <sstream>

//---------------------------------------------------------------------------
namespace simplevm {
// Run the VM. Return the value from register A when the execution finished.
int32_t runVM() {
    int32_t A, B, C, D;
    float Y, X;

    int i, vi; //opcode i //value iimm
    float vf; //value fimm
    char c; //Register

    while (true) {
        //read String
        std::string str;
        std::getline(std::cin, str);

        //count spaces
        int count = 0;
        int length = str.length();
        for (int i = 0; i < length; i++) {
            int c = str[i];
            if (isspace(c)) {
                count++;
            }
        }

        //stringstream to allocate input values to existing variables
        std::istringstream iss(str);
        if (count == 0) {
            //std::cout << "count == 0" << std::endl;
            iss >> i;
        } else if (count == 1) {
            //std::cout << "count == 1" << std::endl;
            iss >> i;
            iss >> c;
        } else if (count == 2) {
            //std::cout << "count == 2" << std::endl;
            iss >> i;
            iss >> c;
            if (str.find('.') != std::string::npos) {
                iss >> vf;
            } else {
                iss >> vi;
            }
        }

        if (i < 0 || i > 100) {
            std::cout << "opcode out of bound ( > 0..100 <)" << std::endl;
            return A;
        } else {
            switch (i) {
                case 0:
                    return A;
                case 10:
                    //std::cout << "opcode 10 - movi" << std::endl;
                    if (c == 'A') {
                        A = vi;
                    } else if (c == 'B') {
                        B = vi;
                    } else if (c == 'C') {
                        C = vi;
                    } else if (c == 'D') {
                        D = vi;
                    }
                    break;

                case 11:
                    //std::cout << "opcode 11 - movf" << std::endl;
                    if (c == 'X') {
                        X = vf;
                    } else if (c == 'Y') {
                        Y = vf;
                    }
                    break;
                case 20:
                    //std::cout << "opcode 20 - loada" << std::endl;
                    if (c == 'A') {
                        A = A;
                    } else if (c == 'B') {
                        A = B;
                    } else if (c == 'C') {
                        A = C;
                    } else if (c == 'D') {
                        A = D;
                    }
                    break;
                case 21:
                    //std::cout << "opcode 21 - storea" << std::endl;
                    if (c == 'A') {
                        A = A;
                    } else if (c == 'B') {
                        B = A;
                    } else if (c == 'C') {
                        C = A;
                    } else if (c == 'D') {
                        D = A;
                    }
                    break;
                case 22: {
                    //std::cout << "opcode 22 - swapab" << std::endl;
                    int z = A;
                    A = B;
                    B = z;
                } break;
                case 30:
                    //std::cout << "opcode 30 - loadx" << std::endl;
                    if (c == 'X') {
                        X = X;
                    } else if (c == 'Y') {
                        X = Y;
                    }
                    break;

                case 31:
                    //std::cout << "opcode 31 - storex" << std::endl;
                    if (c == 'X') {
                        X = X;
                    } else if (c == 'Y') {
                        Y = X;
                    }
                    break;
                case 32: {
                    //std::cout << "opcode 32 - swapxy" << std::endl;
                    float z = X;
                    X = Y;
                    Y = z;
                } break;
                case 40: {
                    //std::cout << "opcode 40 - itof" << std::endl;
                    float z = float(A);
                    X = z;
                } break;

                case 41: {
                    //std::cout << "opcode 41 - ftoi" << std::endl;
                    int z = int(X);
                    A = z;
                } break;

                case 50:
                    //std::cout << "opcode 50 - addi" << std::endl;
                    //2147483648 -2147483648
                    A = A + B;
                    break;
                case 51:
                    //std::cout << "opcode 51 - subi" << std::endl;
                    if (A >= B) {
                        A = A - B;
                    }
                    break;

                case 52:
                    //std::cout << "opcode 52 - rsubi" << std::endl;
                    if (B >= A) {
                        A = B - A;
                    }
                    break;

                case 53:
                    //std::cout << "opcode 53 - muli" << std::endl;
                    A = A * B;
                    break;

                case 54:
                    //std::cout << "opcode 54 - divi" << std::endl;
                    if (B != 0) {
                        int32_t C = A;
                        A = A / B;
                        B = C % B;
                    } else {
                        std::cout << "division by 0" << std::endl;
                        return A;
                    }
                    break;

                case 60:
                    //std::cout << "opcode 60 - addf" << std::endl;
                    X = X + Y;
                    break;
                case 61:
                    //std::cout << "opcode 61 - addf" << std::endl;
                    if (X > Y) {
                        X = X - Y;
                    }
                    break;

                case 62:
                    //std::cout << "opcode 62 - subf" << std::endl;
                    X = X * Y;
                    break;

                case 63:
                    //std::cout << "opcode 63 - divf" << std::endl;
                    if (Y != 0) {
                        X = X / Y;
                    } else {
                        std::cout << "division by 0" << std::endl;
                        return A;
                    }
                    break;
            }
        }
    }
}

//---------------------------------------------------------------------------

// Print a VM program that calculates the nth fibonacci number.
void fibonacciProgram(unsigned n) {
    int t1 = 0, t2 = 1, nextTerm = 0;

    // displays the first two terms which is always 0 and 1
    std::cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    nextTerm = t1 + t2;

    while (n) {
        std::cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    //---------------------------------------------------------------------------
}
} // namespace simplevm
//---------------------------------------------------------------------------
