#include <chrono>
#pragma once

class Timer
{
public:

	void Tick();
	static Timer* GetInstance() { return s_instance = (s_instance != nullptr) ? s_instance : new Timer(); }

	void CalculateFPS();

	inline float GetDeltaTime() { return m_deltaTime; }
	inline float GetCurrentFPS() { return m_currentFrameAverage; }
	inline float GetLastFPS() { return m_recentFrame; }

	inline double GetElapsedTime() { return m_interval; }


private:
	Timer() {}

	static Timer* s_instance;

	float m_deltaTime{ 0.0f };
	float m_currentFrameAverage{ 0.0f };
	float m_recentFrame{ 0.0f };
	double m_interval{ 0.0f };

	std::chrono::time_point<std::chrono::high_resolution_clock> m_frameTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_lastFrameTime;
};

