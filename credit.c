#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
//Request a number
    long ccnum = get_long("Number: ");
//Check the length, store in variable
    int len = floor(1.0 + log10(llabs(ccnum)));
//Push to an array
    int ccArray[len];
    for (int i = 0; i < len; i++){
        if (i < len){
        ccArray[i] = ccnum%10;
        ccnum = ccnum / 10;
        }
        else {
            ccArray[i] = 69;
        }
        }
    //The commented out code below is for testing purposes only, prints length, and then prints the contents of each array.
//        printf("%d\n", len);
//    for (int j = 0; j < len; j++){
//        printf("%d Holds the Number %d\n", j, ccArray[j]);
//    }
 //Declare a set of variables for a method that will use Luhn's algorithm to check for validity.
    int luhn_one = 0;
    int luhn_sec = 0;
    int luhn_why = 0;
    int luhn_fin = 0;
    for (int i = 0; i < len; i ++){
        //Because the array stores the number backwards, the first value of the array is the last value in the input number
        //if the number of i can be divided by two with 0 remainder, it is an even number, and we can assume that the number in the array is not second to last digit or every other digit thereof.
        if (i%2 == 0){
            //The print line below is for testing, it will show the array value, the method, and the calculation to arrive at the total.
            //printf("The number %d", luhn_sec);
            luhn_sec = luhn_sec + ccArray[i];
            //The print line below is for testing
            //printf(" + %d = %d\n", ccArray[i], luhn_sec);
        }
        //Because we can safely say that all the even numbered arrays hold the entries for one method, we can say that the odd numbered entries hold the values we need for the other method.
        else {
            //The print line below is for testing, it will show the array value, the method, and the calculation to arrive at the total.
          //  printf("If the Number is %d, then the number %d is equal to %d", ccArray[i], luhn_one, luhn_one);
            luhn_why = ccArray[i] * 2;
            //If the digit we get is greater than 10 we will break it into two parts, the second part of this if/then statement may not be necessary since int can only return whole numbers.
            if (luhn_why > 10) {
            luhn_one = luhn_one + (luhn_why / 10) + (luhn_why%10);
            }
            //If the digit we get is less than 10 we can leave it alone. 
            else {
            luhn_one = luhn_one + luhn_why;
            }
            //The print line below is for testing, it is part the other test code in this block.
            //printf(" + %d + %d\n", (luhn_why / 10), (luhn_why%10));
        }
    }
    //Now we combine the two numbers for a total, this number is what we will use to check if the card number is valid.
    luhn_fin = luhn_one + luhn_sec;
//The print line below is for testing, it will print each of the luhn variables values for debugging purposes.
//    printf("The Multiples of Underlined Products %d\nThe Addition of non Multiples %d\nFinal Number %d\n", luhn_one, luhn_sec, luhn_fin);
    //Create a variable with a value that we can use to check the card type.
int cardCheck;
    if (ccArray[(len - 1)] == 4){
        cardCheck = 4;
    }
    else {
        cardCheck = (ccArray[(len - 1)] * 10) + (ccArray[(len - 2)]);
    }
    //The print line below is for testing, it will print the value this block of code creates.
//    printf("%d\n", cardCheck);

    //Final Stage.  The following block will check to make sure luhns algorithm is in place, if the card is valid, it will return a card type, otherwise it will print invalid.
    //First an If statement to check Luhn's algorthim.
    if (luhn_fin%10 == 0){
        //A Switch statement to check for card types
        switch (cardCheck){
            case 34:
            case 37:
                printf("AMEX\n");
                    break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            case 4:
                printf("VISA\n");
                break;
                default :
                printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }
}