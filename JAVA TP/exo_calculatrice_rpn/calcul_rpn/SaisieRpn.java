package calcul_rpn;
import java.util.Scanner ;


public class SaisieRpn {
	private Scanner sc ;      // on aura besoin d'un scanner pour les saisie
	private MoteurRpn moteur; // moteur qui representera notre instance de MoteurRpn pour utiliser les méthodes implémenté dans ce dernier
	
	public SaisieRpn() {    //constructeur sans parametres 
		this.sc = new Scanner(System.in);
		this.moteur = new MoteurRpn();
	}
	
	
	public void MethodeSaisieRpn() {
		String str ; // on l'utilisera lors de notre saisie pour recupéré le string entré par l'utilisateur
		
		System.out.println(" Entrez un double ou une operation ou 'exit' pour quitter");
		boolean bool=true;
		System.out.println("MAX ="+moteur.MAX+"   MIN ="+moteur.MIN);
		
		do {
			str = sc.next();
           if(! str.equals("exit")) {		
			if( (bool=isNumeric(str))== true ) {
				
				try { // le try catch servira a etre sur que les valeurs saisie ne sortent pas de l'intervalle donnée
					
				double a= Double.parseDouble(str);
				moteur.operandes_ajouter(a);	
				
				}catch(ValException e) {// valException contient les exception suivantes 'MaxValueException , MinValueException'
					System.out.println(e.getMessage());
					System.out.println("Exception soulever ! Si vous voulez refaire votre saisie merci d'entrer le mot 'continue'");					str = sc.next(); // on donne a l'utilisateur la chance de resaisir une valeur ou operation
					if (str.equals("continue")) {
						System.out.println("Veuillez poursuivre votre saisie ( operandes , operation ) !");
						continue;
						}
					else {
						System.out.println("le programme se ferme !");
						System.exit(1);
					}
					//System.out.println("Fermeture du programme !");
					//System.exit(1);
				}
				
			}
			else {  // un autre try pour etre sur que les operation que l'on va appliqué sont bien possible et qu'elles ne vont pas nous generer des exception
				try {
					if(moteur.operation_possible(str)) { // pour savoir si notre 'str' represente un symbole de l'enum Operation et que notre pile pourra bien supporter une operation ( size> 2)
						Operation op = moteur.getOperation(str);
						moteur.operation_sur_operandes(op);
					}
				} catch( ExpressionException e) { // expressionException contient les exception 'DivisionSurZeroException, FewOperandesException,FewOperationsException'
					System.out.println(e.getMessage());
					System.out.println("Exception soulever ! Si vous voulez refaire votre saisie merci d'entrer le mot 'continue'");
					str = sc.next(); // on donne a l'utilisateur la chance de resaisir une valeur ou operation
					if (str.equals("continue")) {
						System.out.println("Veuillez poursuivre votre saisie ( operandes , operation ) !");
						continue;
						}
					else {
						System.out.println("le programme se ferme !");
						System.exit(1);
					}
					//System.out.println("Fermeture du programme !"); // on aurait tout de meme pu arreter le programme apres une saisie erroné
					//System.exit(1);
				}
				
				
			}
           }
           
          System.out.println(moteur.operandes_stock());
          
			
		}while( !str.equals("exit") );
		
		
		
	}
	
	public static boolean isNumeric(String strNum) { // retourne un booléen (vrai si c un nombre faux sinon)
	    if (strNum == null) {
	        return false;
	    }
	    try {
	        double d = Double.parseDouble(strNum); //commande permettant de trarnsformer une chaine de caractere en double
	    } catch (NumberFormatException nfe) {  //exception non personnalisé lancé par la JVM ( on l'a regle en retounant faux ) 
	        return false;
	    }
	    return true;
	}
	
}
