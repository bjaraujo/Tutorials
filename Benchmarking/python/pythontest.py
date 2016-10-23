
import time
import math

start_time = time.time();

nbCols = 10000;
nbRows = 10000;

mat = [[0 for x in range(nbCols)] for y in range(nbRows)] 

def getValue(i, j):

	if (i > j):
		return (i + j) * math.sqrt(i) * math.sqrt(j) * math.sqrt((i * j) / 3.03) / 3.03;
	elif (i < j):
		return (i + j) * math.sqrt(i) * (math.sqrt(j) + math.sqrt((i * j)) / 3.33) / 3.33;
	else:
		return 3.33;

for i in range(nbCols):
    for j in range(nbCols):
        mat[i][j] = i / (j + 1) * getValue(i, j) * getValue(2 * i, 3 * j);

    
elapsed_time=time.time() - start_time;
