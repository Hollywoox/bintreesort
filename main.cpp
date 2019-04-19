#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;

void swap(int *a, int *b){
  int k = *a;
  *a = *b;
  *b = k;
}

int getMin(vector<int> &array){
  return array[0];
}

void siftUp(int x, vector<int> &array){
  if(x != 0 && array[x] < array[(x - 1) / 2]){
    swap(&array[x], &array[(x - 1) / 2]);
    siftUp((x - 1) / 2, array);
  }
}

void siftDown(int x, vector<int> &array){
  if(x * 2 + 1 < array.size()){
    int y = x * 2 + 1;
    if(y + 1 < array.size() && array[y + 1] < array[y]){
      y += 1;
    }
    if(array[x] > array[y]){
      swap(&array[x], &array[y]);
      siftDown(y, array);
    }
  }
  else{
    return;
  }
}

void extract(int x, vector<int> &array){
  array.push_back(x);
  siftUp(array.size() - 1, array);
} 

void deleteMin(vector<int> &array){
  swap(&array[0], &array[array.size() - 1]);
  array.pop_back();
  siftDown(0, array);
}

void sort(vector<int> &array, vector<int> &answer, vector<int> &heap){
  for(int i = 0; i < array.size(); i++){
    extract(array[i], heap);
  }
  for(int i = 0; i < array.size(); i++){
    answer.push_back(getMin(heap));
    deleteMin(heap);
  }
}

int main(){
    ifstream file1("input.txt");
    ofstream file2("output.txt");
    int n;
    file1 >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++){
      file1 >> array[i];
    }
    vector<int> answer;
    vector<int> heap;
    sort(array, answer, heap);
    for(int  i = 0; i < answer.size(); i++){
      file2 << answer[i] << " ";
    }
    return 0;
}
