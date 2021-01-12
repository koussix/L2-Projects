
public class NomMachine {
	private String NomMachine ;// type de base recuperer du fichier BDD
	
	public NomMachine(String NomMachine) {
		if(check_nm(NomMachine)==true)
			this.NomMachine =NomMachine;
		else
			this.NomMachine="NAN.NAN.NAN";
	}
	
	public String getNomMachine() {
		return this.NomMachine;
	}
	
	private boolean check_nm(String NomMachine) {
		boolean bool= true;
		int nb_points=0;
		String tmp ="";
		for (int i=0 ; i< NomMachine.length();i++) {
			if(NomMachine.charAt(i)=='.') {
				nb_points ++;
				if (isNumeric(tmp)) {
					System.out.println("ERROR NomMachine (suite de nombre detecte): format errone, exp forme -> monserveur.chezmoi.com");
					bool=false;
				}
				tmp ="";
			}
			else {
				tmp += NomMachine.charAt(i);
			}
		}
		if (nb_points < 2 ) {
			bool= false;
			System.out.println("ERROR NomMachine (doit contenir au moins 3 mots) : format errone, exp forme -> monserveur.chezmoi.com");
			//System.exit(1);
		}
		
		return bool;
		
		
	}
	
	public static boolean isNumeric(String strNum) {
	    if (strNum == null) {
	        return false;
	    }
	    try {
	        double d = Double.parseDouble(strNum);
	    } catch (NumberFormatException nfe) {
	        return false;
	    }
	    return true;
	}
	
}
