//Dennis Hahn CS1510 1B Homework #1
//Tube Transport System 

#include <iostream>
using namespace std;
int rowCount(int), columnCount(int), total(int, int);
int **p;
int width, height, minX, minY, T;

int main()
{
	int gridMaps;
	cin >> gridMaps;
	
	
	for (T = 0; T < gridMaps; T++) //For loop to redo the process for multiple grid maps. 
	{
		cin >> width >> height;
		
		p = new int*[width];

		//Creating 2D portion of Array
		for (int k = 0; k < width; k++) 
		{
			p[k] = new int[height];
		}

			//Inputing values into the array.
		for (int k = 0; k < height; k++)  
		{
			for (int z = 0; z < width; z++)
			{
				cin >> p[z][k]; 
			}

		}

		
		//Searching best path.
		int x = total(0, 0) + 1; //Starting value for comparison.
		for (int k = 0; k < height; k++) //change k < height to k < width 
		{
			for (int z = 0; z < width; z++) // change z < width to z < height 
			{
				if (total(z, k) < x)
				{
					x = total(z, k);
					minX = z;
					minY = k;
				}
			}		
		}
		cout << "#" << T << ": (" << minX << ", " << minY << ") " << x << endl;
	   

		for (int k = 0; k < width; k++) //Cleaning up array when done.
		{
			delete [] p[k];
		}
		
		p = NULL;
	}
	
	return 0;
}

int rowCount (int y) //Adds the contents of the specified row. 
{
	int count = 0;
	
	for (int k = 0; k < width; k++)
	{
		count = count + p[k][y];
	}
	return count;
}

int columnCount(int x) //Adds the contents of the specified column.
{
	int count  = 0;
	
	for (int k = 0; k < height; k++)
	{
		count = count + p[x][k];
	}
	return count;
}

int total(int x, int y)
{
	return rowCount(y) + columnCount(x) - p[x][y];
}
