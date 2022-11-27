int process_assign_to_core(int coreis)
{
    char tmpmondirectory[200];
    get_executable_name(tmpmondirectory,sizeof(mondirectory)); //recup du path complet
    char nom_exe[200];
    sprintf(nom_exe, get_filename(tmpmondirectory));//recup du nom de l exe
    char tmp_order_call[512];
    sprintf(tmp_order_call,"%s\\utils\\Process.exe %s -a %d", mondirectory, nom_exe, coreis);
    system(tmp_order_call);//lancement system
    sprintf(string_Last_Order,">>Assigned %s to Core %d", nom_exe, coreis);
    return(0);
}
