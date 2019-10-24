import javafx.application.*;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.paint.Color;
import javafx.event.*;
public class week101 extends Application
{
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage mystage)
	{
		mystage.setTitle("Week 10 Question 1");
		FlowPane rootNode=new FlowPane(100,100);
		Scene myscene=new Scene(rootNode,500,200);
		Label mylabel=new Label();
		mylabel.setText("Welcome to JavaFx Progragmming");
		mylabel.setTextFill(Color.MAGENTA);
		rootNode.getChildren().add(mylabel);
		mystage.setScene(myscene);
		mystage.show();
	}
}

	
