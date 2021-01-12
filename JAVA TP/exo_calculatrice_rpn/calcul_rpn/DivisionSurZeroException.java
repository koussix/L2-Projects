package calcul_rpn;

public class DivisionSurZeroException extends ExpressionException{// mon organisation en Hierarchie fait que les problemes lié a une fausse ecriture de l'expression appartiennent a la class mere
																	//expressionException

	public DivisionSurZeroException() {
		super("ERROR : division sur 0 impossible");
		
	}
}
