# 9-Minishell

https://docs.google.com/spreadsheets/d/1Df8ad8bNuCy5BGgMCzzcW5pYk6Ofmn4RdCJJ7OnYvs4/edit?pli=1#gid=0

## CHECK LEAKS :
sans readline leaks : 
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --memcheck:suppressions=./.minishell.supp ./minishell

## TO DO LIST :
https://trello.com/b/HVYpBej1/minishell-42

## DOCUMENTATION :
42 docs : https://harm-smits.github.io/42docs/projects/minishell
Shell syntax : https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html
Mcombeau tuto : https://www.codequoi.com/pourquoi-je-necris-plus-darticles-sur-les-projets-de-42/
petite explication sur la marche a suivre : http://i.paysdu42.fr/?page=minishell.c

Bonnes explications : https://github.com/maiadegraaf/minishell

## Travailler en équipe avec Git
Travailler en équipe avec Git implique de **gérer les modifications de code source** apportées par plusieurs membres, de résoudre les conflits qui peuvent survenir, et de synchroniser les différentes versions du projet. Voici les principales commandes et fonctionnalités pour travailler efficacement en équipe avec Git :

#### Collaborer sur un même dépôt : 
la première étape pour travailler en équipe avec Git est de se mettre d’accord sur le même dépôt central, qui servira de référence pour le projet. Les membres de l’équipe peuvent alors cloner ce dépôt sur leur propre machine, et y apporter des modifications en local. 

#### Les commandes de base pour collaborer sur un même dépôt sont :
- `git clone` : pour récupérer une copie du dépôt sur sa machine locale.
- `git pull` : pour récupérer les dernières modifications apportées au dépôt central depuis sa machine locale.
- `git push` : pour envoyer les modifications apportées en local sur le dépôt central.
- `git fetch` : pour récupérer les modifications apportées au dépôt central sans les fusionner avec le code local.

#### Résoudre les conflits :
lorsqu’un ou plusieurs membres de l’équipe modifient le même fichier en même temps, **il peut y avoir des conflits à résoudre pour fusionner les modifications**. Git fournit des outils pour faciliter la résolution des conflits, tels que :
- `git merge` : pour fusionner deux branches de développement, en résolvant automatiquement les conflits lorsque cela est possible.
- `git rebase` : pour appliquer les modifications d’une branche sur une autre branche, en réécrivant l’historique des commits pour faciliter la fusion.

#### Éditeur de texte : 
lorsqu’un conflit ne peut pas être résolu automatiquement, Git ouvre un éditeur de texte pour permettre à l’utilisateur de résoudre manuellement le conflit.

#### Gérer les autorisations : 
pour éviter que n’importe qui puisse envoyer des modifications sur le dépôt central, Git et GitHub permettent de gérer les autorisations et les contributions des membres de l’équipe. Les principales fonctionnalités pour gérer les autorisations sur GitHub sont :
- Collaborateurs : pour inviter d’autres membres à rejoindre le projet et contribuer aux modifications.
- Forks : pour créer une copie du projet sur son propre compte GitHub, afin de travailler en parallèle sur une version dédiée.
- Pull requests : pour soumettre des modifications au dépôt central et demander leur intégration dans le projet.
En utilisant ces fonctionnalités de Git et GitHub, les membres de l’équipe peuvent travailler efficacement sur un même projet, tout en gérant les autorisations et les conflits éventuels.

