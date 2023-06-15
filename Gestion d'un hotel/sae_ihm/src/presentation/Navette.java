package com.example.saefx;

public class Navette extends Prestation {
	
	private float montant;
	private String type;

	public Navette(int numChambre) {
		super(numChambre);
		this.montant = (float) 9.99;
		this.type = "Navette";
	}

	public void setMontant(float montant) {
		this.montant = montant;
	}

	public void setType(String type) {
		this.type = type;
	}

	public float getMontant() {
		return montant;
	}

	public String getType() {
		return type;
	}

	@Override
	public void afficher() {
		System.out.println("Date : "+this.getDate()+"\n"+
							"Type : "+this.type+"\n"+
							"Montant : "+this.montant);		
	}

	@Override
	public String toString() {
		return "Date : "+this.getDate()+"\n"+
				"Type : "+this.type+"\n"+
				"Montant : "+this.montant;
	}
	
}
