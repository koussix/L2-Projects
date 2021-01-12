package calcul_rpn;

public class FewOperationException extends ExpressionException {// mon organisation en Hierarchie fait que les problemes lié a une fausse ecriture de l'expression appartiennent a la class mere
																//expressionException

	public FewOperationException(){
		super("Format de l'expression non accepté : OPERATION INEXISTANTE");

	}
}
