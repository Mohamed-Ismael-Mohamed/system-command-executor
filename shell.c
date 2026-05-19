#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char commande[100];
    char *arguments[10];

    while (1) {
        printf("MonShell_Djibouti> ");
        fflush(stdout);

        if (fgets(commande, sizeof(commande), stdin) == NULL) break;

        commande[strcspn(commande, "\n")] = '\0';

        if (strcmp(commande, "exit") == 0) break;

        arguments[0] = strtok(commande, " ");
        int i = 0;
        while (arguments[i] != NULL) {
            i++;
            arguments[i] = strtok(NULL, " ");
        }

        if (arguments[0] == NULL) continue; 

        pid_t pid = fork();

        if (pid < 0) {
            perror("Erreur lors du fork");
            exit(1);
        } 
        else if (pid == 0) {
            if (execvp(arguments[0], arguments) == -1) {
                printf("Commande introuvable : %s\n", arguments[0]);
                exit(1);
            }
        } 
        else {
            wait(NULL);
        }
    }
    return 0;
}
