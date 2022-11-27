int draw_pdf_grid(int grd, HPDF_REAL xx, HPDF_REAL yy)
{


bool steps_to_write[1024];

for(int stp=0;stp<1023;stp++)
{
steps_to_write[stp]=0;//init
for(int c=0;c<512;c++)
{
if(grid_levels[grd][stp][c]>0){steps_to_write[stp]=1;}
}
}

HPDF_REAL nbre_de_grille_par_largeur=(width-20)/((grider_nb_col*6)+10);

int step_enieme=0;
HPDF_REAL interspace_largeur=0;
HPDF_REAL interspace_hauteur=0;

for(int stp=0;stp<1023;stp++)
{
if(steps_to_write[stp]==1 || (stp>0 && steps_to_write[stp-1]==1) || (stp<1022 && steps_to_write[stp+1]==1) )
{
interspace_largeur= step_enieme*((grider_nb_col*6)+10);

HPDF_Page_SetFontAndSize (page, def_font, 6);

sprintf(header_export,"Step: %d",stp+1 );
draw_info(page,xx+interspace_largeur ,yy-interspace_hauteur+12,header_export);

pdf_draw_channels_on_grid(xx+interspace_largeur,yy-interspace_hauteur,grd, stp);
pdf_draw_little_gridplayer(xx+interspace_largeur,yy-interspace_hauteur);
pdf_draw_infos_of_step(xx+interspace_largeur,yy-interspace_hauteur-(6*grider_nb_row-6),grd, stp);
step_enieme++;
if(step_enieme>nbre_de_grille_par_largeur-1  )
{
interspace_hauteur+=((grider_nb_row*6)+60);
step_enieme=0;
if((yy-interspace_hauteur)<((grider_nb_row*6)+60))
{
 saut_de_page();
 interspace_hauteur=0;
}

}


}
}



HPDF_Page_SetFontAndSize (page, def_font, 10);

 return(0);
}
