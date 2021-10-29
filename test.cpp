#include <iostream>
#include<cstring>
using namespace std;
const int MAX_ARRAY_LENGTH=100;
void printArray(const char arr[][MAX_ARRAY_LENGTH+1], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << endl;
   cout << endl;
}

int main(){
    /*
    int x=64;
    int y=2;
    double w=y/x;
    double z=static_cast<double>(y)/x;
    double s=static_cast<double>(y)/static_cast<double>(x);
    cout<<"w= "<<w<<endl;
    cout<<"z= "<<z<<endl;
    cout<<"s= "<<s<<endl;
    cout<<"x= "<<static_cast<char>(x)<<endl;
    
    cout<<"smith\\exam1\\test.txt"<<endl;
    cout<<"smith\"exam1\"text.txt"<<endl;
    //cout<<"smith"\exam1"\text.txt";     error
    cout<<"smith\exam1\test.txt"<<endl;
    
    int x=-1;
    if (((x < 100) && (x < 1)) && (x < 0)){
        cout<<"True"<<endl;
    }
    return 0;
    
    int a,b;
    a=b=0;
    b=a++;
    cout<<a<<" "<<b<<endl;

    int c,d;
    c=d=0;
    c++;
    d=c;
    cout<<c<<" "<<d<<endl;

    int e,f;
    e=f=0;
    f=++e;
    cout<<e<<" "<<f<<endl;
    
    int x,y,z;
    cout<<"Please enter 3 integers: "<<endl;
    cin>>x>>y>>z;
    cout<<"x,y,z= "<<x<<"\t"<<y<<"\t"<<z<<"\t"<<endl;
    
    int score;
    cout<<"Please input your score: "<<endl;
    cin>>score;
    char grade;
    grade=(score>=85)? 'A' :((score>=60) ? 'B' : 'C');    //if then else expression using () ? :
    cout<<grade<<endl;
    
    int number,number_original;
    int factorial=1;
    cout<<"Please enter a number:"<<endl;
    cin>>number;
    number_original=number;
    while(number>0){
        factorial*=number;
        number--;
    }
    cout<<"The factorial of "<<number_original<<" is "<<factorial<<endl;
    
    int x, max_number;
    cout<<"Please enter a number: "<<endl;
    cin>>x;
    max_number=x;
    cout<<"Please enter the next number: "<<endl;
    while(cin>>x){
        if(x>max_number){
            max_number=x;

        }
        cout<<"Enter the next number: "<<endl;
    }
    cout<<"The maximum of the numbers is "<<max_number<<endl;
    
    int x;
    for(int x=0; x<5; x++){  //the value of x is a random number;
        cout<<x<<"\t";
    }
    cout<<endl;
    cout<<x<<endl;
    
    for(int y=0; y<5; y++){         //error
        cout<<y<<"\t";
    }
    cout<<endl;
    cout<<y;
    
    int y=0;
    for(int y=0; y<5; y++){         //y is still 0
        cout<<y<<"\t";
    }
    cout<<endl;
    cout<<y<<endl;

    int z=0;
    for(z=0 ;z<5 ; z++){
        cout<<z<<"\t";              //z is 5

    }
    cout<<endl;
    cout<<z;
    */
/*
    int j=0;
    while (j < 3) {
        cout << "Enter iteration " << j << endl;
        if (j == 1) {
            break;
        }
        cout << "Leave iteration " << j << endl;
        j++; 
    }

    int k=0 ;
    while (k < 3) {
        cout << "Enter iteration " << k << endl;
        if (k == 1){ 
            continue ;
        }
        cout << "Leave iteration " << k << endl;
        k++; 
    }

    for (int j = 1; j <= 10; j++)
    {
        cout << "j = " << j << endl;    // 123910
        if (j == 3) 
        {
            j = 8;
            continue;
        }
    }
    for (int j = 1; j <= 10; j++)
    {
        cout << "j = " << j << endl;       //123
        if (j == 3) 
        {
            j = 8;
            break;
        }
    }

    
    int sum=0;
    int x;
    while(cin>>x){

        sum+=x;
    }
    cout<<"The sum is "<<sum<<endl;

    int j=0;
    while(j<10){
        cout<<"Hello again"<<endl;
        j++;
    }

    char grade;
    int mark;
    cout<<"Please enter your score: "<<endl;        //switch
    cin>>mark;
    switch(mark/10){
        case 10:
        case 9:
            grade = 'A';break;
        case 8: case 7: case 6:
            grade = 'B';break;
        case 5: case 4: case 3: case 2:
            grade ='C'; break;
        case 1:
            grade = 'D';break;
        default:
            grade ='F';break;
    }
    cout<<"Your grade is "<<grade<<endl;

    enum Premier_League{LIVERPOOL,MANCITY,MANUNITED,CHELSEA,ARSENAL,HOTDOG};
    cout<<ARSENAL<<endl;

    bool ascending;
    ascending=false;
    if(ascending){
        cout<<"nb"<<endl;
    }
    if(!ascending){
        cout<<"laji"<<endl;
    }
*/  
    int array_size;
    cout<<"Task 2: sort a cstring array" << endl;
    cout << "Input the array size less than " << MAX_ARRAY_LENGTH << endl;
    cin >> array_size;
    if (cin.fail()){
        cout << "The input is invalid. Please make sure you enter a number between 1 and "<< MAX_ARRAY_LENGTH << endl;
        return 0;
    } 
    cout << "Input the array content " << endl;
    char arr2[MAX_ARRAY_LENGTH+1][MAX_ARRAY_LENGTH+1];
    cin.get();
    for (int i = 0; i < array_size; i++){
        cin.getline(arr2[i], MAX_ARRAY_LENGTH+1, '\n');       
    }
    cout<<endl;
    cout<<"The arr2 is :"<<endl;
    printArray(arr2,array_size);
    char arr3[MAX_ARRAY_LENGTH+1][MAX_ARRAY_LENGTH+1];
    for(int i=0; i<MAX_ARRAY_LENGTH+1; i++){
        strcpy(arr3[i],arr2[i]);
    }
    cout<<"The arr3 is :"<<endl;
    printArray(arr3,array_size);
    for(int j=0; j<array_size-1; j++){
         for(int k=0; k<array_size-1-j;k++){
            if(strcmp(arr2[k],arr2[k+1])<0){
                for(int u=0;u<MAX_ARRAY_LENGTH; u++){
                    char temp;
                    temp=arr2[k][u];
                    arr2[k][u]=arr2[k+1][u];
                    arr2[k+1][u]=temp;
                }
            }
         }
    }
    printArray(arr2,array_size);
    return 0; 
}