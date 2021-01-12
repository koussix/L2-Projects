package calcul_rpn;
import java.util.Vector;

public class MoteurRpn {
	public final double MAX= 100000.0; //en valeur absolue
	public final double MIN= 100000.0;
	private Vector <Double> Operandes; // j'ai choisis la structure Vector pour implémenter ma pile d'opérandes
	
	public MoteurRpn() {
		Operandes = new Vector<Double>(); // initialisation
	}
	
	public double pop_pileD(Vector v1) { // me retourne le haut de la pile ( j'aurai pu utiliser le type stack  mais j'ai préféré manipuler les vector)
		double op1 = (double) v1.lastElement();
		v1.removeElementAt(v1.size()-1);	
		return op1 ;
	}
	
	public boolean operandes_ajouter(double val) throws ValException { // on ajoute une operande a la pile ( on verifie que la valeur ajouter fait partie de l'intervalle MIN MAX) 
		if( val >  MAX ) throw new MaxValueException();
		else if(val < -MIN ) throw new MinValueException();
		return Operandes.add(val);
	}
	
	public boolean operation_sur_operandes(Operation op) throws ExpressionException { // on applique l'opération saisi par l'utilisateur ( On note que cette class peut soulever une exception division par 0 )
		if(Operandes.size() == 1) {
			return Operandes.add(-pop_pileD(Operandes)); // j'ai pris en compte que le - pouvait etre operateur unaire 
														// j'ai déja fait les vérification qu'il fallait pour etre suffisement sur que si ma pile ne contient
														// qu'un seul element alors c'est le cas du ' - ' qu'on traite ici (verification dans la methode operation_possible)
		}
		
			double op1 = pop_pileD(Operandes);
			double op2 = pop_pileD(Operandes);
			if(op2 == 0 && op.getSymbole().equals("/")) { // l'opérande op2 = 0 ce qui souleve alors notre exception de division sur 0
				throw new DivisionSurZeroException();
			}
			return Operandes.add(op.eval(op1, op2));
		
	}
	
	public boolean operation_possible(String Symbole) throws ExpressionException { // cette methode sert a retourner un boolean qui nous informe si oui ou non une opération est possible dans le cas contraire 
																					// la methode nous retourne une exception qu'on pourra gérer
		if( Operandes.size() <2 && !Symbole.equals("-")) { // il ya moins de 2 operandes et l'opérateur n'est pas unaire ( j'ai pris en compte que le '-'en tant que tel )
			throw new FewOperandesException();
		}
		if( Operandes.size() >= 2 ) {
			Operation op = getOperation(Symbole);
			if( op == null ) {  // il ya assez d'opérandes mais l'opération saisi n'est pas repértorié comme étant une opération
				throw new FewOperationException(); // represente le fait qu'il le string entré n'est pas une opération ( manque d'opération )
				}
			else {
			return true ;
			}
			}
		if( Operandes.size() ==1 && Symbole.equals("-")) { // il n'ya qu'une seule operande et le symbole est le MOINS on applique l'opération unaire
			return true ;
		}
		return false ;
		
	}
	
	
	public Operation getOperation(String Symbole) { // on retourne une operation
		for(Operation op : Operation.values()) { // for each
			if( Symbole.equals(op.getSymbole())) {
				return op ;
			}
		}
		return null;
	}
	
	public String operandes_stock() { // retourne une chaine de caractere représentant la pile des opérandes
		String str = "";
		for(Double op : Operandes) {
			str = str +"  "+op ;// a chaque fois op prend la valeur de Operandes
		}
		return str ;
	}
	
	
}
