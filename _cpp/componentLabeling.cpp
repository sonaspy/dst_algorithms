// image component labeling

#include <iostream>
#include "make2dArray.h"
#include "arrayQueue.h"
#include "position.h"

using namespace std;

// global variables
int **pixel;
int size;      // number of rows and columns in the image

// functions
void welcome()
{// Not yet implemented.
}

void inputImage()
{// Input the image.
   std::cout << "Enter image size" << std::endl;
   std::cin >> size;

   // create and input the pixel array
   make2dArray(pixel, size + 2, size + 2);
   std::cout << "Enter the pixel array in row-major order" << std::endl;
   for (int i = 1; i <= size; i++)
      for (int j = 1; j <= size; j++)
          std::cin >> pixel[i][j];
}

void labelComponents()
{// Label the components.

   // initialize offsets
   position offset[4];
   offset[0].row = 0; offset[0].col = 1;   // right
   offset[1].row = 1; offset[1].col = 0;   // down
   offset[2].row = 0; offset[2].col = -1;  // left
   offset[3].row = -1; offset[3].col = 0;  // up
   
   // initialize wall of 0 pixels
   for (int i = 0; i <= size + 1; i++)
   {
      pixel[0][i] = pixel[size + 1][i] = 0; // bottom and top
      pixel[i][0] = pixel[i][size + 1] = 0; // left and right
   }

   int numOfNbrs = 4; // neighbors of a pixel position

   // scan all pixels labeling components
   arrayQueue<position> q;
   position here, nbr;
   int id = 1;  // component id
   for (int r = 1; r <= size; r++)      // row r of image
      for (int c = 1; c <= size; c++)   // column c of image
        if (pixel[r][c] == 1)
        {// new component
           pixel[r][c] = ++id; // get next id
           here.row = r;
           here.col = c;

           while (true)
           {// find rest of component
              for (int i = 0; i < numOfNbrs; i++)
              {// check all neighbors of here
                 nbr.row = here.row + offset[i].row;
                 nbr.col = here.col + offset[i].col;
                 if (pixel[nbr.row][nbr.col] == 1)
                 {// pixel is part of current component
                    pixel[nbr.row][nbr.col] = id;
                    q.push(nbr);
                 }
              }

              // any unexplored pixels in component?
              if (q.empty()) break;
              here = q.front(); // a component pixel
              q.pop();
           }

        } // end of if, for c, and for r
}

void outputImage()
{// Output labeled image.

   std::cout << "The labeled image is" << std::endl;
   for (int i = 1; i <= size; i++)
   {
      for (int j = 1; j <= size; j++)
         std::cout << pixel[i][j] << "  ";
      std::cout << std::endl;
   }
}

void main()
{
   welcome();
   inputImage();
   labelComponents();
   outputImage();
}
