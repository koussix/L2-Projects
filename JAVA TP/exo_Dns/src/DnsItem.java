public class DnsItem {
	
	private AdresseIP adresseIp;
	private NomMachine nomMachine;
	
	
	public DnsItem() { //item par defaut
		this.adresseIp = new AdresseIP("0.0.0.0");
		this.nomMachine= new NomMachine("NAN.NAN.NAN");
	}
	
	public DnsItem(String adresseIp , String nomMachine) {
		this.adresseIp =new AdresseIP(adresseIp);
		this.nomMachine =new NomMachine(nomMachine);
	}
	
	public AdresseIP getIP() {//getter d'IP
		return this.adresseIp;
	}
	
	public NomMachine getnomMachine() {//getter de NomMachine
		return this.nomMachine;
	}
	
	
}
