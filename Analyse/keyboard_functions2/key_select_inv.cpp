int key_select_inv()
{
switch (ClassicalChannelView)
{
case 0:

if(index_blind==0)
           {
           for (int ci=1;ci<514;ci++)
           {
           if( check_presence_of_a_channel_in_views(ci)==1)
           {
           if(bufferSequenciel[ci]>0 && Selected_Channel[ci]==1 )    {Selected_Channel[ci]=0;}
           else if (bufferSequenciel[ci]>0 && Selected_Channel[ci]==0)    {Selected_Channel[ci]=1;}
           }
           }
           }
           else if(index_blind==1)
           {
           for (int ci=1;ci<514;ci++)
           {
           if( check_presence_of_a_channel_in_views(ci)==1)
           {
           if(bufferBlind[ci]>0 && Selected_Channel[ci]==1)    {Selected_Channel[ci]=0;}
           else if (bufferBlind[ci]>0 && Selected_Channel[ci]==0)    {Selected_Channel[ci]=1;}
           }
           }
           }
           sprintf(string_Last_Order,">> Selected All lighting channels non selected ( INV )");


break;
case 1:
if(index_blind==0)
           {
           for (int ci=1;ci<514;ci++)
           {
           if(bufferSequenciel[ci]>0 && Selected_Channel[ci]==1)    {Selected_Channel[ci]=0;}
           else if (bufferSequenciel[ci]>0 && Selected_Channel[ci]==0)    {Selected_Channel[ci]=1;}
           }
           add_channel_selection_to_layers_plot();substract_channel_selection_to_layers_plot();
           }
           else if(index_blind==1)
           {
           for (int ci=1;ci<514;ci++)
           {
           if(bufferBlind[ci]>0 && Selected_Channel[ci]==1)    {Selected_Channel[ci]=0;}
           else if (bufferBlind[ci]>0 && Selected_Channel[ci]==0)    {Selected_Channel[ci]=1;}
           }
           }
           sprintf(string_Last_Order,">> Selected All lighting channels non selected ( INV )");
add_channel_selection_to_layers_plot();
break;
default: break;
}



 return(0);
}
