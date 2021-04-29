#include "Timer.h"
#include <iostream>

Timer* Timer::s_instance = nullptr;

void Timer::Tick()
{
	m_frameTime = std::chrono::steady_clock::now();

	m_deltaTime = std::chrono::duration<float, std::milli>(m_frameTime - m_lastFrameTime).count();
	m_deltaTime /= 1000;
}

void Timer::CalculateFPS()
{
	m_lastFrameTime = m_frameTime;

	m_currentFrameAverage++;
	m_interval += m_deltaTime;

	if (m_interval >= 1) // If it is or has been longer than a second the frame average is saved under recent frame
	{
		m_interval = 0;
		m_recentFrame = m_currentFrameAverage;
		m_currentFrameAverage = 0;
	}
}
