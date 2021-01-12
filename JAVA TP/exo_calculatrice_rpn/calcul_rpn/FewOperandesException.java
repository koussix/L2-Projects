package calcul_rpn;

public class FewOperandesException extends ExpressionException { // mon organisation en Hierarchie fait que les problemes lié a une fausse ecriture de l'expression appartiennent a la class mere
																	//expressionException
	
	public FewOperandesException() {
		super("Format de l'expression non accepté : PAS ASSEZ D'OPERANDES");
	}
}
