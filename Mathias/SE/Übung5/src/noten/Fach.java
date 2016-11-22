package noten;

import com.modeliosoft.modelio.javadesigner.annotations.objid;

@objid ("736692ec-d793-40a4-a5c8-720db36b482f")
public class Fach {
    @objid ("ed0ddf80-c237-4fc4-b2d2-ec5815c233e1")
    private String name;

    @objid ("bf92819f-70c0-40b5-a9ca-c3fad7877503")
    public Lehrer lehrer;

    @objid ("bd5639eb-9058-40a0-8d10-4a0da0e5da66")
    String getName() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.name;
    }

    @objid ("50492845-d3a9-46f9-ac37-4c0d5477f0ca")
    void setName(String value) {
        // Automatically generated method. Please delete this comment before entering specific code.
        this.name = value;
    }

}
