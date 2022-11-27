uint16_t Enttec_Pro_ReceiveData(uint16_t label, uint8_t *data, uint32_t expected_length)
{

	BOOL resIn = 0;
	DWORD length = 0;
	DWORD bytes_read = 0;
	uint8_t byte = 0;
	//HANDLE eventIN = NULL;
	char buffer[513];

	while (byte != label)
	{
		while (byte != 0x7E )
		{
			resIn = READ_ONE_BYTE(com_handle_IN,(uint8_t *)&byte,&bytes_read,NULL );
			if (!resIn || (bytes_read != 1)) return  0;
		}
		if (byte != 0x7E ) continue;

		resIn = READ_ONE_BYTE(com_handle_IN,(uint8_t *)&byte,&bytes_read,NULL );
		if (!resIn || (bytes_read != 1)) return  0;
	}

	resIn = READ_ONE_BYTE(com_handle_IN,(uint8_t *)&byte,&bytes_read,NULL );
	if (!resIn || (bytes_read != 1)) return  0;
	length = byte;


	resIn = READ_ONE_BYTE(com_handle_IN,(uint8_t *)&byte,&bytes_read,NULL );
	if (!resIn || (bytes_read != 1)) return  0;
	length += ((uint32_t)byte)<<8;

	if (length > 513)
		return  0;

	resIn = ReadFile(com_handle_IN,buffer,length,&bytes_read,NULL );
	if (!resIn || (bytes_read != length)) return  0;

	resIn = READ_ONE_BYTE(com_handle_IN,(uint8_t *)&byte,&bytes_read,NULL );
	if (!resIn || (bytes_read != 1)) return  0;
	if (byte != 0xE7) return  0;

	memcpy(data,buffer,expected_length);

	return expected_length;
}
