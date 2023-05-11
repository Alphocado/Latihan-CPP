#include <iostream>
#include "isi.h"

using namespace std;

char opt;

int main(){	
	isi();
	
	label_continue:
	cout << "\nMulai ulang?\n(Y/N) => ";
	cin >> opt;
	
	if((opt == 'y')|(opt == 'Y')){
		isi();
		goto label_continue;
	}
	else if ((opt == 'n')|(opt == 'N')){
		cout << "\nDone" << endl;

	}
	else{
		system("cls");
		goto label_continue;
	}
	cin.get();
	return 0;
}
