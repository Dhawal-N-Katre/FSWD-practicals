<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Dhawal Katre | Developer</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">

	<link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400;700&family=Poppins:wght@300;500;700&display=swap" rel="stylesheet">

	<style>

    .hero{
  min-height:100vh;
  display:flex;
  align-items:center;
  justify-content:space-between;
  padding:50px 10%;
  gap:50px;
}

.hero-left img{
  height:400px;
  width:300px;
  margin:0; /* IMPORTANT */
  border-radius:20px;
}

.hero-right{
  max-width:500px;
}

     

		:root{
  --bg:#020617;
  --card:#020d2b;
  --neon:#00f7ff;
  --blue:#00bfff;
  --text:#e5e7eb;
}
*{margin:0;padding:0;box-sizing:border-box}
html{scroll-behavior:smooth}

body{
  font-family:Poppins,sans-serif;
  background:#020617;
  color:var(--text);
  overflow-x:hidden;
}


/* TECH GRID BACKGROUND */
body::before{
  content:"";
  position:fixed;
  inset:0;
  background:
    linear-gradient(rgba(34,211,238,0.05) 1px, transparent 1px),
    linear-gradient(90deg, rgba(34,211,238,0.05) 1px, transparent 1px);
    background-attachment: fixed;
  background-size:40px 40px;
  z-index:-2;
}

/* GLOW ORBS */
.orb{
  position:fixed;
  width:450px;
  height:450px;
  filter:blur(140px);
  opacity:0.35;
  z-index:-1;
  animation: float 12s infinite alternate;
}
.orb.blue{
  background:#22d3ee;
  top:-150px;
  left:-150px;
}
.orb.pink{
  background:#f43f5e;
  bottom:-150px;
  right:-150px;
}

/* CURSOR */
.cursor{
  width:32px;
  height:32px;
  border:2px solid #22d3ee;
  border-radius:50%;
  position:fixed;
  pointer-events:none;
  transform:translate(-50%,-50%);
  z-index:9999;
}
.cursor-dot{
  width:6px;
  height:6px;
  background:#22d3ee;
  border-radius:50%;
  position:fixed;
  pointer-events:none;
  transform:translate(-50%,-50%);
  z-index:9999;
}

		/* HERO */
.hero{
  min-height:100vh;
  display:flex;
  align-items:center;
  justify-content:center;
  text-align:center;
  padding:100px 20px;
}
.hero h2{
  font-family:Orbitron;
  font-size:3rem;
}
.hero span{color:var(--neon)}
.typing{
  margin-top:15px;
  font-size:1.2rem;
  opacity:.85;
}
.btn{
  display:inline-block;
  margin:20px 10px;
  padding:12px 30px;
  border-radius:30px;
  border:2px solid var(--neon);
  color:var(--neon);
  text-decoration:none;
  transition:.3s;
}
.btn:hover{
  background:var(--neon);
  color:black;
  box-shadow:0 0 20px var(--neon);
}

/* SECTIONS */
section{padding:90px 10%}
h3{
  text-align:center;
  font-family:Orbitron;
  color:var(--neon);
  font-size:2.3rem;
  margin-bottom:50px;
}

