// NECCESSARY HEADER FILES
#include<stdio.h>
#include<math.h>
#include<time.h>

// DEFINING MAXIMUM BOARD SIZE
int board[20];

// VARIABLE TO STORE THE NUMBER OF CONFIGURATIONS POSSIBLE
int count;

// GLOBAL DEFINED TO JUST PRINT 1ST CONFIGURATION
int configuration_print=1;
 
// FUNCTION DECLARATION : 
void n_queen(int row,int n); 

int main(){
    
    // BOARD SIZE : MAXIMUM UPTO 20
    int n;
    
    //DEFINING A CLOCK_T VARIABLE
    clock_t tick; 
    
    printf("*******  N-QUEENS PROBLEM : USING BACKTRACKING  *******\n\n");
    // GET INPUT
    printf("ENTER NUMBER OF QUEENS:");
    scanf("%d",&n); 
    
    // START THE TIMER
    tick=clock(); 
    
    // CALL THE FUNCTION
    n_queen(1,n);
    
    // STOP THE TIMER
    tick=clock()-tick;
    
    /*
        1. CLOCK TICKS : UNITS OF TIME OF A CONTANT BUT SYSTEM-SPECIFIC LENGTH, AS THOSE RETURNED BY FUNCTION CLOCK.
        2. CLOCKS_PER_SEC : THIS MACRO EXPANDS TO AN EXPRESSION REPRESENTING THE NUMBER OF CLOCK TICKS PER SECOND.
           
        DIVIDE 1 BY 2 TO GET TIME TAKEN IN SECONDS!!
    */
    
    // PRINT THE SOLUTION:
    printf("\n\nTIME TAKEN BY PROGRAM IS : %f SECONDS \nNUMBER OF COMBINATIONS COUNTED ARE : %d",(float)tick/CLOCKS_PER_SEC,count);

    return 0;
}
 
void print(int n){
    // CONDITION THE CHECK IF ANY PRINT IS LEFT OF NOT
    
        
    if(configuration_print != 0){
        printf("CONFIGURATION OF THE BOARD %d IS : \n",configuration_print);
        for(int i = 1; i <= n; i++)
            printf("%d ", board[i]);
            
        printf("\n\n");
        configuration_print--;
    }
}
 

// FUNCTION TO CHECK CONFLICTS : 
int place(int row,int column){
    //int i;
    for(int i=1;i<=row-1;++i){
        // COLUMN AND DIAGONAL CONFLICT CHECKING : 
        if(board[i]==column)
            return 0;
        else if(abs(board[i]-column)==abs(i-row))
            return 0;
    }
    
     return 1; //no conflicts
}
 
 
// FUNCTION TO CHECK THE PROPER POSITIONING OF THE QUEEN

void n_queen(int row,int n){
    
    int column;
    for(column=1;column<=n;++column){
        
        // CHECK FOR CONFLICTS AT THIS COLUMN NUMBER  
        if(place(row,column)){
            // NO CONFLICTS
            // THUS WE CAN PLACE THE QUEEN IN THIS COLUMN
            board[row]=column;
        
            // IF LAST ROW REACHED : DEAD END
            if(row==n){ 
                // EVERY DEAD END MEANS THAT A BOARD CONFIGUARTION IS FOUND
                // THUS THE COUNT VARIABLE IS INCREMENTED
                count++;               
                // PRINT THE BOARD CONFIGURATION
                print(n); 
            }
            else{
                // IF NO DEAD END THEN CHECK FOR NEXT ROW
                n_queen(row+1,n);
            }
        }
    }
}
