int ventilate_midi_to_midiarray()
{
    for(int i=0; i<3072; i++) //3072 controls midi possible
    {
        if(midi_needs_no_key_on_key_off[i]==0)//TOUCHE FLASH ne fonctionne que si Key ON
        {
            if(miditable[0][i]==istyp &&
                    miditable[1][i]==ischan && miditable[2][i]==ispitch && ischan!=999 && istyp!=999 && ispitch!=999 )
            {
                val_raccrochage_midi[i]=isvel;
                if(index_midi_auto_demute==1 && is_raccrochage_midi_remote[i]==1 && val_raccrochage_midi[i]==midi_levels[i])
                {
                    is_raccrochage_midi_remote[i]=0;
                }
                if((is_raccrochage_midi_remote[i]==0 )||(( miditable[0][1277]==istyp) && (miditable[1][1277]==ischan) && (miditable[2][1277]==ispitch)))
                {
                    midi_levels[i]=isvel;
                    do_midi_job(i);
                }
                // midi_signal_received_is_assigned=1;
            }
        }
        else
        {
            if(miditable[1][i]==ischan && miditable[2][i]==ispitch
                    && ischan!=999 && istyp!=999 && ispitch!=999
              )//enlev� le typ pour simplifier les histoires de flash
            {
                val_raccrochage_midi[i]=isvel;
                if((is_raccrochage_midi_remote[i]==0) || ((miditable[0][1277]==istyp) && (miditable[1][1277]==ischan) && (miditable[2][1277]==ispitch)))
                {
                    midi_levels[i]=isvel;
                    do_midi_job(i);
                }
                //midi_signal_received_is_assigned=1;
            }
        }



    }

    if(index_midi_global_thruth==1)
    {
        send_immidiateley_my_midi_cc(istyp,ischan,ispitch,isvel);
    }
    return(0);
}
