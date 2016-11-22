package noten;

import java.util.ArrayList;
import java.util.List;
import com.modeliosoft.modelio.javadesigner.annotations.objid;

@objid ("564e1c55-3655-4478-9382-60e82c9e36bf")
public class Schueler extends Person {
    @objid ("acb19b28-f214-4f84-ba58-35f0199c57dd")
    public List<Note> note = new ArrayList<Note> ();

    @objid ("8d5d808d-2867-44e9-90fc-58a2746dd5da")
    private List<Schulklasse> klasse = new ArrayList<Schulklasse> ();

}
