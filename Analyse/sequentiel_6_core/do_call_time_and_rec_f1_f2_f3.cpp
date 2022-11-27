int do_call_time_and_rec_f1_f2_f3(int mem_is)
{
if(numeric_postext>0 && index_affect_time==0 && index_do_dock==0 && index_do_modify==0 && index_do_report==0 )
{
if(call_stage==1){call_mem_onstage();}
else if(call_preset==1)
{
if(index_go==1 || index_pause==1)//double entree en cours de crossfade
{
for (int po=1;po<514;po++)
{
bufferSaisie[po]=bufferSequenciel[po];
}
niveauX1=255;
niveauX2=0;
prepare_crossfade();
floatX1=niveauX1;
floatX2=niveauX2;
}
call_mem_onpreset();
}
}

else if(index_affect_time==1 && index_do_dock==1 && numeric_postext==0 )//si la fenetre time est ouverte
{
affect_time_from_chrono_to_mem(mem_is);
}

else if( index_do_dock==1 && index_affect_time==0 )
{
 for (int dc=1;dc<514;dc++)
 {
 if(call_stage==1){Memoires[position_onstage][dc]=0;  }
 if(index_blind==0)
 {
 Memoires[mem_is][dc]=bufferSequenciel[dc];
 }
 else if(index_blind==1)
 {
 Memoires[mem_is][dc]=bufferBlind[dc];
 }
 Selected_Channel[dc]=0;
 }
 index_do_dock=0;
 ratio_cross_manuel[mem_is]= ratio_X1X2_together;
}
else if( index_do_dock==0 && index_do_modify==1 && index_do_report==0 && index_affect_time==0 )
{
 for (int dc=1;dc<514;dc++)
 {
 if(Selected_Channel[dc]==1)
 {
 if(index_blind==0)
 {
 Memoires[mem_is][dc]=bufferSequenciel[dc];
 }
 else if(index_blind==1)
 {
  Memoires[mem_is][dc]=bufferBlind[dc];
 }
 Selected_Channel[dc]=0;
 }
 }
 index_do_modify=0;
 ratio_cross_manuel[mem_is]= ratio_X1X2_together;
}
else if( index_do_dock==0 && index_do_modify==0 && index_do_report==1 && index_affect_time==0 )
{
if(index_blind==0)
 {
 for (int dc=1;dc<514;dc++)
 {
 if(bufferFaders[dc]>bufferSequenciel[dc]){Memoires[mem_is][dc]=bufferFaders[dc];}
 else { Memoires[mem_is][dc]=bufferSequenciel[dc]; }
 Selected_Channel[dc]=0;
 }
 for (int u=0;u<49;u++)
 {Fader[u]=0;}
 }
 else if(index_blind==1)
 {
 sprintf(string_Last_Order,">>Report concerns only on stage mode");
 }
 index_do_report=0;
 ratio_cross_manuel[mem_is]= ratio_X1X2_together;
}


return(0);
}
