
// best fit box packing

#include <iostream>
#include "dBinarySearchTreeWithGE.h"

using namespace std;

void bestFitPack(int *objectSize, int numberOfObjects, int boxCapacity)
{ // Output best-fit packing into boxs of size boxCapacity.
  // objectSize[1:numberOfObjects] are the object sizes.
  int n = numberOfObjects;
  int boxusedID = 0;
  dBinarySearchTreeWithGE<int, int> theTree; // tree of box capacities
  pair<int, int> theBin;
  pair<const int, int> *bestBin;
  // pack objects one by one
  for (int i = 1; i <= n; i++)
  { // pack object i
    // find best box
    bestBin = theTree.findGE(objectSize[i]);
    if (bestBin == NULL)
    { // no box large enough, start a new box
      theBin.first = boxCapacity;
      theBin.second = ++boxusedID;
    }
    else
    { // remove best box from theTree
      theBin = *bestBin;
      theTree.erase(bestBin->first);
    }

    cout << "Pack object " << i << " in box "
         << theBin.second << endl;
    // insert box in tree unless box is full
    theBin.first -= objectSize[i];
    if (theBin.first > 0)
      theTree.insert(theBin);
  }
}

// test program
int main(void)
{
  cout << "Enter number of objects and box capacity" << endl;
  int numberOfObjects, boxCapacity;
  cin >> numberOfObjects >> boxCapacity;
  if (numberOfObjects < 2)
  {
    cout << "Too few objects" << endl;
    exit(1);
  }

  // input the object sizes objectSize[1:numberOfObjects]
  int *objectSize = new int[numberOfObjects + 1];
  for (int i = 1; i <= numberOfObjects; i++)
  {
    cout << "Enter space requirement of object " << i << endl;
    cin >> objectSize[i];
    if (objectSize[i] > boxCapacity)
    {
      cout << "Object too large to fit in a box" << endl;
      exit(1);
    }
  }

  // output the packing
  bestFitPack(objectSize, numberOfObjects, boxCapacity);
}
