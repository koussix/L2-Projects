package calcul_rpn;

public class MinValueException extends ValException {
	public static final double MIN = 100000.0;
	
	public MinValueException() {
		super("ERROR : Valeur entree inferieur à :"+(-MIN));
	}
			
}
