
public class Gerade {
	private Punkt p;
	private Vektor v;

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
	public Punkt Schnittgerade(Gerade g1, Gerade g2) {

	}

	public Punkt getP() {
		return p;
	}

	public void setP(Punkt p) {
		this.p = p;
	}

	public Vektor getV() {
		return v;
	}

	public void setV(Vektor v) {
		this.v = v;
	}

	@Override
	public String toString() {
		return "Gerade [p=" + p + ", v=" + v + "]";
	}

}
