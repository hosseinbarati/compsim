#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string getdata();
void GRID(string,int*,int*,int*,int*);
double DICON(string,int*);

void main()
{
	string data= getdata();

	int i = 0;
	int nx = 0;
	int ny = 0;
	int nz = 0;
	GRID(data,&i, &nx, &ny, &nz);

	cout << nx;
	cout << "\n";
	cout << ny;
	cout << "\n";
	cout << nz;
	cout << "\n";
	cout << i;


}

string getdata()
{
	string a;
	string STRING;
	ifstream infile;
	infile.open("C:\\Users\\Ramin Moghadasi\\Desktop\\Data1.txt");
	while (!infile.eof()) // To get you all the lines.
	{
		getline(infile, STRING); // Saves the line in STRING.
		a = a + STRING; // Prints our STRING.
	}
	infile.close();

	return a;
}

void GRID(string data,int* i,int* nx,int* ny,int* nz)
{
	string t = "";
	*i = data.find(" ")+1;

nx:
	for (; *i < 20; (*i)++)
	{
		if (data[*i] == ' ')
		{
			*nx = stod(t);
			(*i)++;
			t = "";
			goto ny;
		}
		t = t + data[*i];

	}


ny:

	for (; *i < 20; (*i)++)
	{
		if (data[*i] == ' ')
		{
			*ny = stod(t);
			(*i)++;
			t = "";
			goto nz;
		}
		t = t + data[*i];

	}
nz:

	for (; *i < 20; (*i)++)
	{
		if (data[*i] == 'D')
		{
			*nz = stod(t);
			t = "";
			break;
		}
		t = t + data[*i];

	}






}

double DICON(string data,int *i)
{
	int o = data.find("DI CON");
	o = o + 6;
	string t;

	for ( *i = o; *i < o+10; (*i)++)
	{
		if (data[*i] == 'D')
			break;

		t = t + data[*i];
	}

	double f = stod(t);
	return f;
}