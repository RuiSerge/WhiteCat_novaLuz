int grand_master(int GMX, int GMY)
{
    Rect Gma( Vec2D(GMX,GMY), Vec2D(40,255) );//box du fader
    Gma.SetRoundness(15);
    Gma.SetLineWidth(epaisseur_ligne_fader);
    Rect GmaNiv( Vec2D(GMX,((GMY+255)-niveauGMaster)), Vec2D (40,niveauGMaster+2));//niveau fader
    GmaNiv.SetRoundness(15);
    switch(dmx_view)
    {
    case 0:
        sprintf(string_niveauGMaster, "%d",(int)(((float)niveauGMaster)/2.55));
        break;
    case 1:
        sprintf(string_niveauGMaster,"%d", niveauGMaster);
        break;
    default:
        break;
    }
    GmaNiv.Draw(CouleurBlind);
    Gma.DrawOutline(CouleurLigne);
    neuro.Print(string_niveauGMaster,GMX, GMY-5); //niveau du fader

    Circle BMMidiOut( (GMX+70),(GMY+250), 10);//box du fader
    BMMidiOut.SetLineWidth(epaisseur_ligne_fader);
    if(midi_send_out[615]==1)
    {
        BMMidiOut.Draw(CouleurBlind);
    }
    BMMidiOut.DrawOutline(CouleurLigne);
    Line (Vec2D( GMX+40,GMY+240),Vec2D( GMX+55,GMY+240)).Draw(CouleurLigne);
    Line (Vec2D( GMX+55,GMY+240),Vec2D( GMX+65,GMY+245)).Draw(CouleurLigne);

    neuromoyen.Print("Grand Master",GMX-25, GMY+280);
    if(mouse_x>GMX && mouse_x<GMX+40 && mouse_y>=GMY-5 && mouse_y<=GMY+255 && Midi_Faders_Affectation_Type!=0)
    {
        Gma.DrawOutline(CouleurBlind);
    }

    raccrochage_midi_visuel_vertical_dmx (GMX, GMY, 615,40,255);
    return(0);
}
