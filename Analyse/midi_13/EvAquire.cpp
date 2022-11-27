static char * EvAquire ( MidiEvPtr e)
{

    istyp=(int)EvType(e);
    ischan=(int)Chan(e);
    ispitch=(int)Pitch(e);
    isvel=(int)Vel(e);

    sprintf(typ,TblLibEv[istyp]);
    sprintf (my_midi_original_string, "Raw: Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, typ);

    //christoph 12/05/15 pour midi twister
    if(cheat_key_off_to_key_on==1 && istyp==2)//key off
    {
        istyp=1;
        isvel=0;//�crasement de la v�locit� du key off
    }

    //trichage key on vel 0 at key off
    if(cheat_key_off==1 && (istyp==0 || istyp==1) && isvel==0 )//eviter le flash key off
    {
        istyp=2;
    }
    //affinage midi cheat change signal
    switch(midi_change_vel_type[ischan][ispitch])
    {
    case 0:
        break;
    case 1://inversion 0-127>127-0
        tempvel=isvel;
        isvel=127-tempvel;
        break;
    case 2://toggle
        if(isvel>0)
        {
            midi_recognize_on_off[ischan][ispitch]=toggle(midi_recognize_on_off[ischan][ispitch]);
        }
        isvel=127*midi_recognize_on_off[ischan][ispitch];
        break;
    case 3://midi key on vel 0= midi key off
        if((istyp==0 || istyp==1) && isvel==0 )//eviter le flash key off
        {
            istyp=2;
        }
        break;
    case 4://midi key off = midi key on vel 0
        if(istyp==2)  //eviter le flash key off
        {
            istyp=1;
            isvel=0;
        }
        break;
    case 5://pad to triggers
        if(isvel>0 && isvel<127)
        {
            isvel=127;
        }
        break;
    case 6://CC 0 devient Koff pour touch osc
        if(isvel==0)
        {
            istyp=2;
        }
        break;
    default:
        break;
    }

    add_to_midi_historic();
    //moniteur mis � jour
    sprintf(typ,TblLibEv[istyp]);
    sprintf (my_midi_string, "%s Ch:%-2d P:%-2d Vel:%-2d ",typ,ischan,ispitch,isvel);

    ventilate_midi_to_midiarray();



    return (0);
}
