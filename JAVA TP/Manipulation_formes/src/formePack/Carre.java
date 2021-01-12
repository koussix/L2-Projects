package formePack;

public class Carre extends Forme{
	private Point p1; // le point en bas a gauche 
	private int largeur; // la largueur du carre
	
	public Carre() {
		p1 = new Point();
		largeur = 0;
	}
	
	public Carre(Point p1 , int width) {
		this.p1 = p1;
		this.largeur = width ;
	}

	public Point GetPoint2() {
		Point p2 = new Point() ;
		p2.setAbscice(this.p1.getAbscice()+largeur);
		p2.setOrdonne(this.p1.getOrdonne()+largeur);
		return p2;
	}

	@Override
	public String toString() {
		return "Carré  Point_départ =" + p1 + ", largeur=" + largeur + "";
	}

	@Override
	public double calcul_surface() {
		// TODO Auto-generated method stub
		return this.largeur*this.largeur;
	}

	@Override
	public double calcul_perimetre() {
		// TODO Auto-generated method stub
		return this.largeur*4;
	}

	@Override
	public void deplacer(int abscisse_translation, int ordonne_translation) {
		// TODO Auto-generated method stub
		this.p1.deplacer(abscisse_translation, ordonne_translation);	
	}
	
	
	
}
