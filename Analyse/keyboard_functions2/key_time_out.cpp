int key_time_out()
{
 if (key_shifts & KB_SHIFT_FLAG || index_false_shift==1)
           {
             //delay OUT
           if(numeric_postext==0)
           {
           if(index_type_of_time_to_affect[2]==0){index_type_of_time_to_affect[2]=1;}
           else if(index_type_of_time_to_affect[2]==1){index_type_of_time_to_affect[2]=0;}
           }
           else
           //entree directe pour le preset
            {affect_time_entry_to_mem(2,position_preset);}
           }
           else
           {
           //OUT
            if(numeric_postext==0)
           {
           if(index_type_of_time_to_affect[3]==0){index_type_of_time_to_affect[3]=1;}
           else if(index_type_of_time_to_affect[3]==1){index_type_of_time_to_affect[3]=0;}
            }
            else//entree directe pour le preset
            {affect_time_entry_to_mem(3,position_preset);}
           }

 return(0);
}
