package presentation;

import javafx.application.Application;
import javafx.stage.Stage;
import vue.FenListBarman;

public class Principale extends Application{
	static private FenListBarman fListBar = new FenListBarman();
	
	public void start(Stage f) throws Exception {
		fListBar.show();
	} 
	
	static public void main(String[] args) { 
		Application.launch(args); 
	}
}
