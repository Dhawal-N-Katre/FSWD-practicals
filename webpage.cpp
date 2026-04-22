<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Welcome - Login & Register</title>
<link href="https://fonts.googleapis.com/css2?family=Sora:wght@400;600;700&family=DM+Sans:wght@400;500&display=swap" rel="stylesheet">
<style>
  :root {
    --bg: #eef0f5;
    --card: #ffffff;
    --blue: #1aa3e8;
    --blue-dark: #0e8ecf;
    --text: #0d1b2a;
    --muted: #8a96a3;
    --border: #dde2ea;
    --input-bg: #f7f9fc;
    --shadow: 0 8px 40px rgba(0,0,0,0.10);
  }
  * { box-sizing: border-box; margin: 0; padding: 0; }
  body {
    font-family: 'DM Sans', sans-serif;
    background: var(--bg);
    min-height: 100vh;
    display: flex;
    align-items: center;
    justify-content: center;
    padding: 24px;
  }
  .card {
    background: var(--card);
    border-radius: 20px;
    box-shadow: var(--shadow);
    padding: 48px 52px;
    width: 100%;
    max-width: 900px;
  }
  h1 {
    font-family: 'Sora', sans-serif;
    font-size: 2.2rem;
    font-weight: 700;
    color: var(--text);
    margin-bottom: 6px;
  }
  .subtitle {
    color: var(--muted);
    font-size: 0.95rem;
    margin-bottom: 36px;
  }
  .panels {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 60px;
  }
  .divider {
    width: 1px;
    background: var(--border);
    position: absolute;
    top: 0; bottom: 0;
    left: 50%;
    transform: translateX(-50%);
  }
  .panels-wrapper {
    position: relative;
  }
  h2 {
    font-family: 'Sora', sans-serif;
    font-size: 1.25rem;
    font-weight: 600;
    color: var(--text);
    margin-bottom: 20px;
  }
  .field {
    width: 100%;
    padding: 13px 16px;
    border: 1.5px solid var(--border);
    border-radius: 10px;
    background: var(--input-bg);
    font-family: 'DM Sans', sans-serif;
    font-size: 0.9rem;
    color: var(--text);
    outline: none;
    transition: border-color 0.2s, box-shadow 0.2s;
    margin-bottom: 14px;
    display: block;
  }
  .field:focus {
    border-color: var(--blue);
    box-shadow: 0 0 0 3px rgba(26,163,232,0.12);
    background: #fff;
  }
  .field::placeholder { color: var(--muted); }
  .row { display: grid; grid-template-columns: 1fr 1fr; gap: 12px; }
  .row .field { margin-bottom: 0; }
  .row-wrap { margin-bottom: 14px; }
  .security-row {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 12px;
    margin-bottom: 14px;
  }
  .security-row .field { margin-bottom: 0; }
  select.field { appearance: none; cursor: pointer; background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='12' height='8' viewBox='0 0 12 8'%3E%3Cpath d='M1 1l5 5 5-5' stroke='%238a96a3' stroke-width='1.5' fill='none' stroke-linecap='round'/%3E%3C/svg%3E"); background-repeat: no-repeat; background-position: right 14px center; padding-right: 36px; }
  .btn {
    width: 100%;
    padding: 14px;
    border: none;
    border-radius: 10px;
    font-family: 'Sora', sans-serif;
    font-size: 1rem;
    font-weight: 600;
    cursor: pointer;
    transition: background 0.2s, transform 0.1s, box-shadow 0.2s;
    margin-top: 6px;
  }
  .btn-primary {
    background: var(--blue);
    color: #fff;
    box-shadow: 0 4px 18px rgba(26,163,232,0.35);
  }
  .btn-primary:hover { background: var(--blue-dark); box-shadow: 0 6px 22px rgba(26,163,232,0.45); }
  .btn-primary:active { transform: scale(0.98); }
  .btn-secondary {
    background: transparent;
    color: var(--text);
    border: 1.5px solid var(--border);
  }
  .btn-secondary:hover { border-color: var(--blue); color: var(--blue); }
  .btn-secondary:active { transform: scale(0.98); }

  @media (max-width: 680px) {
    .card { padding: 32px 20px; }
    .panels { grid-template-columns: 1fr; gap: 36px; }
    .divider { display: none; }
  }
</style>
</head>
<body>
<div class="card">
  <h1>Welcome</h1>
  <p class="subtitle">Login or create your account below</p>

  <div class="panels-wrapper" style="position:relative;">
    <div class="panels">
      <!-- LOGIN -->
      <div>
        <h2>Login</h2>
        <input class="field" type="email" placeholder="Email">
        <input class="field" type="password" placeholder="Password">
        <div class="security-row">
          <select class="field">
            <option value="" disabled selected>Select Security Question</option>
            <option>What is your father's name?</option>
            <option>What is your best friend's name?</option>
            <option>How many siblings do you have?</option>
            <option>What is your father's nickname?</option>
          </select>
          <input class="field" type="text" placeholder="Security Answer">
        </div>
        <button class="btn btn-primary">Login</button>
      </div>

      <!-- REGISTER -->
      <div>
        <h2>Register</h2>
        <div class="row row-wrap">
          <input class="field" type="text" placeholder="First Name">
          <input class="field" type="text" placeholder="Last Name">
        </div>
        <input class="field" type="email" placeholder="Email">
        <input class="field" type="tel" placeholder="Phone Number">
        <div class="row row-wrap">
          <input class="field" type="password" placeholder="Password">
          <input class="field" type="password" placeholder="Confirm Password">
        </div>
        <div class="security-row">
          <select class="field">
            <option value="" disabled selected>Select Security Question</option>
            <option>What is your father's name?</option>
            <option>What is your best friend's name?</option>
            <option>How many siblings do you have?</option>
            <option>What is your father's nickname?</option>
          </select>
          <input class="field" type="text" placeholder="Security Answer">
        </div>
        <button class="btn btn-secondary">Create Account</button>
      </div>
    </div>
  </div>
</div>
</body>
</html>
