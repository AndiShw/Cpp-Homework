#include "simplevm/simplevm.hpp"
#include <iostream>
#include <sstream>
#include <limits.h>

//TODO: REFRACTOR!!1!

//---------------------------------------------------------------------------
namespace simplevm {
// Run the VM. Return the value from register A when the execution finished.
int32_t runVM() {
    int32_t A = 0;
    int32_t B = 0;
    int32_t C = 0;
    int32_t D = 0;
    float X = 0;
    float Y = 0;

    int32_t i, vi; //opcode i //value iimm
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
                    // std::cout << "opcode 11 - movf" << std::endl;
                    // jeder Float muss bei mir einen . haben, sonst wird er nicht
                    // erkannt. Da kein typeof() exisitiert wüsst ich nicht wie man sonst
                    // einen Float identifizieren könnte
                    // -> verwendet iimm, falls kein float gegeben
                    if (c == 'X') {
                        if (vf != 0) {
                            X = vf;
                        } else {
                            X = vi;
                        }
                    } else if (c == 'Y') {
                        if (vf != 0) {
                            Y = vf;
                        } else {
                            Y = vi;
                        }
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
                    int32_t z = A;
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
                    A = 0;
                    X = z;
                } break;

                case 41: {
                    //std::cout << "opcode 41 - ftoi" << std::endl;
                    int32_t z = int32_t(X);
                    X = 0;
                    A = z;
                } break;

                case 50:
                    // std::cout << "opcode 50 - addi" << std::endl;
                    // was meint "All arithmetic integer instructions
                    // should wrap their values on over- and underflow?"
                    // Wie soll sich das Programm bei einem Fehlerfall verhalten?
                    // Wenn man den Overflow verhindert stimmt das Ergebnis nicht
                    // mit dem vom beigefügten Google-Test und der Test wird falsch.
                    if (((B > 0) && (A > (INT32_MAX - B))) ||
                        ((B < 0) && (A < (INT32_MIN - B)))) {
                        std::cout << "Over - /Underflow" << std::endl;
                        A = A + B;
                    } else {
                        A = A + B;
                    }
                    break;

                case 51:
                    //std::cout << "opcode 51 - subi" << std::endl;
                    if (((B > 0) && (A < (INT32_MIN + B))) ||
                        ((B < 0) && (A > (INT32_MAX + B)))) {
                        std::cout << "Over - /Underflow" << std::endl;
                        A = A - B;
                    } else {
                        A = A - B;
                    }
                    break;

                case 52:
                    //std::cout << "opcode 52 - rsubi" << std::endl;
                    if (((B > 0) && (A < (INT32_MIN + B))) ||
                        ((B < 0) && (A > (INT32_MAX + B)))) {
                        std::cout << "Over - /Underflow" << std::endl;
                        A = B - A;
                    } else {
                        A = B - A;
                    }
                    break;

                case 53: {
                    //std::cout << "opcode 53 - muli" << std::endl;
                    if (A > 0) { /* si_a is positive */
                        if (B > 0) { /* si_a and si_b are positive */
                            if (A > (INT_MAX / B)) {
                                /* Handle error */
                            }
                        } else { /* si_a positive, si_b nonpositive */
                            if (B < (INT_MIN / A)) {
                                /* Handle error */
                            }
                        } /* si_a positive, si_b nonpositive */
                    } else { /* si_a is nonpositive */
                        if (B > 0) { /* si_a is nonpositive, si_b is positive */
                            if (A < (INT_MIN / B)) {
                                /* Handle error */
                            }
                        } else { /* si_a and si_b are nonpositive */
                            if ((A != 0) && (B < (INT_MAX / A))) {
                                /* Handle error */
                            }
                        } /* End if si_a and si_b are nonpositive */
                    } /* End if si_a is nonpositive */
                    A = A * B;
                } break;

                case 54:
                    //std::cout << "opcode 54 - divi" << std::endl;
                    if (!((B == 0) || ((A == LONG_MIN) && (B == -1)))) {
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
                    X = X - Y;
                    break;

                case 62:
                    //std::cout << "opcode 62 - subf" << std::endl;
                    X = X * Y;
                    break;

                case 63:
                    //std::cout << "opcode 63 - divf" << std::endl;
                    if (!((Y == 0) || ((X == LONG_MIN) && (Y == -1)))) {
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
    if (n < 3) {
        std::cout << 1 << std::endl;
    }

    // irgnedwie müssten die Anweisungen von unten jetzt eingelesen werden.
    // laut der Mail soll jedoch keine Liste an befehlen übergeben werden,
    // deshalb sollte das doch irgendwie wie unten funktionieren, oder?

    runVM();
    std::cout << "10 B 0\n"
              << std::endl; // B = 0
    std::cout << "10 C 1\n"
              << std::endl; // C = 1

    for (unsigned i = 1; i <= n; ++i) {
        std::cout << "20 C\n"
                  << std::endl; // load C into A
        std::cout << "50\n"
                  << std::endl; // add A and B
        std::cout << "21 D\n"
                  << std::endl; // store A in D
        std::cout << "20 C\n"
                  << std::endl; // load C in A
        std::cout << "21 B\n"
                  << std::endl; // Store A in B
        std::cout << "20 D\n"
                  << std::endl; // load D in A
        std::cout << "21 C\n"
                  << std::endl; // store A in C
        std::cout << "20 B\n"
                  << std::endl; // store B in A
        std::cout << "0\n"; //end and return result A

        /*
        for..
            D = B + C
            B = C
            C = D
        endfor
        */
    }
}
} // namespace simplevm
//---------------------------------------------------------------------------
