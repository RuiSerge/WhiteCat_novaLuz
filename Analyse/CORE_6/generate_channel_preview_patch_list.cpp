int generate_channel_preview_patch_list()//affichage du premier grada
{
    reset_channel_first_dimmer_list();

    for (int ch=1; ch<513; ch++)
    {
        int index=0;
        for(int d=1; d<513; d++)
        {
            if(Patch[d]==ch  )
            {
                bool tem=0;
                if(index>3)
                {
                    tem=1;
                }
                switch(tem)
                {
                case 0:
                    show_first_dim_array[ch][index]=d;
                    index++;
                    break;
                case 1:
                    show_more_than_one_dim[ch]=1;
                    break;
                default:
                    break;
                }
            }


        }
    }
    return(0);
}
