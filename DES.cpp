//
//  DES.cpp
//  Created by Gabrielle Guarino on 9/27/15.


#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


static vector<int> PC_1 = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

static vector<int> PC_2 = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

static vector<int> IP_matrix = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

static vector<int> e_bit = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};

static vector<int> P = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};

static vector<int> IP_inverse = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};

static vector<vector<int> > S1 = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7}, {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8}, {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0}, {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};

static vector<vector<int> > S2 = {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10}, {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5}, {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15}, {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};

static vector<vector<int> > S3 = {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8}, {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1}, {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7}, {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}};

static vector<vector<int> > S4 = {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15}, {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9}, {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4}, {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}};

static vector<vector<int> > S5 = {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9}, {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6}, {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14}, {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}};

static vector<vector<int> > S6 = {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11}, {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8}, {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6}, {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}};

static vector<vector<int> > S7 = {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1}, {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6}, {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2}, {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}};

static vector<vector<int> > S8 = {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7}, {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2}, {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8}, {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

string left_shift(string s)
{
   char first_char;
   first_char = s[0];
   
   for (int i = 0; i < int(s.size()) - 1; i++)
   {
      s[i] = s[i+1];
   }
   
   s[s.size() - 1] = first_char;
   return s;
}

string apply_permutation(string s, vector<int> permutation)
{
   string new_string;
   new_string.resize(permutation.size());
   
   for (int i = 0; i < int(permutation.size()); i++)
   {
      new_string[i] = s[permutation[i] - 1];
   }
   
   return new_string;
}

string XOR(string string1, string string2)
{
   string new_string;
   new_string.resize(string1.size());
   
   for (int i = 0; i < string1.size(); i++)
   {
      if (string1[i] == '0' && string2[i] == '0')
      {
         new_string[i] = '0';
      }
      
      else if (string1[i] == '0' && string2[i] == '1')
      {
         new_string[i] = '1';
      }
      
      else if (string1[i] == '1' && string2[i] == '0')
      {
         new_string[i] = '1';
      }
      
      else if (string1[i] == '1' && string2[i] == '1')
      {
         new_string[i] = '0';
      }
   }
   
   return new_string;
}

string binary_string(int num)
{
   switch(num)
   {
      case(0):
         return "0000";
         break;
         
      case(1):
         return "0001";
         break;
         
      case(2):
         return "0010";
         break;
         
      case(3):
         return "0011";
         break;
         
      case(4):
         return "0100";
         break;
      
      case(5):
         return "0101";
         break;
         
      case(6):
         return "0110";
         break;
         
      case(7):
         return "0111";
         break;
         
      case(8):
         return "1000";
         break;
         
      case(9):
         return "1001";
         break;
         
      case(10):
         return "1010";
         break;
         
      case(11):
         return "1011";
         break;
         
      case(12):
         return "1100";
         break;
      
      case(13):
         return "1101";
         break;
         
      case(14):
         return "1110";
         break;
         
      case(15):
         return "1111";
         break;
         
      default:
         break;
   }
   
   return "0000";
}

int binary_4(string s)
{
   if (s == "0000")
   {
      return 0;
   }
   
   else if (s == "0001")
   {
      return 1;
   }
   
   else if (s == "0010")
   {
      return 2;
   }
   
   else if (s == "0011")
   {
      return 3;
   }
   
   else if (s == "0100")
   {
      return 4;
   }
   
   else if (s == "0101")
   {
      return 5;
   }
   
   else if (s == "0110")
   {
      return 6;
   }
   
   else if (s == "0111")
   {
      return 7;
   }
   
   else if (s == "1000")
   {
      return 8;
   }
   
   else if (s == "1001")
   {
      return 9;
   }
   
   else if (s == "1010")
   {
      return 10;
   }
   
   else if (s == "1011")
   {
      return 11;
   }
   
   else if (s == "1100")
   {
      return 12;
   }
   
   else if (s == "1101")
   {
      return 13;
   }
   
   else if (s == "1110")
   {
      return 14;
   }
   
   else
   {
      return 15;
   }
}

int binary_2(string s)
{
   if (s == "00")
   {
      return 0;
   }
   
   else if (s == "01")
   {
      return 1;
   }
   
   else if (s == "10")
   {
      return 2;
   }
   
   else
   {
      return 3;
   }
}

string s_box(int box_num, string block)
{
   string s1, s2;
   s1.resize(2);
   s2.resize(4);
   
   if (block[0] == '0')
   {
      s1[0] = '0';
   }
   
   else
   {
      s1[0] = '1';
   }
   
   if (block[5] == '0')
   {
      s1[1] = '0';
   }
   
   else
   {
      s1[1] = '1';
   }
   
   s2 = block.substr(1, 4);
   
   int row, column;
   row = binary_2(s1);
   column = binary_4(s2);
   
   switch(box_num)
   {
      case(1):
         return binary_string(S1[row][column]);
         break;
         
      case(2):
         return binary_string(S2[row][column]);
         break;
         
      case(3):
         return binary_string(S3[row][column]);
         break;
         
      case(4):
         return binary_string(S4[row][column]);
         break;
         
      case(5):
         return binary_string(S5[row][column]);
         break;
         
      case(6):
         return binary_string(S6[row][column]);
         break;
         
      case(7):
         return binary_string(S7[row][column]);
         break;
         
      case(8):
         return binary_string(S8[row][column]);
         break;
      
      default:
         break;
   }
   
   return "0";
}

void DES(string message, string key)
{
   string C0, D0; // left and right halves
   string C1, D1;
   
   key = apply_permutation(key, PC_1);
   
   // GET C0 AND D0
   // the key is split in half -> each half has 28 bits
   C0 = key.substr(0, 28);
   D0 = key.substr(28, 28);
   C1 = left_shift(C0);
   D1 = left_shift(D0);
   
   string key1;
   key1 = apply_permutation(C1 + D1, PC_2);
   
   cout << "K1: " << key1 << endl;
   
   message = apply_permutation(message, IP_matrix);
   string L0, R0, ER0, A;
   
   L0 = message.substr(0, 32);
   R0 = message.substr(32, 32);
   
   cout << "L0: " << L0 << endl;
   cout << "R0: " << R0 << endl;
   
   ER0 = apply_permutation(R0, e_bit);
   cout << "E[R0]: " << ER0 << endl;
   
   // A = ER0 xor K1
   A = XOR(ER0, key1);
   cout << "A: " << A << endl;
   
   string s1, s2, s3, s4, s5, s6, s7, s8;
   s1 = s_box(1, A.substr(0, 6));
   s2 = s_box(2, A.substr(6, 6));
   s3 = s_box(3, A.substr(12, 6));
   s4 = s_box(4, A.substr(18, 6));
   s5 = s_box(5, A.substr(24, 6));
   s6 = s_box(6, A.substr(30, 6));
   s7 = s_box(7, A.substr(36, 6));
   s8 = s_box(8, A.substr(42, 6));
   
   cout << "S1: " << s1 << endl;
   cout << "S2: " << s2 << endl;
   cout << "S3: " << s3 << endl;
   cout << "S4: " << s4 << endl;
   cout << "S5: " << s5 << endl;
   cout << "S6: " << s6 << endl;
   cout << "S7: " << s7 << endl;
   cout << "S8: " << s8 << endl;
   
   string B;
   B = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8;
   cout << "B: " << B << endl;
   
   string PB;
   PB = apply_permutation(B, P);
   cout << "P[B]: " << PB << endl;
   
   string R1;
   R1 = XOR(PB, L0);
   cout << "R1: " << R1 << endl;
   
   string final = R1 + R0;
   final = apply_permutation(final, IP_inverse);
   cout << "final: " << final << endl;
}

int main()
{
   string message, key;
   // message and key are strings of 0's and 1's
   
   cout << "message (in binary)?: ";
   cin >> message;
   
   cout << "key (in binary)?: ";
   cin >> key;
   
   DES(message, key);
   
   return 0;
}
