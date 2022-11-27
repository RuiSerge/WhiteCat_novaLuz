int pdf_draw_channels_on_grid(HPDF_REAL xx, HPDF_REAL yy, int gr, int ste)
{


    HPDF_Page_SetFontAndSize (page, def_font, 4);


    float colRr, colGg, colBb;
    int the_ch=0;
    HPDF_REAL xp=0;
    HPDF_REAL yp=0;

    for(int ligne=0; ligne<grider_nb_row; ligne++)
    {
        for(int col=0; col<grider_nb_col; col++)
        {
            the_ch=((ligne*grider_nb_col)+col);

            if(grid_levels[gr][ste][the_ch]!=0)
            {



                if(grid_levels[gr][ste][the_ch]==255)
                {
                    colRr=1.0;
                    colGg=0.5;
                    colBb=0.0;  //sab 02/03/2014 unused var print_level=false;
                }
                else
                {
                    colRr=0.0;
                    colGg=1.0;
                    colBb=0.0;   //sab 02/03/2014 unused var  print_level=true;
                }
                xp=xx+(col*6);
                yp=yy- (ligne*6);


                HPDF_Page_SetRGBFill (page,colRr, colGg, colBb);//couleur remplissage
                HPDF_Page_SetRGBStroke (page, colRr, colGg, colBb);//couleur ligne
                HPDF_Page_Rectangle  (page, xp, yp-6, 6,6);
                HPDF_Page_FillStroke (page);
                HPDF_Page_SetRGBFill (page,0.0, 0.0, 0.0);//couleur ligne
                HPDF_Page_SetRGBStroke (page, 0.5, 0.5, 0.5);//couleur ligne



                if(grid_levels[gr][ste][the_ch]!=255)
                {


                    switch(dmx_view)
                    {
                    case 0:
                        sprintf(header_export,"%d",(int)((float)(grid_levels[gr][ste][the_ch])/2.55) );
                        break;
                    case 1:
                        sprintf(header_export,"%d",grid_levels[gr][ste][the_ch] );
                        break;
                    default:
                        break;
                    }
                    draw_info(page,xx+(col*6)+1,yy-(ligne*6)+5,header_export);
                }

            }



        }
    }

    return(0);
}