/* CARDS */
.grid{
  display:grid;
  grid-template-columns:repeat(auto-fit,minmax(260px,1fr));
  gap:30px;
}
.card{
  background:linear-gradient(145deg,#020d2b,#020617);
  padding:30px;
  border-radius:20px;
  box-shadow:0 0 20px rgba(0,191,255,.15);
  transition:.4s;
  text-align: center;
}
.card:hover{
  transform:translateY(-12px);
  box-shadow:0 0 45px rgba(0,247,255,.4);
}

/* SKILLS */
.skill{margin-bottom:20px}
.bar{
  height:8px;
  background:#020617;
  border-radius:10px;
  overflow:hidden;
}
.fill{
  height:100%;
  background:linear-gradient(90deg,var(--blue),var(--neon));
}

/* FOOTER */
footer{
  text-align:center;
  padding:30px;
  opacity:.6;
}

/* REVEAL */
.reveal{
  opacity:0;
  transform:translateY(40px);
  transition:1s;
}
.reveal.active{
  opacity:1;
  transform:none;
}
	</style>

</head>
<body>

	<div class="hero">
  <div class="hero-left">
    <img src="dhawal1 - Copy.jpeg">
  </div>

  <div class="hero-right">
    <h2>Hi, I'm <span>Dhawal Katre</span></h2>
    <div class="typing" id="typing"></div>
    <a class="btn" href="https://github.com/Dhawal-N-Katre" target="_blank">GitHub</a>
    <a class="btn" href="https://www.linkedin.com/in/dhawal-katre-9222a737a" target="_blank">LinkedIn</a>
  </div>
</div>

	<div class="orb blue"></div>
<div class="orb pink"></div>

<div class="cursor"></div>
<div class="cursor-dot"></div>


<!-- ABOUT -->
<section id="about" class="reveal">
<h3>About Me</h3>
<div class="card">
Hi, I’m Dhawal Katre, a passionate Computer Engineering student currently pursuing my B.Tech (2nd Year). I am an aspiring Web Developer who enjoys building clean, functional, and user-friendly web applications.

I have a strong foundation in programming with languages like C, C++, and JavaScript, along with front-end technologies such as HTML and CSS. I actively apply my knowledge by working on real-world projects, which helps me strengthen both my technical skills and problem-solving abilities.

I am a fast learner who adapts quickly to new technologies and concepts. Even though I am at the early stage of my career and have not yet gained formal industry experience or internships, I focus on continuously improving my skills through hands-on practice and self-learning.

I strongly believe in learning by doing, and I am always exploring new tools and technologies to grow as a developer. My goal is to become a skilled software developer and contribute to innovative and impactful projects in the tech industry.
</div>
</section>

<!-- SKILLS -->
<section id="skills" class="reveal">
<h3>Skills & Tools</h3>
<div class="grid">
<div class="card">
<div class="skill">C / C++
<div class="bar"><div class="fill" style="width:80%"></div></div>
</div>
<div class="skill">HTML
<div class="bar"><div class="fill" style="width:85%"></div></div>
</div>
<div class="skill">CSS
<div class="bar"><div class="fill" style="width:80%"></div></div>
</div>
<div class="skill">JavaScript
<div class="bar"><div class="fill" style="width:65%"></div></div>
</div>
<div class="skill">GitHub
<div class="bar"><div class="fill" style="width:85%"></div></div>
</div>
I am continuously learning and expanding my knowledge in modern web technologies to build better and more efficient applications.
</div>
</div>
</section>

<!-- PROJECTS -->
<section id="projects" class="reveal">
<h3>Projects</h3>
<div class="grid">
<div class="card">
<h4>🏠 Home Automation System</h4>
<p>Developed a smart system that allows users to control home appliances efficiently.
This project focuses on automation, convenience, and improving everyday life using technology.<br>

Key Highlights:<br>

Automation of electrical devices<br>
User-friendly control system<br>
Practical implementation of embedded concepts</p>
</div>
<div class="card">
<h4>👣 Footstep Energy Generator</h4>
<p>Created an innovative system that generates electricity from human footsteps.
This project demonstrates how renewable energy can be generated using simple mechanical principles.<br>

Key Highlights:<br>

Eco-friendly energy generation<br>
Sustainable technology concept<br>
Practical application of physics and engineering</p>
</div>
</div>
</section>

<!-- CONTACT -->
<section id="contact" class="reveal">
<h3>Contact</h3>
<div class="card">
<p>💻 Open for internships & projects</p>
<p>🔗 Connect via GitHub & LinkedIn</p>
</div>
</section>

<footer> Built with Tech ⚡</footer>

<script>
	const cursor = document.querySelector(".cursor");
const dot = document.querySelector(".cursor-dot");

document.addEventListener("mousemove", e=>{
  cursor.style.left = e.clientX + "px";
  cursor.style.top = e.clientY + "px";
  dot.style.left = e.clientX + "px";
  dot.style.top = e.clientY + "px";
});


// TYPING
const text=["Computer Engineering Student","Web Developer","Automation & Tech Enthusiast"];
let i=0,j=0;
const typing=document.getElementById("typing");
function type(){
  if(j<text[i].length){
    typing.textContent+=text[i][j++];
    setTimeout(type,80);
  }else{
    setTimeout(erase,1500);
  }
}
function erase(){
  if(j>0){
    typing.textContent=text[i].substring(0,--j);
    setTimeout(erase,40);
  }else{
    i=(i+1)%text.length;
    setTimeout(type,300);
  }
}
type();

// REVEAL
const reveals=document.querySelectorAll(".reveal");
window.addEventListener("scroll",()=>{
  reveals.forEach(r=>{
    if(r.getBoundingClientRect().top<window.innerHeight-100)
      r.classList.add("active");
  });
});

</script>

</body>
</html>
