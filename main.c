#include <stdio.h>
#include <string.h>

#define MAX 50

// Removes '\n' at the end of a string
void removeNewline(char text[]) {
    int len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') //Checks if the string is empty and if the last character is a new line
        text[len - 1] = '\0';             //Replaces the new line with a null terminator
}

// Caesar encryption moves 3 letters to the right 
void caesarEncrypt(char text[]) { //Gets the text from the user input
    for (int i = 0; text[i] != '\0'; i++) { //starts with the first character in the string and moves on to the next character
        if (text[i] >= 'A' && text[i] <= 'Z') { //Controls if its a capital letter between A-Z
            text[i] = ((text[i] - 'A' + 3) % 26) + 'A'; //Removes A from the letter to get a value between 0-25, add 3 to move 3 spaces forward, % to ensure it rolls over
        }
    }
}

// Caesar decryption moves 3 letters to the left
void caesarDecrypt(char text[]) { 
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - 3 + 26) % 26) + 'A'; //Same as encryption but removes 3 instead of adding
        }
    }
}

// Vigenere encryption
void vigenereEncrypt(char text[], char key[]) { //Gets the text and key from user input
    int keyLen = strlen(key); 
    for (int i = 0, j = 0; text[i] != '\0'; i++) { //starts with the first character in the text and moves on to the next character, j are representing the char in the key 
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int shift = key[j % keyLen] - 'A';  //Ensures the key can roll over and calculates how much a number is moved by the key
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A'; //Removes A from the letter to get a value between 0-25, add shift to move shift spaces forward, % to ensure it rolls over
            j++;
        }
    }
}

// Vigenere decryption
void vigenereDecrypt(char text[], char key[]) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int shift = key[j % keyLen] - 'A';
            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A'; //Same as encryption but removes the desired amount instead of adding it
            j++;
        }
    }
}


int main() {
    int choice; 
    int cipher;
    char text[MAX]; 
    char key[MAX];

    while (1) { //Main menu - lets the user choose what they want to do:
        printf("\n--- MENU ---\n");
        printf("1. Encrypt text\n");
        printf("2. Decrypt text\n");
        printf("3. Exit\n"); //Lets the user exit the program and exit the loop
        printf("Choose what you want to do: ");
        scanf("%d", &choice);
        getchar(); //removes new line

        if (choice == 3) { //User chose exit:
            printf("Goodbye!\n");
            break; //
        }

        printf("\nChoose cipher:\n1. Caesar\n2. Vigenere\nChoose: "); //Lets the user choose which cipher/method they want to use
        scanf("%d", &cipher);
        getchar();

        printf("Enter text (UPPERCASE ONLY): "); //Reads the text from the user and removes new line
        fgets(text, MAX, stdin);
        removeNewline(text);

        if (cipher == 2) { //If the user chose viginere as a method it asks for a key
            printf("Enter key (UPPERCASE ONLY): ");
            fgets(key, MAX, stdin);
            removeNewline(key);
        }

        if (choice == 1) { // Encrypt
            if (cipher == 1) caesarEncrypt(text);
            else vigenereEncrypt(text, key);
            printf("Encrypted text: %s\n", text);
            printf("\n");
        } 
        else if (choice == 2) { // Decrypt
            if (cipher == 1) caesarDecrypt(text);
            else vigenereDecrypt(text, key);
            printf("Decrypted text: %s\n", text);
            printf("\n");
        } 
        else {
            printf("Invalid choice!\n");
            printf("\n");
        }
    }
    return 0;
}