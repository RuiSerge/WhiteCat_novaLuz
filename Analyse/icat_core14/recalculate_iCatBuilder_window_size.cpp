int recalculate_iCatBuilder_window_size()
{

switch(surface_type)
{
case 0://iPOD
   if(iCat_preset_orientation[iCatPageis]==0)
   {
    L_tablier_iCat=160;H_tablier_iCat=240;
   }
   else {L_tablier_iCat=240;H_tablier_iCat=160;}
largeuriCat=650;
hauteuriCat=320 + H_tablier_iCat;
break;
case 1://iPAD
   if(iCat_preset_orientation[iCatPageis]==0)
   {
    L_tablier_iCat=384;H_tablier_iCat=512;
   }
   else {
   L_tablier_iCat=512;H_tablier_iCat=384;
   }
largeuriCat=650;
hauteuriCat=320 + H_tablier_iCat;
break;
default:
break;
}

 return(0);
}
