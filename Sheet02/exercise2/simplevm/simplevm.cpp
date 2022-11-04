#include "simplevm/simplevm.hpp"
#include <iostream>
//---------------------------------------------------------------------------
namespace simplevm {
//---------------------------------------------------------------------------
int32_t runVM()
// Run the VM. Return the value from register A when the execution finished.
{
    // Add your code here
}
//---------------------------------------------------------------------------
void fibonacciProgram(unsigned n)
// Print a VM program that calculates the nth fibonacci number.
{
    int t1 = 0, t2 = 1, nextTerm = 0, n;

    // displays the first two terms which is always 0 and 1
    std::cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    nextTerm = t1 + t2;

    while (nextTerm <= n) {
        std::cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}
//---------------------------------------------------------------------------
} // namespace simplevm
//---------------------------------------------------------------------------
