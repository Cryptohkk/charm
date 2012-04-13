#include "sdlconfig.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Future TODO: tinyXML for deserializing structures to C++

void decout(PairingGroup & group, CharmDict & ciphertext, ZR & zz, GT & egg)
{
	GT R;
	GT T0 = ciphertext['T0']->gt;
	T1 = ciphertext['T1'];
	GT T2 = ciphertext['T2']->gt;

	CharmList sList;

	R = group.div(T0, group.exp(T2, zz));
	s_sesskey = SHA1(R);
	M = SymDec(s_sesskey, T1); // need to implement this as well ==> TRICKY!!!

	sList.append(R);
	sList.append(M);
	s = group.hashListToZR(sList);

	if( (T0 == group.mul(R, group.exp(egg, s))) && (T2 == group.mul(R, group.exp(egg, s / zz))) ) {
		cout << "Successful Decryption!!!" << endl;
		return M; // should be a string at this point
	}
	else {
		cout << "FAILED DECRYPTION!!!" << endl;
	}

}

int main()
{
	PairingGroup group(AES_SECURITY);

	// get filename with ciphertext, secret key and public key ==> deserialize into object
	// follow 'key' : 'value' format and parsing will be easier using standard string handling functions

	// verify objects well-formed

	// call decout(group, ciphertext, zz, pk) ==> M or error!

	return 0;
}
