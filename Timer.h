#include <SDL.h>
#include <chrono>
#pragma once

class Timer
{
public:
	void Tick();
	inline float GetDeltaTime() { return m_deltaTime; }
	inline static Timer* GetInstance() { return s_Instance = (s_Instance != nullptr)? s_Instance : new Timer (); }

	void CalculateFPS();
	inline float GetCurrentFPS() { return m_currentFPS; }
	inline float GetRecentFPS() { return m_recentFPS; }
	inline double GetTimer() { return m_timer; }

private:
	Timer() {}
	static Timer* s_Instance;
	float m_deltaTime;
	double m_timer;
	float m_recentFPS;
	float m_currentFPS;

	std::chrono::time_point<std::chrono::high_resolution_clock> m_currentFPSTimer;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_recentFPSTimer;

};

