// class du lanceur de commande qui se charge de lancer les commandes
public class LanceurCommande implements Commande{
	private String action ;
	private String saisie ;
	private Dns dns1 ;
	
	public LanceurCommande(String action, String saisie , Dns dns1) {
		this.action = action ;
		this.saisie = saisie ;
		this.dns1 = dns1 ;
	}
	
	public String getAction() {
		return this.action;
	}
	@Override
	public void execute() {
		//Dns dns1 = new Dns(); // dans le cas ou on avait pas envoyé le dns a dnsTUI on serait obligé de l'instancier ici
		
		if( this.action.equals("rechercher une IP") ) { //cas d'une recherche d'ip 
			this.dns1.getItem(new NomMachine(saisie)); // recherche d'item en parametre une instance de nomMachine
		}
		else if ( this.action.equals("rechercher une machine")){
			this.dns1.getItem(new AdresseIP(saisie));//recherche d'une machine en pararmetre une instance d'adresseIP
		}
		else if (this.action.equals("rechercher les machines")) {
			this.dns1.getItems(saisie);
		}
		else if (this.action.equals("Format non valide")) {
			System.out.println("Refaites votre saisie s'il vous plait");
		}
		else
			this.dns1.quitter_application();
		
	}

}
