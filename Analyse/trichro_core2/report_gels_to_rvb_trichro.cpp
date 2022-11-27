int report_gels_to_rvb_trichro(int manufacturer, int gel_position)
{

    switch(index_use_transmission)
    {
    case 0:
        my_red=rvb_of_gels[manufacturer][gel_position][0];
        my_green=rvb_of_gels[manufacturer][gel_position][1];
        my_blue=rvb_of_gels[manufacturer][gel_position][2];
        break;
    case 1://use transmission data
        my_red=(int)((((float)rvb_of_gels[manufacturer][gel_position][0])/100)*gel_transimission[manufacturer][gel_position]);
        my_green=(int)((((float)rvb_of_gels[manufacturer][gel_position][1])/100)*gel_transimission[manufacturer][gel_position]);
        my_blue=(int)((((float)rvb_of_gels[manufacturer][gel_position][2])/100)*gel_transimission[manufacturer][gel_position]);
        break;
    default:
        break;
    }
    do_colors();
    sprintf(string_Last_Order,">>Gel list Called Position %d / ref %d",gel_position,refs_of_gels[manufacturer][gel_position]);
    return(0);
}
