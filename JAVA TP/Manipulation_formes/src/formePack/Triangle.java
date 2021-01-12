package formePack;

public class Triangle extends Forme{
	Point p1;
	Point p2;
	Point p3;
	
	public Triangle() {
		p1 = new Point();
		p2 = new Point();
		p3 = new Point();
	}
	
	public Triangle(Point p1, Point p2, Point p3) {
		
		this.p1 = p1;
		this.p2 = p2;
		this.p3 = p3;
	}
	
	@Override
	public String toString() {
		return "Triangle [p1=" + p1 + ", p2=" + p2 + ", p3=" + p3 + "]";
	}


	private int getHauteur() {
		int min_ord = Math.min(Math.min(p1.getOrdonne(), p2.getOrdonne()), p3.getOrdonne());
		int max_ord = Math.max(Math.max(p1.getOrdonne(), p2.getOrdonne()), p3.getOrdonne());
		
		return max_ord - min_ord ;
	}
	
	private int getBase() {
		int min_abs = Math.min(Math.min(p1.getAbscice(), p2.getAbscice()), p3.getAbscice());
		int max_abs = Math.max(Math.max(p1.getAbscice(), p2.getAbscice()), p3.getAbscice());
		
		return max_abs - min_abs;
		
	}


	private double taille_cote( Point p1 , Point p2 ) {
		
		return Math.sqrt(Math.pow(2, p1.getAbscice() - p2.getAbscice())+
						 Math.pow(2, p1.getOrdonne()-p2.getOrdonne()) );
	}


	@Override
	public double calcul_surface() {
		// TODO Auto-generated method stub
		System.out.println("Hauteur = "+getHauteur()+" Base = "+getBase());
		return (double)(getHauteur()*getBase()) / 2;
	}


	@Override
	public double calcul_perimetre() {
		// TODO Auto-generated method stub
		return taille_cote(this.p1,this.p2)+taille_cote(this.p2,this.p3)+taille_cote(this.p3,this.p1);
		
	}


	@Override
	public void deplacer(int abscisse_translation, int ordonne_translation) {
		
		this.p1.deplacer(abscisse_translation, ordonne_translation);
		this.p2.deplacer(abscisse_translation, ordonne_translation);
		this.p3.deplacer(abscisse_translation, ordonne_translation);
		
	}
	
}
