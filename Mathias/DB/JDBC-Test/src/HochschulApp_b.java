import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class HochschulApp_b {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("PW:");
		Connection conn = null;
		try {
			DriverManager.registerDriver(new oracle.jdbc.driver.OracleDriver());

			conn = DriverManager.getConnection("jdbc:oracle:thin:@10.0.107.20:1521:GBIR", "aiws1617012", sc.next());
			conn.setAutoCommit(false);
			String stmt1 = "select * from Dozent";
			Statement s1 = conn.createStatement();
			ResultSet rs1 = s1.executeQuery(stmt1);
			ausgeben(rs1, conn);
			conn.commit();
			sc.close();
			s1.close();
			rs1.close();

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
		} finally {
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public static void ausgeben(ResultSet rs, Connection conn) {
		String jerg1 = new String();
		try {
			ResultSetMetaData meta = rs.getMetaData();
			while (rs.next()) {
				for (int j = 1; j <= meta.getColumnCount(); j++) {
					jerg1 = jerg1 + rs.getString(j) + " ";
				}
				System.out.println(jerg1);
				jerg1 = "";
			}
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
}