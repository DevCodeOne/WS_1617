import static org.junit.Assert.*;

import org.junit.Test;

public class VektorTest {

	@Test
	public void KonstruktorTest() {
		Vektor v1 = new Vektor();
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 0.0 && y == 0.0 && z == 0.0);
	}

	@Test
	public void KonstruktorTest2Para() {
		Vektor v1 = new Vektor(3.0, 2.3);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 3.0 && y == 2.3 && z == 0.0);
	}

	@Test
	public void KonstruktorTest3Para() {
		Vektor v1 = new Vektor(3.0, 2.3, 1.1);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 3.0 && y == 2.3 && z == 1.1);
	}

	@Test
	public void Vektoraddition() {
		Vektor v1 = new Vektor(3.0, 2.3, 1.1);
		Vektor v2 = new Vektor(3.0, 2.3, 1.1);
		v1.addVec(v2);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 6.0 && y == 4.6 && z == 2.2);
	}

	@Test
	public void SkalaresVielfaches() {
		Vektor v1 = new Vektor(3.0, 2.3, 1.1);
		v1.mult(2);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 6.0 && y == 4.6 && z == 2.2);
	}

	@Test
	public void Skalarprodukt() {
		Vektor v1 = new Vektor(3.0, 2.3, 1.1);
		Vektor v2 = new Vektor(3.0, 2.3, 1.1);
		assertTrue(v1.scalarProd(v2) == 15.5);
	}

	@Test
	public void leange() {
		Vektor v1 = new Vektor(3.0, 2.3, 1.1);
		assertTrue((v1.laenge() > 3.9370) && (v1.laenge() < 4));
	}

	@Test
	public void normaleGerade() {
		Vektor v1 = Vektor.normGerade(new Vektor(1, 2));
		double x = v1.getX();
		double y = v1.getY();
		assertTrue(x == 2.0 && y == -1.0);
	}

	@Test
	public void normaleEbene() {
		Vektor v1 = Vektor.normEbene(new Vektor(2, 3, 1), new Vektor(1, 2, 2));
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 4.0 && y == -3.0 && z == 1.0);
	}

	@Test
	public void Vektorprodukt() {
		Vektor v1 = new Vektor(3.0, 2.3, 1.1);
		Vektor v2 = new Vektor(2.0, 1.3, 9.1);
		Vektor v3 = Vektor.Vektorprodukt(v1, v2);
		double x = v3.getX();
		double y = v3.getY();
		double z = v3.getZ();
		assertTrue((Math.abs(x) - 19.5 < Double.MIN_VALUE)
				&& (Math.abs(y) - 25.1 < Double.MIN_VALUE) & (Math.abs(z) - 0.7 < Double.MIN_VALUE));
	}

	@Test
	public void Zwischenwinkel() {
		Vektor v1 = new Vektor(3.0, 2.3);
		Vektor v2 = new Vektor(-2.3, 3.0);
		assertTrue(Vektor.Zwischenwinkel(v1, v2) == 90);
	}

	@Test
	public void Orthogonalprojektion() {
		Vektor v1 = new Vektor(6, 2);
		Vektor v2 = new Vektor(3, -9);
		Vektor v3 = Vektor.Orthogonalprojektion(v1, v2);
		double x = v3.getX();
		double y = v3.getY();
		double z = v3.getZ();
		assertTrue(x == 0 && y == 0 && z == 0);
	}

}
