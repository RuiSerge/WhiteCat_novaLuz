int attribute_midi_to_control(int faderis, int typaction, int modeaction)
{

    if(index_midi_auto_desaffect==1)
    {
        search_and_desaffect_previous_midi_signal(typaction);   //bug desaffectation
    }
    if(modeaction==1)//reset
    {
        istyp=999;
        ischan=999;
        ispitch=999;
        modeaction=0;
    }

    if(modeaction==2)//generated fake midi
    {
        istyp=fakemiditype;
        ischan=fakemidichan;
        ispitch=fakemidipitch;
        modeaction=0;
    }

    if(typaction==1 )//1/1
    {
        if(ischan<16 && ispitch<128)
        {
            miditable[0][faderis]=istyp;
            miditable[1][faderis]=ischan;
            miditable[2][faderis]=ispitch;
        }
    }

    if(typaction==2)//1/8
    {
        if(ischan<16 && ispitch<128)
        {
            switch(toggle_numerical_midi_way)//numeric pitch
            {
            case 0:
                for(int h=0; h<8; h++)
                {
                    miditable[0][faderis+h]=istyp;
                    miditable[1][faderis+h]=ischan;
                    miditable[2][faderis+h]=ispitch+h;
                }
                break;
            case 1: //numeric channel
                for(int h=0; h<8; h++)
                {
                    miditable[0][faderis+h]=istyp;
                    miditable[1][faderis+h]=ischan+h;
                    miditable[2][faderis+h]=ispitch;
                }
                break;
            default:
                break;
            }
        }
    }

    if( index_midi_affectation_autoclose==1)
    {
        Midi_Faders_Affectation_Type=0;
    }


    return(0);
}
