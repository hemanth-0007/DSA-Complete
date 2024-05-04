#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ROLL_LENGTH 9

// Structure to represent a student
typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char rollNumber[MAX_ROLL_LENGTH];
    int age;
    char branch[3];
} Student;

// Function to calculate hash value
int calculateHash(Student student) {
    int sum = 0;
    for (int i = 0; i < strlen(student.firstName); i++) {
        sum += student.firstName[i];
    }
    return (sum + student.age) % 4;
}

// Function to initialize groups
// void initializeGroups(Student groups[][MAX_STUDENTS], Student students[], int n) {
//     int key = 0;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < groupSize; j++) {
//             groups[i][j] = -1;
//         }
//     }
// }

// Function to add student to a group
// void addToGroup(int groups[][MAX_STUDENTS], Student students[], int studentIndex, int group) {
//     int i = 0;
//     while (groups[group][i] != -1) {
//         i++;
//     }
//     groups[group][i] = studentIndex;
// }

// Function to count students in a group
int countStudentsInGroup(Student students[],int n, int group) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (calculateHash(students[i]) == group) {
            count++;
        }
    }
    return count;
}

// Function to print student list in a group
void printStudentListInGroup(Student students[],int n, int group) {
    for (int i = 0; i < n; i++) {
        if (calculateHash(students[i]) == group) {
            printf("%s ", students[i].firstName);  
        }
    }
    printf("\n");
}

// Function to print student list from the same branch in a group
void printSameBranchStudentsInGroup(Student students[], int n, int group, char branch[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (calculateHash(students[i]) == group && strcmp(students[i].branch, branch) == 0) {
            // printf("The stringCompare of %s and %s is %d\n", students[i].branch, branch, strcmp(students[i].branch, branch));
            printf("%s ", students[i].firstName);
            count = count + 1;
        }
    }
    if(count == 0) printf("-1\n");
    else printf("\n");
}


void extractLastTwo(const char *input, char *output) {
    int length = strlen(input);
    if (length >= 2) {
        output[0] = input[length - 2];
        output[1] = input[length - 1];
        output[2] = '\0'; // Null-terminate the output string
    } else {
        strcpy(output, input); // Copy the entire input string if it's less than 2 characters
    }
}

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    
    // Reading student information
   for (int i = 0; i < n; i++) { // Corrected loop condition
        scanf("%s %s %d", students[i].firstName, students[i].rollNumber, &students[i].age); // Removed space after %d
        extractLastTwo(students[i].rollNumber, students[i].branch); 
    }

    // for (int i = 0; i < n; i++) { // Corrected loop condition
    //     printf("%s %s %s\n", students[i].firstName, students[i].rollNumber, students[i].branch); // Removed * before students[i].firstName, etc.
    // }
    
    // Student groups[4][MAX_STUDENTS];
    // initializeGroups(groups,students,n);

    char option;
    while (1) {
        scanf(" %c", &option);
        if (option == 'e') {
            break;
        }
        if (option == 'c') {
            int group;
            scanf("%d", &group);
            int count = countStudentsInGroup(students,n, group);
            printf("%d ", count);
            printStudentListInGroup(students,n, group);
        } else if(option == '1' || option == '2' || option == '3' || option == '0'){
            int group = option - '0';
            char branch[3];
            scanf("%s", branch);
            toUpperCase(branch);
            printSameBranchStudentsInGroup(students,n, group, branch);
        }
    }

    return 0;
}
