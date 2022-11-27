int key_at_zero()
{
    if ((key_shifts & KB_SHIFT_FLAG || index_false_shift==1) && index_patch_window==1)
    {
        patch_clear_selected();
    }
    else
    {
        reset_numeric_entry();
        for (int ci=1; ci<514; ci++)
        {
            if(Selected_Channel[ci]==1 && index_blind==0)
            {
                bufferSaisie[ci]=0;
            }
            else if(Selected_Channel[ci]==1  && index_blind==1)
            {
                bufferBlind[ci]=0;
            }
        }
        sprintf(string_Last_Order,">> Selection AT ZERO");
        index_level_attribue=1;//pour déselection lors prochain circuit piqué
    }
    return(0);
}
