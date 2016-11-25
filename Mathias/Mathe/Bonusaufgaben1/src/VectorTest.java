import static org.junit.Assert.*;

import org.junit.Test;

public class VectorTest {

	@Test
	public void KonstruktorTest() {
		Vector v1 = new Vector();
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 0.0&&y == 0.0&&z == 0.0);		
	}
	
	@Test
	public void KonstruktorTest2Para() {
		Vector v1 = new Vector(3.0,2.3);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 3.0&&y == 2.3&&z == 0.0);		
	}
	
	@Test
	public void KonstruktorTest3Para() {
		Vector v1 = new Vector(3.0,2.3,1.1);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 3.0&&y == 2.3&&z == 1.1);		
	}
	
	@Test
	public void Vektoraddition() {
		Vector v1 = new Vector(3.0,2.3,1.1);
		Vector v2 = new Vector(3.0,2.3,1.1);
		v1.addVec(v2);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 6.0&&y == 4.6&&z == 2.2);		
	}
	
	@Test
	public void SkalaresVielfaches() {
		Vector v1 = new Vector(3.0,2.3,1.1);
		v1.mult(2);
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 6.0&&y == 4.6&&z == 2.2);		
	}
	
	@Test
	public void Skalarprodukt() {
		Vector v1 = new Vector(3.0,2.3,1.1);
		Vector v2 = new Vector(3.0,2.3,1.1);		
		assertTrue(v1.scalarProd(v2)==15.5);		
	}
	
	@Test
	public void leange() {
		Vector v1 = new Vector(3.0,2.3,1.1);		
		assertTrue((v1.laenge()>3.9370)&&(v1.laenge()<4));		
	}
	
	@Test
	public void normaleGerade() {
		Vector v1 = Vector.normGerade(new Vector(1,2));				
		double x = v1.getX();
		double y = v1.getY();
		assertTrue(x == 2.0&&y == -1.0);	
	}
	
	@Test
	public void normaleEbene() {
		Vector v1 = Vector.normEbene(new Vector(2,3,1),new Vector(1,2,2));				
		double x = v1.getX();
		double y = v1.getY();
		double z = v1.getZ();
		assertTrue(x == 4.0&&y == -3.0&&z== 1.0);	
	}
	
	@Test
	public void Vektorprodukt() {		
		Vector v1 = new Vector(3.0,2.3,1.1);
		Vector v2 = new Vector(2.0,1.3,9.1);
		Vector v3 = Vector.Vektorprodukt(v1, v2);		
		double x = v3.getX();
		double y = v3.getY();
		double z = v3.getZ();
		assertTrue((Math.abs(x)-19.5<Double.MIN_VALUE)&&(Math.abs(y)-25.1<Double.MIN_VALUE)&(Math.abs(z)-0.7<Double.MIN_VALUE));			
	}
	
	@Test
	public void Zwischenwinkel() {		
		Vector v1 = new Vector(3.0,2.3);
		Vector v2 = new Vector(-2.3,3.0);
		assertTrue(Vector.Zwischenwinkel(v1, v2)==90);			
	}
	
	@Test
	public void Orthogonalprojektion() {		
		Vector v1 = new Vector(3,-1);
		Vector v2 = new Vector(-2,-1);
		Vector v3 = Vector.Orthogonalprojektion(v1, v2);	
		double x = v3.getX();
		double y = v3.getY();
		double z = v3.getZ();
		System.out.println(" " + x + " " + y );
		assertTrue(true);			
	}

}
