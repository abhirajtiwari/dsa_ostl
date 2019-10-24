import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.event.*;
import javafx.geometry.*;
public class week102 extends Application
{
public static void main(String[] args)
{
launch(args);
}
public void start(Stage myStage)
{
myStage.setTitle("Week 10 Question 2");
FlowPane root = new FlowPane(10 , 10);
root.setAlignment(Pos.CENTER);
root.setOrientation(Orientation.VERTICAL);
Scene myScene = new Scene(root , 500 , 300);

Label Result = new Label("");
TextField tf = new TextField("Enter the number");
Button btn=new Button("Enter");

btn.setOnAction(new EventHandler<ActionEvent>()
{
public void handle(ActionEvent e)
{
String r="\n";
int t = Integer.parseInt(tf.getText());
for (int i = 1 ; i <=10 ; i++)

	r +=t+"*"+i+"="+(i*t)+"\n" ; 

Result.setText(r);

}
});
root.getChildren().addAll(tf,btn);
root.getChildren().add(Result);
myStage.setScene(myScene);
myStage.show();
}
}