#include <iostream>
#include <cmath>
using namespace std;

//membuat angka tiap bagian papan
char papan[3][3] = {

	{'1', '2', '3'}, 

	{'4', '5', '6'}, 

	{'7', '8', '9'}

	};


	//Yang normalnya
	//+---+---+---+
	//|0,0|0,1|0,2|
	//+---+---+---+
	//|1,0|1,1|1,2|
	//+---+---+---+
	//|2,0|2,1|2,2|
	//+---+---+---+
	//
	//diubah nilainya menjadi
	//
	//+---+---+---+
	//| 1 | 2 | 3 |
	//+---+---+---+
	//| 4 | 5 | 6 |
	//+---+---+---+
	//| 7 | 8 | 9 |
	//+---+---+---+



char current_marker;
int current_player;

//fungsi untuk papannya
void gambarpapan();

//fungsi untuk penanda
//mengganti array kolum menjadi X
bool penanda(int slot);

//RUMUS FUNGSI UNTUK MELIHAT PEMENANG
int pemenang();

//Dari player 1 ke player 2,dan sebaliknya
void swap_pemain_dan_marker();

//Front-game
void game();


//Inti
int main(){
	
	system("cls");
	cout << "TicTacToe!!" << endl;

	game();

	cout << "\n\nDone" << endl;
	cin.get();
	return 0;
}





























void gambarpapan(){
	
	cout << "+---+---+---+\n";
	cout << "| " << papan[0][0] << " | " << papan[0][1] << " | " << papan[0][2] << " |" << endl;
	cout << "+---+---+---+\n";
	cout << "| " << papan[1][0] << " | " << papan[1][1] << " | " << papan[1][2] << " |" << endl;
	cout << "+---+---+---+\n";
	cout << "| " << papan[2][0] << " | " << papan[2][1] << " | " << papan[2][2] << " |" << endl;
	cout << "+---+---+---+\n";
}

bool penanda(int slot){
	int baris = slot / 3;
	int kolom;

	//Jika penanda() inputnya 9/6/3 maka lakukan ini
	if(slot % 3 == 0)
	{
		baris = baris - 1;
		kolom = 2;
	}

	//Selain dari ketiga angka tersebut, maka lakukan ini
	else kolom = (slot % 3) - 1;

	//mengganti kan alamat papan yg dipilih dengan X (penanda)
	if(papan[baris][kolom] != 'X' && papan[baris][kolom] != 'O'){
		papan[baris][kolom] = current_marker;
		return true;
	}
	else return false;
}

int pemenang(){

	//BARIS DAN KOLOM`
	for(int i = 0; i < 3; i++){

		//baris '-'
		if(papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]){
			return current_player;
		}

		//kolom '|'
		if(papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i]){
			return current_player;		
		}
	}

	//DIAGONAL '\'
	if(papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) {
		return current_player;
	}
	
	//DIAGONAL '/'
	if(papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0]) {
		return current_player;
	}

	return 0;
}

void swap_pemain_dan_marker(){
	
	//Jika X sudah, ganti ke O
	if(current_marker == 'X'){
		current_marker = 'O';
	}

	//Jika O sudah, ganti ke X
	else{
		current_marker = 'X';
	}

	

	//Jika player 1 sudah, ganti giliran player 2
	if(current_player == 1){
		current_player = 2;
	}

	//Jika player 2 sudah, ganti giliran player 1
	else{
		current_player = 1;
	}
}

void game(){
	
	//Deklarasi
	char marker_p1;
	int slot;
	int pemain_menang;
	
	//Input untuk memilih jenis penanda apa
	
	gocontinue:
	cout << "\nPlayer 1, pilih penanda mu! (Pakai kapital)\nX atau O?\n=>";
	cin >> marker_p1;

	if(marker_p1 == 'X' || marker_p1 == 'O'){
		current_marker = marker_p1;
	}else{
		system("cls");
		goto gocontinue;
	}
	current_player = 1;

	system("cls");

	gambarpapan();
	
	//Looping 9 kali yang artinya 9 kali kesempatan memilih
	for(int i = 0; i < 9; i++){					

		cout << "Player " << current_player << " masukan slot : ";
		cin >> slot;

		
		//Jika slot yg diisi kurang dari 1 atau lebih dari 9
		if(slot < 1 || slot >9){
			cout << "Maaf nomor yang dimasukan kurang dari 1 atau lebih dari 9! Coba lagi!" << endl;
			i--;
			continue;
		}else if(!penanda(slot)){
			cout << "Sudah penuh! Coba lagi!" << endl;
			i--;
			continue;
		}

	
		penanda(slot);
		system("cls");
		gambarpapan();

		pemain_menang = pemenang();

		if(pemain_menang == 1){
			cout << "Pemain 1 menang! Selamat!";
			break;
		}
		if(pemain_menang == 2){
			cout << "Pemain 2 menang! Selamat!";
			break;
		}

		swap_pemain_dan_marker();

		
	}

	if(pemain_menang == 0){
		cout << "Seri, tidak ada yang menang" << endl;
	}



}
