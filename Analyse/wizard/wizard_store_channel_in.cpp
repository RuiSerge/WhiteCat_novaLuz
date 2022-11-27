int wizard_store_channel_in()
{
number_inchannels=0;
clear_wizard_store_ch_in();

strcpy( tmp_wizbuffer,"");


for (int w=1;w<513;w++)
{
wizard_buffer_in[w]=Selected_Channel[w];
}

char tmpw[6];
for (int w=1;w<513;w++)
{
if(wizard_buffer_in[w]==1)
{
sprintf(tmpw,"%d-", w);
strcat(tmp_wizbuffer, tmpw);
number_inchannels++;
}
}

for (int ly=0;ly<36;ly++)
{
strcpy(show_buff_wizIN[ly],"");
for (int by=0;by<71;by++)
{
show_buff_wizIN[ly][by]=tmp_wizbuffer[(ly*71)+by];
}
show_buff_wizIN[ly][72]='\0';
}

for (int ci=1;ci<514;ci++)
{Selected_Channel[ci]=0;}

last_ch_selected=0;
index_level_attribue=0;

index_do_dock=0;
return(0);
}
