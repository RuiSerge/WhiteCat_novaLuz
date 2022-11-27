void ShowSupportedAudioDevices()
{
    std::vector<audiere::AudioDeviceDesc> devices;
    audiere::GetSupportedAudioDevices(devices);

    for(unsigned int i=0; i<devices.size(); i++)
    {
        sprintf(list_audio_device[i],"%s-%s",devices[i].name.c_str(),devices[i].description.c_str());
    }
}
