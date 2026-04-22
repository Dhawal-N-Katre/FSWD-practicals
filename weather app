<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Weather App</title>
<link href="https://fonts.googleapis.com/css2?family=Sora:wght@600;700&family=DM+Sans:wght@400;500&display=swap" rel="stylesheet">
<style>
  * { box-sizing: border-box; margin: 0; padding: 0; }
  body {
    font-family: 'DM Sans', sans-serif;
    min-height: 100vh;
    display: flex;
    align-items: center;
    justify-content: center;
    background: linear-gradient(135deg, #89b4f7 0%, #a78bfa 100%);
  }
  .card {
    background: #fff;
    border-radius: 18px;
    box-shadow: 0 8px 40px rgba(0,0,0,0.13);
    padding: 36px 40px 32px;
    width: 380px;
    text-align: center;
  }
  h1 {
    font-family: 'Sora', sans-serif;
    font-size: 1.5rem;
    font-weight: 700;
    color: #0d1b2a;
    margin-bottom: 24px;
  }
  .search-row {
    display: flex;
    gap: 10px;
    margin-bottom: 24px;
  }
  #city-input {
    flex: 1;
    padding: 10px 14px;
    border: 1.5px solid #dde2ea;
    border-radius: 8px;
    font-family: 'DM Sans', sans-serif;
    font-size: 0.95rem;
    outline: none;
    transition: border-color 0.2s;
  }
  #city-input:focus { border-color: #2979ff; }
  button {
    padding: 10px 20px;
    background: #2979ff;
    color: #fff;
    border: none;
    border-radius: 8px;
    font-family: 'Sora', sans-serif;
    font-size: 0.9rem;
    font-weight: 600;
    cursor: pointer;
    transition: background 0.2s;
  }
  button:hover { background: #1a5fd4; }
  #result {
    font-size: 1rem;
    color: #0d1b2a;
    line-height: 2;
    min-height: 60px;
  }
  #result.error { color: #e53935; }
  #result .value { font-weight: 600; }
  #loading { color: #888; font-size: 0.9rem; }

  /* API key notice */
  .notice {
    margin-top: 20px;
    font-size: 0.78rem;
    color: #aaa;
  }
  .notice a { color: #2979ff; }
</style>
</head>
<body>
<div class="card">
  <h1>Weather App</h1>

  <!-- ⚠️ Apna API key yahan paste karo -->
  <input type="text" id="api-key-input" placeholder="🔑 Paste your OpenWeatherMap API key here" style="width:100%;padding:9px 12px;border:1.5px dashed #f0a500;border-radius:8px;font-size:0.82rem;margin-bottom:14px;outline:none;color:#555;">

  <div class="search-row">
    <input type="text" id="city-input" placeholder="Enter city name..." value="Nagpur" />
    <button onclick="getWeather()">Search</button>
  </div>

  <div id="result"></div>

  <p class="notice">
    Free API key: <a href="https://openweathermap.org/api" target="_blank">openweathermap.org/api</a><br>
    (Register → Copy API key → Paste above)
  </p>
</div>

<script>
  async function getWeather() {
    const city = document.getElementById('city-input').value.trim();
    const apiKey = document.getElementById('api-key-input').value.trim();
    const resultDiv = document.getElementById('result');

    if (!city) {
      resultDiv.className = 'error';
      resultDiv.innerHTML = 'Please enter a city name.';
      return;
    }
    if (!apiKey) {
      resultDiv.className = 'error';
      resultDiv.innerHTML = '⚠️ Please paste your OpenWeatherMap API key above first!';
      return;
    }

    resultDiv.className = '';
    resultDiv.innerHTML = '<span id="loading">Fetching weather...</span>';

    const url = `https://api.openweathermap.org/data/2.5/weather?q=${encodeURIComponent(city)}&appid=${apiKey}&units=metric`;

    try {
      const res = await fetch(url);
      const data = await res.json();

      if (data.cod !== 200) {
        resultDiv.className = 'error';
        resultDiv.innerHTML = `❌ ${data.message || 'City not found!'}`;
        return;
      }

      const temp = data.main.temp.toFixed(2);
      const weather = data.weather[0].main;
      const humidity = data.main.humidity;
      const icon = data.weather[0].icon;

      resultDiv.className = '';
      resultDiv.innerHTML = `
        <img src="https://openweathermap.org/img/wn/${icon}@2x.png" style="width:60px;margin-bottom:4px;"><br>
        Temperature: <span class="value">${temp} °C</span><br>
        Weather: <span class="value">${weather}</span><br>
        Humidity: <span class="value">${humidity}%</span>
      `;
    } catch (err) {
      resultDiv.className = 'error';
      resultDiv.innerHTML = '❌ Network error. Please check your connection.';
    }
  }

  document.getElementById('city-input').addEventListener('keydown', function(e) {
    if (e.key === 'Enter') getWeather();
  });
</script>
</body>
</html>
