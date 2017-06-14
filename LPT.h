/////////////////////////////////
// Name: Alejandro Pena Caicedo//
// UF id: 3712-3113            //
// Gator id: alejandropenacai  //
// Discussion Section: 1085    //
////////////////////////////////



#ifndef _LPT_H_
#define _LPT_H_


#include <iostream>
#include <string> 
#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>


using namespace std;

class Heap {
private:

      struct machine{// add a machine size(num of jobs)
      int myArray[100]; //= new int[50];
      int machsize = 0;
      int total = 0; //sum of processing times
      
      };
      machine *data;
      int heapSize;
      int arraySize;

      //require input function declaration
 
      int getLeftNodeIndex(int nodeIndex); 
      
     // int getLeftNodeValue(int nodeIndex); 

      int getRightNodeIndex(int nodeIndex);

     // int getRightNodeValue(int nodeIndex); 
     
      int getParentIndex(int nodeIndex); 
public:
      
      Heap(int size);

      ~Heap();

      int top(); //NEED A SIZE FUNCTION&**HGERHREHGERGERGHRHEWTHERHERHEGEHERHREGERG#$G#$G#$G#$@G@#G#
      
      int size();

      bool empty();  
      
      void push(int value);  

      void organize(int nodeIndex);

      void pop(); //EDIT !!!!

      int getLeftNodeValue(int nodeIndex); 

      int getRightNodeValue(int nodeIndex); 

      void quickprint(); //delete this     RENAME AND ADD FINAL FUNCTIO

};


class lefttree
{
	private :

      struct machine{// add a machine size(num of jobs)
        
        int myArray[100]; //= new int[50];
        int machsize = 0;
        int total = 0; //sum of processing times
      
      };


     struct treenode{ //add machine node for value
      
      int s,level;
      machine element; //machine nodes
      treenode *left;
      treenode *right;
    };

    treenode* root;

	public :
    
	lefttree(int value);	//need destructor!!

  ~lefttree();	

	void insert(machine elem);    

  void push(int value);

	treenode* meld(treenode* nodeA, treenode* nodeB);  

	void pop();

  void print_inorder();

  void inorder(treenode* p); 

  int top(); 

  int size();

  bool empty(); 



};


#endif

