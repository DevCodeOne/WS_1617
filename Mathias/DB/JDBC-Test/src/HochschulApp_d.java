import java.sql.*;
import java.util.Scanner;

public class HochschulApp_d {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {

		System.out.println("PW:");
		Connection conn = null;
		try {
			DriverManager.registerDriver(new oracle.jdbc.driver.OracleDriver());
			conn = DriverManager.getConnection("jdbc:oracle:thin:@10.0.107.20:1521:GBIR", "aiws1617012", sc.nextLine());

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
		ResultSetMetaData meta;
		meta = rs.getMetaData();
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
		ResultSet rs1 = null;
		System.out.println("MENÜ");
		System.out.println("1. Dozenten anzeigen");
		System.out.println("2. Studenten anzeigen");
		System.out.println("3. Veranstaltungen anzeigen");
		System.out.println("4. Datensatz Dozent hinzufügen");
		System.out.println("0. Beenden");

		while (true) {
			System.out.println("Ihre Eingabe:");
			switch (Integer.parseInt(sc.nextLine())) {
			case 0: {
				s1.close();
				sc.close();
				rs1.close();
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
			case 4: {
				stmt1 = "insert into dozent (name,vorname,gebdat,geschlecht,buero,telnr,email,einstelldatum,fachgebiet,fbnr) values (?,?,?,?,?,?,?,?,?,?)";
				PreparedStatement ps1 = conn.prepareStatement(stmt1);
				System.out.print("Name: ");
				ps1.setString(1, sc.nextLine());
				System.out.print("\nVorname: ");
				ps1.setString(2, sc.nextLine());
				System.out.print("\nGeburtsdatum (Format dd.mm.yyyy): ");
				ps1.setString(3, sc.nextLine());
				System.out.print("\nGeschlecht (M oder W): ");
				ps1.setString(4, sc.nextLine());
				System.out.print("\nBueronummer: ");
				ps1.setString(5, sc.nextLine());
				System.out.print("\nTelefonnummer: ");
				ps1.setString(6, sc.nextLine());
				System.out.print("\nE-Mail: ");
				ps1.setString(7, sc.nextLine());
				System.out.print("\nEinstelldatum (Format dd.mm.yyyy): ");
				ps1.setString(8, sc.nextLine());
				System.out.print("\nFachgebiet: ");
				ps1.setString(9, sc.nextLine());
				System.out.print("\nNr des Fachbereichs: ");
				rs1 = s1.executeQuery("select * from Fachbereich");
				ausgeben(rs1);
				ps1.setInt(10, Integer.parseInt(sc.nextLine()));

				// ,einstelldatum DATE, fachgebiet VARCHAR(30), fachbereich
				// VARCHAR(30)
				System.out.println("Zeilen wurden geändert:" + ps1.executeUpdate());
				conn.commit();
				break;
			}
			default: {
				System.out.println("falsche eingabe!");
			}
			}
			
		}
	}
}
