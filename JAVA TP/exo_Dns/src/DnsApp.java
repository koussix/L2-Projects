//Nom : LABCHRI
//Prenom : Koceila 
//Num_etud : 21919396

import java.util.Scanner;


public class DnsApp { // class contenant la methode main
	public DnsApp(){}
	
	public void run(String[]args) {
		System.out.println("Bienvenu dans le programme DNS ");
		System.out.println("Possibilites de saisie :\n 1-Une adresseIP -> forme 192.168.1.1\n 2-Un nom de machine -> exp forme -> imprimante.chezmoi.fr"
				+ "\n\t -Commande 'ls domaine' "
				+ "vous permet de lister -> Exemple :'ls chezmoi.fr'\n\t -'ls -a domaine' si vous voulez un ordre selon"
				+ " les IP \n3-Tappez 'quit' pour aretter");
		Scanner sc= new Scanner(System.in);
		Dns dns1 = new Dns();
		
		while ( true ) {
			//System.out.println(Dns.a);
	    	String entree = sc.nextLine();
			DnsTUI dnsentry = new DnsTUI(entree);
			dnsentry.setDns(dns1); // on passe notre objet a notre instance de dnsTUI pour tout gerer de maniere centralisé
			LanceurCommande c1 = dnsentry.nextCommand();
			c1.execute(); //lancement de la methode execute
			dnsentry.afficher(); //affichage de la liste des item
		}
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DnsApp app = new DnsApp();
		app.run(args);
	
	}

}
