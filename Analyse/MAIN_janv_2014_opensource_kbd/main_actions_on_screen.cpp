int main_actions_on_screen()
{
    Canvas::Fill(CouleurFond);
    if(index_writing_curve==0)
    {
        Boxes();
    }
    if(core_do_calculations[3]==1)
    {
        trichro_back_buffer(315/2,550/2,125,15);//calcul trichro ( triangle et saturation dans buffer separ�)
    }


    if (mouseClicLeft.isDown() || mouseClicMiddle.isDown() || mouseClicRight.isDown())
    {
        mousePtr.SetLook(whc_mousePointer::arrow_down);
    }
    else
    {
        mousePtr.SetLook(whc_mousePointer::arrow);
    }

    //if (mouse_on_screen())
    {
        if (not mousePtr.Draw())   //si les images ne sont pas charg�es, on dessine la souris
        {
            DoMouse();
        }
        if(Midi_Faders_Affectation_Type!=0  )
        {
            neuromoyen.Print( string_shortview_midi, mouse_x-20,mouse_y+40);


        };
    }
    previous_ch_selected=last_ch_selected;
    return(0);
}
