//
//  affine_cipher.cpp
//  Created by Gabrielle Guarino on 9/17/15.

#include "affine_cipher.h"
#include <string>
#include <iostream>
using namespace std;

// A can be values:
// 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25
// Inverse of A:
// 1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25

// (ciphertext[i] - b)*(A inverse) = message[i]

int letter_to_num(char letter)
{
   switch(letter)
   {
      case ('a'):
         return 0;
         break;
         
      case ('b'):
         return 1;
         break;
         
      case ('c'):
         return 2;
         break;
         
      case ('d'):
         return 3;
         break;
         
      case ('e'):
         return 4;
         break;
         
      case ('f'):
         return 5;
         break;
         
      case ('g'):
         return 6;
         break;
         
      case ('h'):
         return 7;
         break;
         
      case ('i'):
         return 8;
         break;
         
      case ('j'):
         return 9;
         break;
         
      case ('k'):
         return 10;
         break;
         
      case ('l'):
         return 11;
         break;
      case ('m'):
         return 12;
         break;
         
      case ('n'):
         return 13;
         break;
         
      case ('o'):
         return 14;
         break;
         
      case ('p'):
         return 15;
         break;
         
      case ('q'):
         return 16;
         break;
         
      case ('r'):
         return 17;
         break;
         
      case ('s'):
         return 18;
         break;
         
      case ('t'):
         return 19;
         break;
         
      case ('u'):
         return 20;
         break;
         
      case ('v'):
         return 21;
         break;
         
      case ('w'):
         return 22;
         break;
         
      case ('x'):
         return 23;
         break;
         
      case ('y'):
         return 24;
         break;
         
      case ('z'):
         return 25;
         break;
         
      default:
         // error
         return 0;
         break;
   }
}

char num_to_letter(int num)
{
   switch(num)
   {
      case (0):
         return 'a';
         break;
         
      case (1):
         return 'b';
         break;
         
      case (2):
         return 'c';
         break;
         
      case (3):
         return 'd';
         break;
         
      case (4):
         return 'e';
         break;
         
      case (5):
         return 'f';
         break;
         
      case (6):
         return 'g';
         break;
         
      case (7):
         return 'h';
         break;
         
      case (8):
         return 'i';
         break;
         
      case (9):
         return 'j';
         break;
         
      case (10):
         return 'k';
         break;
         
      case (11):
         return 'l';
         break;
         
      case (12):
         return 'm';
         break;
         
      case (13):
         return 'n';
         break;
         
      case (14):
         return 'o';
         break;
         
      case (15):
         return 'p';
         break;
         
      case (16):
         return 'q';
         break;
         
      case (17):
         return 'r';
         break;
         
      case (18):
         return 's';
         break;
         
      case (19):
         return 't';
         break;
         
      case (20):
         return 'u';
         break;
         
      case (21):
         return 'v';
         break;
         
      case (22):
         return 'w';
         break;
         
      case (23):
         return 'x';
         break;
         
      case (24):
         return 'y';
         break;
         
      case (25):
         return 'z';
         break;
         
      default:
         // do something
         return '0';
         break;
   }
}


void affine_options(string ciphertext)
{
   int message[ciphertext.size()];
   int current = 0;
   int a_ = 0;
   
   for (int a = 0; a < 12; a++)
   {
      switch(a)
      {
         case(0):
            a_ = 1;
            break;
         case(1):
            a_ = 9;
            break;
         case(2):
            a_ = 21;
            break;
         case(3):
            a_ = 15;
            break;
         case(4):
            a_ = 3;
            break;
         case(5):
            a_ = 19;
            break;
         case(6):
            a_ = 7;
            break;
         case(7):
            a_ = 23;
            break;
         case(8):
            a_ = 11;
            break;
         case(9):
            a_ = 5;
            break;
         case(10):
            a_ = 17;
            break;
         case(11):
            a_ = 25;
            break;
         default:
            // shouldn't get here
            break;
      }
      
      for (int b = 0; b < 26; b++)
      {
         for (int i = 0; i < int(ciphertext.size()); i++)
         {
            //cout << ciphertext[i] << endl;
            current = letter_to_num(ciphertext[i]);
            message[i] = ((current - b)*(a_)) % 26;
            
            if (message[i] < 0)
            {
               message[i] = message[i] + 26;
            }
            
            //cout << message[i] << endl;
            
            cout << num_to_letter(message[i]);
         }
         
         cout << endl;
         cout << "a_ = " << a_ << endl;
         cout << "b = " << b << endl;
         cout << endl;
         cout << endl;
      }
   }
}


int main(void)
{
   string ciphertext;
   cout << "ciphertext?: ";
   cin >> ciphertext;
   
   affine_options(ciphertext);
   
   
   return 0;
}


// possible: a_ = 21, b = 8


