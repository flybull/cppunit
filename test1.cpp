#include "impl.h"
#include <iostream>
using namespace std;
static impl::demo test {
	"test1",
	[]() { cout << "init" << endl;},
	[]() { cout << "start" << endl;},
	[]() { cout << "join" << endl;},
	[]() { cout << "stop" << endl;},
	[]() { cout << "uninit" << endl;}		
};
