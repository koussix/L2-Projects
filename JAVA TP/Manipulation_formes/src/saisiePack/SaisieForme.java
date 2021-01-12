package saisiePack;
import formePack.*;
import exceptionPack.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;
import java.util.Vector;

//cette class contient la plupart des fonction dont nous aurons besoin pour l'interaction
//avec l'utilisateur

public class SaisieForme {
	private List< Forme > collectionForme;
	private Scanner sc;
	
	public SaisieForme() {
		collectionForme = new ArrayList<Forme>();
		sc = new Scanner(System.in);
	}
	
	public void saisir() throws ErreurSaisieException {
		System.out.println(" Trois choix de traitement s'offrent à vous, "
			+"\n 1-Saisir element\n 2-Traitement ensemble(tout les objets)\n 3-Traitement sur des objets déja existants\n"
			+ "\nVeuillez saisir le numero correspondant à votre demande ! :");
		int choix = saisieIntSecure();
		if(choix == 1) {
			try {
				saisirElement(); 
			}catch (ErreurSaisieException e) {
				e.getMessage();
			}
		}
		else if (choix == 2) {
			try {
				saisirOperationForme();
			} catch (InexistantException e) {
				// TODO Auto-generated catch block
				e.getMessage();
			}
		}
		else if (choix == 3) {
			try {
				Traitement();
			} catch (InexistantException e) {
				// TODO Auto-generated catch block
				e.getMessage();
			}
		}
		else
			throw new ErreurSaisieException();
		
	}
	
	public void saisirOperationForme() throws InexistantException {
		if(collectionForme.isEmpty()) {
			throw new InexistantException();
			//System.out.println("La liste est vide veuillez d'abord ajouter des objets");
			//return ;
		}
		try {
			Traitement(collectionForme);
		} catch (ErreurSaisieException e) {
			// TODO Auto-generated catch block
			e.getMessage();
		}
	}
	
	public void saisirElement() throws ErreurSaisieException {
		System.out.println("\nSaisir le numero de la forme que vous voulez ajouter "
				+"\n 1.Carre  2.Rectangle  3.Cercle  4.Triangle");
			int choix = saisieIntSecure();
			switch(choix) {
			case 1:
				saisirCarre(); break ;
			case 2: 
				saisirRectangle(); break;
			case 3:
				saisirCercle(); break;
			case 4:
				saisirTriangle(); break;
			default:
				throw new ErreurSaisieException();
			}
	}

	private void saisirCercle() {
		
		System.out.println("\nUn cercle a besoin d'un point et d'un rayon !");
		System.out.println("Saisir les coordonnés du point");
		Point p1 = saisirPoint();
		System.out.println("Saisir la taille du rayon ");
		System.out.print("Rayon =");
		int rayon = saisieIntSecure();
		
		Forme c1 = new Cercle(p1,rayon);
		System.out.println("Votre cercle :[ "+c1+" ]");
		Interagir(c1);
		
	}
	
	private void saisirTriangle() {
		
		System.out.println("\nUn triangle a besoin de 3 points");
		System.out.println("Saisir les coordonnés du point 1");
		Point p1 = saisirPoint();
		System.out.println("Saisir les coordonnés du point 2");
		Point p2 = saisirPoint();
		System.out.println("Saisir les coordonnés du point 3");
		Point p3 = saisirPoint();
		
		Forme t1 = new Triangle(p1 ,p2 ,p3);
		System.out.println("Le triangle saisi: ["+t1+" ]");
		Interagir(t1);
		
	}
	
	private void saisirRectangle() {
		
		System.out.println("\nUn rectangle un besoin d'un point (bas gauche dans notre implementation)"
				+ "et d'un taille et d'une largeur");
		System.out.println("Saisir les coordonnés du point");
		Point p1 = saisirPoint();
		System.out.print("Saisir la longueur = ");
		int longueur = saisieIntSecure();
		System.out.print("Saisir la largeur = ");
		int largeur = saisieIntSecure();
		
		Forme r1 = new Rectangle(p1, longueur , largeur);
		System.out.println("Votre rectangle :[ "+r1+ " ]");
		Interagir(r1);
	}

	private void saisirCarre() {
		System.out.println("\nUn carré a besoin d'un point (bas gauche dans notre implementation) "
				+ "et d'une taille de coté");
		System.out.println("Saisir les coordonnés du point");
		Point p1 = saisirPoint();
		System.out.print("Saisir taille coté = ");
		int taille = saisieIntSecure();
		
		Forme c1 = new Carre(p1 , taille);
		System.out.println("Votre carré : ["+c1 +" ]");
		Interagir(c1);
	}
	
	
	private Point saisirPoint() {
		
		System.out.print("Abscisse = ");
		int abs = saisieIntSecure();
		System.out.print("Ordonnes = ");
		int ord = saisieIntSecure();
		
		return new Point(abs , ord);
	}
	
	private void Interagir(Forme f1) {
		// fonction qui se charge de l'interarction logiciel/client
		String str ="";
		System.out.println("\nVoulez vous appliqué un traitement spécifique ou ajouter votre cercle à la liste des forme");
		int choix;
		do {	
			System.out.println("1. Traitement unique  2. Ajouter à la liste des formes  3. Ne rien faire ");
			choix = saisieIntSecure();
			if(choix != 3) {
				if(choix == 1) {
					try {
						Traitement(f1);
					} catch (ErreurSaisieException e) {
						// TODO Auto-generated catch block
						e.getMessage();
					}
				}
				if(choix ==2) {
					collectionForme.add(f1);
				}
				System.out.println("\nVoulez vous continuer votre traitement sur le meme objet ?");
				System.out.println("Saisir le numero correspondant : 1-Oui  2-Non");
				choix = saisieIntSecure();
			}		
		}while(choix == 1);
	}
	
