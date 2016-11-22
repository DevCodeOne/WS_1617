package noten;

import java.util.ArrayList;
import java.util.List;
import com.modeliosoft.modelio.javadesigner.annotations.objid;

@objid ("9598fdae-0dac-4db5-a7df-756a064c6754")
public class Schulklasse {
    @objid ("89ddd62f-587e-4627-b0ad-67c45f762ca7")
    private int nr;

    @objid ("04109061-11a2-423b-b8e1-5a02c911b77f")
    private List<Schueler> schueler = new ArrayList<Schueler> ();

    @objid ("bafa6df2-2704-4655-9ba2-9673a045f3ed")
    public void print() {
    }

    @objid ("1e8cb8c5-f6cf-41cb-a69f-631765cb542f")
    int getNr() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.nr;
    }

    @objid ("c107b9b8-69b9-48be-9ef8-76a2a7972c8c")
    void setNr(int value) {
        // Automatically generated method. Please delete this comment before entering specific code.
        this.nr = value;
    }

    @objid ("1a6bd221-4081-4eb9-8239-0958036ae49d")
    List<Schueler> getSchueler() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.schueler;
    }

    @objid ("da945e72-1a30-4adb-a38b-3f8a38043f25")
    void setSchueler(List<Schueler> value) {
        // Automatically generated method. Please delete this comment before entering specific code.
        this.schueler = value;
    }

    @objid ("1a29ef5c-732e-461b-a39c-18743023309b")
    public void printSchuelerliste() {
    }

}
