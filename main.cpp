#include <iostream>
#include "DateTime.hpp"

using namespace std;

int main()
{
	DateTime dt{};

	cout << "Seconds since 1/1/1970: " << dt.getCurrentTimestamp();
	cout << endl;

	cout << "Day: " << dt.getDay() << endl;
	cout << "Month: " << dt.getMonth() << endl;
	cout << "Year: " << dt.getYear() << endl;
	cout << endl;

	cout << "Hour: " << dt.getHour() << endl;
	cout << "Minute: " << dt.getMinute() << endl;
	cout << "Second: " << dt.getSecond() << endl;
	cout << endl;

	cout << dt.getFormatedStr("WW DD/MM/YYYY hh:mm:ss") << endl;
	cout << dt.getFormatedStr("DD/MM/YYYY WW") << endl;
	cout << dt.getFormatedStr("hh:mm:ss") << endl;
	cout << dt.getFormatedStr("WW") << endl;
	cout << endl;

	return EXIT_SUCCESS;
}