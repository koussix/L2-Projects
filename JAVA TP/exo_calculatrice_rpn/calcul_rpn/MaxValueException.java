package calcul_rpn;


public class MaxValueException extends ValException{
	public static final double MAX = 100000.0;
	public MaxValueException() {
		super("ERROR : Valeur entré superieur à "+ MAX);
	}
	
}
