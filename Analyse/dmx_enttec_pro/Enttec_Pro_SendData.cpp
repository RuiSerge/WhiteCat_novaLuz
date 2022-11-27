int Enttec_Pro_SendData(int label, unsigned char *data, unsigned int length, LPOVERLAPPED lpOverlapped)
{

	BOOL res = false;
	DWORD bytes_written = 0;
	//HANDLE event = NULL;

	unsigned char header[4];
	header[0] = 0x7E;
	header[1] = label;
	header[2] = length & 0xFF;
	header[3] = length >> 8;

	res = WriteFile(
		com_handle_,					//Instance de votre accès au port série
		(unsigned char *)header,		//Pointeur sur la donnée à écrire
		4,								//Nombre de bytes à écrire
		&bytes_written,					//pointeur to number of bytes written
		lpOverlapped					//Doit être NULL pour windows CE
	);
	if (!res || (bytes_written != 4)) return -1;


	res = WriteFile(
		com_handle_,					//Instance de votre accès au port série
		(unsigned char *)data,			//Pointeur sur la donnée à écrire
		length,							//Nombre de bytes à écrire
		&bytes_written,					//pointeur to number of bytes written
		lpOverlapped			        //Doit être NULL pour windows CE
	);
	if (!res || (bytes_written != length)) return -1;


	unsigned char end_code = 0xE7;
	res = WriteFile(
		com_handle_,					//Instance de votre accès au port série
		(unsigned char *)&end_code,		//Pointeur sur la donnée à écrire
		1,								//Nombre de bytes à écrire
		&bytes_written,					//pointeur to number of bytes written
		lpOverlapped					//Doit être NULL pour windows CE
	);
	if (!res || (bytes_written != 1)) return -1;

	return 0;
}
