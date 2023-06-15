package com.example.saefx;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Scanner;

public class Barman {

	private ArrayList<Consomation> les_consos;
	private ArrayList<Petit_dej> les_petit_dejs;

	public Barman() {
		this.les_consos = new ArrayList<Consomation>();
		this.les_petit_dejs = new ArrayList<Petit_dej>();
	}

	public ArrayList<Consomation> getLes_consos() {
		return les_consos;
	}

	public ArrayList<Petit_dej> getLes_petit_dejs() {
		return les_petit_dejs;
	}
	
	public void EnregistrerConso(int chambre, String type, String libelle, int quantite) {
		Consomation c1 = new Consomation(chambre, type, libelle, quantite);
		les_consos.add(c1);
		c1.afficher();
	}
	
	public void EnregistrerPetitDej(int chambre, String type, String libelle, int quantite) {
		Petit_dej d1 = new Petit_dej(chambre, type, libelle, quantite);
		les_petit_dejs.add(d1);
		d1.afficher();
	}
	
	public void ModifierConso(int chambre, Calendar date, int quantite, String libelle) {
		for (Consomation c : les_consos) {
			if (c.getNumChambre() == chambre && c.getDate() == date) {
				if(quantite > 0) {
					c.setQuantite(quantite);
				}
				c.setLibelle(libelle);
				c.afficher();
			}
		}
	}
	
	public void ModifierPetitDej(int chambre, Calendar date, int quantite, String libelle) {
		for (Petit_dej c : les_petit_dejs) {
			if (c.getNumChambre() == chambre && c.getDate() == date) {
				if(quantite > 0) {
					c.setQuantite(quantite);
				}
				c.setLibelle(libelle);
				c.afficher();
			}
		}
	}

	public void SupprimerConso(int chambre, Calendar date) {
		for (Consomation c : les_consos) {
			if (c.getNumChambre() == chambre && c.getDate() == date) {
				les_consos.remove(c);
			}
		}
	}

	public void SupprimerTouteConso() {
		les_consos.clear();
	}

	public void SupprimerPetitDej(int chambre, Calendar date) {
		for (Petit_dej c : les_petit_dejs) {
			if (c.getNumChambre() == chambre && c.getDate() == date) {
				les_petit_dejs.remove(c);
			}
		}
	}

	public void SupprimerToutPetitDej() {
		les_petit_dejs.clear();
	}
	
}
