int ChannelsMenuSelection(int chx, int chy)
{
    Rect Barre(Vec2D(chx,chy),Vec2D(largeur_ChannelMenu,hauteur_ChannelMenu));
    Barre.Draw(CouleurFond);
    neuromoyen.Print("Ch.View:",chx,chy+13);
    Rect Classical(Vec2D(chx+70,chy+1),Vec2D(60,18));
    Classical.SetRoundness(5.0);
    Classical.Draw(CouleurFader.WithAlpha(ClassicalChannelView));
    Classical.DrawOutline(CouleurLigne.WithAlpha(0.4));
    petitchiffre.Print("Classical", chx+75,chy+14);

    if(window_focus_id==0 && Midi_Faders_Affectation_Type!=0 && mouse_x>chx+70 && mouse_x<chx+130 && mouse_y>chy+1 && mouse_y<chy+19)
    {
        Classical.DrawOutline(CouleurBlind);
        show_type_midi(1644,"Classical Channel View");
    }


    Rect ChooseChannelView(Vec2D(chx+80,chy+5),Vec2D(10,10));
    char tmp_hain[24];
    for(int lv=0; lv<2; lv++)
    {
        for(int i=0; i<8; i++)
        {
            ChooseChannelView.MoveTo(Vec2D(chx+140+(i*15),chy+1+(15*lv)));
            ChooseChannelView.Draw(CouleurNiveau.WithAlpha(Channel_View_MODE[i+(lv*8)]));
            ChooseChannelView.DrawOutline(CouleurLigne.WithAlpha(0.4));
            minichiffre.Print(ol::ToString(i+(lv*8)+1),chx+142+(i*15),chy+(15*lv)+8);
            if(window_focus_id==0 && Midi_Faders_Affectation_Type!=0 && mouse_x>chx+140+(i*15) && mouse_x<chx+150+(i*15) && mouse_y>chy+1+(15*lv) && mouse_y<chy+11+(15*lv))
            {
                ChooseChannelView.DrawOutline(CouleurBlind);
                sprintf(tmp_hain,"Channel View %d",i+(lv*8)+1);
                show_type_midi(1628+(i+(lv*8)),tmp_hain);
            }
        }
    }


    command_button_view(chx+270,chy+1,index_blind,"BLIND","Shift-F10",754);// int x, inty ,bool state, char *textedesc, int midiaffectation
    switch(multiple_direct_chan)
    {
    case 0:
        command_button_view(chx+340,chy+1,index_direct_chan,"Direct CH.","",1333);
        break;
    case 1:
        command_button_view(chx+340,chy+1,index_direct_chan,"Direct x12","",1333);
        break;
    default:
        break;
    }

    command_button_view(chx+410,chy+1,index_inspekt,"View","",1334);// int x, inty ,bool state, char *textedesc, int midiaffectation
    command_button_view(chx+480,chy+1,index_do_hipass,"HiPass","",1542);// int x, inty ,bool state, char *textedesc, int midiaffectation
    command_button_view(chx+550,chy+1,index_do_fgroup,"FGroup","",1592);// int x, inty ,bool state, char *textedesc, int midiaffectation

    switch(Midi_Faders_Affectation_Type)
    {
    case 0:
        command_button_view(chx+620,chy+1,Midi_Faders_Affectation_Type,"MidiAffect","",1625);// int x, inty ,bool state, char *textedesc, int midiaffectation
        break;
    case 1:
        command_button_view(chx+620,chy+1,Midi_Faders_Affectation_Type,"MidiAff.X1","",1625);// int x, inty ,bool state, char *textedesc, int midiaffectation
        break;
    case 2:
        command_button_view(chx+620,chy+1,Midi_Faders_Affectation_Type,"MidiAff.X8","",1625);// int x, inty ,bool state, char *textedesc, int midiaffectation
        if(toggle_numerical_midi_way==0)
        {
            minidoomblanc.Print("P",chx+670,chy+25);
        }
        else
        {
            minidoomblanc.Print("CH",chx+670,chy+25);
        }
        break;
    default:
        break;
    }
    command_button_view(chx+690,chy+1,index_midi_mute,"MidiMute","",1277);// int x, inty ,bool state, char *textedesc, int midiaffectation
    command_button_view(chx+760,chy+1,index_global_midi_send_on_faders,"M.Out Fad.","",1593);// int x, inty ,bool state, char *textedesc, int midiaffectation

    command_button_view(chx+830,chy+1,index_do_dock,"STORE","F1",743);// int x, inty ,bool state, char *textedesc, int midiaffectation
    command_button_view(chx+900,chy+1,index_do_modify,"MODIFY","F2",744);
    command_button_view(chx+970,chy+1,index_do_report,"REPORT","F3",745);
    command_button_view(chx+1040,chy+1,index_main_clear,"CLEAR","F4",746);
    command_button_view(chx+1110,chy+1,index_show_main_menu,"MENUS","RIGHT CLICK",1634);

    Line(Vec2D(chx,chy+hauteur_ChannelMenu),Vec2D(chx+largeur_ChannelMenu,chy+hauteur_ChannelMenu)).Draw(CouleurLigne);

    return(0);
}
