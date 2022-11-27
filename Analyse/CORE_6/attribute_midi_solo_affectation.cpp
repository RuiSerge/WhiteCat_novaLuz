int attribute_midi_solo_affectation(int faderis, int modeaction)
{

    if(index_midi_auto_desaffect==1)
    {
        search_and_desaffect_previous_midi_signal(1);   //bug desaffectation
    }


    if(Midi_Faders_Affectation_Mode==1)//reset
    {
        istyp=999;
        ischan=999;
        ispitch=999;
        Midi_Faders_Affectation_Mode=0;//modeaction=0;
    }
    else if(Midi_Faders_Affectation_Mode==2)//generated fake midi
    {
        if(ischan<16 && ispitch<128)
        {
            istyp=fakemiditype;
            ischan=fakemidichan;
            ispitch=fakemidipitch;
            Midi_Faders_Affectation_Mode=0;//modeaction=0;
        }
    }

    if(ischan<16 && ispitch<128)
    {
        miditable[0][faderis]=istyp;
        miditable[1][faderis]=ischan;
        miditable[2][faderis]=ispitch;
    }

    if( index_midi_affectation_autoclose==1)
    {
        Midi_Faders_Affectation_Type=0;
    }

    return(0);
}
