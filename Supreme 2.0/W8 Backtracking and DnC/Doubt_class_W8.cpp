#include<bits/stdc++.h>
using namespace std;

void permutation_print(){
    string str = "abc";
    // next_permutation(str.begin(), str.end());
    // cout << str;
    // if we want to print all the permutations of a string
    while(next_permutation(str.begin(), str.end())){
        cout << str << endl;
    }
}

struct employee{
    int age, salary;
    string name;
};

int main(){
    // Lets learn about Dynamic Memory Allocation
    // 1. Allocate int
    int *a = new int;
    // 2. Allocate array
    int *arr = new int[10];
    // 3. Allocate 2D array
    int **arr2D = new int*[10];
    for(int i = 0; i < 10; i++){
        arr2D[i] = new int[10];
    }
    // 4. Deallocate int
    delete a;
    // 5. Deallocate array
    delete[] arr;
    // 6. Deallocate 2D array
    for(int i = 0; i < 10; i++){
        delete[] arr2D[i];
    }
    delete[] arr2D;
    
    // What if we can't use new and delete
    // 1. Allocate int 
    int *b = (int*)malloc(sizeof(int));
    // 2. Allocate array
    int *arr1 = (int*)malloc(10 * sizeof(int));
    // 3. Allocate 2D array
    int **arr2D1 = (int**)malloc(10 * sizeof(int*));
    for(int i = 0; i < 10; i++){
        arr2D1[i] = (int*)malloc(10 * sizeof(int));
    }
    // 4. Deallocate int
    free(b);
    // 5. Deallocate array
    free(arr1);
    // 6. Deallocate 2D array
    for(int i = 0; i < 10; i++){
        free(arr2D1[i]);
    }
    free(arr2D1);

    void *ptr = malloc(4);
    *((int*)ptr) = 10;
    cout << *((int*)ptr) << endl;

    // Lets learn about the structure
    employee *e = new employee;
    e->age = 10;
    e->salary = 10000;
    e->name = "Rahul";
    cout << e->age << " " << e->salary << " " << e->name << endl;
    delete e;
    
    employee *e1 = (employee*) malloc(sizeof(employee));
    e1->age = 10;
    e1->salary = 10000;
    e1->name = "Rahul";
    cout << e1->age << " " << e1->salary << " " << e1->name << endl;
    free(e1);
    cout<< sizeof(employee) << endl;

    // My personal study
    char *str = "These are reserved words in C language are int, float, "
             "if, else, for, while etc. An Identifier is a sequence of"
             "letters and digits, but must start with a letter. "
             "Underscore ( _ ) is treated as a letter. Identifiers are "
             "case sensitive. Identifiers are used to name variables,"
             "functions etc.";
    cout << str << endl;
    return 0;
}