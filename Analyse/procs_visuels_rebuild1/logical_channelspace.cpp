int logical_channelspace()
{
if(ClassicalChannelView==1)   //512
{
if(mouse_y> ChannelYMenu+hauteur_ChannelMenu)//les menus
{
do_logical_ClassicalChannelSpace(XChannels, YChannels,  scroll_channelspace);
}
}


else
{
int pos_y_vision=0;
for(int i=0;i<=nbre_de_vues_circuits;i++)
{
if(Channel_View_MODE[i]==1)
{
do_logical_Draw_Channel_Preset_Title(XChannels,YChannels+pos_y_vision-(int)(((float)scroll_channelspace)/ ratioview),i);
pos_y_vision+= 60;
do_logical_Draw_Channel_Preset_View(XChannels,YChannels+pos_y_vision-(int)(((float)scroll_channelspace)/ ratioview),i);
pos_y_vision+=((channel_number_of_lines[i])*70)+ hauteur_preset_titre;
} //pas de scroll
}
}

 return(0);
}
