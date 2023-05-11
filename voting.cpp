#include <iostream>
#include <cmath>

using namespace std;

char voting;
int A, B;
double jumlahA, jumlahB;

double persenA(double a){
	double hasilA;
	hasilA = a * 100/(a+B);
	return hasilA;
}
double persenB(double b){
	double hasilB;
	hasilB = b * 100/(A+b);
	return hasilB;
}

int main(){
	is_continue:
	jumlahA = persenA(A);
	jumlahB = persenB(B);


	system("cls");

	



	cout << "Voting" << endl;
	cout << "1. A = " << A << " = " << jumlahA << endl;
	cout << "2. B = " << B << " = " << jumlahB <<endl;
	cout << "\n=> ";
	cin >> voting;
	
	if(voting == '1'){
		A = A + 1;
		goto is_continue;
	}
	else if(voting == '2'){
		B = B + 1;
		goto is_continue;
	}
	else{
		goto is_continue;
	}

	cin.get();
	return 0;
}
