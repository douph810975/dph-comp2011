/*
 * COMP2011 (Fall 2021) Programming Assignment 1
 *
 * Student name: DOU Peihao
 * Student ID: 20760151
 * Student email: pdou@connect.ust.hk
 *
 */

#include <iostream>
#include <limits>
using namespace std;

// Global Constants
// You cannot modify these global constants
// You cannot use your own global variables
const int MAX_ARR_LEN = 16;
const int MAX_ROTATIONS = 1024;
// End of Global Constants

// Helper Functions
// Declare additional helper functions below when necessary
// int myHelperFunction(int argc, char *argv[])

// End of Helper Functions

// Tasks
// Please write your code under the TODO tag
// You cannot change the function declarations

// Task 1
int rotate(int arr[], int arrLen, int k)
{
    // Task 1 TODO
    if (k<0 || k>(arrLen-1)){
        cout<<"Error: Index k is out of range."<<endl;
        return -1;
    }
    else
    {
        int arr_susb[MAX_ARR_LEN];
        for(int l=0; l<MAX_ARR_LEN-1; l++){
            arr_susb[l]=arr[l];
        }
        if(k%2==1){
            for(int i=0; i<=(k-1)/2;i++){
                arr[i]=arr[k-i];
            }
            for(int j=(k+1)/2; j<=k; j++){
                arr[j]=arr_susb[k-j];
            }
        }
        if(k%2==0){
            for(int h=0;h<=(k/2)-1;h++){
                arr[h]=arr[k-h];
            }
            for(int u=(k/2)+1;u<=k;u++){
                arr[u]=arr_susb[k-u];
            }
        }
        return 0;
    }
    
    // End of Task 1 TODO
}

//Task 2
int swapAndRecord(int arr[], int arrLen, int indexA, int indexB, int rotations[], int &rotationLen)
{
    // Task 2 TODO
    int L,R;
    if(indexA<0 || indexA>(arrLen-1)){
        cout<<"Error: Index out of range."<<endl;
        return -1;
    }
    else if(indexB<0 || indexB>(arrLen-1)){
        cout<<"Error: Index out of range."<<endl;
        return -1;
    }
    else
    {   
        if(indexA<=indexB){
            L=indexA;
            R=indexB;
            if(L==0&&R>=2){
                rotate(arr,arrLen,R);
                rotate(arr,arrLen,R-1);       
                rotate(arr,arrLen,R-2); 
                rotate(arr,arrLen,R-1);
            }
            else if(L==0&&R==1){
                rotate(arr,arrLen,1);
            }
            else if(L==0&&R==0){
                rotate(arr,arrLen,0);
            }
            else if(L==R){
                rotate(arr,arrLen,L-1);
                rotate(arr,arrLen,L);           
                rotate(arr,arrLen,R);
                rotate(arr,arrLen,R-1);
            }
            else if(R-L-1==0){
                rotate(arr,arrLen,L-1);
                rotate(arr,arrLen,L);           
                rotate(arr,arrLen,R);           
                rotate(arr,arrLen,R-L-1);       
                rotate(arr,arrLen,R-1);
        
            }
            else if(R-L>=2){
                rotate(arr,arrLen,L-1);
                rotate(arr,arrLen,L);           
                rotate(arr,arrLen,R);           
                rotate(arr,arrLen,R-L-1);       
                rotate(arr,arrLen,R-L-2);
                rotate(arr,arrLen,R-1);
            }    
        }   
        else if(indexA>indexB){
            L=indexB;
            R=indexA;
            if(L==0&&R>=2){
                rotate(arr,arrLen,R);
                rotate(arr,arrLen,R-1);       
                rotate(arr,arrLen,R-2); 
                rotate(arr,arrLen,R-1);
            }
            else if(L==0&&R==1){
                rotate(arr,arrLen,1);
            }
            else if(L==0&&R==0){
                rotate(arr,arrLen,0);
            }
            else if(L==R){
                rotate(arr,arrLen,L-1);
                rotate(arr,arrLen,L);           
                rotate(arr,arrLen,R);
                rotate(arr,arrLen,R-1);
            }
            else if(R-L-1==0){
                rotate(arr,arrLen,L-1);
                rotate(arr,arrLen,L);           
                rotate(arr,arrLen,R);           
                rotate(arr,arrLen,R-L-1);       
                rotate(arr,arrLen,R-1);
            }
            else if(R-L>=2){
                rotate(arr,arrLen,L-1);
                rotate(arr,arrLen,L);           
                rotate(arr,arrLen,R);           
                rotate(arr,arrLen,R-L-1);       
                rotate(arr,arrLen,R-L-2);
                rotate(arr,arrLen,R-1);
            }
        }
        int pre_rotations[6]={L-1,L,R,R-L-1,R-L-2,R-1};
        int number_of_zero=0;
        for(int i=0;i<6;i++){
            if (pre_rotations[i]<=0){
                number_of_zero+=1;
            }    
        }    
        rotationLen=6-number_of_zero;
        int j=0;
        for(int k=0;k<6;k++){
            if (pre_rotations[k]>0){
                rotations[j]=pre_rotations[k];
                j++;
            }
        }  
        
        return 0;
    
    }
    // End of Task 2 TODO
}

//Task 3
void sortAndRecord(int arr[], int arrLen, int rotations[], int &rotationLen)
{
    // Task 3 TODO
    rotationLen=0;
    int rotations_sort[MAX_ROTATIONS];
    int rotationLen_sort;
    int i,j;
    for(i=0; i<arrLen-1; i++){
        for(j=0; j<arrLen-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapAndRecord(arr,arrLen,j,j+1,rotations_sort,rotationLen_sort);
                for(int k=rotationLen;k<rotationLen+rotationLen_sort;k++){
                    rotations[k]=rotations_sort[k-rotationLen];
                }
                rotationLen=rotationLen+rotationLen_sort;
            }
        }
    }
    
    // End of Task 3 TODO
}

