int Filter_Image(int xorigin, int yorigin, int largeurRoi, int hauteurRoi)
{
cvSetImageROI(onech_snap_background,cvRect(xorigin,yorigin,largeurRoi,hauteurRoi));
cvSetImageROI(onech_temoin,cvRect(xorigin,yorigin,largeurRoi,hauteurRoi));
cvSetImageROI(onech_difference,cvRect(xorigin,yorigin,largeurRoi,hauteurRoi));
cvSetImageROI(affichage,cvRect(xorigin,yorigin,largeurRoi,hauteurRoi));

if(ocv_calcul_mode==0)//MODE BACKGROUND SUPPRESSION
{
cvDiv(onech_temoin,onech_snap_background,onech_difference,div_facteur);
if(blur_on==1){cvSmooth(onech_difference,onech_difference,CV_BLUR,3,3,0,0);}
if(threshold_on==1)
{cvThreshold(onech_difference,onech_difference,threshold_level,255,CV_THRESH_BINARY);}

pixels_changed=(cvCountNonZero(onech_difference));
}

else if(ocv_calcul_mode==1)//MODE NORMAL THERSHOLD ONLY
{
if(blur_on==1)
{
cvSmooth(onech_temoin,onech_temoin,CV_BLUR,3,3,0,0);
}
if(threshold_on==1)
{
cvThreshold(onech_temoin,onech_temoin,threshold_level,255,CV_THRESH_BINARY);
}
pixels_changed=(cvCountNonZero(onech_temoin));
}

if(pixels_changed>=old_pixels_changed){nbre_pixels_changed=pixels_changed-old_pixels_changed;}
else if(pixels_changed<old_pixels_changed){nbre_pixels_changed=old_pixels_changed-pixels_changed;}

old_pixels_changed=pixels_changed;

cvResetImageROI(onech_temoin);
cvResetImageROI(onech_difference);
cvResetImageROI(affichage);
cvResetImageROI(onech_snap_background);

int fract_pix=(int)((float)(largeurRoi*hauteurRoi)/255);;
int indicateur_pixels=(int)(((float)pixels_changed)/fract_pix);
if(indicateur_pixels>255){indicateur_pixels=255;}
else if(indicateur_pixels<0){indicateur_pixels=0;}

return(indicateur_pixels);
}
