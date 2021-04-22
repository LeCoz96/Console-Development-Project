#include "Timer.h"

Timer* Timer::s_Instance = nullptr;

void Timer::Tick()
{
	m_currentFPSTimer = std::chrono::steady_clock::now();

	m_deltaTime = std::chrono::duration<float, std::milli>(m_currentFPSTimer - m_recentFPSTimer).count();

	m_deltaTime /= 1000.0f;
}

void Timer::CalculateFPS()
{
	m_recentFPSTimer = m_currentFPSTimer;

	m_currentFPS++;
	m_timer += m_deltaTime;

	if (m_timer >= 1)				// If timer is > 1 second the frame count will be recorded in m_recentFPS
	{
		m_timer = 0;				// Reset Timer
		m_recentFPS = m_currentFPS;	// 
		m_currentFPS = 0;			// Reset current frame count
	}
}
