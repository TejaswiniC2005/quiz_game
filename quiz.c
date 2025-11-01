#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Question {
    char q[200], a[100], b[100], c[100], d[100];
    char correct;
    struct Question *next;
} Question;

Question *head = NULL;

// Add question to linked list
void addQuestion(char *q, char *a, char *b, char *c, char *d, char correct) {
    Question *newNode = (Question*)malloc(sizeof(Question));
    strcpy(newNode->q, q);
    strcpy(newNode->a, a);
    strcpy(newNode->b, b);
    strcpy(newNode->c, c);
    strcpy(newNode->d, d);
    newNode->correct = toupper(correct);
    newNode->next = head;
    head = newNode;
}

// Admin: add question manually
void adminAddQuestion() {
    char q[200], a[100], b[100], c[100], d[100], correct;

    getchar(); // flush newline
    printf("Enter question: ");
    fgets(q, 200, stdin);
    q[strcspn(q, "\n")] = 0;

    printf("Option A: "); fgets(a, 100, stdin); a[strcspn(a, "\n")] = 0;
    printf("Option B: "); fgets(b, 100, stdin); b[strcspn(b, "\n")] = 0;
    printf("Option C: "); fgets(c, 100, stdin); c[strcspn(c, "\n")] = 0;
    printf("Option D: "); fgets(d, 100, stdin); d[strcspn(d, "\n")] = 0;

    printf("Correct (A/B/C/D): ");
    scanf(" %c", &correct);

    addQuestion(q, a, b, c, d, correct);
    printf("✅ Question added!\n");
}

// Run quiz
void startQuiz() {
    Question *temp = head;
    char choice;
    int score = 0, total = 0;

    while (temp != NULL) {
        printf("\nQ: %s\nA) %s\nB) %s\nC) %s\nD) %s\n", 
            temp->q, temp->a, temp->b, temp->c, temp->d);
        printf("Your answer (A/B/C/D): ");

        while (1) {
            scanf(" %c", &choice);
            choice = toupper(choice);
            if(choice=='A'||choice=='B'||choice=='C'||choice=='D') break;
            printf("Invalid! Enter A/B/C/D: ");
        }

        if(choice == temp->correct) score++;
        total++;
        temp = temp->next;
    }

    printf("\n===== RESULT =====\nScore: %d/%d\n", score, total);

    FILE *fp = fopen("scores.txt", "a");
    fprintf(fp, "Score: %d/%d\n", score, total);
    fclose(fp);
}

// Show all questions
void viewQuestions() {
    Question *t = head;
    printf("\n--- Stored Questions ---\n");
    while(t) {
        printf("%s (Answer: %c)\n", t->q, t->correct);
        t = t->next;
    }
}

// Show score history
void viewScores() {
    FILE *fp = fopen("scores.txt", "r");
    if(!fp) { printf("No score history yet.\n"); return; }

    char line[100];
    printf("\n--- Score History ---\n");
    while(fgets(line, sizeof(line), fp))
        printf("%s", line);
    fclose(fp);
}

int main() {
    // Default questions
    addQuestion("Which DS uses FIFO?", "Stack","Queue","Tree","Graph",'B');
    addQuestion("Which is fastest lookup?", "Array","Hash Table","Queue","Stack",'B');
    addQuestion("Pointer dereference operator?", "*","&","%","@",'A');

    int choice;
    while(1) {
        printf("\n====== QUIZ MENU ======\n");
        printf("1. Start Quiz\n2. Add Question (Admin)\n3. View Questions (Admin)\n4. View Score History\n5. Exit\nChoose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: startQuiz(); break;
            case 2: adminAddQuestion(); break;
            case 3: viewQuestions(); break;
            case 4: viewScores(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
