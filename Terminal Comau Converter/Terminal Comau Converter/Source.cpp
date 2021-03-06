#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	ifstream infile("./input.stp");
	ofstream outfile("./sculpture.scl");
	string inln = "";
	string outln = "";
	string end = "ENDSEC";
	char delim = ';';
	char iscart = 'S';
	bool stop = 1;
	bool threesteps = 1;
	bool headerend = 1;
	int n = 0;
	int l = -2;
	int c = 0;
	string bnum = "";
	string x = "";
	string y = "";
	string z = "";

	cout << "||===========================================================================||\n";
	cout << "||======|| Alessandro's .stp to .scl translator for COMAU C4G Robots ||======||\n";
	cout << "||                                                                           ||\n";
	cout << "||   This Translator will work from files named \"input.stp\" in this folder.  ||\n";
	cout << "||      The output will be \"sculpture.scl\". Please move your file here.      ||\n";
	cout << "||    If no file is available, translation won't start and thus won't end.   ||\n";
	cout << "||                                                                           ||\n";
	cout << "||======||   Compiled the 26th of November in 2015 at DIMEC, Genua   ||======||\n";
	cout << "||===========================================================================||\n";
	cout << "||                                                                           ||\n";
	cout << "|| ";
	system("pause");
	cout << "|| Starting translation...\n";
	outfile << "//This is the file intestation. You can freely edit it. Consider describing the shape the file contains.\n";

	while (stop)
	{
		getline(infile, inln, delim);
		if (headerend)
		{
			while (inln[1] != '#')
			{
				getline(infile, inln, delim);
			}
			headerend = 0;
		}
		if (inln == end)
		{
			cout << "|| Finished Translation. ";
			stop = 0;
		}
		else
		{
			while (inln[c] != '=')
			{
				c++;
				l++;
			}
			if ((inln[3 + l] == 'C') && (inln[5 + l] == 'R') &&(inln[6 + l] == 'T'))
			{
				while (inln[c] != ',')
				{
					c++;
				}
				c++;
				c++;
				while (inln[c] != ',')
				{
					bnum = bnum + inln[c];
					c++;
				}
				c++;
				x = bnum;
				bnum = "";
				while (inln[c] != ',')
				{
					bnum = bnum + inln[c];
					c++;
				}
				c++;
				y = bnum;
				bnum = "";
				while (inln[c] != ')')
				{
					bnum = bnum + inln[c];
					c++;
				}
				c++;
				z = bnum;
				bnum = "";

				outln = "<" + x + "," + y + "," + z + ",0,0,0,>TRUE";
				outfile << outln << endl;

				cout << "|| " << inln << ";\n";
				cout << "||===========================|  Translating to  |============================||\n";
				cout << "|| " << outln << "\n";
				cout << "||                                                                           ||\n";

			}
			else
			{
				cout << "||===========================|   Line Ignored   |============================||\n";
				cout << "||                                                                           ||\n";
			}
		}
		getline(infile, inln);
		inln = "";
		l = -2;
		c = 0;
	}
	outln = "<0,0,0,0,0,0,>FALSE";
	outfile << outln;
	system("pause");
	return 0;
}