<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Chat Bot</title>
<link href="https://fonts.googleapis.com/css2?family=Sora:wght@600;700&family=DM+Sans:wght@400;500&display=swap" rel="stylesheet">
<style>
  * { box-sizing: border-box; margin: 0; padding: 0; }
  body {
    font-family: 'DM Sans', sans-serif;
    background: #eef0f5;
    min-height: 100vh;
    display: flex;
    align-items: center;
    justify-content: center;
  }
  .card {
    background: #fff;
    border-radius: 18px;
    box-shadow: 0 8px 40px rgba(0,0,0,0.10);
    padding: 28px 28px 24px;
    width: 380px;
  }
  h1 {
    font-family: 'Sora', sans-serif;
    font-size: 1.3rem;
    font-weight: 700;
    text-align: center;
    color: #0d1b2a;
    margin-bottom: 16px;
  }
  #chat-box {
    background: #f5f6f8;
    border: 1px solid #dde2ea;
    border-radius: 10px;
    padding: 16px;
    height: 300px;
    overflow-y: auto;
    display: flex;
    flex-direction: column;
    gap: 8px;
    margin-bottom: 16px;
  }
  .msg { font-size: 0.9rem; line-height: 1.5; }
  .msg .label { font-weight: 600; }
  .msg.user .label { color: #1a56e8; }
  .msg.bot .label { color: #1a9e5e; }
  .msg.user .text { color: #0d1b2a; }
  .msg.bot .text { color: #0d1b2a; }
  .input-row {
    display: flex;
    gap: 10px;
  }
  #user-input {
    flex: 1;
    padding: 10px 14px;
    border: 1.5px solid #dde2ea;
    border-radius: 8px;
    font-family: 'DM Sans', sans-serif;
    font-size: 0.9rem;
    outline: none;
    transition: border-color 0.2s;
  }
  #user-input:focus { border-color: #1a56e8; }
  button {
    padding: 10px 20px;
    background: #1a56e8;
    color: #fff;
    border: none;
    border-radius: 8px;
    font-family: 'Sora', sans-serif;
    font-size: 0.9rem;
    font-weight: 600;
    cursor: pointer;
    transition: background 0.2s;
  }
  button:hover { background: #1441c0; }
</style>
</head>
<body>
<div class="card">
  <h1>Chat Bot</h1>
  <div id="chat-box"></div>
  <div class="input-row">
    <input type="text" id="user-input" placeholder="Type a message..." />
    <button onclick="sendMessage()">Send</button>
  </div>
</div>

<script>
  const responses = {
    "hi": "Hello",
    "hello": "Hello! How can I help you?",
    "hey": "Hey there!",
    "what is your name": "I am a simple JavaScript chatbot",
    "your name": "I am a simple JavaScript chatbot",
    "who are you": "I am a simple JavaScript chatbot",
    "how are you": "I am fine",
    "how r u": "I am fine, thanks!",
    "what can you do": "I can chat with you! Try asking me something.",
    "bye": "Goodbye! Have a nice day!",
    "good morning": "Good morning! Hope you have a great day!",
    "good night": "Good night! Sweet dreams!",
    "thank you": "You're welcome!",
    "thanks": "No problem!",
    "help": "You can ask me things like: 'what is your name', 'how are you', etc.",
  };

  function getBotReply(input) {
    const lower = input.toLowerCase().trim();
    for (const key in responses) {
      if (lower.includes(key)) return responses[key];
    }
    return "Sorry, I didn't understand that. Try asking something else!";
  }

  function appendMessage(sender, text, type) {
    const chatBox = document.getElementById('chat-box');
    const div = document.createElement('div');
    div.className = `msg ${type}`;
    div.innerHTML = `<span class="label">${sender}:</span> <span class="text">${text}</span>`;
    chatBox.appendChild(div);
    chatBox.scrollTop = chatBox.scrollHeight;
  }

  function sendMessage() {
    const input = document.getElementById('user-input');
    const text = input.value.trim();
    if (!text) return;

    appendMessage('You', text, 'user');
    input.value = '';

    setTimeout(() => {
      const reply = getBotReply(text);
      appendMessage('Bot', reply, 'bot');
    }, 400);
  }

  document.getElementById('user-input').addEventListener('keydown', function(e) {
    if (e.key === 'Enter') sendMessage();
  });
</script>
</body>
</html>
