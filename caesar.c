#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(int argc, string argv[])
{
if (argc == 2){
    //This boolean will check argv to make sure it is a valid number.
    bool verify_me;
        for (int i = 0, n = strlen(argv[1]); i < n; i++){
            if (argv[1][i] - '0' >= 0 && argv[1][i] - '0' <= 9 && argc == 2){
                verify_me = true;
            }
            else{
                i = n;
                verify_me = false;
            }
        }
    //This if statement checks the boolean value: returning true will execute the program.
    if (verify_me == true){
    //Key will end up holding the key value.  X will be used to do a simple conversion of the     argv into an int we can use.
    int key = 0;
    int x = 1;
    //This is the conversion of argv to an integer, using basic math.
    for (int i = strlen(argv[1]) - 1, n = 0; i >= n; i--){
        key = ((argv[1][i] - '0') * x) + key;
            x = x * 10;
    }
    //Now that we have our cipher in int form, we will prompt the user for a phrase.
    string plain_input = get_string("plaintext: ");
    //Now to create a string that will hold the encrypted text.
    char crypt_output[strlen(plain_input) + 1];
    //This for loop holds the code to copy the input array into the output array.
    for (int i = 0, n = strlen(plain_input); i <= n; i++){
        //this if statement will allow us to only capture characters in the alphabet, ignoring         punctuation.  We can add any type of punctuation with an else if in this block.
        if (plain_input[i] >= 65 && plain_input[i] <= 122){
        int plain_int = plain_input[i];
        int final_int = plain_int;
            //The line below is commented out to comply with the pset instruction.  But it can             be used to adjust the key formula.  We could even take user input to add the the               complexity fairly easily.  
            //key = (final_int + key)%26;
            if (plain_int <= 122 && plain_int >= 97){
                //this loop will have the character circle back around if it breaks out of the                 alphabet for lower case characters.
                for (int t = 0; t < key; t++){
                        if (final_int < 122 && final_int >= 97){
                            final_int++;
                        }
                        else {
                            final_int = 97;
                        }
                    }
                }
                //Now we need to make sure upper case can't break out of the alphabet either.
                else if (plain_int <= 90 && plain_int >= 65){
                    for (int y = 0; y < key; y++){
                        if (final_int < 90 && final_int >= 65){
                            final_int++;
                        }
                        else {
                            final_int = 65;
                        }
                    }                
                }
                else {
                    final_int = plain_int;
                }
        //Now well will cast the output to the output array, using number i to assign to the           appropriate block in the array.
        crypt_output[i] = (char) final_int; 
        }
        //This else if will make sure all the non alphabet characters stay untouched.
        else if (plain_input[i] != '\0'){
            crypt_output[i] = plain_input[i];
        }
        //This will put the appropriate ending \0 in the array once the program finishes               executing.
        else{
            crypt_output[i] = '\0';
        }
    }
    //This will just print the output cipher.
    printf("ciphertext: %s\n", crypt_output);
    }
    //This is what executes if the boolean at the start of the program returns false.
    else {
        printf("Usage: ./caesar key\n");
    }
    }
    else {
         printf("Usage: ./caesar key\n");
    }
    }