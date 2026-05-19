# system-command-executor

# Shell en Langage C

Ce projet a été réalisé sur mon temps libre en fin de L2 Informatique. 
Il s'agit d'un interpréteur de commandes personnalisé fonctionnant sous Linux (Unix).

## Fonctionnalités
- Lecture des entrées utilisateur dans une boucle infinie.
- Découpage des commandes et des arguments (Parsing avec strtok).
- Création de processus enfants (`fork`) et exécution de commandes système (`execvp`).
- Gestion de la commande de sortie (`exit`).

## Technologies utilisées
- Langage C
- API POSIX (Système d'exploitation Linux)

## Comment lancer le projet sur Ubuntu ?
1. Compiler le code : gcc shell.c -o monshell
2. Lancer le shell : ./monshell
