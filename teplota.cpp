#include <iostream>
#include <cmath>
#include <iomanip>
#include <queue> 
#include <ctime> 
#include <unistd.h>

using namespace std;

double getTeplota()
{
    double t = (double)rand() / RAND_MAX;
    return 35.0 + t * (41.0 - 35.0);
}

double getAvg30(queue<double> mereni) { 
	while (mereni.size() > 3) {
		mereni.pop();
	}
	double mereniCount = (double) mereni.size(); // duplicite code I know. Shoot me! :-)
	double total = 0;
	while(!mereni.empty()) {
		total = total + mereni.front();
		mereni.pop();
	}

	return (total / mereniCount);

}

double getAvg(queue<double> mereni) {
	double mereniCount = (double) mereni.size();
	double total = 0;
	while(!mereni.empty()) {
		total = total + mereni.front();
		mereni.pop();
	}

	return (total / mereniCount);

}

double getMin(queue<double> mereni) {
	double min = 100;
	while(!mereni.empty()) {
		if (min > mereni.front()) {
			min = mereni.front();
		}
		mereni.pop();
	}
	return min;
}

double getMax(queue<double> mereni) {
	double max = 0;
	while(!mereni.empty()) {
		if (max < mereni.front()) {
			max = mereni.front();
		}
		mereni.pop();
	}
	return max;
}

int main() {
	
	queue<double> hodnoty;

	cout << "Monitoring teploty pana Brzotuhého." << endl;
	cout << "" << endl;	

	while (true) {
		
		if (hodnoty.size() >= 6) {
			hodnoty.pop();
		}

		hodnoty.push(getTeplota());

		if (hodnoty.back() > 38.5) {
				cout << "Pacient nám skoro hoří!" << endl;
			}

		if (hodnoty.size() < 6) {
			cout << "Nemáme dostatek hodnot pro další výpočty, zatím jen " << hodnoty.size() << ", proto pokračujeme v měření." << endl;
		} else {
			//cout << "Máme " << hodnoty.size() << " hodnot jdeme počítat." << endl;
			
		    time_t now;
	    	time(&now);
	    	char buf[sizeof "YYYY-mm-ddTHH:MM:SSZ"];
	    	strftime(buf, sizeof buf, "%Y-%m-%dT%H:%M:%SZ", gmtime(&now));

			//cout << time(0) << endl;
			cout << buf << endl;
			double avg30 = getAvg30(hodnoty);
			double min = getMin(hodnoty);
			double max = getMax(hodnoty);
			double avg = getAvg(hodnoty);
			cout << "Průměr za posledních 30 minut je " << fixed << setprecision(2) << avg30 << "°C." << endl;
			cout << "Minimum za posledních 60 minut je " << fixed << setprecision(2) << min << "°C." << endl;
			cout << "Maximum za posledních 60 minut je " << fixed << setprecision(2) << max << "°C." << endl;
			cout << "Průměr za posledních 60 minut je " << fixed << setprecision(2) << avg << "°C." << endl;

			if ((max - min) > 0.5) {
				cout << "Za posledních 60 minut teplota vzrostla o více než 0.5°C." << endl;
			}
		}
		sleep(600);
	}
}

