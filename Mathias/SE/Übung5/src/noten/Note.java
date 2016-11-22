package noten;

import java.util.ArrayList;
import java.util.List;
import com.modeliosoft.modelio.javadesigner.annotations.objid;

@objid ("25bbef7a-6de1-40ab-a4e8-04af0fc30da5")
public class Note {
    @objid ("61ce9965-354d-4d36-98cb-f9d90b2c523e")
    private double wert;

    @objid ("f81d2ef6-4c7f-4bec-8677-6c80936c03cf")
    private List<Fach> fach = new ArrayList<Fach> ();

    @objid ("5f7f76c0-1524-4f1b-a540-77a58567f8d0")
    double getWert() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.wert;
    }

    @objid ("88438427-abe4-4ae9-a57d-4134b5220ad0")
    void setWert(double value) {
        // Automatically generated method. Please delete this comment before entering specific code.
        this.wert = value;
    }

}
