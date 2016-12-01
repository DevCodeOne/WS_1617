import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class HochschulApp_a {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("PW:");
		Connection conn=null;
		try {			
			DriverManager.registerDriver( new oracle.jdbc.driver.OracleDriver() );
			conn = DriverManager.getConnection("jdbc:oracle:thin:@10.0.107.20:1521:GBIR", "aiws1617012", sc.next());
			conn.setAutoCommit(false);
			String stmt1 = "select * from Dozent";
			Statement s1 = conn.createStatement();
			ResultSet rs1 = s1.executeQuery (stmt1);
			String jerg1 = new String();
			while (rs1.next ()) {
				for (int i=1;i <= rs1.getMetaData().getColumnCount(); i++) {
					jerg1 = jerg1 + rs1.getString(i) + " ";
				}
				System.out.println (jerg1);
				jerg1 = "";
			}
			conn.commit();
			s1.close();
			rs1.close();
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			try{
				conn.rollback();
			} catch (SQLException ex) {
				// TODO Auto-generated catch block
				ex.printStackTrace();
			}
		}
		//conn. commit();
	}
	
	

}
