#include "Hash.h"

//The magic of number 33, i.e. why it works better than many other constants,
//prime or not, has never been adequately explained by anyone.
int Hash::String(const char* szOrg) {
	int iHash = 5381;

	while (int iStr = *szOrg++) iHash = iHash * 33 + iStr;

	return iHash;
}
