int print_midi_command(int idMidi)
{
    char typ_temp[16];
    switch(miditable[0][idMidi])
    {
    case 0:
        sprintf(typ_temp,"Note");
        break;
    case 1:
        sprintf(typ_temp,"Key On");
        break;
    case 2:
        sprintf(typ_temp,"Key Off");
        break;
    case 4:
        sprintf(typ_temp,"Ctrl Change");
        break;
    default:
        sprintf(typ_temp,"-");
        break;
        break;
    }
    sprintf(header_export, " %s: %s Chan %d Pitch %d \n",list_midi_affect[idMidi],typ_temp, miditable[1][idMidi],miditable[2][idMidi]);
    if(miditable[1][idMidi]!=999)
    {
        draw_info(page, 120, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        cmptline_pdf++;
        verification_fin_de_page();
    }
    return(0);
}
