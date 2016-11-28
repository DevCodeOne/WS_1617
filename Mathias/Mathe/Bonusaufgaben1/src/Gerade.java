
public class Gerade {
	private Punkt p;
	private Vektor v;
	double a, b, c;

	/**
	 * Gerade vom Nullpunkt aus.
	 * 
	 * @param v
	 *            Vektor
	 */
	public Gerade(Vektor v) {
		this.p = new Punkt();
		this.v = v;

	}

	/**
	 * Gerade mit Punkt != Nullpunkt und Vektor
	 * 
	 * @param p
	 *            Punkt
	 * @param v
	 *            Vektor
	 */
	public Gerade(Punkt p, Vektor v) {
		this.p = p;
		this.v = v;
	}

	/**
	 * Gerade die aus zwei Punkten entsteht
	 * 
	 * @param p1
	 *            Punkt 1
	 * @param p2
	 *            Punkt 2
	 */
	public Gerade(Punkt p1, Punkt p2) {
		this.p = p1;
		this.v = new Vektor(p2.getxKoord() - p1.getxKoord(), p2.getyKoord() - p1.getyKoord(),
				p2.getzKoord() - p1.getzKoord());
	}

	/*
	 * Schnitt, Abstand, orientierter Abstand zwischen Punkten und einer Gerade
	 * usw. enthalten
	 */
	/**
	 * Schnittpunkt zwischen einer Geraden und einem Punkt
	 * 
	 * @param p1
	 *            Punkt
	 * @return Boolean schneidet oder nicht
	 */
	public boolean Schnitt(Punkt p1) {
		if (Math.abs(Vektor.scalarProd(new Vektor(p, p1), Vektor.normGerade(v))) <= Double.MAX_VALUE)
			return true;
		return false;
	}

	public void setImp() {
		if (v.getY() == 0 && v.getX() != 0) {
			a = 0;
			b = 1;
			c = -p.getyKoord();
		} else if (v.getY() != 0) {
			a = 1;
			b = -(v.getX() / v.getY());
			c = (v.getX() / v.getY()) * p.getyKoord() - p.getxKoord();
		} else {
			System.out.println("Kein Vektor");
		}
	}

	public Punkt getP() {
		return p;
	}

	public void setP(Punkt p) {
		this.p = p;
		this.setImp();
	}

	public Vektor getV() {
		return v;
	}

	public void setV(Vektor v) {
		this.v = v;
		this.setImp();
	}

	@Override
	public String toString() {
		this.setImp();
		return "Gerade [p=" + p + ", v=" + v + "]" + "\n" + "impl. Darstellung: " + a + "*x + " + b + "*y " + c
				+ " = 0";
	}

}
