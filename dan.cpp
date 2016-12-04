#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	string shodnota;
	bool pribuzny;
	double hodnota;

	cout << "Dostal si dárek? A budeš danit?" << endl;
	cout << "" << endl;

	cout << "Jakou má dar hodnotu? ";
	cin >> shodnota;

   	hodnota = strtod(shodnota.c_str(), NULL);  	// Y U No Throw Exception?
    
   	if (hodnota < 15000) {
   		cout << "Dárek pod 15 000 Kč danit nemusíš." << endl;
   		return 1;	
   	} else {
   		cout << "Jsi příbuzný? (Ano = 1; Ne = 0) ";
		cin >> pribuzny;
		if (cin && (pribuzny == 0 || pribuzny == 1)) {
			if (pribuzny == true) {
   				cout << "Jako příbuzný danit nemusíš." << endl;
   				return 1;					
			} else {
				double vysledek = hodnota * 0.15;
				cout << "Zaplať daň v hodnotě ";
				cout << fixed << setprecision(2) << vysledek;
				cout << " Kč." << endl;
				return 1;
			}
		} else {
			cout << "Když jsi příbuzný zadej 1, když nejsi zadej 0." << endl;
			cout << "Za trest si to zkus celé od začátku!" << endl;
			return -1;
		}
   	}
}

