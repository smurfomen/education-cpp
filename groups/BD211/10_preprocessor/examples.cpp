#include <iostream>
#include <string>
#include <cmath>

using namespace std;
#define DEBUG


#define MAX(a,b) ((a) > (b) ? (a) : (b) )
#define MIN(a,b) ((a) > (b) ? (b) : (a) )
#define SQUARE(a) ((a) * (a))
#define POW(a,b) (pow(a,b))
#define IS_EVEN(a) (static_cast<bool>((a)%2 == 0))
#define IS_NOT_EVEN(a) (static_cast<bool>((a)%2))
#include <cassert>
int main()
{
	cout << __FILE__ << ":" << __LINE__ << endl;
	cout << MAX(5, 7) << endl;
	cout << MIN(5, 7) << endl;
	cout << SQUARE(4) << endl;
	cout << POW(2, 2) << endl;
	cout << IS_EVEN(2) << endl;
	cout << IS_NOT_EVEN(3) << endl;


	assert(MAX(5, 7) == 7);
	assert(MAX(5 + 3, 7) == 8);

	assert(MIN(5, 7) == 5);
	assert(MIN(5 + 3, 7) == 7);

	assert(SQUARE(2) == 4);
	assert(SQUARE(4) == 16);

	assert(POW(2, 2) == 4);
	assert(POW(2, 5) == 32);

	assert(IS_EVEN(2));
	assert(IS_EVEN(4));
	assert(!IS_EVEN(3));

	assert(IS_NOT_EVEN(5));
	assert(IS_NOT_EVEN(3));
	assert(!IS_NOT_EVEN(2));

	return 0;
}