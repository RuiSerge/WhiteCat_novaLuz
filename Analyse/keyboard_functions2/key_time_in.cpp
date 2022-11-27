int key_time_in()
{
           if (key_shifts & KB_SHIFT_FLAG || index_false_shift==1)
           {
            // delay IN
             if(numeric_postext==0)
             {
             if(index_type_of_time_to_affect[0]==0){index_type_of_time_to_affect[0]=1;}
             else if(index_type_of_time_to_affect[0]==1){index_type_of_time_to_affect[0]=0;}
             }
             else //entree directe pour le preset
            {affect_time_entry_to_mem(0,position_preset);}
           }
           else {
            // IN
            if(numeric_postext==0)
           {
            if(index_type_of_time_to_affect[1]==0){index_type_of_time_to_affect[1]=1;}
            else if(index_type_of_time_to_affect[1]==1){index_type_of_time_to_affect[1]=0;}
            }
            else //entree directe pour le preset
            {affect_time_entry_to_mem(1,position_preset);}
           }
 return(0);
}
