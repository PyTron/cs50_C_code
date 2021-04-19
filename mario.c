#include <cs50.h>
#include <stdio.h>

int main(void)
{
int height = get_int("Height: ");
int rows;
    //you can adjust the height allowed for minimums and maximums here.
    //this loop forces the user to put in an appropriate number defined by the program.
    while (height < 1 || height > 8) {
        height = get_int("Height: ");
    }
    //This loop is built to cycle through each row individually
    for (rows = 0; rows < height; rows++) {
    //the loop below cycles through each individual character in the row.
    //The integer columns will start at a maximum, and work it's way backwards, checking each     //indiviual space for specific arguments.  I have no idea why I had to add 1 to make it       //work.  I could have used an incrementing loop as well.
    for (int columns = height * 2 + 1; columns > 0; columns--){
    //This is the opening if statement, it says that a hash is always to be placed to the         //right and left of center.  Honestly this could be taken out and the other two statements     //could take over, but I'm leaving here because it makes it easier for me to see what I       //was doing.
        if (columns == height || columns == height + 2){
            printf("#");
    //This is what the program uses to decide whether it should place a hash on the left.
        } else if (columns >= height - rows && columns < height){
            printf("#");
    //This is what the program uses to decided whether it should place a hash on the right.
        } else if (columns <= height + 2 + rows && columns > height + 2){
            printf("#");
        } else {
            printf(" ");
        }
        
        }
     //This is the closing bracket for columns loop, and the printf below will create a new        //line for the next iteration of the loop.
             printf("\n");
    }
}