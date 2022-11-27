int search_and_desaffect_previous_midi_signal(int typaction)
{

    if (typaction==1)//1/1
    {
        for (int i=0; i<3072; i++)
        {
            if (miditable[0][i]==istyp && miditable[1][i]==ischan && miditable[2][i]==ispitch) //0.8.2.2
            {
                miditable[0][i]=999;
                miditable[1][i]=999;
                miditable[2][i]=999;
                midi_launchpad_state[i]=0;

            }
        }
    }
    else if(typaction==2 )
    {
        switch(toggle_numerical_midi_way)
        {
        case 0:
            for(int h=0; h<8; h++)
            {
                for (int i=0; i<3072; i++)
                {
                    if (miditable[0][i]==istyp && miditable[1][i]==ischan && miditable[2][i]==ispitch+h)
                    {
                        miditable[0][i]=999;
                        miditable[1][i]=999;
                        miditable[2][i]=999;
                        midi_launchpad_state[i]=0;
                    }
                }
            }
            break;
        case 1:
            for(int h=0; h<8; h++)
            {
                for (int i=0; i<3072; i++)
                {
                    if (miditable[0][i]==istyp && miditable[1][i]==ischan+h && miditable[2][i]==ispitch)

                    {
                        miditable[0][i]=999;
                        miditable[1][i]=999;
                        miditable[2][i]=999;
                        midi_launchpad_state[i]=0;
                    }
                }
            }
            break;
        default:
        break;
        }
    }


    return(0);
}
