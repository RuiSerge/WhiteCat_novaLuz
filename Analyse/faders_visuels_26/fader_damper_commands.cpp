int fader_damper_commands(int _x,int _y, int fd)
{
    Rect DB(Vec2D(_x, _y+20),Vec2D( 20,20 ));
    DB.SetRoundness(4);
    DB.DrawOutline(CouleurLigne.WithAlpha(0.5));
    DB.Draw(CouleurBleuProcedure.WithAlpha(fader_damper_is_on[fd]));
    DB.DrawOutline(CouleurLigne.WithAlpha(fader_damper_is_on[fd]));
    neuro.Print("~",_x+5,_y+36);

    Rect Lev(Vec2D(_x+30, _y+15),Vec2D( 127*(Fader_dampered[fd].getdecay()),12 ));
    Rect Flev(Vec2D(_x+30, _y+15),Vec2D( 127,12 ));
    Lev.Draw(CouleurConfig);
    Flev.DrawOutline(CouleurLigne.WithAlpha(0.5));
    minichiffregris.Print("Decay",_x+35,_y+24);
    int f=127*Fader_dampered[fd].getdecay();
    petitpetitchiffregris.Print(ol::ToString(f),_x+65,_y+24);

    Rect levDt(Vec2D(_x+30, _y+35),Vec2D( 127*(Fader_dampered[fd].getdt()*10),12 ));
    Rect FDt(Vec2D(_x+30, _y+35),Vec2D( 127,12 ));
    levDt.Draw(CouleurConfig);
    FDt.DrawOutline(CouleurLigne.WithAlpha(0.5));
    minichiffregris.Print("Delta",_x+35,_y+43);
    f=127*Fader_dampered[fd].getdt()*10;
    petitpetitchiffregris.Print(ol::ToString(f),_x+65,_y+43);


    Rect Mod(Vec2D(_x+137, _y),Vec2D( 20,10 ));
    Mod.Draw(CouleurConfig.WithAlpha(fader_damper_is_on[fd]));
    Mod.DrawOutline(CouleurLigne.WithAlpha(0.5));
    minichiffregris.Print(ol::ToString(Fader_dampered[fd].getdampermode()),_x+146,_y+8);


    button_midi_out_visu(_x+130,_y+65,fd+1960);//decaybutton_midi_out_visu(_x+150,_y+65,fd+1960);//decay
    button_midi_out_visu(_x+150,_y+65,fd+2056);//dt
    if(window_focus_id==W_FADERS && Midi_Faders_Affectation_Type!=0)
    {
        if( mouse_x>_x && mouse_x<_x+20 && mouse_y>_y+20 && mouse_y<_y+40)
        {
            DB.DrawOutline(CouleurBlind);
        }

        if( mouse_x>_x+30 && mouse_x<=_x+157 && mouse_y>_y+15 && mouse_y<_y+27)
        {
            Flev.DrawOutline(CouleurBlind);
        }
        if( mouse_x>_x+30 && mouse_x<=_x+157 && mouse_y>_y+35 && mouse_y<_y+47)
        {
            FDt.DrawOutline(CouleurBlind);
        }
        if( mouse_x>_x+137 && mouse_x<_x+157 && mouse_y>_y && mouse_y<_y+10)
        {
            Mod.DrawOutline(CouleurBlind);
        }
    }
    return(0);
}
