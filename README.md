# Minishell

## Introduction

Minishell is an assignement given by the 42 school.
The main purpose of this project is to create a rather simple shell.
Feature list below.

## Features

### Mandatory

- [ ] Display a prompt when waiting for a new command
- [ ] Have a working history
- [ ] Search and launch the right executable (base on the PATH variable or using a relative or an absolute path)
- [ ] Avoid using more than one global variable to indicate a received signal.
- [ ] Not interpret unclosed quotes or special characters which are not required by the subject such as \ or ;
- [ ] Handle single-quote '
- [ ] Handle double-quote "

- [ ] Implement redirections
    - [ ] < should redirect input.
    - [ ] > should redirect output.
    - [ ] << should be given a delimiter, then read the input until a line containing the delimiter is seen. It doesn't have to update the history.
    - [ ] >> should redirect output in append mode.

- [ ] Implement pipes ( | ). The output of each command in the pipeline is connected to the input of the next command via pipe.
- [ ] Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
- [ ] Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
- [ ] Handle ctrl-C, ctrl-D, and ctrl-\ which should behave like in bash.

- [ ] Your shell must implement the following builtins :
    - [ ] echo with option -n
    - [ ] cd with only a relative or absolute path
    - [ ] pwd with no options
    - [ ] export with no options
    - [ ] unset with no options
    - [ ] env with no options or arguments
    - [ ] exit with no options

### Bonus part

- [ ] You must implement && and || along with parenthesis priorities.
- [ ] Wildcards ( * ) should work for the current directory.


### Parties

- Partie 1 : Structure de base et gestion des commandes

Gestion du prompt : Créer la boucle principale qui affiche le prompt et attend une commande.
Lecture de la commande : Utiliser readline() pour récupérer la commande saisie par l'utilisateur.
Exécution de commandes simples : Implémenter la recherche d'exécutables et l'exécution de commandes basiques comme echo ou ls.


- Partie 2 : Gestion des redirections et des pipes

Redirections simples (<, >, >>, <<) : Implémenter la gestion des redirections dans la commande, c’est-à-dire modifier l’entrée et la sortie des commandes.
Pipes (|) : Implémenter le mécanisme de pipe entre plusieurs commandes pour que la sortie d’une commande serve d’entrée à la suivante.


- Partie 3 : Gestion des builtins

Les commandes intégrées (echo, cd, pwd, exit, etc.) : Créer les fonctions pour ces commandes intégrées, qui n'ont pas besoin de processus externes.
Gestion des variables d'environnement : Implémenter le mécanisme pour l’expansion de variables comme $HOME ou $USER.


- Partie 4 : Gestion des signaux et de l'historique

Gestion des signaux (comme Ctrl+C, Ctrl+D) : Implémenter la gestion des signaux.
Historique des commandes : Ajouter la gestion de l'historique avec add_history() et read_history().

### Repartition

- cpoulain (Partie 1 et Partie 2) :

- Partie 1 :
Création de la boucle principale avec le prompt.
Lecture des commandes avec readline() et stockage dans un buffer.
Recherche d'exécutables dans le PATH et exécution des commandes simples (comme echo, pwd, etc.).

- Partie 2 :
Implémentation des redirections (>, <, >>, <<).
Mise en place du mécanisme de pipes (|).


- jcheron (Partie 3 et Partie 4) :


- Partie 3 :
Implémentation des builtins (echo, cd, pwd, export, unset, env, exit).
Gestion des variables d’environnement et expansion des variables comme $HOME, $USER.

- Partie 4 :
Implémentation de la gestion des signaux (Ctrl+C, Ctrl+D, Ctrl-\).
Mise en place de l'historique des commandes.
