import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.Statement;
import java.util.Scanner;

public class HochschulApp_b {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		System.out.println("PW:");
		DriverManager.registerDriver( new oracle.jdbc.driver.OracleDriver() );
		Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@10.0.107.20:1521:GBIR", "aiws1617012", sc.next());
		String stmt1 = "select * from Dozent";
		Statement s1 = conn.createStatement();
		ResultSet rs1 = s1.executeQuery (stmt1);
		ausgeben(rs1);
		s1.close();
		rs1.close();		
	}

	public static void ausgeben(ResultSet rs) throws Exception{
		String jerg1 = new String();
		ResultSetMetaData meta = rs.getMetaData();
		while (rs.next()) {
			for (int j=1;j <= meta.getColumnCount(); j++) {
				jerg1 = jerg1 + rs.getString(j) + " ";
			}
			System.out.println (jerg1);
			jerg1 = "";
		}


	}
}