import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;


public class Dns {

	public static List<DnsItem> collectionDns = new ArrayList<>(); // de type static pour nous permettre d'y acceder et d'afficher son contenu modifié

	private Map <AdresseIP, NomMachine > mapDns ; //variable d'instance qui chargera notre base de données
	
	public Dns() {
		mapDns = new HashMap <>();
		chargement();	// on charge notre fichier dans notre structure mapDns
	}
	
	private void chargement(){ // une methode chargement pour evite d'ecrire trop de code dans le constructeur
		AdresseIP ip;
		NomMachine nm;
		List <String> fich = new ArrayList <String>();
		try {
	    	InputStream flux=new FileInputStream("Bdd.txt"); // on lit dans le fichier Bdd
	    	InputStreamReader lecture=new InputStreamReader(flux);
	    	BufferedReader buff=new BufferedReader(lecture);
	    	String ligne;
	    	while ((ligne=buff.readLine())!=null){
	    		//System.out.println(ligne);
	    		fich.add(ligne);
	    	}
	    	buff.close(); 
	    	}		
	    catch (Exception e){
	    	System.out.println(e.toString());
	    }
	    for ( String s : fich ) {
	    	int i=0;
    		String str1="";
    		String str2="";
    		while(s.charAt(i) != ' ') {
    			str1 +=s.charAt(i);
    			i++;
    		}
    		i++;
    		while(i!= s.length() ) {
    			str2 +=s.charAt(i);
    			i++;
    		}
    		ip = new AdresseIP(str1); // recuperation de notre AdresseIP
    		nm = new NomMachine(str2); //recuperation de notre NomMachine
    		this.mapDns.put(ip, nm); // insertion dans la map
    		//System.out.println(ip.getIP());
    		//System.out.println(nm.getNomMachine());
    		
	    }
	}
	
	public DnsItem getItem(AdresseIP ip) { //methode qui permet de retourne un Dnsitem si on saisi une AdresseIP
		
		//saisie errone de l'utilisateur
		if (ip.getIP().equals("0.0.0.0")) {
			System.out.println("Refaites votre saisie s'il vous plait");
			return new DnsItem();
		}
		
		//saisie accepte
		System.out.println("Parcours de notre base de donnees en cours..: ");
	    Set<Entry<AdresseIP, NomMachine>> setHm = mapDns.entrySet();
	    Iterator<Entry<AdresseIP, NomMachine>> it = setHm.iterator();
	    while(it.hasNext()){
	         Entry<AdresseIP, NomMachine> e = it.next();
	         if(  e.getKey().getIP().equals(ip.getIP()) ) {
		         //System.out.println("Ligne contenant votre IP : KEY =>"+e.getKey().getIP() + " VALUE => " + e.getValue().getNomMachine());
		         collectionDns.add(new DnsItem(e.getKey().getIP(), e.getValue().getNomMachine()));
		         return new DnsItem(e.getKey().getIP(), e.getValue().getNomMachine());
	         }
	    }
	    
		System.out.println("aucun objet ne correspond a votre recherche dans notre base de donnees "); //je prefere garder l'affichage ici pour ne pas encombrer la fonction afficher
		return new DnsItem();
	}
	
	public DnsItem getItem(NomMachine nm) {
		
		// saisi erroner de l'utilisateur
		if(nm.getNomMachine().equals("NAN.NAN.NAN")) {
			System.out.println("Refaites votre saisie s'il vous plait");
			return new DnsItem();
		}
		
		// saisie accepte
		System.out.println("Parcours de notre base de donnees en cours..: ");
	    Set<Entry<AdresseIP, NomMachine>> setHm = mapDns.entrySet();
	    Iterator<Entry<AdresseIP, NomMachine>> it = setHm.iterator();
	    while(it.hasNext()){
	         Entry<AdresseIP, NomMachine> e = it.next();
	         if(e.getValue().getNomMachine().equals(nm.getNomMachine())) {
		         //System.out.println("Ligne contenant votre NomMachine : KEY => "+e.getKey().getIP() + " VALUE => " + e.getValue().getNomMachine());
		         collectionDns.add(new DnsItem(e.getKey().getIP(), e.getValue().getNomMachine()));
		         return new DnsItem(e.getKey().getIP(), e.getValue().getNomMachine());
	         }
	    }
	    
		System.out.println("aucun objet ne correspond a votre recherche dans notre base de donnees"); //je prefere garder cet affichage ici pour ne pas encombrer la fonction afficher
		return new DnsItem();
		
	}
	
