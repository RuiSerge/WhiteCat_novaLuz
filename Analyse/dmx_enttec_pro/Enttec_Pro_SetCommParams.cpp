int Enttec_Pro_SetCommParams()
{
    // SetCommState & Timeouts
    DCB dcb;
    GetCommState(com_handle_, &dcb);


    dcb.fBinary = true; /* binary mode, no EOF check */
    dcb.fErrorChar = false; /* disable error replacement */
    dcb.fAbortOnError = false;
    /* Set the baud rate */
    dcb.BaudRate = 57600;

    /* Set the data characteristics */
    dcb.ByteSize = 8; /* 8 data bits */
    dcb.StopBits = ONESTOPBIT; /* 1 stop bit */
    dcb.fParity = NOPARITY; /* no parity */
    dcb.Parity = 0;

    /* diable all flow control stuff */
    dcb.fDtrControl = DTR_CONTROL_DISABLE;
    dcb.fRtsControl = RTS_CONTROL_DISABLE;
    dcb.fInX = FALSE;
    dcb.fOutX = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fOutxCtsFlow = FALSE;

    SetCommState(com_handle_, &dcb);

    COMMTIMEOUTS timeouts;
    GetCommTimeouts(com_handle_, &timeouts);
    /* set timimg values */
    timeouts.ReadIntervalTimeout = 500;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.ReadTotalTimeoutConstant = 500;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 500;

    SetCommTimeouts(com_handle_, &timeouts);

    return (0);
}
