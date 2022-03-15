#include "mat.hpp"
#include "mat.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::mat(9, 7, '@', '-') << endl;
/* Should print:
@@@@@@@@@
@-------@
@-@@@@@-@
@-@---@-@
@-@@@@@-@
@-------@
@@@@@@@@@
*/
}