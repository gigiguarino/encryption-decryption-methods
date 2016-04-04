//
//  substitution_cipher.cpp
//  Created by Gabrielle Guarino on 9/15/15.

#include "s_cipher.h"
#include <iostream>
#include <string>
using namespace std;

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

void print_letter_frequencies(string ciphertext)
{
   int alphabet[26];
   int sum = 0;
   
   for (int i = 0; i <= 25; i++)
   {
      alphabet[i] = 0;
   }
   
   for (int i = 0; i <= int(ciphertext.size()) - 1; i++)
   {
      alphabet[letter_to_num(ciphertext[i])] += 1;
   }
   
   
   for (int i = 0; i <= 25; i++)
   {
      cout << num_to_letter(i) << " appears " << alphabet[i] << " times.\n";
      sum += alphabet[i];
   }
   
   cout << endl;
   cout << sum << endl;
   
   return;
}

void print_options(string ciphertext)
{
   string message = ciphertext;
   
   for (int i = 0; i <= int(ciphertext.size()); i++)
   {
      // 14.5%
      
      if (ciphertext[i] == 'c')
      {
         message[i] = 'e'; // KEEP THIS
      }
      
      // 9.4%
      
      else if (ciphertext[i] == 'g')
      {
         message[i] = 'a'; // KEEP THIS
      }
      
      // 7.5%
      
      else if (ciphertext[i] == 's')
      {
         message[i] = 'o'; // KEEP THIS
      }
      
      // 7.1%
      
      else if (ciphertext[i] == 'k')
      {
         message[i] = 's'; // KEEP
      }
      
      // 5.9%
      
      else if (ciphertext[i] == 'i')
      {
         message[i] = 'd'; // keep
      }
      
      else if (ciphertext[i] == 'y')
      {
         message[i] = 'r'; // KEEP
      }
      
      // 5.5
      
      else if (ciphertext[i] == 'u')
      {
         message[i] = 't'; // keep
      }
      
      // 5.1
      
      else if (ciphertext[i] == 'z')
      {
         message[i] = 'h'; // keep
      }
      
      else if (ciphertext[i] == 'n')
      {
         message[i] = 'l'; // keep
      }
      
      // 4.7
      
      else if (ciphertext[i] == 'e')
      {
         message[i] = 'i';
      }
      
      // 3.9
      
      else if (ciphertext[i] == 'o')
      {
         message[i] = 'n'; // keep
      }
      
      // 3.5
      
      else if (ciphertext[i] == 'f')
      {
         message[i] = 'w'; // given
      }
      
      // 3.1
      
      else if (ciphertext[i] == 'd')
      {
         message[i] = 'b'; // keep
      }
      
      // 2.7
      
      else if (ciphertext[i] == 'x')
      {
         message[i] = 'p';
      }
      
      else if (ciphertext[i] == 'l')
      {
         message[i] = 'y'; // keep
      }
      
      else if (ciphertext[i] == 'j')
      {
         message[i] = 'c'; // keep
      }
      
      // 2.4
      
      else if (ciphertext[i] == 'p')
      {
         message[i] = 'u';
      }
      
      else if (ciphertext[i] == 'a')
      {
         message[i] = 'v'; // keep
      }
      
      // 1.9
      
      else if (ciphertext[i] == 'w')
      {
         message[i] = 'g';
      }
      
      else if (ciphertext[i] == 'm')
      {
         message[i] = 'm'; // keep
      }
      
      else if (ciphertext[i] == 'h')
      {
         message[i] = 'f';
      }
      
      else if (ciphertext[i] == 'q')
      {
         message[i] = 'j';
      }
      
      
      
      
      
      
      else
      {
         message[i] = '0';
      }
   }
   
   cout << message << endl;
}

int main(void)
{
   string ciphertext;
   cout << "ciphertext?:";
   cin >> ciphertext;
   
   print_letter_frequencies(ciphertext);
   return 0;
}