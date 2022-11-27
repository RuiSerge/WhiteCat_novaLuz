int simulate_midi(int letype,int lechan, int lepitch, int lavaleur)
{
    istyp=letype;
    ischan=lechan;
    ispitch=lepitch;
    isvel=lavaleur;
    ventilate_midi_to_midiarray();
    return(0);
}
