#include <iostream>

using namespace std;

void max_heapify(int index, int *a, int size){
  int max = index;
  do{
    index = max;
    int left = index*3-1;
    int right = left+2;
    int middle = left+1;
    if(left <= size && a[left] > a[max]){
      max = left;
    }
    else if(right <= size && a[right] > a[max]){
      max = right;
    }
    else if(middle <= size && a[middle] > a[max]){
      max = middle;
    }
    if(max != index){
      int temp = a[index];
      a[index] = a[max];
      a[max] = temp;
    }
  }while(max != index);
}

void Heap(int *a, int size){
  int *array = new int[size];
  array[0]=0;
  for(int i = 0; i < size; i++){
    array[i+1] = a[i+1];
  }
  for(int i = size/3; i > 0; i--){
      max_heapify(i,array, size);
  }
  for(int i = 0; i < size; i++){
    cout << array[i] << "  ";
  }
  cout << endl;
}

int main(){
  int a[] = {3,4,1,5,6, 12, 7,2,8, 22};

  Heap(a, 10);

  return 0;
}
