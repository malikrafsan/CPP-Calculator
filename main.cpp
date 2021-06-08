# include <iostream>
#include <vector>
using namespace std;

double pangkat(double num1, double num2){
	// I.S. num1 dan num2 terdefinisi
	// F.S. dikembalikan nilai num1 pangkat num2 dengan metode rekursif
    
	// Base case
	if(num2==0)
        return 1;
	// Recursive case
    else
        return num1 * pangkat(num1,(num2-1));
}

double f(double x, vector<double> &lst) {
	// I.S. x dan lst terdefinisi
	// F.S. dikembalikan nilai f(x)
	
	// KAMUS
	double hasil = 0;
	
	// ALGORITMA
	// Menghitung nilai f(x) untuk masing masing derajat f(x) dan menjumlahkannya 
	for(int i{0}; i<lst.size(); ++i) hasil += (pangkat(x,i)) * lst[i];
	return hasil;
}

double integral(double delta, double bawah, double atas, vector<double> &lst) {
	// I.S. delta, bawah, atas, dan lst terdefinisi
	// F.S. dikembalikan nilai integral dengan metode jumlah riemann tengah, dengan dx, yaitu delta
	// batas bawah, yaitu bawah, batas atas yaitu atas, dan koefisien masing-masing derajat polinom pada lst

	// KAMUS
	double sum = 0;

	// ALGORITMA
	// Melakukan penjumlahan luas untuk setiap delta
	while(bawah < atas) {
		double luas = 0.5 * delta * (f(bawah, lst) + f((bawah + delta), lst));
		sum += luas;
		bawah += delta;
	}
	return sum;
}


int main() {
	// KAMUS
    char op;
    float num1;
	int num2;

	// Menampilkan main menu
	cout << "Calculator C++\n"<<endl;
	cout << "Kalkulator ini memiliki, berbagai fitur yaitu: "<<endl;
	cout << "1. Operasi tambah (ketik '+')"<<endl;
	cout << "2. Operasi kurang (ketik '-')"<<endl;
	cout << "3. Operasi kali (ketik 'x')"<<endl;
	cout << "4. Operasi bagi (ketik '/')"<<endl;
	cout << "5. Operasi pangkat (ketik '^')"<<endl; //hanya berlaku pada pangkat bilangan bulat >= 0
	cout << "6. Operasi integral (ketik 'S')"<<endl;
	cout << "-------------------------------------------------"<<endl;
	
	// Pengganti nilai boolean
	char lanjut;
	lanjut = 'Y';
	
	while (lanjut == 'Y'){
		cout << "Masukkan operator: "<<endl; cin >> op;
		
		// Kasus operator sederhana
		if (op == '+' || op == '-' || op == 'x' || op == '/'){
		    cout << "Masukan dua bilangan (pisahkan dengan spasi): ";
		    cin >> num1 >> num2;
		
		    switch(op) {
		        case '+': // Operasi tambah
		            cout <<"Hasil: "<< num1+num2<<endl;
		            break;
		
		        case '-': // Operasi kurang
		            cout <<"Hasil: "<< num1-num2<<endl;
		            break;
		
		        case 'x': // Operasi kali
		            cout <<"Hasil: "<< num1*num2<<endl;
		            break;
		
		        case '/': // Operasi bagi
		            cout << "Hasil: "<< num1/num2<<endl; // num1 bertipe float sehingga akan menghasilkan tipe float juga
		            break;
		    }
		// Operasi integral
		} else if (op == 'S'){ 
			cout <<"\n*Kalkulator ini hanya bisa untuk fungsi polinom, berpangkat bulat dengan pangkat nol atau positif"<<endl;
			
			cout <<"Masukkan pangkat tertinggi dari polinom anda"<<endl;
			int n; cin >> n;
			n = n + 1;
			// Membuat array dinamis dengan vektor untuk menyimpan koefisien dari masing masing pangkat fungsi f(x)
			vector<double> v(n);
			
			// Mengisi array koefisien pangkat dari input user
			for(int j{0};j < n; j++) {
				cout << "Masukkan koefisien dari x pangkat "<<j<<endl;
				cin >> v[j];	
			}
			// Meminta input boundary integral dari user
	  		double bawah, atas, delta;
	  		cout << "Masukkan batas bawah"<<endl; cin >> bawah;
	  		cout << "Masukkan batas atas"<<endl; cin >> atas; 
			cout << "Masukkan delta x (besar langkah)"<<endl; cin >> delta;
	  		
			// Menampilkan hasil ke layar
			cout << "Hasilnya: "<< integral(delta, bawah, atas, v) << endl;

			/* Contoh test case:
			integral x^2 + 2x + 5 dari x = 3 sampai 5 dengan delta x sebesar 0.0001
			integral x^3 - x^2 + 2x + 5 dari x = 3 sampai 5 dengan delta x sebesar 0.005
			integral 5x^0 dari x = 1 sampai 3 dengan delta x sebesar 0.2
			
			Kalkulator ini hanya bisa untuk fungsi polinom, berpangkat bulat dengan pangkat nol atau positif
			*/

		// Operasi pangkat			
		} else if (op=='^') {
			cout << "\nKalkulator ini hanya menerima bilangan pangkat berupa bilangan bulat (positif atau negatif)"<<endl;
			cout << "Masukan dua bilangan (bil1 pangkat bil2): ";
			cin >> num1 >> num2;
			
			// Kasus pangkat bilangan positif / nol
			if (num2 >= 0) {
				cout << "Hasil: " << pangkat(num1,num2)<<endl;
			} 
			// Kasus pangkat bilangan negatif
			else {
				num2 = - num2;
				cout << "Hasil: " << 1 / pangkat(num1,num2)<<endl;
			}
		} else {
		    cout << "Error! operator yang anda masukan tidak valid"<<endl;
		}
		cout << "Ada lagi? (Ketik 'Y' untuk lanjut dan apapun untuk tidak) "<< endl; cin >> lanjut;
	}
	
	cout << "Terima kasih. Semoga bermanfaat ^_^"<<endl;
    return 0;
}

