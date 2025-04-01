// HW10 : Gabriel Cotua
// I know might not be the best use of Linked Lists but I wanted to try it out.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ARRSIZE 20
#define ARRPEOPLESIZE 5


typedef struct PersonNamesTemplate {
    char first[19];
    char last[19];
} Names;

typedef struct PersonTemplate {
    int SSN;
    Names name;
} Person;

typedef struct PersonNode {
    Person * Person;
    struct PersonNode * Next;
} PersonNode;


void Add_Node(PersonNode ** root);
void Person_Fill(PersonNode * person);
void PersonNode_Print(PersonNode *head);

int main(void) {
    printf("\n\n|#####################|\n|HW #10, Gabriel Cotua|\n|#####################|\n\n");
    srand(time(NULL));
    PersonNode *root = NULL;
    
    int count = 0;
    for (count = 0; count < ARRPEOPLESIZE; count++) {  
        Add_Node(&root);
        //printf("Adding node %d\n", count);
        Person_Fill(root);  // Fill the new node (root is the most recent node)
        //printf("Node %d added\n", count++);
    }

   // printf("Printing...\n");
    PersonNode_Print(root);
    
    return 0;
}

void Add_Node(PersonNode ** root) { // New node to the list
    PersonNode * newNode = (PersonNode *)malloc(sizeof(PersonNode));
    if (newNode == NULL) { // Check if memory allocation was successful, aka there was enough memory to take from
        printf("Memory allocation failed\n");
        free(newNode);
        exit(1);
    }
    newNode->Person = (Person *)malloc(sizeof(Person));
    if (newNode->Person == NULL) { // same for the Person struct
        printf("Memory allocation for Person failed\n");
        free(newNode);
        exit(2);
    }
    newNode->Next = *root;  // Link new node to current root
    *root = newNode;  // Update root
}

void Person_Fill( PersonNode *people)
{
    //printf("Filling...");
    if (people == NULL || people->Person == NULL) {  // PREVENIR ACCESO A NULL
        printf("Error: Nodo de persona no inicializado\n");
        return;
    }
    // Ai was used to generate the names, last names and SSNs.
    const char Names[ARRSIZE][ARRSIZE] = {
        "John", "Jane", "Alice", "Bob", "Charlie",
        "David", "Eve", "Jocabed", "Gabriel", "Heidi",
        "Ivan", "Judy", "Mallory", "Niaj", "Grabrielle",
        "Peggy", "Rupert", "Alejandro", "Trent", "Victor"
    };
    const char LastNames[ARRSIZE][ARRSIZE] = {
        "Angular", "Johnson", "Ramirez", "Jones", "Moles",
        "Davis", "Miller", "Wilson", "Moore", "Taylor",
        "Cotua", "De la Cruz", "Jackson", "Aguilar", "Harris",
        "Martin", "Saldivar", "Garcia", "Martinez", "Robinson"
    };
    const int SSNs[ARRSIZE] ={
        123456789, 987654321, 555555555, 111223344, 222334455,
        333445566, 444556677, 555667788, 666778899, 777889900,
        888990011, 999001122, 101112131, 121314151, 131415161,
        171819202, 202122232, 232425262, 262728293, 29293031
    };
        strcpy(people->Person->name.first, Names[rand() % ARRSIZE]); // assign a random name from the array to Person
        strcpy(people->Person->name.last, LastNames[rand() % ARRSIZE]); // assign a random last name from the array to Person
        people->Person->SSN = SSNs[rand() % ARRSIZE];
        //printf("done\n");
}

void PersonNode_Print(PersonNode *head) {
    //printf("Printing List:\n");
    PersonNode* curr;
    for ( curr = head; curr != NULL; curr = curr->Next) { // Gouing through the Linked List, good to note that instead of being in a int count, is more similar to what python does with {for x in ""}
        printf("%d -- %s, %s\n", curr->Person->SSN, curr->Person->name.last, curr->Person->name.first);
    }
}

/*
Spected output:

|#####################|
|HW #10, Gabriel Cotua|
|#####################|

29293031 -- Moore, Victor
777889900 -- Harris, Judy
29293031 -- Saldivar, Jane
666778899 -- Angular, Alejandro
111223344 -- Angular, Grabrielle

 */