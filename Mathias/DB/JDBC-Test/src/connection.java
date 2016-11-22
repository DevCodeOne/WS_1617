import java.sql.*;
import java.io.*;


public class connection {


	public static void main (String args [ ]) throws SQLException, ClassNotFoundException, IOException {
		// Laden des Oracle JDBC driver
		DriverManager.registerDriver( new oracle.jdbc.driver.OracleDriver() );
		// Aufbau einer Verbindung:
		Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@10.0.107.20:1521:GBIR", "aiws1617012", "051283");
		// Erzeugen eines selects, das alle Personendaten aus der Tabelle Personentab selektiert und ausgibt:
		String stmt1 = "select doznr, vorname, name, geschlecht from Dozent";
		Statement s1 = conn.createStatement();
		ResultSet rs1 = s1.executeQuery (stmt1);
		String jerg1 = new String();
		while (rs1.next ()) {
			for (int i=1;i <= 4; i++) {
				jerg1 = jerg1 + rs1.getString(i) + " ";
			}
			System.out.println (jerg1);
			jerg1 = "";
		}
		s1.close();
		rs1.close();
		//conn. commit();
	}


}
