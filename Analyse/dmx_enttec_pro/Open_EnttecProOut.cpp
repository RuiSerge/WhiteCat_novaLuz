int Open_EnttecProOut()
{
 	char com_str[10];
	sprintf(com_str,"%s:",DeviceName);
	LPSTR lpszPortName = _T(com_str);
	com_handle_ = CreateFile(
		lpszPortName,
		GENERIC_READ | GENERIC_WRITE,
		0,								// DWORD dwShareMode,
		NULL,							// LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		OPEN_EXISTING,					// DWORD dwCreationDispostion,
		0, //FILE_FLAG_OVERLAPPED,		// DWORD dwFlagsAndAttributes,
		NULL							// HANDLE hTemplateFile
	);

	/*sab 23/11/2022 - deb
	int iRet = (int)(com_handle_ );
	*/
	int iRet = (int) GetLastError();
	/*sab 23/11/2022 - fin */

	if (iRet<0)
	{
    com_handle_ = NULL;
    index_init_dmx_ok[3]=0;
	sprintf(string_display_dmx_params,"Impossible to open ENTTEC PRO Out, is it PLUGGED ?");
    return(0);
	}

	// SetCommState & Timeout
    Enttec_Pro_SetCommParams();

	// flush rx & tx buffers
	res = FlushFileBuffers(com_handle_);
	if (!res)
	{
    sprintf(string_display_dmx_params,"ENTTEC PRO Out: Flush file buffers failed...");
	CloseHandle(com_handle_); com_handle_ = NULL;
	return(0);
	}
return(0);
}
