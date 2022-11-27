void On_Open_name_of_directory()
{
	char localTempChar[512];
	get_executable_name(localTempChar,sizeof(localTempChar));
	replace_filename(localTempChar,localTempChar,"\0",sizeof(localTempChar));
	strcpy(mondirectory,localTempChar) ;
}
