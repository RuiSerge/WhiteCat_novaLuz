int refresh_check_buttons()
{

    for(int i=0; i<48; i++)
    {
        before_check_button_state[i]=1-before_check_button_state[i];
    }
    return(0);
}
