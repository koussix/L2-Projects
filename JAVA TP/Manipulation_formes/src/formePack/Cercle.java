package formePack;

public class Cercle extends Forme{
	private Point p1;
	private double rayon;
	
	public Cercle() {
		p1 = new Point();
		rayon = 0;
	}
	
	public Cercle(Point p1 , int rayon) {
		this.p1 = p1;
		this.rayon = rayon;
	}
	
	
	@Override
	public String toString() {
		return "Cercle : Centre=" + p1 + ", rayon=" + rayon + "";
	}

	@Override
	public double calcul_surface() {
		// TODO Auto-generated method stub
		
		return Math.PI*(rayon*rayon);
	}

	@Override
	public double calcul_perimetre() {
		// TODO Auto-generated method stub
		return 2*Math.PI*rayon;
	}

	@Override
	public void deplacer(int abscisse_translation, int ordonne_translation) {
		// TODO Auto-generated method stub
		this.p1.deplacer(abscisse_translation, ordonne_translation);
		
	}
	
	
}