	public List<DnsItem> getItems (String nomDomaine){ //l'utilisateur a donc saisi 'ls ' ou 'ls -a'
		
		
		// traitement pour savoir si on a saisi un ls -a ou un ls
		boolean operation_tri = false ; // false voudra dire qu'on va trier selon l'ordre des nomMachine
		String parametre1= "";
		try {
			parametre1= nomDomaine.substring(0,6);
			if(parametre1.equals("ls -a ")) operation_tri= true ; //tri selon les ip
		}
		catch(StringIndexOutOfBoundsException e) {
			System.out.println("ERROR nomDomaine : Veuillez saisir un nom de domaine contenant au moins 2 mots");
			collectionDns.add(new DnsItem());
			return collectionDns;
		}

		if(operation_tri == true) {
			nomDomaine = nomDomaine.substring(6 , nomDomaine.length()); // on recupere alors la chaine qu'on chercher
			//System.out.println(nomDomaine);
		}
		else {
			nomDomaine = nomDomaine.substring(3, nomDomaine.length()); // on recupere alors la chaine qu'on chercher
			//System.out.println(nomDomaine);
		}
		//////////////////
		
		// debut du traitement 
		//List<DnsItem> collectionDns = new ArrayList<>();
		System.out.println("Parcours de notre base de donnees en cours : ");
	    Set<Entry<AdresseIP, NomMachine>> setHm = mapDns.entrySet();
	    Iterator<Entry<AdresseIP, NomMachine>> it = setHm.iterator();
	    while(it.hasNext()){
	         Entry<AdresseIP, NomMachine> e = it.next();
	         String NomMachine = e.getValue().getNomMachine();
	         String Domaine_tmp=""; // on doit récuperer le nom de domaine correspondant a la valeur contenu
	         int i =0 ;
	         while(NomMachine.charAt(i)!= '.') {
	        	 i++; // on cherche a virer le nom de la machine uniquement !!
	         }
	         i++; // pour skip le '.'
	         for (int j= i ; j <NomMachine.length() ; j++) {
	        	Domaine_tmp += NomMachine.charAt(j); // pour recuprer notre nom de domaine 
	         }
	         // une fois récupérer on compare alors avec le NomDomaine saisi !
	         if ( Domaine_tmp.equals(nomDomaine) ) { // on fait un print de notre ligne et on ajoute le resultat dans la liste
		         collectionDns.add(new DnsItem(e.getKey().getIP(), e.getValue().getNomMachine()));
	         }
	         
	    }
	    
	    
	   if(operation_tri == true) { 
		   System.out.println("Tri selon les IP : SELECTED ");
		   tri_selon_ip(collectionDns);
	   }
	   else {
		   System.out.println("Tri selon les NomMachine : SELECTED ");
		   tri_selon_nom(collectionDns);
	   }
	   
	   if(collectionDns.isEmpty()) {
	    	System.out.println("aucun objet ne correspond a votre saisi essayez 'ls chezmoi.fr' ou'ls -a chezmoi.fr' !"); // pour ne pas encombrer la fonction afficher !
	    }																						// sachant que je veux un autre affichage dans le cas ou c'est une adresseIP ou nomMachine qui a ete saisi
	   
	   
	    return collectionDns;
	
		
	}
	
	public void afficher(List<DnsItem> collectionDns) {
		if(!collectionDns.isEmpty()) {
		System.out.println("Le/Les les objets DnsItem correspondants : ");
		for(int i=0 ; i<collectionDns.size();i++) {
			   System.out.println("KEY ==> "+collectionDns.get(i).getIP().getIP() +" VALUE ==> " +collectionDns.get(i).getnomMachine().getNomMachine());
		   }
		}
		collectionDns.clear(); //on vide notre collection a chaque fois pour permettre d'afficher de nouveaux resultats
	}
	
	public void tri_selon_nom(List<DnsItem> collectionDns ){
		for(int i=0 ; i<collectionDns.size()-1;i++) {
	    	for (int j=i+1 ; j <collectionDns.size() ; j ++) {
	    		String nom1 = collectionDns.get(i).getnomMachine().getNomMachine() ;
	    		String nom2 = collectionDns.get(j).getnomMachine().getNomMachine() ;
	    		
	    		if(compare(nom1,nom2)==1) {
	    			DnsItem temp = collectionDns.get(i);
	    			collectionDns.set(i, collectionDns.get(j));
	    			collectionDns.set(j, temp);
	    		}
	    	}
	    }
		
		
	}
	public void tri_selon_ip(List<DnsItem> collectionDns ){
		for(int i=0 ; i<collectionDns.size()-1;i++) {
	    	for (int j=i+1 ; j <collectionDns.size() ; j ++) {
	    		String ip1 = collectionDns.get(i).getIP().getIP() ;
	    		String ip2 = collectionDns.get(j).getIP().getIP() ;
	    		
	    		if(compare(ip1,ip2)==1) {
	    			DnsItem temp = collectionDns.get(i);
	    			collectionDns.set(i, collectionDns.get(j));
	    			collectionDns.set(j, temp);
	    		}
	    	}
	    }
		
		
	}
	
	
	 public int compare(String  s1, String  s2) //comparaison de String selon l'ordre naturel en partant de gauche
     {
		 int max = (s1.length() > s2.length() ) ? s1.length() : s2.length() ;
         for (int i = 0 ; i < max ; i ++) {
        	 if(i > s1.length()) return -1;
        	 else if (i > s2.length()) return 1;
        	 
        	 if(s1.charAt(i) > s2.charAt(i)) return 1;
        	 else if(s1.charAt(i) < s2.charAt(i)) return -1;
         }
		 
         return 0;
     }
	public void quitter_application() {
		System.out.println("Le programme se ferme");
		System.exit(2);
	}
}
