int Box_artnet_udpport(int macx, int macy)
{
    petitchiffre.Print("Art-Net UDP Ports",macx-5,macy-20);
    petitpetitchiffre.Print("- default 6454 -",macx+10,macy);
    petitpetitchiffre.Print("Out:",macx-5,macy+20);
    petitpetitchiffre.Print("In:",macx+70,macy+20);
    Rect UDPOut(Vec2D(macx+20,macy+5),Vec2D(45,25));
    UDPOut.SetRoundness(7.5);
    UDPOut.Draw(CouleurFond.WithAlpha(0.4));
    Rect UDPIn(Vec2D(macx+95,macy+5),Vec2D(45,25));
    UDPIn.SetRoundness(7.5);
    UDPIn.Draw(CouleurFond.WithAlpha(0.4));
    petitpetitchiffre.Print(ol::ToString(clientport_artnet),macx+25,macy+20);
    petitpetitchiffre.Print(ol::ToString(serveurport_artnet),macx+100,macy+20);


    if(mouse_y>macy+5 && mouse_y<macy+5+25 && window_focus_id==920)
    {
        if(mouse_x>macx+20 && mouse_x<macx+20+45)
        {
            UDPOut.DrawOutline(CouleurLevel);
            if(mouse_button==1 && mouse_released==0)
            {
                clientport_artnet=atoi(numeric);
                reset_numeric_entry();
                index_re_init_client_artnet=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
        }
        else    if(mouse_x>macx+95 && mouse_x<macx+95+45)
        {
            UDPIn.DrawOutline(CouleurLevel);
            if(mouse_button==1 && mouse_released==0)
            {
                serveurport_artnet=atoi(numeric);
                reset_numeric_entry();
                index_re_init_serveur_artnet=1;
                index_ask_confirm=1;
                mouse_released=1;
            }
        }
    }

    return(0);
}
