#include "paintRoom.h"

void recPaintRoom( RoomData room, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/ );
/* declare any other helper functions here*/

/* printName
 * input: none
 * output: none
 *
 * Prints name the student who worked on this solution
 */
void printName( )
{
    /* TODO : Fill in your name*/
    printf("\nThis solution was completed by:\n");
    printf("Qustandi Fashho\n");
    printf("N/A\n");
}

/* TODO
 * paintRoom
 * input: the room to process 
 * output: N/A
 *
 * This non-recursive function is called by the driver and it makes the initial call to recursive function recPaintRoom.
 */
void paintRoom( RoomData room ){
    /* Call any other helper functions (a helper function to find the location of 'A' in room may be handy) */
    // left upper hand corner is 0,0
    int startingRow = 0;
    int startingColumn = 0;
    int i;
    int j;
    for(i = 0; i < room.numrows; i++){ // iterate over the rows of the 2d array of the room 
        for(j = 0; j < room.numcols; j++){ // iterate over the columns of the 2d array of the room 
            if (room.roomArray[i][j] == 'A'){
                startingRow = i;
                startingColumn = j;
                printf("Found 'A' at Row: %d, Column: %d\n", startingRow, startingColumn); // remove before submission 

                break;
            }
        }
        // if(startingRow == -1){
        //     break; // getting out of outer for loop if A is found. 
        // }
    
    }
     if (startingRow == -1 || startingColumn == -1){
        printf("Jethro's computer (A) is not in the room.\n"); // A check remove before submission
        return;
    }

    /* Call your recursive function here */
    //recPaintRoom( room, /* initial row value */, /* initial col value */, /* initial value for distanceFromA */  );
    recPaintRoom(room, startingRow, startingColumn, 0);
}

 

/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location being explored, the distance traveled from 'A'
 * output: N/A
 */
void recPaintRoom(RoomData room, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/ ) {
    char currentDistance = room.roomArray[row][col] - 'A';

    // printf("TEST 1 (void recPointRoom)\n"); // should print 
    // Base case: Check if the current location is outside the room boundaries or is an obstacle/wall.
    if (row < 0 || col < 0 || row >= room.numrows || col >= room.numcols || room.roomArray[row][col] == '*') { // basically if not in the room boundaries
        return;
    }
    //printf("TEST 2 (void recPointroom)\n"); 
    
    // Base case: Check if the current location has been visited already AND IF IT HITS A WALL OR OBSTACLE FIRST 
    /////// || A AND SEE WHAT ELSE BECAUASE THIS IS WHERE A BIG PROBLEM IS ~ FIXED but A does not show up
    if ((room.roomArray[row][col] != ' ') && (room.roomArray[row][col] != 'A')) {
        // If it has been visited before, check if the new distance is smaller, and update if necessary.
        //char currentDistance = room.roomArray[row][col] - 'A';
        if (distanceFromA < currentDistance) {
            room.roomArray[row][col] = 'A' + distanceFromA;
            
        }
        return;
    }
    //printf("TEST 3 (void recPointroom)\n");
  
    //printf("TEST 4 (void recPointroom)\n");
    // Mark the current location as visited with the letters 'A' to 'Z'
    // if (distanceFromA <= 25) {
    //     room.roomArray[row][col] = 'A' + distanceFromA;
    //     //printf("%d", distanceFromA);
    // } 
    // /*else if(distanceFromA == 0){
    //     room.roomArray[row][col] = 'A' + distanceFromA ;
    // }*/
    // else {
    //     room.roomArray[row][col] = 'Z'; // If distance is 25 or more, use 'Z' (would only be 26 or higher because dan havbe more than 26 steps which would just keep giving z with each step).
    // }



    // Mark the current location as visited with the letters 'A' to 'Z', except if it's already 'A'.
    if (room.roomArray[row][col] != 'A') {
        if (distanceFromA <= 25) {
        room.roomArray[row][col] = 'A' + distanceFromA;
    } 
        else {
            room.roomArray[row][col] = 'Z'; // If distance is 25 or more, use 'Z'.
    }
}


   // printf("TEST 5 (void recPointroom)\n");
    // Recursive calls to go to the next space.
    recPaintRoom(room, row - 1, col, distanceFromA + 1); // Up
    recPaintRoom(room, row, col + 1, distanceFromA + 1); // Right
    recPaintRoom(room, row + 1, col, distanceFromA + 1); // Down
    recPaintRoom(room, row, col - 1, distanceFromA + 1); // Left
    //printf("TEST 6 (void recursion)\n");

}







