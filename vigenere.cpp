//
//  vigenere.cpp
//  Created by Gabrielle Guarino on 9/21/15.


#include "vigenere.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// find the length of the keyword
// viding the message into that many simple
// substitution ciphers

// how to find length of keyword:
// measuring the distance between repeated bigrams


struct bigram
{
   string gram;
   int num_appeared;
};

struct trigram
{
   string gram;
   int num_appeared;
};

char num_to_letter(int num)
{
   switch(num)
   {
      case(0):
         return 'a';
         break;
         
      case(1):
         return 'b';
         break;
         
      case(2):
         return 'c';
         break;
         
      case(3):
         return 'd';
         break;
         
      case(4):
         return 'e';
         break;
         
      case(5):
         return 'f';
         break;
         
      case(6):
         return 'g';
         break;
         
      case(7):
         return 'h';
         break;
         
      case(8):
         return 'i';
         break;
         
      case(9):
         return 'j';
         break;
         
      case(10):
         return 'k';
         break;
         
      case(11):
         return 'l';
         break;
         
      case(12):
         return 'm';
         break;
         
      case(13):
         return 'n';
         break;
         
      case(14):
         return 'o';
         break;
         
      case(15):
         return 'p';
         break;
         
      case(16):
         return 'q';
         break;
         
      case(17):
         return 'r';
         break;
         
      case(18):
         return 's';
         break;
         
      case(19):
         return 't';
         break;
         
      case(20):
         return 'u';
         break;
         
      case(21):
         return 'v';
         break;
         
      case(22):
         return 'w';
         break;
         
      case(23):
         return 'x';
         break;
         
      case(24):
         return 'y';
         break;
         
      case(25):
         return 'z';
         break;
         
      default:
         return '0';
         break;
   }
}

void count_bigrams(string cipher)
{
   vector<bigram> vec;
   vector<trigram> vec2;
   bigram current;
   current.gram[0] = 'a';
   current.gram[1] = 'a';
   trigram current2;
   
   
   for (int i = 0; i < 26; i++)
   {
      for (int j = 0; j < 26; j++)
      {
         current.gram[0] = num_to_letter(i);
         current.gram[1] = num_to_letter(j);
         current.num_appeared = 0;
         
         for (int k = 0; k < int(cipher.size()) - 1; k++)
         {
            if (cipher[k] == current.gram[0] &&
                cipher[k+1] == current.gram[1])
            {
               current.num_appeared++;
            }
         }
         
         vec.push_back(current);
      }
   }
   
   for (int i = 0; i < 26; i++)
   {
      for (int j = 0; j < 26; j++)
      {
         for (int k = 0; k < 26; k++)
         {
            current2.gram[0] = num_to_letter(i);
            current2.gram[1] = num_to_letter(j);
            current2.gram[2] = num_to_letter(k);
            current2.num_appeared = 0;
            
            for (int z = 0; z < int(cipher.size()) - 2; z++)
            {
               if (cipher[z] == current2.gram[0] &&
                   cipher[z+1] == current2.gram[1] &&
                   cipher[z+2] == current2.gram[2])
               {
                  current2.num_appeared++;
               }
            }
            
            vec2.push_back(current2);
         }
      }
   }
   
   //cout << cipher.size() << endl;
   
   
   for (int i = 0; i < int(vec.size()); i++)
   {
      if (vec[i].num_appeared > 2)
      {
         cout << vec[i].gram[0] << vec[i].gram[1] << endl;
         cout << vec[i].num_appeared << endl;
         cout << endl;
      }
   }
   
   for (int i = 0; i < int(vec2.size()); i++)
   {
      if (vec2[i].num_appeared > 2)
      {
         cout << vec2[i].gram[0] << vec2[i].gram[1] << vec2[i].gram[2] << endl;
         cout << vec2[i].num_appeared << endl;
         cout << endl;
      }
   }
   
   return;
}

void distance_between(string cipher)
{
   // distance between HJV because that is the most common trigram
   int length = 1;
   
   for (int i = 0; i < int(cipher.size()); i++)
   {
      if (cipher[i] == 'h' && cipher[i+1] == 'j' && cipher[i+2] == 'v')
      {
         if (length != 0)
         {
            cout << length << endl;
            cout << endl;
            length = 0;
         }
      }
      
      length++;
   }
}

void print_out_columns(string cipher)
{
   vector<char> vec1;
   vector<char> vec2;
   vector<char> vec3;
   vector<char> vec4;
   vector<char> vec5;
   vector<char> vec6;
   
   int num = 1;
   
   for (int k = 0; k < int(cipher.size()); k++)
   {
      switch(num)
      {
         case (1):
            vec1.push_back(cipher[k]);
            num++;
            break;
         case (2):
            vec2.push_back(cipher[k]);
            num++;
            break;
         case(3):
            vec3.push_back(cipher[k]);
            num++;
            break;
         case(4):
            vec4.push_back(cipher[k]);
            num++;
            break;
         case(5):
            vec5.push_back(cipher[k]);
            num++;
            break;
         case(6):
            vec6.push_back(cipher[k]);
            num = 0;
            num++;
            break;
         default:
            break;
      }
   }
   
   for (int i = 0; i < int(vec6.size()); i++)
   {
      cout << vec6[i];
   }
   
   cout << endl;
   
   return;
}

void print_options(void)
{
   for (int a = 0; a < 3; a++)
   {
      for (int b = 0; b < 4; b++)
      {
         for (int c = 0; c < 6; c++)
         {
            for (int d = 0; d < 2; d++)
            {
               for (int e = 0; e < 7; e++)
               {
                  for (int f = 0; f < 3; f++)
                  {
                     switch(a)
                     {
                        case(0):
                           cout << "m";
                           break;
                        case(1):
                           cout << "f";
                           break;
                        case(2):
                           cout << "c";
                           break;
                        default:
                           break;
                     }
                  
                     switch(b)
                     {
                        case(0):
                           cout << "n";
                           break;
                        case(1):
                           cout << "b";
                           break;
                        case(2):
                           cout << "g";
                           break;
                        case(3):
                           cout << "r";
                           break;
                        default:
                           break;
                     }
                  
                     switch(c)
                     {
                        case(0):
                           cout << "h";
                           break;
                        case(1):
                           cout << "z";
                           break;
                        case(2):
                           cout << "n";
                           break;
                        case(3):
                           cout << "b";
                           break;
                        case(4):
                           cout << "y";
                           break;
                        case(5):
                           cout << "u";
                        default:
                           break;
                     }
                  
                     switch(d)
                     {
                        case(0):
                           cout << "p";
                           break;
                        case(1):
                           cout << "z";
                           break;
                        default:
                           break;
                     }
                  
                     switch(e)
                     {
                        case(0):
                           cout << "d";
                           break;
                        case(1):
                           cout << "g";
                           break;
                        case(2):
                           cout << "w";
                           break;
                        case(3):
                           cout << "x";
                           break;
                        case(4):
                           cout << "e";
                           break;
                        case(5):
                           cout << "l";
                           break;
                        case(6):
                           cout << "t";
                           break;
                        default:
                           break;
                     }
                  
                     switch(f)
                     {
                        case(0):
                           cout << "y" << endl << endl;
                           break;
                        case(1):
                           cout << "o" << endl << endl;
                           break;
                        case(2):
                           cout << "d" << endl << endl;
                           break;
                        default:
                           break;
                     }
                  }
               }
            }
         }
      }
   }
}




int main(void)
{
   string ciphertext;
   cout << "ciphertext?: ";
   cin >> ciphertext;
   
   print_options();
   
   

   
   
   return 0;
}
