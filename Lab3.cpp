/*****************************************************************************************
Project Name: Lab 3
Name: Kristopher Lowell
Date Completed: 8/7/2018
Purpose: To accept a temperature (number and scale) and by using a class, determine the
value of the same temperature in the other two scales (kelvin, celsius, fahrenheit).
*****************************************************************************************/

#include <iostream>

using namespace std;

class Temperature
{
public:
	Temperature() {}	// Default constructor

	double getK() { return kelvin; }	// Accessor functions
	double getC() { return celsius; }
	double getF() { return fahrenheit; }

	void setFromKelvin(double kelvinVal)	// Mutator function for setting from Kelvin
	{
		kelvin = kelvinVal;
		celsius = kelvin - 273.15;
		fahrenheit = (celsius * (9.00 / 5.00)) + 32;
	}

	void setFromCelsius(double celsiusVal)	// Mutator function for setting from Celsius
	{
		celsius = celsiusVal;
		kelvin = celsius + 273.15;
		fahrenheit = (celsiusVal * (9.00 / 5.00)) + 32;
	}

	void setFromFahrenheit(double fahrenheitVal)	// Mutator function for setting from Fahreheit
	{
		fahrenheit = fahrenheitVal;
		celsius = (5.00 / 9.00) * (fahrenheit - 32);
		kelvin = celsius + 273.15;
	}

private:
	double kelvin;			// Data members
	double celsius;
	double fahrenheit;
};

int main(int argc, char *argv[])
{
	double number;
	char scale;
	Temperature temp;

	cout << "Enter a temperature: ";	// Accepting value of temperature
	cin >> number;

	do									// Accepting the scale of temperature (Kelvin, Celsius, or Fahrenheit)
	{
		cout << "Enter the temperature scale (K/C/F): ";
		cin >> scale;
		cin.ignore(INT_MAX, '\n');
	} while (scale != 'K' && scale != 'k' && scale != 'C' && scale != 'c' && scale != 'F' && scale != 'f');

	cout.setf(ios_base::fixed);			// Setting output precision/format
	cout.precision(2);

	if (scale == 'K' || scale == 'k')	// In the case of a Kelvin temperature entered
	{
		temp.setFromKelvin(number);		// Using a mutator function for Temperature Class

		cout << "Temperature in Celsius: " << temp.getC() << endl;		// Using accessor functions to access private data members
		cout << "Temperature in Fahrenheit: " << temp.getF() << endl;
	}
	else if (scale == 'C' || scale == 'c')	// In the case of a Celsius temperature entered
	{
		temp.setFromCelsius(number);	// Using a mutator function for Temperature Class

		cout << "Temperature in Kelvin: " << temp.getK() << endl;		// Using accessor functions to access private data members
		cout << "Temperature in Fahrenheit: " << temp.getF() << endl;
	}
	else								// In the case of a Fahrenheit temperature entered
	{
		temp.setFromFahrenheit(number);	// Using a mutator function for Temperature Class

		cout << "Temperature in Kelvin: " << temp.getK() << endl;		// Using accessor functions to access private data members
		cout << "Temperature in Celsius: " << temp.getC() << endl;
	}

	cin >> number;
}