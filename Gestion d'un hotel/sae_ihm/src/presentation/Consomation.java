package presentation;

import java.util.Calendar;

public class Consomation {
	
	private int numChambre;
	private String type;
	private String libelle;
	private int quantite;
	private Calendar date;
	
	public Consomation(int numChambre, String type, String libelle, int quantite) {
		this.numChambre = numChambre;
		this.type = type;
		this.libelle = libelle;
		this.quantite = quantite;
		this.date = Calendar.getInstance();
	}

	public int getNumChambre() {
		return numChambre;
	}

	public String getType() {
		return type;
	}

	public String getLibelle() {
		return libelle;
	}

	public int getQuantite() {
		return quantite;
	}

	public void setQuantite(int quantite) {
		this.quantite = quantite;
	}

	public void setLibelle(String libelle) {
		this.libelle = libelle;
	}

	public Calendar getDate() {
		return date;
	}
	
	public void afficher() {
		System.out.println("numero Chambre : "+this.numChambre+"\n"+
				"type : "+this.type+"\n"+
				"libelle : "+this.libelle+"\n"+
				"quantité : "+this.quantite+"\n"+
				"date : "+this.date+"\n");
	}

	@Override
	public String toString() {
		return "numero Chambre : "+this.numChambre+"\n"+
				"type : "+this.type+"\n"+
				"libelle : "+this.libelle+"\n"+
				"quantité : "+this.quantite+"\n"+
				"date : "+this.date+"\n";
	}
	
	
}
