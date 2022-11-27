int do_wizard_mem()
{
    if(wizard_amplitude_is_global==1)
    {
        bool firstmem=0;
        for(int m=0; m<10000; m++)
        {
            if(MemoiresExistantes[m]==1 && firstmem==0)
            {
                firstmem=1;
                wizard_from_mem=m;
            }
            if(MemoiresExistantes[m]==1 && firstmem!=0)
            {
                wizard_to_mem=m;
            }
        }
    }

    switch(wizard_action_mem) // 0 rebuild numerical order / 1 insert me / 2 del mem / 3 move mem /
    {
    case 0:// 0 rebuild numerical order
        wizard_copy_mem();
        wizard_calcul_nbre_de_mem();
        wizard_clear_mem_original();
        switch(mode_rebuild)
        {
        case 0:
            wizard_rebuild(1);
            break;
        case 1:
            wizard_rebuild(10);
            break;
        case 2:
            wizard_rebuild(100);
            break;
        default:
            break;
        }
        break;
    case 1:// 1 insert mem
        wizard_to_mem=9999;
        wizard_copy_mem();
        wizard_calcul_nbre_de_mem();
        wizard_clear_mem_original();
        wizard_insert_mems();
        break;
    case 2:// 2 del mem
        wizard_calcul_nbre_de_mem();
        wizard_delete_mem();
        break;
    case 3:// 3 move mem
        wizard_calcul_nbre_de_mem();
        wizard_move_mems();
        break;
    case 4://4 inspekt delmem
        wizard_inspekt_mem();
        break;
    case 5:// 5 restore del mem
        wizard_calcul_nbre_de_mem_deleted();
        wizard_restore_mem();
        break;
    case 6:// 6 reset times
        wizard_reset_to_default_time();
        break;
    default:
        break;
    }

    return(0);
}
