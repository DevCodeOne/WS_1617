import java.sql.*;
import java.util.Scanner;

public class HochschulApp_c {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println("PW:");
		Connection conn = null;
		try {
			DriverManager.registerDriver(new oracle.jdbc.driver.OracleDriver());

			conn = DriverManager.getConnection("jdbc:oracle:thin:@10.0.107.20:1521:GBIR", "aiws1617012", sc.next());
			conn.setAutoCommit(false);
			abfrage(conn);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			try {
				conn.rollback();
				conn.close();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}

	}

	public static void ausgeben(ResultSet rs) throws SQLException {
		String jerg1 = new String();
		ResultSetMetaData meta = rs.getMetaData();
		while (rs.next()) {
			for (int j = 1; j <= meta.getColumnCount(); j++) {
				jerg1 = jerg1 + rs.getString(j) + " ";
			}
			System.out.println(jerg1);
			jerg1 = "";
		}

	}

	public static void abfrage(Connection conn) throws SQLException {
		Statement s1 = conn.createStatement();
		String stmt1 = "";
		ResultSet rs1;
		System.out.println("MENÜ");
		System.out.println("1. Dozenten anzeigen");
		System.out.println("2. Studenten anzeigen");
		System.out.println("3. Veranstaltungen anzeigen");
		System.out.println("0. Beenden");

		while (true) {
			System.out.println("Ihre Eingabe:");
			switch (sc.nextInt()) {
			case 0: {
				s1.close();
				sc.close();
				System.exit(0);
			}
			case 1: {
				stmt1 = "select * from Dozent";
				rs1 = s1.executeQuery(stmt1);
				ausgeben(rs1);
				conn.commit();
				break;
			}
			case 2: {
				stmt1 = "select * from Student";
				rs1 = s1.executeQuery(stmt1);
				ausgeben(rs1);
				conn.commit();
				break;
			}
			case 3: {
				stmt1 = "select * from Veranstaltung natural join studiengang";
				rs1 = s1.executeQuery(stmt1);
				ausgeben(rs1);
				conn.commit();
				break;
			}

			default: {
				System.out.println("falsche eingabe!");
				continue;
			}
			}

			rs1.close();
		}

	}
}
