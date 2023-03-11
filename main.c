/* 
~ Husen Abugosh (حسين ابوغوش) 
~ 1210338
~ lab section: 5L / lecture section: 3
 */


// libraries that included in this project :
#include <stdio.h>
#include <stdlib.h>


// constant that will be  the size of 2 arrays
#define MAXSIZE 100


// project prtotype function:
void displayMainMenu();
void addStudent(int ids[], double avgs[], int *size);
void removeStudent(int ids[], double avgs[], int *size);
void searchForStudent(int ids[], double avgs[], int  size);
void uploadDataFile(int ids[], double avgs[], int  *size );
void updateDataFile(int ids[], double avgs[], int  size);
void printStudents(int ids[], double avgs[], int  size);

// extra prototype function:
int linear_Search(int a[], int size, int key);


// global varibales:
    int ids[MAXSIZE];
    double avgs[MAXSIZE];
    int n;


int main() { 

printf("\n\awelcome to my Student Mangement System:\n\n");
uploadDataFile(ids,avgs,&n);


return 0;
}


void displayMainMenu() {

int choise; 

printf("\aplease Select an operation (1-4):\n");
printf("1- Add a Student:\n");
printf("2- Remove a Student:\n");
printf("3- Search for a Student:\n");
printf("4- Print Student List:\n");
printf("5- Exit System:\n");
printf("\n");
scanf("%d", &choise);


switch (choise) {

 case 1: addStudent(ids,avgs,&n);
 break;

 case 2: removeStudent(ids,avgs,&n);
 break;

 case 3: searchForStudent(ids,avgs,n);
 break;

 case 4: printStudents(ids,avgs,n);
 break;

 case 5: updateDataFile(ids,avgs,n);
 break;

default: 
printf("No Such operation! Please try again.\n\n");
displayMainMenu();
 break;
}


}

//  addStudent: used to add a new id number and his average:
void addStudent(int ids[], double avgs[], int *size) {


if(*size < MAXSIZE){                                           // <---- will check if the maxsize(100) > number of student list(n). 

 int idNum;                                                  // <----  used to save the id that added from the user inside it.
 int isSimilar = 0;                                         // <----  bool varibale to check if there any similar value to idNum.

printf("\aPlease enter id number for Student: \n");
scanf("%d", &idNum);

for(int i=0; i<((*size)-1); i++){                            // <----   linear_Search method to check if is there any similar value to idNum.

 if(ids[i] == idNum){
   printf("the id that you are trying to added is similar to another id (please try again!)\n\n");
   isSimilar = 1;
  }

}

if (isSimilar == 0){                                // <---- if there is no similar value save it in the aaray and take the averge for it.

  ids[*size-1] = idNum;
  printf("\aPlease enter avg of Student: \n");
  scanf("%lf", &avgs[*size-1]);
  (*size)++ ;

  printf("Student with id: %d has been added. \n\n", idNum);

}

// ascendig sort by Bubble sort (it should be with Shift method!!)  !!!!!!!!!!!!!
for(int i = 0; i<(*size)-1; i++){

 for(int j=0; j< ((*size)-2); j++){

     if(ids[j]>ids[j+1]){
    
     int temp = ids[j];
     ids[j] = ids[j+1];
     ids[j+1] = temp;

     int temp2 = avgs[j];
     avgs[j] = avgs[j+1];
     avgs[j+1] = temp2;

     }
  }
}

}else{
// if the maxsize(100) is *LESS* than  THE number of student list(n)  IT will show the error meesage below:  
printf("\n the file is Full try to remove ids or upradge to our new version! \n\n");
}
      displayMainMenu();

}





void removeStudent(int ids[], double avgs[], int *size){
      
if(*size > 0){

 int idNum;                                                  // <----  used to save the id that added from the user inside it.
 int isSimilar = 0;                                         // <----  bool varibale to check if there any similar value to idNum.

printf("\aPlease enter id number for Student to remove: \n");
scanf("%d", &idNum);

for(int i=0; i<MAXSIZE; i++){                            // <----   linear_Search method to check if is there any similar value to idNum.

 if(ids[i] == idNum){

      isSimilar = 1;

   if (i < (MAXSIZE -1)){                          // <---- remove shift method.
  
       for (int j = i; j < (MAXSIZE-1); j++)
       {
           ids[j] = ids[j+1];
           avgs[j] = avgs[j+1];
       }
   }
   (*size)--;
   printf("Student with id: %d has been removed. \n\n",idNum);
  }

}

if (isSimilar == 0){                                // <---- if there is no similar value save it in the aaray and take the averge for it.
 printf("Student with %d id does not exist.\n\n", idNum);
}

 }else{
// if the file is empty show that message error:
printf("\nthere is no ids student to remove \n");

}
      displayMainMenu();

}




void searchForStudent(int ids[], double avgs[], int  size){ 


 if(size > 0){

 int idNum;                                                  // <----  used to save the id that added from the user inside it.
 int isSimilar = 0;                                         // <----  bool varibale to check if there any similar value to idNum.

printf("\aPlease enter id number for Student to search for : \n");
scanf("%d", &idNum);

for(int i=0; i<MAXSIZE; i++){                            // <----   linear_Search method to check if is there any similar value to idNum.

 if(ids[i] == idNum){
      isSimilar = 1;
      printf("id# = %d \t\t avg = %.2f\n\n",ids[i],avgs[i]);  //<----- will print the id and his avg.
   }
   size--;
  }

 if (isSimilar == 0){                                // <---- if there is no similar value save it in the aaray and take the averge for it.
 printf("Student with %d id does not exist (you can add one).\n\n", idNum);
}

} else{
// if the file is empty show that message error:
printf("\nthere is no ids student to search for \n");
}

      displayMainMenu();

}



void uploadDataFile (int ids[], double avgs[], int  *size ){
  
    printf("Uploading data file ... \n");

     FILE *input;                                 // <--- will declare a file pointer variable.
     input = fopen("students.txt","r");          // <--- will call a function that open the file and put it in the reading mode
     int idInput = 0;                           //
     double avgInput = 0.0;                    //  <--- varibales
     int lines = 0;                           

    /* so here there will be reading all the data(id and the avrage) in the file & save it in there varibales then will save the avg data in avg[] and the ids data in id[]
    until the end of file :
    */
    while (fscanf(input, "%d %lf", &idInput, &avgInput) != EOF)
    {
        ids[lines] = idInput;
        avgs[lines] = avgInput;
        lines++;
    }

    *size = lines + 1;
    printf("Data File uploaded \n \n");
    displayMainMenu();

}

void updateDataFile(int ids[], double avgs[], int size){

    printf("\nUpdating data file ... \n");

    FILE *output;                                 // <--- will declare a file pointer variable.
    output = fopen("students.txt","w");          // <--- will call a function that open the file and put it in the wirting mode.
    int idOutput = 0;                           //
    double avgOutput = 0.0;                    //  <--- varibales
    int i = 0; 

    while (i < (size-1))
    {
        idOutput = ids[i];
        avgOutput = avgs[i];
        fprintf(output, "%d %.2lf \n", idOutput, avgOutput);      // <---- will print the ids[] values and avgs[] values in the  (students.txt) file
        i++;
    }
    fclose(output);
    
    printf("Data File updated. \n\n");
    printf("Thank you for using My Student Management System. GoodBye :)\n\n");
   
}



void printStudents(int ids[], double avgs[], int  size) {
      
// it will print all the ids and avgs values 
    for(int i = 0; i<(size-1); i++){   
       printf("id# = %d \t\t avg = %.2f\n",ids[i],avgs[i]);
    }
    printf("\n");
    displayMainMenu();
}