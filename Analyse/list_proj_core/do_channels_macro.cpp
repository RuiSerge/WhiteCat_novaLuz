int do_channels_macro()
{
    for(int i=1; i<513; i++)
    {

        for(int evo=0; evo<4; evo++)
        {
            if(macro_channel_on[i][evo]==1 && MergerArray[i]!=previous_state_of_outputted_channels[i])
            {
                bool is_ok_for_condition=0;
                switch(channel_macro_reaction[i][evo])//condition
                {
                case 0:
                    //nothing
                    break;
                case 1://>=
                    if(MergerArray[i]>=channel_macro_val[i][evo][0] )
                    {
                        is_ok_for_condition=1;
                    }
                    break;
                case 2://>
                    if(MergerArray[i]>channel_macro_val[i][evo][0] )
                    {
                        is_ok_for_condition=1;
                    }
                    break;
                case 3://==
                    if(MergerArray[i]==channel_macro_val[i][evo][0] )
                    {
                        is_ok_for_condition=1;
                    }
                    break;
                case 4://!=
                    if(MergerArray[i]!=channel_macro_val[i][evo][0] )
                    {
                        is_ok_for_condition=1;
                    }
                    break;
                case 5://<=
                    if(MergerArray[i]<=channel_macro_val[i][evo][0] )
                    {
                        is_ok_for_condition=1;
                    }
                    break;
                case 6://<
                    if(MergerArray[i]<channel_macro_val[i][evo][0] )
                    {
                        is_ok_for_condition=1;
                    }
                    break;
                case 7://Follow
                    is_ok_for_condition=1;
                    break;
                case 8://Follow inv
                    is_ok_for_condition=1;
                    break;
                default:
                    break;
                }
                if(is_ok_for_condition==1)
                {
                    do_the_macro_of_the_channel(i,evo);
                    sprintf(string_Last_Order,"Channel %d: Macro %d !",i, evo+1);
                }
                //fin macro on et diff  d etat
            }
            //fin check macro on   x 4
        }
        previous_state_of_outputted_channels[i]=MergerArray[i];//stockage pour declenchements
    }

    return(0);
}
