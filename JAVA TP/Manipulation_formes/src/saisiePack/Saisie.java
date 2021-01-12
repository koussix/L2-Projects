package saisiePack;

import java.util.Scanner;

import exceptionPack.ErreurSaisieException;

// la class saisie servira d'objet intermédiaire qui va instancier la class saisieForme et se chargera
// de faire une boucle tant que l'utilisateur n'aura pas saisi 'quit'
public class Saisie {
	SaisieForme s1 ;
		
	public Saisie() {
		s1 = new SaisieForme();
	}
	
	public void saisieGen() {
		
		Scanner sc = new Scanner(System.in);
		String str ="";
		SaisieForme s1 = new SaisieForme();
		do {
			try {
				s1.saisir();
			} catch (ErreurSaisieException e) {
				// TODO Auto-generated catch block
				e.getMessage();
			}
			
			System.out.println("\n\n--- Voulez vous continuer le traitement/saisie des objets ? ---\n saisir "
					+ "'quit' pour arêter le programme ! (ou autre chose sinon)");
			str = sc.next();
			
		}while(!str.equals("quit"));
		
		System.out.println("Fermeture du programme");
	}


}

