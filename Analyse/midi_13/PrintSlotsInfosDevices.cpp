int PrintSlotsInfosDevices(short driverRef)
{
    TDriverInfos dInfos;
    TSlotInfos sInfos;

    compt_midi_in=0;
    compt_midi_out=0;//compteurs pour affichages

    compt_first_device_out=0;
    compt_first_device_inout=0;

    if (MidiGetDriverInfos (driverRef, &dInfos))
    {
        short     i;
        SlotRefNum slotRef;

        char temp_device_name[64];
        sprintf(string_nbre_de_devices,"Founded: %d",dInfos.slots);

        for( i = 1; i <= dInfos.slots; i++ )
        {
            slotRef = MidiGetIndSlot(driverRef, i);


            if (MidiGetSlotInfos (slotRef, &sInfos))
            {

                if(sInfos.direction== MidiInputSlot)
                {
                    //ok pour avoir l info de connect� ou pas
                    if(!MidiIsSlotConnected (0,slotRef ))
                    {
                        midi_in_is_connected[i]=0;
                    }
                    else
                    {
                        midi_in_is_connected[i]=1;
                    }

                    compt_midi_in++;//permet apr�s de definir la position des out

                    sprintf(temp_device_name,"%s", sInfos.name);
                    strncpy (tableau_peripheriques_in[i],temp_device_name,32);
                    tableau_peripheriques_indexs_in[i]=1;//acces au num de slot

                    if(do_connect_in[compt_midi_in]==1)
                    {
                        if(midi_in_is_connected[i]==0)
                        {
                            MidiConnectSlot(0,slotRef,1);
                            do_connect_in[i]=0;
                        }
                        else
                        {
                            MidiConnectSlot(0,slotRef,0);
                            do_connect_in[i]=0;
                        }
                    }
                }
                //OUT PUT MIDI LIST
                if(sInfos.direction== MidiOutputSlot)
                {
                    if(!MidiIsSlotConnected (0,slotRef ))
                    {
                        midi_out_is_connected[i]=0;
                    }
                    else
                    {
                        midi_out_is_connected[i]=1;
                    }

                    compt_midi_out++;

                    sprintf(temp_device_name,"%s", sInfos.name);

                    strncpy (tableau_peripheriques_out[compt_midi_out],temp_device_name,32);
                    tableau_peripheriques_indexs_out[i]=1;//acces au num de slot

                    if( compt_first_device_out==0)
                    {
                        compt_first_device_out=i;
                    }

                    if(do_connect_out[i]==1)
                    {
                        if(midi_out_is_connected[i]==0)
                        {
                            MidiConnectSlot(0,slotRef,1);//ok connecter
                        }
                        else
                        {
                            MidiConnectSlot(0,slotRef,0);//ok deconnecter
                        }
                        do_connect_out[i]=0;
                    }
                }

            }
        }
    }

    return(0);
}
