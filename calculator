<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Calculator</title>
<link href="https://fonts.googleapis.com/css2?family=Sora:wght@600;700&family=DM+Mono:wght@400;500&display=swap" rel="stylesheet">
<style>
  * { box-sizing: border-box; margin: 0; padding: 0; }
  body {
    font-family: 'Sora', sans-serif;
    background: #f0f0f0;
    min-height: 100vh;
    display: flex;
    align-items: center;
    justify-content: center;
  }
  .calc {
    background: #1e1e1e;
    border-radius: 16px;
    padding: 28px 24px 24px;
    width: 300px;
    box-shadow: 0 12px 50px rgba(0,0,0,0.35);
  }
  h1 {
    color: #fff;
    font-size: 1.3rem;
    font-weight: 700;
    text-align: center;
    margin-bottom: 20px;
    letter-spacing: 0.5px;
  }
  #display {
    width: 100%;
    background: #fff;
    border: none;
    border-radius: 8px;
    padding: 14px 16px;
    font-family: 'DM Mono', monospace;
    font-size: 1.5rem;
    text-align: right;
    color: #1e1e1e;
    margin-bottom: 16px;
    outline: none;
    pointer-events: none;
    min-height: 58px;
    word-break: break-all;
  }
  .buttons {
    display: grid;
    grid-template-columns: repeat(4, 1fr);
    gap: 10px;
  }
  .btn {
    background: #f5f5f5;
    border: none;
    border-radius: 8px;
    padding: 18px 0;
    font-family: 'Sora', sans-serif;
    font-size: 1.1rem;
    font-weight: 600;
    color: #1e1e1e;
    cursor: pointer;
    transition: background 0.15s, transform 0.1s;
  }
  .btn:hover { background: #e0e0e0; }
  .btn:active { transform: scale(0.94); background: #d0d0d0; }
  .btn.equals {
    grid-column: span 2;
    background: #f5a623;
    color: #fff;
    font-size: 1.3rem;
  }
  .btn.equals:hover { background: #e0941a; }
  .btn.equals:active { background: #cc8515; }
  .btn.operator { color: #f5a623; }
  .btn.clear { color: #e53935; }
</style>
</head>
<body>
<div class="calc">
  <h1>Calculator</h1>
  <div id="display">0</div>
  <div class="buttons">
    <!-- Row 1 -->
    <button class="btn clear"    onclick="clearAll()">C</button>
    <button class="btn operator" onclick="append('/')">÷</button>
    <button class="btn operator" onclick="append('*')">×</button>
    <button class="btn operator" onclick="append('-')">−</button>
    <!-- Row 2 -->
    <button class="btn" onclick="append('7')">7</button>
    <button class="btn" onclick="append('8')">8</button>
    <button class="btn" onclick="append('9')">9</button>
    <button class="btn operator" onclick="append('+')">+</button>
    <!-- Row 3 -->
    <button class="btn" onclick="append('4')">4</button>
    <button class="btn" onclick="append('5')">5</button>
    <button class="btn" onclick="append('6')">6</button>
    <button class="btn" onclick="append('1')">1</button>
    <!-- Row 4 -->
    <button class="btn" onclick="append('2')">2</button>
    <button class="btn" onclick="append('3')">3</button>
    <button class="btn" onclick="append('0')">0</button>
    <button class="btn" onclick="append('.')">.</button>
    <!-- Row 5 -->
    <button class="btn equals" onclick="calculate()">=</button>
    <button class="btn" onclick="backspace()">⌫</button>
    <button class="btn" onclick="append('%')">%</button>
  </div>
</div>

<script>
  let expression = '';
  let justCalculated = false;

  function updateDisplay(val) {
    const d = document.getElementById('display');
    d.textContent = val === '' ? '0' : val;
  }

  function append(val) {
    const operators = ['+', '-', '*', '/'];
    if (justCalculated && !operators.includes(val)) {
      expression = '';
    }
    justCalculated = false;

    // Prevent double operators
    if (operators.includes(val) && operators.includes(expression.slice(-1))) {
      expression = expression.slice(0, -1);
    }
    // Prevent leading operator (except minus)
    if (expression === '' && operators.includes(val) && val !== '-') return;

    expression += val;
    updateDisplay(expression);
  }

  function clearAll() {
    expression = '';
    justCalculated = false;
    updateDisplay('0');
  }

  function backspace() {
    expression = expression.slice(0, -1);
    updateDisplay(expression || '0');
  }

  function calculate() {
    if (!expression) return;
    try {
      let result = Function('"use strict"; return (' + expression + ')')();
      if (!isFinite(result)) {
        updateDisplay('Error');
        expression = '';
        return;
      }
      // Round floating point issues
      result = parseFloat(result.toPrecision(12));
      updateDisplay(result);
      expression = String(result);
      justCalculated = true;
    } catch (e) {
      updateDisplay('Error');
      expression = '';
    }
  }

  // Keyboard support
  document.addEventListener('keydown', function(e) {
    if ('0123456789'.includes(e.key)) append(e.key);
    else if (['+', '-', '*', '/', '.', '%'].includes(e.key)) append(e.key);
    else if (e.key === 'Enter' || e.key === '=') calculate();
    else if (e.key === 'Backspace') backspace();
    else if (e.key === 'Escape') clearAll();
  });
</script>
</body>
</html>
