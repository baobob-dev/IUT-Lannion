package com.example.saefx;

import java.util.Calendar;

public class Petit_dej extends Consomation {
	
	private Calendar date;

	public Petit_dej(int numChambre, String type, String libelle, int quantite) {
		super(numChambre, type, libelle, quantite);
		this.date = Calendar.getInstance();
	}

	public Calendar getDate() {
		return date;
	}
	
	

}
