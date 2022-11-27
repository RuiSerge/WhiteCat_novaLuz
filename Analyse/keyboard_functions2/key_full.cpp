int key_full()
{
    if ((key_shifts & KB_SHIFT_FLAG || index_false_shift==1) && index_patch_window==1)
    {
        patch_to_default_selected();
    }
    else
    {
        reset_numeric_entry();
        for (int ci=1; ci<514; ci++)
        {
            if(Selected_Channel[ci]==1 && index_blind==0)
            {
                bufferSaisie[ci]=255;
            }
            else if(Selected_Channel[ci]==1  && index_blind==1)
            {
                bufferBlind[ci]=255;
            }
        }
        sprintf(string_Last_Order,">> Selection AT FULL");
        index_level_attribue=1;//pour déselection lors prochain circuit piqué
    }
    return(0);
}
