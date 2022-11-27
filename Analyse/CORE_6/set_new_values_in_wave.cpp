int set_new_values_in_wave()
{
    int _index=0;
    for(int i=waver_control; i<26; i++) //vers la droite
    {
        if(lead_brush_reading[brush_selected]+_index<26)
        {
            Wave_Dampered[i].set_target_val(255*brush_slots[brush_selected][lead_brush_reading[brush_selected]+_index]);
            _index++;
        }
        if(lead_brush_reading[brush_selected]+_index>=26)
        {
            break;
        }
    }


    _index=0;
    for(int i=waver_control; i>=0; i--) //vers la gauche
    {

        if(lead_brush_reading[brush_selected]-_index<0)//protection
        {
            break;
        }
        if(lead_brush_reading[brush_selected]-_index>=0)
        {
            Wave_Dampered[i].set_target_val(255*brush_slots[brush_selected][lead_brush_reading[brush_selected]-_index]);
            _index++;
        }
    }
    return(0);
}
