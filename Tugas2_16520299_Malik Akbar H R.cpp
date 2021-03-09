# include <iostream>
#include <vector>
using namespace std;


double pangkat(double num1, double num2){
    if(num2==0)
        return 1;
    else
        return num1 * pangkat(num1,(num2-1));
}


double f(double x, vector<double> &lst) {
  double hasil = 0;
  for(int i{0}; i<lst.size(); ++i) hasil += (pangkat(x,i)) * lst[i];
  return hasil;
}

double integral(double delta, double bawah, double atas, vector<double> &lst) {
  double sum = 0;
  while(bawah < atas) {
    double luas = 0.5 * delta * (f(bawah, lst) + f((bawah + delta), lst));
    sum += luas;
    bawah += delta;
  }
  return sum;
}


int main()
{
    char op;
    float num1;
	int num2;

	cout << "Calculator C++"<<endl;
	cout <<endl;
	cout << "Kalkulator ini memiliki, berbagai fitur yaitu: "<<endl;
	cout << "1. Operasi tambah (ketik '+')"<<endl;
	cout << "2. Operasi kurang (ketik '-')"<<endl;
	cout << "3. Operasi kali (ketik 'x')"<<endl;
	cout << "4. Operasi bagi (ketik '/')"<<endl;
	cout << "5. Operasi pangkat (ketik '^')"<<endl; //hanya berlaku pada pangkat bilangan bulat >= 0
	cout << "6. Operasi integral (ketik 'S')"<<endl;
	cout << "-------------------------------------------------"<<endl;
	
	char lanjut;
	lanjut = 'Y';
	
	while (lanjut == 'Y'){
		cout << "Masukkan operator"<<endl;
	    cin >> op;
		
		if (op == '+' || op == '-' || op == 'x' || op == '/'){
		    cout << "Masukan dua bilangan (pisahkan dengan spasi): ";
		    cin >> num1 >> num2;
		
		    switch(op)
		    {
		        case '+':
		            cout <<"Hasil: "<< num1+num2<<endl;
		            break;
		
		        case '-':
		            cout <<"Hasil: "<< num1-num2<<endl;
		            break;
		
		        case 'x':
		            cout <<"Hasil: "<< num1*num2<<endl;
		            break;
		
		        case '/':
		            cout << "Hasil: "<< num1/num2<<endl;
		            break;
		    }
		} else if (op == 'S'){
			cout <<"Kalkulator ini hanya bisa untuk fungsi polinom, berpangkat bulat dengan pangkat nol atau positif"<<endl;
			
			cout <<"Masukkan pangkat tertinggi dari polinom anda"<<endl;
			int n; cin >> n;
			n = n + 1;
			vector<double> v(n);
			
			
			for(int j{0};j < n; j++) {
				cout << "Masukkan koefisien dari x pangkat "<<j<<endl;
				cin >> v[j];	
			} 
	  		double bawah, atas, delta;
	  		cout << "Masukkan batas bawah"<<endl;
	  		cin >> bawah;
	  		cout << "Masukkan batas atas"<<endl;
			cin >> atas; 
			cout << "Masukkan delta x (besar langkah)"<<endl;
			cin >> delta;
	  		
			cout << "Hasilnya: "<< integral(delta, bawah, atas, v) << endl;
			
		} else if (op=='^') {
			cout << "Kalkulator ini hanya menerima bilangan pangkat berupa bilangan bulat (positif atau negatif)"<<endl;
			cout << "Masukan dua bilangan (pisahkan dengan spasi): ";
			cin >> num1 >> num2;
			
			if (num2 >= 0) {
				cout << "Hasil: " << pangkat(num1,num2)<<endl;
			} else {
				num2 = - num2;
				
				cout << "Hasil: " << 1 / pangkat(num1,num2)<<endl;

			/* Contoh test case:
			integral x^2 + 2x + 5 dari x = 3 sampai 5 dengan delta x sebesar 0.0001
			integral x^3 - x^2 + 2x + 5 dari x = 3 sampai 5 dengan delta x sebesar 0.005
			integral 5x^0 dari x = 1 sampai 3 dengan delta x sebesar 0.2
			
			Kalkulator ini hanya bisa untuk fungsi polinom, berpangkat bulat dengan pangkat nol atau positif
			*/
			}
		} else {
		    cout << "Error! operator yang anda masukan tidak valid"<<endl;
		}
		cout << "Ada lagi? (Ketik 'Y' untuk lanjut dan apapun untuk tidak) "<<endl;
		cin >> lanjut;
	}
	
	cout << "Terima kasih. Semoga bermanfaat ^_^"<<endl;
	
    return 0;
}

