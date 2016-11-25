
public class Punkt {
	private double xKoord;
	private double yKoord;
	private double zKoord;

	/**
	 * Leerer Standartkonstuktor
	 */
	public Punkt(){
		xKoord = 0;
		yKoord = 0;
		zKoord = 0;
	}

	/**
	 * Konstruktor zur Erstellung eines Punktes in der Ebene
	 * @param x X-Koordinate
	 * @param y Y-Koordinate
	 */
	public Punkt(double x, double y){
		xKoord = x;
		yKoord = y;
		zKoord = 0;
	}

	/**
	 * Konstruktor zu Erstellung eines Punktes im Raum
	 * @param x
	 * @param y
	 * @param z
	 */
	public Punkt(double x, double y, double z){
		xKoord = x;
		yKoord = y;
		zKoord = z;
	}
	
	/**
	 * Berechnet die Distanz zwischen zwei Punkten
	 * @param X erster Punkt
	 * @param Y zweiter Punkt
	 * @return Länge als double
	 */
	public static double dist(Punkt X, Punkt Y){
		return Math.sqrt(Math.pow(X.getxKoord()-Y.getxKoord(),2)+Math.pow(X.getyKoord()-Y.getyKoord(),2)+Math.pow(X.getzKoord()-Y.getzKoord(),2));
	}

	/**
	 * Getter Methode zur Ausgabe der X-Koordinate
	 * @return X-Koordinate als Double
	 */
	public double getxKoord() {
		return xKoord;
	}

	/**
	 * Setter Methode zum Setzen der X-Koordinate
	 * @param xKoord X-Koordinate
	 */
	public void setxKoord(double xKoord) {
		this.xKoord = xKoord;
	}
	
	/**
	 * Getter Methode zur Ausgabe der Y-Koordinate
	 * @return Y-Koordinate als Double
	 */
	public double getyKoord() {
		return yKoord;
	}

	/**
	 * Setter Methode zum Setzen der Y-Koordinate
	 * @param yKoord Y-Koordinate
	 */
	public void setyKoord(double yKoord) {
		this.yKoord = yKoord;
	}
	
	/**
	 * Getter Methode zur Ausgabe der Z-Koordinate
	 * @return Z-Koordinate als Double
	 */
	public double getzKoord() {
		return zKoord;
	}

	/**
	 * Setter Methode zum Setzen der Z-Koordinate
	 * @param xKoord Z-Koordinate
	 */
	public void setzKoord(double zKoord) {
		this.zKoord = zKoord;
	}

	/** 
	 * Formatierte Ausgabe eines Punktes
	 */
	@Override
	public String toString() {
		return "Punkt [X-Koordinate=" + xKoord + ", Y-Koordinate=" + yKoord + ", Z-Koordinate=" + zKoord + "]";
	}



}
