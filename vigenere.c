#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
//first, check to make sure argc is good
if (argc == 2)
{
    //Now check that characters are valid in string
    bool checkVal;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        //Throw an if then condition to check for acceptable values.
        //Declare an integer with the value of whatever character is being cycled.
        int checkMe = argv[1][i];
        //Check valid capital letters
        if (checkMe >= 65 && checkMe <= 90)
        {
            checkVal = true;
        }
        //Now check valid lower case chars
        else if (checkMe >= 97 && checkMe <= 122)
        {
            checkVal = true;
        }
        //if an invalid char is found, we will return false and exit the loop.
        else 
        {
            checkVal = false;
            i = n;
        }
    }
    //if the characters in argv[1] check out, we will proceed with the program.
    if (checkVal == true)
    {
        printf("%s\n", argv[1]);
        //Get a string from the user
        string plainText = get_string("plaintext: ");
        //Create a new character array to store the modified values
        char cryptText[strlen(plainText) + 1];
        //create a for loop that will cycle through each character individually, replacing them using the key.
        for (int i = 0, j = 0, n = strlen(plainText); i <= n; i++, j++)
        {
            int n_2 = strlen(argv[1]);
            int plainInt = plainText[i];
            int argPush = plainInt;
            //Begin code rewerite.  
            //This if else is to check the count of j, and reset.
            if (j >= 0 && j < n_2) 
            {
               int key = argv[1][j];
                //this will check to make sure that it is a character we want to alter.
               if ((argPush >= 65 && argPush <= 90) || (argPush >= 97 && argPush <= 122))
               {
                  //This will execute for uppercase letters.
                    if (isupper(argv[1][j])) 
                    {
                    //we will subtract by 65 to get a 0-25 value
                    key = key - 65;
                    //Create a loop to make sure that the digit does not break out
                    //of the alphabet.
                        for (int k = 0; k < key; k++)
                        {
                            if ((argPush >= 65 && argPush < 90) || (argPush >= 97 && argPush < 122))
                            {
                                argPush = argPush + 1;
                            }
                            else {
                                argPush = argPush - 25;
                            }
                        
                        }
                        //Push new value to corresponding slot in cipher array.
                    cryptText[i] = (char) argPush;
                    }
                else 
                {
                    //if it is lower case we subtract 97 to get a 0-25 value.
                    key = key - 97;
                    //Create a loop to make sure that the digit does not break out
                    //of the alphabet.
                    for (int k = 0; k < key; k++)
                    {
                        if ((argPush >= 65 && argPush < 90) || (argPush >= 97 && argPush < 122))
                        {
                            argPush = argPush + 1;
                        }
                        else 
                        {
                            argPush = argPush - 25;
                        }
                    }
                    //push the new character to corresponding slot of cipher array.
                    cryptText[i] = (char) argPush;
                    }
                }
                //If it is not a character we want to alter, and the string has not ended, we will place the character in the corresponding slot in the output array
               else if (plainText[i] != '\0')
               {
                   cryptText[i] = plainText[i];
                   j--;
               }
                //this will put the necessary \0 at the end of the cryptText array
               else
               {
                   cryptText[i] = '\0';
                       j = n;
                       i = n;
               } 
            }
            //If the value of j is out of range, this will put it back in range and cycle i back.
            else
            {
                j = -1;
                i--;
            }
        }
        //This will print the output of the program.
        printf("%s\n%s\n", cryptText, plainText);
    }
    //If an invalid character is entered, we will throw the user out of the program.
    else {
        printf("Usage: ./vignere keyword\n");
    }
}
    //If argc does not equal the correct number, we will throw the user out of the program.
else 
{
    printf("Usage: ./vigenere keyword\n");
}
}