	public void Traitement() throws InexistantException {
	// la fonction appelé quand l'utilisateur choisi l'option traitement spécifique sur des objets a choisir	
		if(collectionForme.isEmpty()) {
			throw new InexistantException();
			//System.out.println("La liste est vide veuillez ajouter des elements avant de choisir cette option");
			//return;
		}
		
		System.out.println("\nLa liste des objets déja contenu est celle ci :");
		afficher_liste();
		System.out.println("\nSaisir le/les numero des objets que vous voulez traiter ( saisir -1 pour aretter la saisie ) :");
		
		Vector<Integer> aTraiter = new Stack<Integer>(); //pile d'entiers
		int x = 0;
		
		do {
			x =saisieIntSecure();
			if(x < collectionForme.size() && x>= 0)
				aTraiter.add(x);  // on ajoute a notre liste
			else if(x != -1)
				System.out.println("Veuillez saisir un numero entre 0 et"+(collectionForme.size()-1));
			
		}while(x!= -1);
		
		
		while(!aTraiter.isEmpty()) {
			int actuel = (int)aTraiter.firstElement();
			aTraiter.remove(aTraiter.firstElement());
			int i = 0;
			for( Forme e : collectionForme ) {
				if (i == actuel) {
					System.out.println("L'element "+ i +" a traité :"+e );
					try {
						Traitement(e);
					} catch (ErreurSaisieException e1) {
						// TODO Auto-generated catch block
						e1.getMessage();
					}
				}
				i++;
			}
		}
		
		
		
	}
	
	public void Traitement(List<Forme> collectionForme) throws ErreurSaisieException{
		// si l'utilisateur choisi un traitement sur la liste ça sera la fonction a appeler
		System.out.println("Vous avez la possibilité de faire subir un traitement à votre liste d'elements"
				+ "que vous avez rempli, choisissez le numero correspondant à votre requete"
				+ "\n 1-Deplacer_elements \n 2-Calcul_Perimetre \n 3-Calcul_Surface\n ");
		int choix = saisieIntSecure();
		switch(choix) {
		case 1:
			System.out.println("Saisir les coordonnés de translation");
			System.out.print("Abscisse_translation =");
			int abs = saisieIntSecure();
			System.out.print("Ordonne_translation =");
			int ord = saisieIntSecure();
			System.out.println("Voici votre liste d'element à jour :");
			for(Forme e : collectionForme) {
				e.deplacer(abs, ord);
				System.out.println(e);
			}
			break;	
		case 2:
			for(Forme e : collectionForme) {
				System.out.println("\nL'element : "+e+"\n Perimetre ="+e.calcul_perimetre());
			}
			break;
		case 3:
			for(Forme e : collectionForme) {
				System.out.println("\nL'element : "+e+"\n Surface ="+e.calcul_perimetre());
			}
			break;
		default:
			//System.out.println("Erreur de saisie");
			throw new ErreurSaisieException();
		}	
			
	}
	
	public void Traitement(Forme f1) throws ErreurSaisieException{
		//La fonction qui se chargera de l'interaction une fois la forme créé
		System.out.println("\nOn dispose de 3 operation saisir le numero correspondant a votre requete\n"
				+ "1. Deplacer \n 2.Calul perimetre \n 3.Calcul surface ");
		int choix = saisieIntSecure();
		switch(choix) {
		case 1:
			System.out.println("Saisir les coordonnés de translation");
			System.out.print("Abscisse_translation =");
			int abs = saisieIntSecure();
			System.out.print("Ordonne_translation =");
			int ord =saisieIntSecure();
			f1.deplacer(abs, ord);
			System.out.println("Les coordonnees ont été mise à jour "+f1);
			break;
		case 2:
			System.out.println("le perimetre = "+f1.calcul_perimetre());
			break;
		case 3:
			System.out.println("la surface = "+f1.calcul_surface());
			break;
		default:
			//System.out.println("Erreur saisie");
			//break;
			throw new ErreurSaisieException();

		}
		
	}
	
	public void afficher_liste() {
		int i = 0 ;
		for (Forme e : collectionForme) {
			System.out.println("Elem "+i+" :"+e);
			i++;
		}
	}
	
	public int saisieIntSecure() {
		// si l'utilsateur saisie autre chose qu'un num alors l'exception de saisie
		//sera traité ( la saisie secure que j'ai mit au point consiste à recupéré un String sur
		//lequel je fais un traitement particulier
		
		boolean bool = true ;
		int x;
		String res="";
		do {
			x = 0;
			res = sc.next();
			bool = isNumeric(res);
			
			if(bool == true)
				x = (int) Double.parseDouble(res);
			else
				System.out.println("Erreur Veuillez refaire votre saisie : ");
			
		}while (bool!= true);
		
		return x ;
	}
	
	public static boolean isNumeric(String strNum) {
	    if (strNum == null) {
	        return false;
	    }
	    try {
	        double d = Double.parseDouble(strNum);
	    } catch (NumberFormatException nfe) {
	        return false;
	    }
	    return true;
	}
	
}

