int DoDock(int fad, int dk)
{
 ClearDock(fad,dk);

 if(numeric_postext==0)//si pas de chaine de caracteres tapés
 {
 DockTypeIs[fad][dk]=0;//le type est 0, circuits normaux
 if(index_blind==0)
 {
 for (int dc=1;dc<514;dc++)
 {
 FaderDockContains[fad][dk][dc]=0;//nettoyage du fader
 FaderDockContains[fad][dk][dc]=bufferSequenciel[dc];
 //rajout
 bufferSaisie[dc]=0;
 Selected_Channel[dc]=0;
 }
 index_do_dock=0;
 Unselect_other_docks(fad,dk);
 DockIsSelected[fad][dk]=1;
 Fader[fad]=255;
 sprintf(string_Last_Order,">>n Stage Stored in F %d Dock %d",fad+1, dk);
 }

 else if(index_blind==1)
 {
 for (int dc=1;dc<514;dc++)
 {
 FaderDockContains[fad][dk][dc]=bufferBlind[dc];
 }
 index_do_dock=0;
 sprintf(string_Last_Order,">>n Preset Stored in F %d Dock %d",fad+1, dk);
 }
 }
 else if (numeric_postext>0)
 {
 int mem_to_load_in_dock= (int)(atof(numeric)*10.0001);
 if(MemoiresExistantes[mem_to_load_in_dock]==1)
 {
 //ClearDock(fad,dk);
 DockTypeIs[fad][dk]=5;
 int mem_to_load_in_dock= (int)(atof(numeric)*10.0001);
 DockHasMem[fad][dk]=mem_to_load_in_dock;
 reset_numeric_entry();
 sprintf(string_Last_Order,">>n Stored Mem %.1f in F %d Dock %d",(float (mem_to_load_in_dock))/10,fad+1, dk);
 }
 else
 {sprintf(string_Last_Order,">>n Mem %.1f doesn't exist",(float (mem_to_load_in_dock))/10);  }

 }
 return(0);
}
