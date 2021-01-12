package exceptionPack;

public class InexistantException extends Exception{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public InexistantException(){
		System.out.println("Exception : Elements introuvable (astuce : ajoutez de nouveaux elements)");
	}
}
