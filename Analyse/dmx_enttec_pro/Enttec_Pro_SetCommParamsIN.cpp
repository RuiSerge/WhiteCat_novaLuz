int Enttec_Pro_SetCommParamsIN()
{
	// SetCommState & Timeouts
	DCB dcbIN;
	GetCommState(com_handle_IN, &dcbIN);



	dcbIN.fBinary = true; /* binary mode, no EOF check */
	dcbIN.fErrorChar = false; /* disable error replacement */
	dcbIN.fAbortOnError = false;

	/* Set the baud rate */
	dcbIN.BaudRate = 57600;

	/* Set the data characteristics */
	dcbIN.ByteSize = 8; /* 8 data bits */
	dcbIN.StopBits = ONESTOPBIT; /* 1 stop bit */
	dcbIN.fParity = NOPARITY; /* no parity */
	dcbIN.Parity = 0;

	/* diable all flow control stuff */
	dcbIN.fDtrControl = DTR_CONTROL_DISABLE;
	dcbIN.fRtsControl = RTS_CONTROL_DISABLE;
	dcbIN.fInX = FALSE;
	dcbIN.fOutX = FALSE;
	dcbIN.fOutxDsrFlow = FALSE;
	dcbIN.fOutxCtsFlow = FALSE;

	SetCommState(com_handle_IN, &dcbIN);

    COMMTIMEOUTS timeoutsIN;
	GetCommTimeouts(com_handle_IN, &timeoutsIN);
	/* set timimg values */
	timeoutsIN.ReadIntervalTimeout = 500;
	timeoutsIN.ReadTotalTimeoutMultiplier = 10;
	timeoutsIN.ReadTotalTimeoutConstant = 500;
	timeoutsIN.WriteTotalTimeoutMultiplier = 10;
	timeoutsIN.WriteTotalTimeoutConstant = 500;

	SetCommTimeouts(com_handle_IN, &timeoutsIN);

	return 0;
}
