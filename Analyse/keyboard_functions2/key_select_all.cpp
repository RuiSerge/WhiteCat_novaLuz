int key_select_all()
{
 if ((key_shifts & KB_SHIFT_FLAG  || index_false_shift==1)&& index_patch_window==1)
             {patch_select_all_dimmers();}
          else{
             if(index_blind==0)
             {
             for (int ci=1;ci<514;ci++)
             {
             if(bufferSequenciel[ci]==0)    {Selected_Channel[ci]=0;}
             else if (bufferSequenciel[ci]>0)    {Selected_Channel[ci]=1;}
             }
             }
             if(index_blind==1)
             {
             for (int ci=1;ci<514;ci++)
             {
             if(bufferBlind[ci]==0)    {Selected_Channel[ci]=0;}
             else if (bufferBlind[ci]>0)    {Selected_Channel[ci]=1;}
             }
             }
             add_channel_selection_to_layers_plot();
             sprintf(string_Last_Order,">> Selected All lighting channels ");
           }
 return(0);
}
