
public class DnsTUI {
	
	private String saisie ; // la saisie de l'utilisateur
	private Dns dns1; // notre instance de Dns
	
	public DnsTUI (String saisie) {
		this.saisie =saisie;
	}
	
	public void setDns ( Dns dns1 ) {
		this.dns1= dns1 ;
	}
	
	public LanceurCommande nextCommand(){
		String str="";
		char c=' ';
		boolean bool= false;
		try {	
			c = saisie.charAt(0);
			bool=false;
			str += saisie.substring(0 , 3);
		}catch (StringIndexOutOfBoundsException e) {
			System.out.println("Veuillez saisir une chaine de caractere contenant au moins 3 lettres");
			return new LanceurCommande("Format non valide",saisie,dns1);
		}
		
		boolean bool2=false;
		if(str.equals("ls ")) bool2=true; // pour savoir si l'utilisateur veut une liste des Items
		
		if (c>='0'&& c<='9') bool = true; // nous servira a reconnaitre si l'utilisateur cherche a saisir une adresseIP
		
		if( this.saisie.equals("quit") ) {
			return new LanceurCommande("quitter l'application",saisie,dns1); // utilisateur a saisi quit
		}
		else if (bool == true) {
			return new LanceurCommande("rechercher une machine",saisie,dns1);// l'utilisateur a saisie une AdrIP
		}
		else if (bool2 == true) {
			return new LanceurCommande("rechercher les machines",saisie,dns1);// l'utilisateur a saisi ls ou ls -a
		}
		else {
			return new LanceurCommande("rechercher une IP",saisie,dns1); //l'utilisateur a saisi un nomMachine
		}
	}
	
	public void afficher(){
		dns1.afficher(dns1.collectionDns);
	}


}