#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	
	string sstrana, suhlopricka;
	double strana, uhlopricka;

	cout << "Slyšel jsem, že neumíš spočítat obvod obdelníku." << endl;
	cout << "No, docela vostuda!" << endl;
	cout << "" << endl;

	cout << "Stranu změřit umíš? Tak ukaž: ";
	cin >> sstrana;

   	strana = strtod(sstrana.c_str(), NULL);  	// Y U No Throw Exception?
    
	cout << "A co úhlopříčku? Zkus to: ";
	cin >> suhlopricka;

  	uhlopricka = strtod(suhlopricka.c_str(), NULL);    	// Y U No Throw Exception? 
	
	if (uhlopricka > 0 && strana > 0) {
		cout << "Deme počítat." << endl;
		double vysledek = (2 * strana + 2 * pow(abs (pow(strana, 2) - pow(uhlopricka, 2)), 0.5));
		cout << "Výsledek je: ";
		cout << fixed << setprecision(2) << vysledek << endl;
		return 1;
	} else {
    	cout << "Člověče, už jsi viděl obdelník s nulovou nebo zápornou stranou či úhlopříčkou?" << endl;
    	cout << "Vzpamatuj se!" << endl;
    	return -1;		
	}
}

