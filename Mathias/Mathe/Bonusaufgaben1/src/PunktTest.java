import static org.junit.Assert.*;

import org.junit.Test;

public class PunktTest {

	@Test
	public void KonstruktorTest() {
		Punkt p1 = new Punkt();
		double x = p1.getxKoord();
		double y = p1.getyKoord();
		double z = p1.getzKoord();
		assertTrue(x == 0.0 && y == 0.0 && z == 0.0);
	}

	@Test
	public void KonstruktorTest2Para() {
		Punkt p1 = new Punkt(3.0, 2.3);
		double x = p1.getxKoord();
		double y = p1.getyKoord();
		double z = p1.getzKoord();
		assertTrue(x == 3.0 && y == 2.3 && z == 0.0);
	}

	@Test
	public void KonstruktorTest3Para() {
		Punkt p1 = new Punkt(3.0, 2.3, 1.1);
		double x = p1.getxKoord();
		double y = p1.getyKoord();
		double z = p1.getzKoord();
		assertTrue(x == 3.0 && y == 2.3 && z == 1.1);
	}

	@Test
	public void Distancetest() {
		Punkt p1 = new Punkt(2.0, 5.0);
		Punkt p2 = new Punkt(4.0, 5.0);
		assertTrue(Punkt.dist(p1, p2) == 2.0);
	}
}
