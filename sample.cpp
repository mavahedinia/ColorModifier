// TODO : Choose an Appropriate Name!!
// We're not here because we're free. We're here because we are not free.
//											   The Matrix Reloaded (2003)
#include <bits/stdc++.h>
#include "ColorModifier.h"

using namespace std;
using namespace ColorModifier;

#define MohammadAmin main()
#define c_false ios_base::sync_with_stdio(false); cin.tie(0)

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int MohammadAmin {
	c_false;
	message("Hello World!\n"); // No styles and Colors!
	message("Hello Red World!\n", Red); // Just Colored red!
	message("Hello Green Bold World!\n", Green, Bold); // Bold and Green!
	setColor(Blue);
	setStyle(Underline | Bold);
	cout << "This is Bold and Underlined Blue Text!!!" << endl;
	resetColor();
	cout << "Still Underlined!!" << endl;
	resetStyle();
	cout << "Normal!!" << endl;
	resetAll();
	cout << "Again normal!" << endl;
	destroyPrinter(); // to bring terminal its normal functionality
	return 0;
}
