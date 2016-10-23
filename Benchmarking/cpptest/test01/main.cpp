
#include <iostream>
#include <ctime>

const __int32 nbCols = 10000;
const __int32 nbRows = 10000;

static double mat[nbCols][nbRows];

double getValue(const int i, const int j)
{

	if (i > j)
		return (i + j) * sqrt(i) * sqrt(j) * sqrt((i * j) / 3.03) / 3.03;
	else if (i < j)
		return (i + j) * sqrt(i) * (sqrt(j) + sqrt((i * j)) / 3.33) / 3.33;
	else
		return 3.33;

}

void main() {

	clock_t begin = clock();

	for (int i = 0; i < nbCols; ++i)
	{		
		for (int j = 0; j < nbRows; ++j)
		{
			mat[i][j] = i / (j + 1) * getValue(i, j) * getValue(2 * i, 3 * j);
		} 
	}

	double elapsed_secs = double(clock() - begin) / CLOCKS_PER_SEC;

	std::cout << "Elapsed time: " << elapsed_secs << " s" << std::endl;

	system("pause");

}