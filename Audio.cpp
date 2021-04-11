#include "Audio.h"

Audio::Audio()
{
    //frequency value (KHz), Audio format, number of channels, total chunk size (Sample size)
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 512);
}

Audio::~Audio()
{
    if (&m_music != NULL)
    {
        for (int i = 0; i < m_music.size(); i++)
        {
            Mix_FreeMusic(m_music[i]);
        }
        m_music.clear();
    }
    if (&m_sfx != NULL)
    {
        for (int i = 0; i < m_sfx.size(); i++)
        {
            Mix_FreeChunk(m_sfx[i]);
        }
        pMusic = nullptr;
        pChunk = nullptr;
        Mix_CloseAudio();
    }
}

bool Audio::LoadAudio(std::string filename, int id, type AudioType, int volume)
{
    if (AudioType == MUSIC)
    {
        pMusic = Mix_LoadMUS(filename.c_str());
        if (!pMusic)
        {
            std::cout << "Unable to load music file: " << Mix_GetError() << std::endl;
            return false;
        }
        m_music.push_back(pMusic);
        Mix_VolumeMusic(volume);
        return true;
    }
    else if (AudioType == SFX)
    {
        pChunk = Mix_LoadWAV(filename.c_str());
        if (pChunk == 0)
        {
            std::cout << "Usable to load SFX file: " << Mix_GetError() << std::endl;
            return false;
        }
        Mix_VolumeChunk(pChunk, volume);
        m_sfx.push_back(pChunk);
        return true;
    }
    return false;
}

void Audio::PlayMusicTrack(int id, int loopNumber)
{
    Mix_PlayMusic(m_music[id], loopNumber);
}

void Audio::PlaySFX(int id, int loopNumber, int channel)
{
    if (!Mix_Playing(channel))
    {
        Mix_PlayChannel(channel, m_sfx[id], loopNumber);
    }
}

void Audio::FadeMusicTrack(int id, int loopNumber, int fadeLength)
{
    if (Mix_PlayingMusic())
    {
        Mix_FadeOutMusic(fadeLength);
    }
    Mix_FadeInMusic(m_music[id], loopNumber, fadeLength);
}
