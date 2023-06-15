package com.example.saefx;

import java.util.Calendar;

public abstract class Prestation {
	
	private int numChambre;
	private String type;
	private float montant;
	private Calendar date;
	
	public Prestation(int numChambre) {
		this.numChambre = numChambre;
		this.date = Calendar.getInstance();
	}

	public int getNumChambre() {
		return numChambre;
	}

	public String getType() {
		return type;
	}

	public float getMontant() {
		return montant;
	}

	public Calendar getDate() {
		return date;
	}
	
	public abstract void afficher();
	public abstract String toString();
}
