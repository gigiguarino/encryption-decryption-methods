//
//  matrixMul.cpp
//  Created by Gabrielle Guarino on 11/22/15.

#include <iostream>
#include <math.h>
using namespace std;

struct matrix
{
   float topLeft;
   float topRight;
   float bottomLeft;
   float bottomRight;
};

matrix multiplyMatrices(matrix m1, matrix m2)
{
   matrix returnMatrix;
   
   returnMatrix.topLeft = (m1.topLeft * m2.topLeft) + (m1.bottomLeft * m2.topRight);
   returnMatrix.topRight = (m1.topRight * m2.topLeft) + (m1.bottomRight * m2.topRight);
   returnMatrix.bottomLeft = (m1.topLeft * m2.topRight) + (m1.bottomLeft * m2.bottomRight);
   returnMatrix.bottomRight = (m1.topRight * m2.bottomLeft) + (m1.bottomRight * m2.bottomRight);
   
   return returnMatrix;
}

int main(void)
{
   matrix start;
   start.topLeft = 0;
   start.topRight = 1;
   start.bottomLeft = 2;
   start.bottomRight = 3;
   
   matrix current;
   current = start;
   int t = 0;
   
   for (int j = 0; j <= 24; j++)
   {
      t = j - 1;
      current = start;
      
      for (int i = 0; i < t; i++)
      {
         current = multiplyMatrices(start, current);
      }
   
      cout << endl << endl;
      cout << j << ": \n";
      cout << "Final matrix: \n";
      cout << fmod(current.topLeft, 5) << endl;
      cout << fmod(current.bottomLeft, 5) << endl;
   }
   
   return 0;
}