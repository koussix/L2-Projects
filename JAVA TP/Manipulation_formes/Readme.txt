Compilation, execution :
	2 Methodes :
		1 - En ligne de commande :
			-Il faut se positionner dans le dossier src/
			-Un makefile a été mit a disposition pour compiler executer avec la commande "make"
			-Une cible make clean : pour supprimer les fichier.class
			*Details du makefile :
				-Compiler en utilisant la commande : javac exceptionPack/*.java execPack/*.java formePack/*.java saisiePack/*.java 
				-Executer en utilisant la commande : java execPack.Main

		2 - En utilisant un IDE ( Intellij, ECLIPS ).

Explication : 
	1- Hierarchie : 
		Le package "formePack" : on retrouve notamment l'implémentation de nos formes et la hierarchie basique nos formes basiques "héritent" 	de la class forme, et sont composé de point.

		Le package "saisiePack" : est essentiellement composé de nos class qui se chargeront de la saisie ( affichage pour l'utilisateur ), tout en communiquant avec les autres package pour diffuser l'information.

		Le package "exceptionPack" : contient nos exception, 2 exception personnalisé ont été traité dans notre projet à savoir erreurSaisie et InexistantException.
			Note : j'ai soulevé d'autres exception dans le programme mais étant donné que c'est des exception propre au langage je les ai traité directement avec un try catch ( exemple : j'ai implémenté une methode de saisie securisé qui récupére la saisie de l'utilisateur sous forme de String puis la convertis en Int si cela est possible sinon une exception sera soulevé ! ).

		Le package "execPack" : contient la class Main qui se chargera uniquement de l'execution de notre programme.

	2- Fonctionnement :
		Dans mon implémentation j'ai choisi de faire un programme intéractif qui intéragie à chaque fois avec l'utilisateur en lui donnant un ensemble de possibilités ( fonctions ) à executer ou non, tout en soulevant les exceptions de saisie si besoin.

		A chaque tour de boucle l'utilisateur pourra choisir entre l'ajout d'un element, le traitement globale (sur tout les objet), et le traitement spécifique sur des objets déjà saisi qu'il choisira par lui même.

		A chaque fin de tour, on demande à l'utilisateur s'il veut poursuivre son traitement ou bien quitter le programme en tappant "exit".
