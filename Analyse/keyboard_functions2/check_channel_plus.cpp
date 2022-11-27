int check_channel_plus()
{
int vv=0;
int circ=0;
int nextcirc=0;
switch (ClassicalChannelView)
{
case 0: //VIEWS
for(int v=0;v<nbre_de_vues_circuits; v++)
{
if(Channel_View_MODE[v]==1 && check_presence_of_any_channel_in_A_view(v)==1)
{
vv=v;
break;
}
}


for(int ck=0;ck<=channel_number_in_View[vv];ck++)
{
circ=Channel_View_ROUTING[vv][ck];
    if(Selected_Channel[circ]==1)
    {
    bufferSaisie[circ]=0;
    Selected_Channel[circ]=0;
    if(ck+1!=channel_number_in_View[vv])
    {
    nextcirc=Channel_View_ROUTING[vv][ck+1];
    }
    else
   {
    bool gotit=0;
    for(int i=vv+1;i<nbre_de_vues_circuits;i++)
    {
    if(Channel_View_MODE[i]==1)
    {nextcirc= Channel_View_ROUTING[i][0];
    gotit=1;
    break;}
    if(gotit==1){break;}
    }
    }

    if(nextcirc==0){nextcirc=circ;}
    Selected_Channel[nextcirc]=1;
    bufferSaisie[nextcirc]=check_channel_level;
    last_ch_selected=nextcirc;
    break;
    }



        if(index_patch_window==1)
        {
        patch_unselect_all_dimmers();
        for(int dop=0;dop<513;dop++)
        {
        if(Patch[dop]==nextcirc){Dimmers_selected[dop]=1;}
        }
        }


}




add_channel_selection_to_layers_plot();
break;
case 1:
    for(int ck=1;ck<512;ck++)
    {
    if(Selected_Channel[ck]==1)
    {
    bufferSaisie[ck]=0;
    Selected_Channel[ck]=0;

    Selected_Channel[ck+1]=1;
    bufferSaisie[ck+1]=check_channel_level;

        if(index_patch_window==1)
        {
        patch_unselect_all_dimmers();
        for(int dop=0;dop<513;dop++)
        {
        if(Patch[dop]==(ck+1)){Dimmers_selected[dop]=1;}
        }
        }
        last_ch_selected=ck+1;
    break;
    }
    }

add_channel_selection_to_layers_plot();
break;
default: break;
}
return(0);
}
