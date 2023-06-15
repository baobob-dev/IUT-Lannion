package com.example.saefx;

public class Pressing extends Prestation{

	private float montant;
	private String libelle;
	private String type;

	private int quantite;
	
	public Pressing(int numChambre, String libelle, int quantite) {
		super(numChambre);
		this.libelle = libelle;
		this.quantite = 1;
		this.type = "Pressing";
		this.montant = (float) 10.50;
	}

	public float getMontant() {
		return montant;
	}

	public String getLibelle() {
		return libelle;
	}

	public String getType() {
		return type;
	}

	public void setQuantite(int quantite) {
		this.quantite = quantite;
	}

	public void setLibelle(String libelle) {
		this.libelle = libelle;
	}

	@Override
	public void afficher() {
		System.out.println("Date : "+this.getDate()+"\n"+
							"Type : "+this.type+"\n"+
							"Libellé : "+this.libelle+"\n"+
							"Montant : "+this.montant);
		
	}

	@Override
	public String toString() {
		return "Date : "+this.getDate()+"\n"+
				"Type : "+this.type+"\n"+
				"Libellé : "+this.libelle+"\n"+
				"Montant Hors Taxe : "+this.montant;
	}

	public static void main(String[] args) {
		Pressing b = new Pressing(1, "Chemise", 1);
		b.afficher();
	}
	
}
