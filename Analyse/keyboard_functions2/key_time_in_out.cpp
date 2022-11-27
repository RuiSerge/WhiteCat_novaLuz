int key_time_in_out()
{
           if (key_shifts & KB_SHIFT_FLAG || index_false_shift==1)
           {
            //IN OUT SEL
             if(numeric_postext==0)
           {
           if(index_type_of_time_to_affect[0]==0 || index_type_of_time_to_affect[2]==0 )//Delay selection
           {index_type_of_time_to_affect[0]=1; index_type_of_time_to_affect[2]=1; }//delay in et out sélectionnés
            else if(index_type_of_time_to_affect[0]==1 || index_type_of_time_to_affect[2]==1 )//Delays déselection 18/12/14 christoph
            {index_type_of_time_to_affect[0]=0; index_type_of_time_to_affect[2]=0; }//0=DIN 1=IN 2=DOUT 3=OUT
            }
            else//entree directe pour le preset
            {
            affect_time_entry_to_mem(0,position_preset);
            Times_Memoires[position_preset][2]=Times_Memoires[position_preset][0];
            }
           }
           else
           {
           //IN OUT SEL

            if(numeric_postext==0)
            {
            if(index_type_of_time_to_affect[1]==0 || index_type_of_time_to_affect[3]==0 )
            {index_type_of_time_to_affect[1]=1; index_type_of_time_to_affect[3]=1; }
            else if(index_type_of_time_to_affect[1]==1 || index_type_of_time_to_affect[3]==1 )
            {index_type_of_time_to_affect[1]=0; index_type_of_time_to_affect[3]=0; }
            }
           else //entree directe pour le preset
            {
            affect_time_entry_to_mem(1,position_preset);
            Times_Memoires[position_preset][3]=Times_Memoires[position_preset][1];
            }

           }
 return(0);
}
