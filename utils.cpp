#include <iostream> /* COMP2011 Lab 7: utils.cpp */
#include <cstring>
#include "my_include.h"


/* Task One */
void bubbleSort(double arr[], int n, bool ascending)
{
   if(ascending){
      for(int i=0; i<n-1 ;i++){
         for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
               double temp;
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;

            }
         }
      }
   }
   if(! ascending){
      for(int i=0; i<n-1 ;i++){
         for(int j=0; j<n-1-i; j++){
            if(arr[j]<arr[j+1]){
               double temp;
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;

            }
         }
      }
   }
}


/* Task Two */
void bubbleSort(char arr[][MAX_ARRAY_LENGTH+1], int n, bool ascending)
{  
   if(ascending){
      for(int j=0; j<n-1; j++){
         for(int k=0; k<n-1-j;k++){
            if(strcmp(arr[k],arr[k+1])>0){
               for(int u=0;u<MAX_ARRAY_LENGTH; u++){
                  char temp;
                  temp=arr[k][u];
                  arr[k][u]=arr[k+1][u];
                  arr[k+1][u]=temp;
               }
            }
         }
      }
   }

   if(!ascending){
      for(int j=0; j<n-1; j++){
         for(int k=0; k<n-1-j;k++){
            if(strcmp(arr[k],arr[k+1])<0){
               for(int u=0;u<MAX_ARRAY_LENGTH; u++){
                  char temp;
                  temp=arr[k][u];
                  arr[k][u]=arr[k+1][u];
                  arr[k+1][u]=temp;
               }
            }
         }
      }
   }
}



/* Given Functions */
void printArray(const double arr[], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
   cout << endl;
}

void printArray(const char arr[][MAX_ARRAY_LENGTH+1], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << endl;
   cout << endl;
}

