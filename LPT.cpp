/////////////////////////////////
// Name: Alejandro Pena Caicedo//
// UF id: 3712-3113            //
// Gator id: alejandropenacai  //
// Discussion Section: 1085    //
////////////////////////////////


#include "LPT.h"



Heap::Heap(int size) {
            data = new machine[size];
            
            heapSize = size;
            arraySize = size;
}  

Heap::~Heap() {
            delete[] data;
}
 
int Heap::getLeftNodeIndex(int nodeIndex) {
            return 2 * nodeIndex + 1;
}

int Heap::getLeftNodeValue(int nodeIndex){//gotta change

  return data[2*nodeIndex+1].total;

}

 
int Heap::getRightNodeIndex(int nodeIndex) {
            return 2 * nodeIndex + 2;
}

int Heap::getRightNodeValue(int nodeIndex){//gotta change

  return data[2*nodeIndex + 2].total;

}

 
int Heap::getParentIndex(int nodeIndex) {
            return ((nodeIndex - 1) / 2);
}
  
int Heap::top() {//change maybe
            if (empty())
                  throw string("Heap is empty");
            else
                  return data[0].total;
}
 

int Heap::size(){

  return heapSize ;
}


bool Heap::empty() {
            return (heapSize == 0);
}
 
 
void Heap::push(int value) { //limit inserting more elements than heapsize***
     // if (heapSize == arraySize)
           // throw string("Heap's underlying storage is overflow");
     // else {
            //++heapSize;
            //data[heapSize - 1]. = value;
           
            //siftUp(heapSize-1);

            int tmp = data[0].machsize; //all data[0]
            data[0].myArray[tmp] = value;
            data[0].total += value;
            data[0].machsize++;
            //cout<<data[0].total <<endl;
           //cout<<data[0].myArray[0]<<endl;
           //cout<<data[0].myArray[1]<<endl;
            
            //cout<<data[1].total<<endl;
            //cout<<data[1].myArray[0]<<endl;


            organize(0);
     // }


}

void Heap::quickprint(){

for(int i = 0; i<heapSize; i++){

  int temp = data[i].machsize;

  cout<<"Total Processing Time:  " << data[i].total << "  ; Processing Jobs:  " ;

  for(int j = 0; j<temp; j++){
  
  cout<< " "<<data[i].myArray[j] << " ";
  
  }


}

  
}

void Heap::organize(int nodeIndex) {//edit
      int leftChildIndex, rightChildIndex, minIndex;
      machine tmp;

      leftChildIndex = getLeftNodeIndex(nodeIndex);
      rightChildIndex = getRightNodeIndex(nodeIndex);
      if (rightChildIndex >= heapSize) {
            if (leftChildIndex >= heapSize)
                  return;
            else
                  minIndex = leftChildIndex;
      } else {
            if (data[leftChildIndex].total <= data[rightChildIndex].total)
                  minIndex = leftChildIndex;
            else
                  minIndex = rightChildIndex;
      }
      if (data[nodeIndex].total > data[minIndex].total) {
           // tmp = data[minIndex];
           // data[minIndex] = data[nodeIndex];
           // data[nodeIndex] = tmp;
            tmp = data[nodeIndex];
            data[nodeIndex] = data[minIndex];
            data[minIndex] = tmp;

            
            organize(minIndex);
      }
} 


void Heap::pop() {//edit
      if (empty())
            throw string("Heap is empty");
      else {
            data[0] = data[heapSize - 1];
            heapSize--;
            if (heapSize > 0)
                  organize(0);
      }
}









lefttree::lefttree(int value)					//lefttree class constructor
	{
		root=NULL;
    
    //vector<machine> vectorOfMach;
    for(int i = 0; i<value ; i++){

    machine myMachine;
    insert(myMachine);
     }

  }

lefttree::~lefttree(){
    
    while(root != NULL){
      
      pop();

    }
    
  }
	
	void lefttree::insert(machine elem)				//Inserting into lefttree tree
	{
	         
	        treenode* node=new treenode;
	        node->element=elem;
	        node->left=NULL;
	        node->right=NULL;
		      node->s=1;
		      root=meld(root,node);
	}

	void lefttree::push(int value)				//Inserting into lefttree tree
	{
	   machine temp = root->element;
     pop();
     temp.myArray[temp.machsize] = value;
     temp.total += value;
     temp.machsize++;
     insert(temp);


	}


       
	lefttree::treenode* lefttree::meld(treenode* nodeA, treenode* nodeB)		//Merging lefttree tree nodes
	{
                  if((nodeA==NULL)&&(nodeB!=NULL))
                                 return nodeB;
                  else if((nodeB==NULL)&&(nodeA!=NULL))
				return nodeA;
                  else if((nodeB==NULL)&&(nodeA==NULL))
				return nodeA;
		  else if(nodeA->element.total > nodeB->element.total)
                  {
          		treenode* temp=nodeA;
          		nodeA=nodeB;
          		nodeB=temp;
                  }
                  nodeA->right=meld(nodeA->right,nodeB);
		  if((nodeA->left==NULL)&&(nodeA->right!=NULL))
		  {
			nodeA->left=nodeA->right;
			nodeA->right=NULL;
			nodeA->s=1;
		  }
		  else
		  {
			if(nodeA->left->s < nodeA->right->s)
			{
				treenode* temp=nodeA->left;
          			nodeA->left=nodeA->right;
          			nodeA->right=temp;
			}
			nodeA->s=nodeA->right->s+1;
		  }
		  return nodeA;
	}
  
  

	void lefttree::pop()							//Deleting the minimum element (root) function for lefttree tree
	{
		if(root!=NULL)
			  root=meld(root->right,root->left);
	}

void lefttree::print_inorder()
{
  inorder(root);
}

void lefttree::inorder(treenode* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<" "<< "Total Time:  "<<p->element.total<<" " <<"; Processing Times:";
        for(int i = 0; i<p->element.machsize; i++){
        cout<< "  "<< p->element.myArray[i] << "  ";
        }
        if(p->right) inorder(p->right);
    }
    else return;
}

int lefttree::top(){

return root->element.total;

}

int lefttree::size(){

return root->element.machsize;

}

bool lefttree::empty(){

return (root == NULL);

} 










int main(){


  vector<int> myvec;
  int numJob;
  int numMach;
  int temp;

  cout<<"Enter number of job(s):"<<endl;
  cin>>numJob;

  cout<<"Enter number of machine(s):" <<endl;
  cin>>numMach;

  cout<< "Enter processing time(s):"<<endl;

  for(int i = 0; i<numJob; i++){
    
    cin>>temp;
    myvec.push_back(temp);

  } //put into header class

  sort(myvec.begin(), myvec.end());
  reverse(myvec.begin(),myvec.end());


  lefttree* myTree = new lefttree(numMach);
  Heap* myheap= new Heap(numMach); 

  clock_t start_tree, end_tree, tree_total, start_heap, end_heap, heap_total;


  

start_heap = clock();

for(int i = 0; i<numJob; i++){ //time before and after

myheap->push(myvec[i]);

}

end_heap = clock();

heap_total = end_heap - start_heap;

cout<< endl << "Time elapsed for heap in clocks: " << end_heap <<endl;




myheap->quickprint();

cout<<'\n' <<endl;






  
  
  
start_tree = clock();

for(int i = 0; i<numJob; i++){ //time before and after

myTree->push(myvec[i]);

}

end_tree = clock();

tree_total = end_tree - start_tree;

cout<< endl << "Time elapsed for tree in clocks: " << end_tree <<endl;


myTree->print_inorder();

cout << '\n' <<endl;












return 0;
}

