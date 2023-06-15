package vue;

import javafx.geometry.Insets;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import presentation.Principale;

import java.time.LocalDate;
import java.util.ArrayList;

import presentation.Consomation;

import javafx.beans.binding.*;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

public class FenListBarman extends Stage {
	static private ObservableList<Consomation> lesConso = FXCollections.observableArrayList();
	// les composants du formulaire
	private GridPane racine = new GridPane();
	private HBox zone = new HBox();
	
	private VBox Lzone = new VBox();
	private Label titre = new Label("Liste des consommations");
	private TableView<Consomation> tablePresta = new TableView<Consomation>();
	private Label trouve = new Label("14 préstations trouvées");
	
	private VBox Rzone = new VBox();
	private VBox radio = new VBox();
	private RadioButton b_conso = new RadioButton();
	private RadioButton b_dejeun = new RadioButton();
	private ToggleGroup group = new ToggleGroup();
	private Button b_ajouter = new Button();
	private Button b_modifier = new Button();
	private Button b_supprimer = new Button();
	
	private Button b_fermer = new Button();
	
	
	
	
	// constructeur : initialisation de la fenetre et des données
	public FenListBarman() {		
		this.setTitle("Détail employé");
		this.sizeToScene();
		this.setResizable(false);
		this.setScene(new Scene(creerContenu()));
	}
	
	private Parent creerContenu() {
		TableColumn<Consomation,Integer> colonne1 = new TableColumn<Consomation,Integer>("Type");
		colonne1.setCellValueFactory(new PropertyValueFactory<Consomation,Integer>("type"));	
		tablePresta.getColumns().add(colonne1);
		
		TableColumn<Consomation, String> colonne2 = new TableColumn<Consomation,String>("Libelle");
		colonne2.setCellValueFactory(new PropertyValueFactory<Consomation, String>("libelle"));
		tablePresta.getColumns().add(colonne2);
		
		TableColumn<Consomation, String> colonne3 = new TableColumn<Consomation,String>("Quantité");
		colonne3.setCellValueFactory(new PropertyValueFactory<Consomation, String>("quantite"));
		tablePresta.getColumns().add(colonne3)
		;
		TableColumn<Consomation,Integer> colonne4 = new TableColumn<Consomation,Integer>("Date");
		colonne4.setCellValueFactory(new PropertyValueFactory<Consomation, Integer>("date"));
		tablePresta.getColumns().add(colonne4);
				
		
		racine.getChildren().addAll(tablePresta);
		return racine;
	}
	
	public void init() {
		
	}
}