//Task 4
int transformAndRecord(int src[], int tgt[], int arrLen, int rotations[], int &rotationLen)
{
    // Task 4 TODO
    rotationLen=0;
    int rotations_tran[MAX_ROTATIONS];
    int rotationLen_tran;
    for(int i=0;i<arrLen;i++){
        for(int j=0;j<arrLen;j++){
            if(src[i]!=tgt[i]&&src[i]==tgt[j]){
                swapAndRecord(src,arrLen,i,j,rotations_tran,rotationLen_tran);
                for(int k=rotationLen;k<rotationLen+rotationLen_tran;k++){
                    rotations[k]=rotations_tran[k-rotationLen];
                }
                rotationLen=rotationLen+rotationLen_tran;
            }
        }
    }
    bool same=true;
    for(int i=0;i<arrLen;i++){
        if(src[i]!=tgt[i]){
            same=false;
        }
    }
    if(!same){
        return -1;
    }
    else
        return 0;
    // End of Task 4 TODO
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED

int init(int arr[], int arrLen)
{
    char buffer;
    cout << "? Please enter one digit at a time and press return:" << endl;
    for (int i = 0; i < arrLen; i++)
    {
        cin >> buffer;
        if (buffer > '9' || buffer < '0')
        {
            cout << "Error: Illegal digit input." << endl;
            return -1;
        }
        else
        {
            arr[i] = (int)buffer - 48;
        }
    }
    return 0;
}

void printArr(int arr[], int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i];
        if (i < arrLen - 1)
        {
            cout << ',';
        }
    }
    cout << endl;
}

void runInit(int arr[], int &arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Initializing" << endl;
    cout << endl;

    int initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter the length of your array:" << endl;
        cin >> arrLen;
        if (arrLen < 1)
        {
            cout << "! Error: Length should be larger than 0." << endl;
            continue;
        }
        else if (arrLen > MAX_ARR_LEN)
        {
            cout << "Error: arrLen of should be less than or equal to " << MAX_ARR_LEN << endl;
            continue;
        }
        cout << "? Enter " << arrLen << " elements of your array." << endl;
        initResult = init(arr, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! Initialization succeeded!" << endl;
    cout << "! Printing the array:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runPrint(int arr[], int arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Printing the array" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runRotate(int arr[], int arrLen)
{
    int k, output;
    cout << "##################################################" << endl;
    cout << "# Rotating the array:" << endl;
    cout << "? Enter the index k:";
    cin >> k;
    output = rotate(arr, arrLen, k);
    if (output < 0)
    {
        cout << "! Error: Rotation failed." << endl;
    }
    else
    {
        cout << "! Rotated." << endl;
        cout << "! Array after rotation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
    }
}

void runSwap(int arr[], int arrLen)
{
    int indexA, indexB, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Swapping elements:" << endl;
    cout << "? Enter the 1st index:";
    cin >> indexA;
    cout << "? Enter the 2nd index:";
    cin >> indexB;
    output = swapAndRecord(arr, arrLen, indexA, indexB, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Swap failed." << endl;
    }
    else
    {
        cout << "! Swapped." << endl;
        cout << "! Array after swap:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runSort(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Sorting the array:" << endl;
    sortAndRecord(arr, arrLen, rotations, rotationLen);
    cout << "! Sorted." << endl;
    cout << "! Array after sorting:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
    cout << "! Rotations:" << endl;
    cout << endl;
    printArr(rotations, rotationLen);
    cout << endl;
}

void runTransform(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Transforming src array to the tgt:" << endl;
    int tgt[MAX_ARR_LEN], initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter " << arrLen << " elements of the tgt array." << endl;
        initResult = init(tgt, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! The target array:" << endl;
    cout << endl;
    printArr(tgt, arrLen);
    cout << endl;
    output = transformAndRecord(arr, tgt, arrLen, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Cannot transform array to target." << endl;
    }
    else
    {
        cout << "! Transformed." << endl;
        cout << "! Array after transformation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runOption()
{
    int arrLen = 0;
    bool is_initialized = false;
    int src[MAX_ARR_LEN];
    int tgt[MAX_ARR_LEN];
    int option;
    cout << "===========================================" << endl;
    cout << "= Welcome to COMP2011 PA1 1D Rubik's Cube =" << endl;
    cout << "===========================================" << endl;

    while (true)
    {
        if (!is_initialized)
        {
            runInit(src, arrLen);
            is_initialized = true;
        }
        else
        {
            cout << "##################################################" << endl;
            cout << "# Main Menu" << endl;
            cout << endl;
            cout << "1 Initialize" << endl;
            cout << "2 Print" << endl;
            cout << "3 Rotate" << endl;
            cout << "4 Swap" << endl;
            cout << "5 Sort" << endl;
            cout << "6 Transform" << endl;
            cout << "0 Exit" << endl;
            cout << endl;
            cout << "? Please enter an option (0-7): ";
            cin >> option;
            switch (option)
            {
            case 0:
                cout << "! Bye Bye." << endl;
                return;
            case 1:
                runInit(src, arrLen);
                break;
            case 2:
                runPrint(src, arrLen);
                break;
            case 3:
                runRotate(src, arrLen);
                break;
            case 4:
                runSwap(src, arrLen);
                break;
            case 5:
                runSort(src, arrLen);
                break;
            case 6:
                runTransform(src, arrLen);
                break;
            default:
                cout << "Illegal Choice, please try again." << endl;
                break;
            }
            cout << "! Returning to main menu." << endl;
        }
    }
}

int main()
{
    runOption();
    return 0;
}