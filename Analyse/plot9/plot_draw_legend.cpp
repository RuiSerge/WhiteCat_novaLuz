int plot_draw_legend(int xplot, int yplot)
{


    Rect CadreDescriptif(Vec2D(xplot,yplot),Vec2D(180,25));
    CadreDescriptif.SetRoundness(7.5);
    CadreDescriptif.Draw(CouleurBlind.WithAlpha(0.5));
    neuromoyen.Print("Spots & Symbols List",xplot+5,yplot+14);

    int refth=0;
    int thx=0;
    int thy=0;
    int the_ecrat=0;
    int nbre_cl=0;
    int typap=0;



    switch(legend_view)
    {
    case 0://liste simple
        nbre_cl=nbre_symbols_differents_sur_plot/16;
        for(int cl=0; cl<nbre_cl+1; cl++)
        {
            the_ecrat=0;
            for(int i=0; i<16; i++)
            {
                refth=i+(cl*16);

                typap=index_list_appareils_pour_la_legende[refth];
                if(refth<nbre_symbols_differents_sur_plot)
                {
                    petitchiffrenoir.Print(ol::ToString(plot_list_appareils[typap]),xplot+(200*cl),yplot+40+(i*15));
                    petitchiffrenoir.Print(symbol_nickname[typap],xplot+30+(200*cl),yplot+40+(i*15));
                }
            }
        }
        break;
    case 1://legende projos
        nbre_cl=nbre_symbols_differents_sur_plot/8;
        for(int cl=0; cl<nbre_cl+1; cl++)
        {
            the_ecrat=0;
            for(int i=0; i<8; i++)
            {
                refth=i+(cl*8);

                typap=index_list_appareils_pour_la_legende[refth];
                if(refth<nbre_symbols_differents_sur_plot)
                {
                    thx= xplot+70+(cl*220);
                    the_ecrat+= 35+ (int)(plot_ecartement_legende[typap]*size_symbol[typap]);
                    thy= yplot+50+the_ecrat;
                    plot_print_neutral_symbol(typap,thx,thy   );
                    petitchiffrenoir.Print(ol::ToString(plot_list_appareils[typap]),thx+40,thy);
                    petitchiffrenoir.Print(symbol_nickname[typap],thx+60,thy);
                }
            }
        }
        break;
    default:
        break;
    }

    if(thx==0)
    {
        thx=200;
    }


    CadreDescriptif.MoveTo(Vec2D(xplot+thx,yplot));
    CadreDescriptif.Draw(CouleurBlind.WithAlpha(0.5));
    neuromoyen.Print("Sorted Gels List",xplot+5+thx,yplot+14);


    int clnbre=nbre_ligne_pour_gelats/24;


    for(int cl=0; cl<=clnbre; cl++)
    {
        for(int ln=0; ln<24; ln++)
        {
            petitchiffrenoir.Print(Geo[ln+(cl*ln)],xplot+thx+(cl*200),yplot+40+(ln*10));
        }
    }
    return(0);
}
