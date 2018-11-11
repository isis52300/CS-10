#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

   int trunkHeight;
   int trunkWidth;
   int levels;
   int runs;
   int count;

   cout << "Enter trunk height: ";
   cin >> trunkHeight;
   cout << endl;

   cout << "Enter trunk width: ";
   cin >> trunkWidth;
   cout << endl;

   while (trunkWidth % 2 == 0) {                         //Makes sure that the trunk width is odd
      cout << "Please enter an odd number for the width: ";
      cin >> trunkWidth;
      cout << endl;
   }

   cout << "Enter leaves width: ";
   cin >> levels;
   cout << endl;
   cout << endl;

   runs = levels;
   count = levels;

   // Draws the leaves
   for (int k = 0; k < levels / 2 + 1; ++k) {            //Makes the correct number of levels
      for (int g = runs / 2; g > 0; --g) {               //Makes the correct number of spaces
         cout << " ";
      }
      for (int h = 0; h < count - levels + 1; ++h) {      //Makes the first set of leaves
         cout << "*";
      }
      for (int s = 0; s < count - levels; ++s) {          //Makes the second set of leaves
         cout << "*";
      }
      cout << endl;
      runs -= 2;
      ++count;
   }


   //Draws the trunk
   for (int j = 0; j < trunkHeight; ++j) {               //Makes the trunk the rigth height
      for (int a = 0; a < (levels - trunkWidth) / 2; ++a ) {  //Centers the trunk around the tree leaves
         cout << " ";
      }
      for (int i = 0; i < trunkWidth; ++i) {             //Draws the correct size trunk
         cout << "*";
      }
      cout << endl;
   }



    return 0;
}
