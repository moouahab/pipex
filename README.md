#PIPEX
#Description

PipeX est un projet conçu pour initier les étudiants aux concepts de programmation multiprocessus en langage C. Ce projet met l'accent sur l'utilisation des tubes (pipes) pour établir des communications entre différents processus, simulant ainsi le fonctionnement de pipelines de commandes dans un environnement UNIX. En implémentant une chaîne de traitement de données à travers des tubes, les étudiants explorent les notions de création de processus, de redirection des flux d'entrée/sortie, et de synchronisation de l'exécution de processus.
Objectifs Principaux

    Création de Processus: L'objectif principal de PipeX est de créer une série de processus qui interagissent via des tubes pour manipuler des données. Chaque processus représente une étape de la chaîne de traitement et communique avec les autres processus en envoyant et recevant des données à travers les tubes.

    Redirection des Flux: Le projet implique la redirection des flux d'entrée/sortie standard des processus vers des tubes afin de permettre le transfert de données entre eux. Cela nécessite une manipulation soigneuse des descripteurs de fichiers et la compréhension des mécanismes de redirection dans un environnement UNIX.

    Gestion des Erreurs: Une attention particulière est portée à la gestion des erreurs et à la robustesse du programme. Les étudiants doivent anticiper et gérer divers scénarios d'erreur, tels que l'échec de création de tubes, les erreurs d'exécution des processus, et les problèmes de synchronisation.

Améliorations Suggérées

Pour améliorer le projet PipeX, voici quelques suggestions :

    Optimisation de la Performance: Revoir et optimiser le code pour réduire la surcharge et améliorer l'efficacité de l'exécution des processus.

    Gestion des Signaux: Implémenter la gestion des signaux pour permettre une terminaison propre et une manipulation des processus en cas de signaux système ou utilisateur.

    Support de Fonctionnalités Avancées: Étendre le projet pour prendre en charge des fonctionnalités avancées telles que la prise en charge de commandes avec des arguments, la gestion de processus en arrière-plan, ou la redirection vers des fichiers.

Utilisation

Pour utiliser le programme PipeX, suivez les étapes suivantes :

    Compilez le programme en exécutant la commande make dans le répertoire du projet.
    Exécutez le programme en fournissant les commandes à exécuter dans le pipeline.

    css

    ./pipex [file1] [cmd1] [cmd2] [file2]

    où file1 est le fichier d'entrée initial, cmd1 et cmd2 sont les commandes à exécuter, et file2 est le fichier de sortie final.

Conclusion

Le projet PipeX offre aux étudiants une première approche pratique de la programmation multiprocessus, leur permettant de manipuler des tubes et de créer des pipelines de commandes similaires à ceux trouvés dans les systèmes d'exploitation UNIX. En complétant ce projet avec succès, les étudiants acquièrent une compréhension fondamentale des concepts de multiprocessus et renforcent leurs compétences en programmation système.
