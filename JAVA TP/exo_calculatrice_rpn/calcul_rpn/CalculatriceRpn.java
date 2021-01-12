package calcul_rpn;

public enum CalculatriceRpn {
	RUN ; // nous servira a appeler la methode lancer_programme 
	
	public void lancer_programme(String[] args) {
		SaisieRpn saisie =  new SaisieRpn();
		saisie.MethodeSaisieRpn();
	}

	public static void main(String[] args) { // methode principale main
		CalculatriceRpn calcul= RUN;
		calcul.lancer_programme(args);
		System.out.println("FIN DU PROGRAMME");
	}
}


