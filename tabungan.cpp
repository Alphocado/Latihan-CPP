#include <iostream>
#include <fstream>
using namespace std;
char pilih;
char is_continue;
int hasil;
int number;
fstream myFile;
void checkDatabase(fstream &myFile);
void opsi();
void add();
void take();
int main(){
	sambung:
	system("cls");
	opsi();
	while(pilih != '3'){
		if(pilih == '1'){
			add();
		}
		else if(pilih == '2'){
			take();
		}
		else{
			goto sambung;
		}
		lanjut:
		cout << "\nLanjut?(y/n)\n=> ";
		cin >> is_continue;
		if((is_continue == 'y') | (is_continue == 'Y')){
			opsi();
		}
		else if((is_continue == 'n') | (is_continue == 'N')){
			break;
		}
		else{
			goto lanjut;
		}
	}
	cout << "\nDone" << endl;
	cin.get();
	return 0;
}
void checkDatabase(fstream &myFile){
	system("cls");
	myFile.open("data.bin", ios::out | ios::in | ios::binary);
	if(myFile.is_open()){
		myFile.close();

	}else{
		myFile.close();
		myFile.open("data.bin", ios::trunc | ios::out | ios::in| ios::binary);
		myFile.close();
	}
}
void opsi(){
	system("cls");
	checkDatabase(myFile);
	myFile.open("data.bin", ios::in | ios::binary);
	myFile.read(reinterpret_cast<char*>(&hasil), sizeof(hasil));
	myFile.close();
	cout << "Tabungan = Rp." << hasil;
	cout << "\n   Program tabungan   " << endl;
	cout << "O====================O" << endl;
	cout << "| 1. Tambah tabungan |" << endl;
	cout << "| 2. Ambil uang      |" << endl;
	cout << "| 3. Selesai         |" << endl;
	cout << "O====================O" << endl;
	cout << "Pilih [1-3]\n=> ";
	cin >> pilih;
	
}
void add(){
	cout << "\nMasukan uang\n=> Rp.";
	cin >> number;
	myFile.open("data.bin", ios::out | ios::binary);
	number = hasil + number;
	myFile.write(reinterpret_cast<char*>(&number), sizeof(number));
	myFile.close();
}

void take(){
	cout << "\nAmbil berapa uang\n=> Rp.";
	cin >> number;
	myFile.open("data.bin", ios::out | ios::binary);
	number = hasil - number;
  	myFile.write(reinterpret_cast<char*>(&number), sizeof(number));
	myFile.close();
}
