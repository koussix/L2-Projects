package formePack;

public class Rectangle extends Forme{
	private Point p1; // le point en bas a gauche 
	private int longueur; // la hauteur du rectangle 
	private int largeur; // la largueur du rectangle
	
	public Rectangle() {
		p1 = new Point();
		longueur=0;
		largeur = 0;
	}
	
	public Rectangle(Point p1 ,int height , int width) {
		this.p1 = p1;
		this.longueur = height;
		this.largeur = width ;
	}

	public Point GetPoint2() {
		Point p2 = new Point() ;
		p2.setAbscice(this.p1.getAbscice()+largeur);
		p2.setOrdonne(this.p1.getOrdonne()+longueur);
		return p2;
	}

	@Override
	public String toString() {
		return "Rectangle : Point_départ=" + p1 + ", longueur=" + longueur + ", largeur=" + largeur + "";
	}

	@Override
	public double calcul_surface() {
		// TODO Auto-generated method stub
		return this.largeur*this.longueur;
	}

	@Override
	public double calcul_perimetre() {
		// TODO Auto-generated method stub
		return (this.largeur+this.longueur)*2;
	}

	@Override
	public void deplacer(int abscisse_translation, int ordonne_translation) {
		// TODO Auto-generated method stub
		this.p1.deplacer(abscisse_translation, ordonne_translation);
	}
	
	
	

}
