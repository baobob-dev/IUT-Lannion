import java.util.ArrayList;
import java.util.Calendar;
import java.util.Scanner;

public class Accueil {

	private ArrayList<Navette> les_navettes;
	private ArrayList<Pressing> les_pressings;

	public Accueil() {
		this.les_navettes = new ArrayList<Navette>();
		this.les_pressings = new ArrayList<Pressing>();
	}
	
	public ArrayList<Navette> getLes_navettes() {
		return les_navettes;
	}

	public ArrayList<Pressing> getLes_pressings() {
		return les_pressings;
	}

	public void EnregistrerPressing(int chambre, String libelle) {
		Pressing p1 = new Pressing(chambre, libelle, 1);
		les_pressings.add(p1);
		p1.afficher();
	}
	
	public void EnregistrerNavette(int chambre) {
		Navette n1 = new Navette(chambre);
		n1.afficher();
		les_navettes.add(n1);
	}
	
	public void ModifierNavette(int chambre, Calendar date, String type, int montant) {
		for (Navette n : les_navettes) {
			if (n.getNumChambre() == chambre && n.getDate() == date) {
				n.setType(type);
				if(montant > 0) {
					n.setMontant(montant);
				}
				n.afficher();
			}
		}
	}

	public void ModifierPressing(int chambre, Calendar date, String libelle, int quantite) {
		for (Pressing n : les_pressings) {
			if (n.getNumChambre() == chambre && n.getDate() == date) {
				if(quantite > 0) {
					n.setQuantite(quantite);
				}
				n.setLibelle(libelle);
				n.afficher();
			}
		}
	}

	public void SupprimerNavette(int chambre, Calendar date) {
		for (Navette n : les_navettes) {
			if (n.getNumChambre() == chambre && n.getDate() == date) {
				les_navettes.remove(n);
			}
		}
	}

	public void SupprimerPressing(int chambre, Calendar date) {
		for (Pressing n : les_pressings) {
			if (n.getNumChambre() == chambre && n.getDate() == date) {
				les_pressings.remove(n);
			}
		}
	}

	public void SupprimerTouteNavette() {
		les_navettes.clear();
	}

	public void SupprimerToutPressing() {
		les_pressings.clear();
	}

	public void SupprimerPrestation() {

	}

	public void afficher() {
		System.out.println("Les navettes : ");
		for (Navette n : les_navettes) {
			n.afficher();
		}
		System.out.println("Les pressings : ");
		for (Pressing p : les_pressings) {
			p.afficher();
		}
	}

	public static void main(String[] args) {
		Accueil a = new Accueil();
		Navette n1 = new Navette(1);
		Navette n2 = new Navette(2);
		Pressing p1 = new Pressing(1, "chemise", 1);
		Pressing p2 = new Pressing(2, "pantalon", 1);
		a.afficher();
		a.EnregistrerNavette(n2.getNumChambre());
		a.EnregistrerNavette(n1.getNumChambre());
		a.afficher();
		a.EnregistrerPressing(p1.getNumChambre(), p1.getLibelle());
		a.EnregistrerPressing(p2.getNumChambre(), p2.getLibelle());
		a.afficher();
	}
}
