#include <fstream>
#include <iostream>
#include <string>

// Unused Code. I'll keep it here just in case.
/*char numeri;
int fine;
char *dnumeri = &numeri;*/
/*leggofile.read(dnumeri, 1);
cout << numeri << "\n";
leggofile.read(dnumeri, 1);
cout << numeri << "\n";
leggofile.read(dnumeri, 1);
cout << numeri << "\n";*/

using namespace std;

int main()
{
	ifstream infile("C:/Temp/input.stp");
	ofstream outfile("C:/Temp/output.scl");
	string inln = "0";
	string outln = "0";
	string end = "ENDSEC";
	char delim = ';';
	char iscart = 'S';
	bool stop = 1;
	int lx = 0;
	int ly = 0;
	int lz = 0;

	cout << "Starting translation...\n";
	outfile << "//This is the file intestation. You can freely edit it. Consider describing the shape the file contains.\n";

	while (stop)
	{
		getline(infile, inln, delim);

		if (inln == end)
		{
			cout << "\nFinished Translation. ";
			stop = 0;
		}
		else if (inln[8+]=='S')
		{
			cout << "||   " << inln << ";\n|| Translating to ||\n";


			outln = inln + ";";
			outfile << outln << endl;

		}
		else
		{
			cout << "\n|| Line Ignored   ||\n";
		}
		getline(infile, inln);
		inln = "";
	}
}