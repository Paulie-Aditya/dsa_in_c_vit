#include <stdio.h>
#include <stdlib.h>

struct person{
    int age;
    char name[30];
};

int main(){
    struct person *ptr;
    int i,n;

    printf("Enter the number of Persons: ");
    scanf("%d",&n);

    //allocating memory for n numbers of struct person
    ptr = (struct person*)malloc(n*sizeof(struct person));
    
    for(int i = 0; i<n;i++){
        printf("Enter first name and age respectively: ");
        scanf("%s %d",(ptr+i)->name,&(ptr+i)->age);
        printf("\n");
    }

    printf("Displaying Information: \n");

    for(i=0; i<n;i++){
        printf("Name of Person %d: %s\n",i+1,(ptr+i)->name);
        printf("Age of Person %d: %d\n",i+1,(ptr+i)->age);
        printf("/n");
    }

}
