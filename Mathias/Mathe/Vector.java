
public class Vector {

	private double x = 0, y = 0, z = 0;
	/**
	 * Standartkonstruktor ohne werte
	 */
	public Vector() {

	}

	/**
	 * Zwei dimensionaler Vector
	 * 
	 * @param x
	 *            X-Achse
	 * @param y
	 *            Y-Achse
	 */
	public Vector(double x, double y) {
		this.x = x;
		this.y =y;
	}

	/**
	 * Drei Dimensionaler Vector
	 * 
	 * @param x
	 *            X-Achse
	 * @param y
	 *            Y-Achse
	 * @param z
	 *            Z-Achse
	 */
	public Vector(double x, double y, double z) {
		this.x = x;
		this.y =y;
		this.z=z;
	}

	/**
	 * addiert Vector zu diesem(this) hinzu
	 * 
	 * @param v
	 *            zu addierender Vector
	 * @return this
	 */
	public Vector addVec(Vector v) {
		this.x += v.getX();
		this.y += v.getY();
		this.z += v.getZ();
		return this;
	}

	/**
	 * Skalares Vielfaches
	 * @param p 
	 * 		Skalar
	 * @return Vector
	 */

	public Vector mult(double p) {
		this.x *= p;
		this.y *= p;
		this.z *= p;
		return this;
	}

	/**
	 * Scalarprodukt zweier Vectoren (this und v)
	 * 
	 * @param v
	 *            Vector
	 * @return doublewert
	 */
	public double scalarProd(Vector v) {
		return (this.getX() * v.getX() + this.getY() * v.getY() + this.getZ() * v.getZ());
	}

	/**
	 * liefert die Normale des Vectors
	 * 
	 * @return Normale als double
	 */
	public double norm() {
		if (z<Double.MIN_VALUE)
			return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
		return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2) + Math.pow(z, 2));
	}

	/**
	 * Statische Methode für VektorProdukt/Kreuzprodukt
	 * @param v1 Vektor 1
	 * @param v2 Vektor 2
	 * @return Vektor 3
	 */

	public static Vector Vektorprodukt(Vector v1, Vector v2){
		Vector v3 = new Vector();
		v3.setX(v1.getY()*v2.getZ()-v1.getZ()*v2.getY());
		v3.setY(v1.getZ()*v2.getX()-v1.getX()*v2.getZ());
		v3.setZ(v1.getX()*v2.getY()-v1.getY()*v2.getX());
		return v3;
	}
	/**
	 * Liefert den Winkel zwischen zwei Vektoren
	 * @param v1 Vektor 1
	 * @param v2 Vektor 1
	 * @return Winkel dazwischen
	 */
	public static double Zwischenwinkel(Vector v1, Vector v2){
		return ((Math.acos(v1.scalarProd(v2)/(v1.norm()*v2.norm()))/(2*Math.PI))*360);
	}

	/**
	 * Orthogonalprojektion von v1 auf v2
	 * @param v1 
	 * @param v2
	 * @return vektor
	 */
	public static Vector Orthogonalprojektion(Vector v1, Vector v2){
		return v2.mult(v1.scalarProd(v2)/Math.pow(v2.norm(),2));

	}

	/**
	 * 
	 * @return x-Wert
	 */
	public double getX() {
		return x;
	}

	/**
	 * Setzt den x-Wert
	 * 
	 * @param x
	 *            x-Wert
	 */

	public void setX(double x) {
		this.x = x;
	}

	/**
	 * 
	 * @return y-Wert
	 */
	public double getY() {
		return y;
	}

	/**
	 * Setzt den y-Wert
	 * 
	 * @param y
	 *            y-Wert
	 */
	public void setY(double y) {
		this.y = y;
	}

	/**
	 * 
	 * @return z-Wert
	 */
	public double getZ() {
		return z;
	}

	/**
	 * Setzt den z-Wert
	 * 
	 * @param z
	 *            z-Wert
	 */
	public void setZ(double z) {
		this.z = z;
	}

}
