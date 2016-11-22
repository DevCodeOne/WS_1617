package noten;

import com.modeliosoft.modelio.javadesigner.annotations.objid;

@objid ("44e06cad-7d24-46c8-8de5-dfa94a01d726")
public class Person {
    @objid ("5dbf7f42-b470-4684-a55b-f46d35e60d90")
    private String name;

    @objid ("fede13a6-2b2f-45be-b247-cbad8cce7444")
    private String vorname;

    @objid ("1d0083a5-205c-4022-ad45-a7c8b8b2a233")
    String getVorname() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.vorname;
    }

    @objid ("54c5af49-b2b6-4b55-88f8-8156ccfb6778")
    void setVorname(String value) {
        // Automatically generated method. Please delete this comment before entering specific code.
        this.vorname = value;
    }

    @objid ("45de8891-d448-4d04-bc36-ce99c5577248")
    String getName() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.name;
    }

    @objid ("890b4bdd-071e-44b2-a4e7-ccc08e5912c8")
    void setName(String value) {
        // Automatically generated method. Please delete this comment before entering specific code.
        this.name = value;
    }

}
