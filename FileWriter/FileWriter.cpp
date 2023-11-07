#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream in;
	ofstream out;
	string line;
	int lineCount = 1;

	// Checking for proper input
	if (argc != 3)
	{
		cerr << "Usage: " << argv[0] << "<input file> <output file>" << endl;
		return EXIT_FAILURE;
	}

	// Opening the input file for reading
	in.open(argv[1]);
	if (!in.is_open())
	{
		cerr << "Unable to open file " << argv[1] << " for reading" << endl;
		return EXIT_FAILURE;
	}

	// Openiing the output file for writing
	out.open(argv[2]);
	if (!out.is_open())
	{
		cerr << "Unable to open file " << argv[2] << " for writing" << endl;
		return EXIT_FAILURE;
	}

	// Reading from infile and writing to outfile
	string inputTextBuffer;
	string outputTextBuffer;
	while (getline(in, inputTextBuffer))
	{
		outputTextBuffer = inputTextBuffer;
		out << "\n" << outputTextBuffer;
	}

	// Closing Files
	in.close();
	out.close();

	return 0;
}
