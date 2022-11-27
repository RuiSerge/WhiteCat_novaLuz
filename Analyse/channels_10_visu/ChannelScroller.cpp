int ChannelScroller( int ScrollX, int ScrollY)
{
    Line( Vec2D( ScrollX, ScrollY ), Vec2D( ScrollX,ScrollY+250)).Draw( CouleurLigne );



    float positiony=0;


    switch(ClassicalChannelView)
    {
    case 0:
        // YChannels+pos_y_vision-(int)(scroll_channelspace* facteur_scroll_channel_space),i);


        for(int i=0; i<nbre_de_vues_circuits; i++)
        {
            if(Channel_View_MODE[i]==1)
            {
                Line( Vec2D(ScrollX,ScrollY+positiony), Vec2D( ScrollX+5,ScrollY+positiony)).Draw( CouleurLigne );
                minichiffre.Print( channel_view_Name[i],ScrollX+6,(int)(ScrollY+positiony));
                positiony=(ratioview*scroll_pos_preset[i]);

            }

        }

        break;
    case 1:
        Line( Vec2D(ScrollX,ScrollY), Vec2D( ScrollX+10,ScrollY)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "  1 -48",ScrollX+25,ScrollY );
        Line( Vec2D(ScrollX,ScrollY+25), Vec2D( ScrollX+10,ScrollY+25)).Draw( CouleurLigne );
        petitpetitchiffre.Print( " 49 -96",ScrollX+25,ScrollY+25 );
        Line( Vec2D(ScrollX,ScrollY+50), Vec2D( ScrollX+10,ScrollY+50)).Draw( CouleurLigne );
        petitpetitchiffre.Print( " 97-144",ScrollX+25,ScrollY+50 );
        Line( Vec2D(ScrollX,ScrollY+75), Vec2D( ScrollX+10,ScrollY+75)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "145-192",ScrollX+25,ScrollY+75 );
        Line( Vec2D(ScrollX,ScrollY+100), Vec2D( ScrollX+10,ScrollY+100)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "193-240",ScrollX+25,ScrollY+100 );
        Line( Vec2D(ScrollX,ScrollY+125), Vec2D( ScrollX+10,ScrollY+125)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "241-288",ScrollX+25,ScrollY+125 );
        Line( Vec2D(ScrollX,ScrollY+150), Vec2D( ScrollX+10,ScrollY+150)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "289-336",ScrollX+25,ScrollY+150 );
        Line( Vec2D(ScrollX,ScrollY+175), Vec2D( ScrollX+10,ScrollY+175)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "337-384",ScrollX+25,ScrollY+175 );
        Line( Vec2D(ScrollX,ScrollY+200), Vec2D( ScrollX+10,ScrollY+200)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "385-432",ScrollX+25,ScrollY+200 );
        Line( Vec2D(ScrollX,ScrollY+225), Vec2D( ScrollX+10,ScrollY+225)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "433-480",ScrollX+25,ScrollY+225 );
        Line( Vec2D(ScrollX,ScrollY+250), Vec2D( ScrollX+10,ScrollY+250)).Draw( CouleurLigne );
        petitpetitchiffre.Print( "  ->512",ScrollX+25,ScrollY+250 );
        break;
    default:
        break;
    }

    Rect Curseur_ScrollChannel(Vec2D(ScrollX-10,ScrollY+scroll_channelspace-10),Vec2D(100,20));
    Curseur_ScrollChannel.SetRoundness(10);
    Curseur_ScrollChannel.SetLineWidth(epaisseur_ligne_fader);
    Curseur_ScrollChannel.DrawOutline(CouleurFader);

    if(Midi_Faders_Affectation_Type!=0  && mouse_x>ScrollX-10 && mouse_x<ScrollX+90 && mouse_y>ScrollY+scroll_channelspace && mouse_y<ScrollY+scroll_channelspace+20)
    {
        Curseur_ScrollChannel.DrawOutline(CouleurBlind);
        show_type_midi(1624,"Channels Handle" );
    }


    refresh_positions_preset_view_poignee();
    return(0);
}
