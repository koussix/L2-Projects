
public class AdresseIP {
	private String ip ; //tyoe de base String pris dans la bdd
	
	public AdresseIP(String ip) {
		if(check_ip(ip)==true ) //on verifie que c bien une IP
			this.ip = ip;
		else
			this.ip ="0.0.0.0"; //cas d'erreur on fait une instance "vide"
	}
	
	public String getIP() {
		return ip;
	}
	
	public boolean check_ip(String ip) {
		boolean bool= true;
		int nb_points=0;
		String tmp ="";
		for (int i=0 ; i< ip.length();i++) {
			if(ip.charAt(i)=='.') {
				nb_points ++;
				tmp ="";
			}else {
				tmp +=ip.charAt(i);
				if( isNumeric(tmp)==false) {
					System.out.println("ERROR IP : format non accepte exp forme -> 192.168.1.1 ");
					return bool=false;
					//System.exit(1);
				}
				else {
					if((Integer.parseInt(tmp)<0) || (Integer.parseInt(tmp)>255)){
						System.out.println("ERROR IP : format errone, exp forme -> 0.0.0.0 -> 255.255.255.255 ");
						return bool = false;
					}
				}
			}
			
		}
		if (nb_points != 3 ) {
			bool= false;
			System.out.println("ERROR IP : format errone, exp forme -> 192.168.1.1");
			//System.exit(1);
		}
		
		return bool;
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
