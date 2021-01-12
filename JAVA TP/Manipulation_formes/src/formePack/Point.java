package formePack;

public class Point {
	private int abscice;
	private int ordonne;
	
	public Point() {
		abscice= 0 ;
		ordonne = 0;
	}
	public Point(int x , int y ) {
		this.abscice = x;
		this.ordonne = y;
	}
	public int getAbscice() {
		return abscice;
	}
	public void setAbscice(int abscice) {
		this.abscice = abscice;
	}
	public int getOrdonne() {
		return ordonne;
	}
	public void setOrdonne(int ordonne) {
		this.ordonne = ordonne;
	}
	
	public void deplacer( int abs_decale , int ord_decale ) {
		this.abscice += abs_decale;
		this.ordonne += ord_decale;
	}
	@Override
	public String toString() {
		return "Point [abscice=" + abscice + ", ordonne=" + ordonne + "]";
	}
	
	
}
