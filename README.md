<!DOCTYPE html>
<html lang="uz">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>TARZ — Kiyim do'koni</title>
<link rel="preconnect" href="https://fonts.googleapis.com">
<link href="https://fonts.googleapis.com/css2?family=Fraunces:ital,opsz,wght@0,9..144,300;0,9..144,500;0,9..144,600;1,9..144,400&family=Space+Grotesk:wght@400;500;600&display=swap" rel="stylesheet">
<style>
  :root{
    --ink:#211f1a;
    --paper:#efe9dd;
    --clay:#b5502d;
    --olive:#5f6349;
    --mustard:#c99a2e;
    --line: rgba(33,31,26,0.15);
  }
  *{margin:0;padding:0;box-sizing:border-box;}
  html{scroll-behavior:smooth;}
  body{
    background:var(--paper);
    color:var(--ink);
    font-family:'Space Grotesk', sans-serif;
    overflow-x:hidden;
  }
  @media (prefers-reduced-motion: reduce){
    *{animation-duration:0.01ms !important; animation-iteration-count:1 !important; transition-duration:0.01ms !important;}
  }
  a{color:inherit;text-decoration:none;}
  img{display:block;max-width:100%;}

  /* ---------- NAV ---------- */
  nav{
    display:flex;
    justify-content:space-between;
    align-items:center;
    padding:28px 48px;
    position:relative;
    z-index:10;
  }
  .logo{
    font-family:'Fraunces', serif;
    font-weight:600;
    font-size:26px;
    letter-spacing:-0.01em;
  }
  .nav-links{
    display:flex;
    gap:36px;
    font-size:15px;
  }
  .nav-links a{
    position:relative;
    padding-bottom:3px;
  }
  .nav-links a::after{
    content:'';
    position:absolute;
    left:0;bottom:0;
    width:0;
    height:1px;
    background:var(--ink);
    transition:width .3s ease;
  }
  .nav-links a:hover::after{width:100%;}
  .nav-cart{
    display:flex; align-items:center; gap:8px; font-size:15px;
  }
  .dot{width:6px;height:6px;border-radius:50%;background:var(--clay);}

  @media(max-width:720px){
    nav{padding:20px 24px;}
    .nav-links{display:none;}
  }

  /* ---------- HERO ---------- */
  .hero{
    padding:64px 48px 0;
    display:grid;
    grid-template-columns:1.4fr 1fr;
    gap:40px;
    align-items:end;
  }
  .hero-text h1{
    font-family:'Fraunces', serif;
    font-weight:500;
    font-size:clamp(52px, 8vw, 118px);
    line-height:0.94;
    letter-spacing:-0.015em;
  }
  .hero-text h1 .line{
    display:block;
    overflow:hidden;
  }
  .hero-text h1 .word{
    display:inline-block;
    transform:translateY(110%);
    animation:riseUp 0.9s cubic-bezier(.19,1,.22,1) forwards;
  }
  @keyframes riseUp{
    to{transform:translateY(0);}
  }
  .hero-sub{
    max-width:340px;
    margin-top:28px;
    font-size:16px;
    line-height:1.6;
    color:var(--ink);
    opacity:0;
    animation:fadeIn 0.8s ease forwards 0.9s;
  }
  @keyframes fadeIn{ to{opacity:1;} }
  .hero-cta{
    display:inline-flex;
    align-items:center;
    gap:12px;
    margin-top:34px;
    padding:15px 26px;
    background:var(--ink);
    color:var(--paper);
    font-size:14px;
    border-radius:2px;
    opacity:0;
    animation:fadeIn 0.8s ease forwards 1.1s;
    transition:background .3s ease;
  }
  .hero-cta:hover{background:var(--clay);}

  .hero-frame{
    position:relative;
    aspect-ratio:3/4;
    overflow:hidden;
    border-radius:2px;
    opacity:0;
    animation:fadeIn 1s ease forwards 0.5s;
  }
  .hero-frame img{
    width:100%;height:100%;object-fit:cover;
    filter:saturate(0.85) contrast(1.05);
    transform:scale(1.08);
    transition:transform 8s ease;
  }
  .hero-frame:hover img{transform:scale(1);}
  .hero-tag{
    position:absolute;
    bottom:16px;left:16px;
    background:var(--paper);
    padding:8px 14px;
    font-size:13px;
    border-radius:2px;
  }

  @media(max-width:900px){
    .hero{grid-template-columns:1fr; padding:40px 24px 0;}
    .hero-frame{order:-1; aspect-ratio:4/3;}
  }

  /* ---------- MARQUEE ---------- */
  .marquee-wrap{
    margin-top:64px;
    border-top:1px solid var(--line);
    border-bottom:1px solid var(--line);
    overflow:hidden;
    white-space:nowrap;
    padding:16px 0;
  }
  .marquee{
    display:inline-block;
    animation:scroll 22s linear infinite;
    font-family:'Fraunces', serif;
    font-style:italic;
    font-size:20px;
  }
  .marquee span{
    margin:0 28px;
    color:var(--olive);
  }
  .marquee span:nth-child(3n){color:var(--clay);}
  @keyframes scroll{
    from{transform:translateX(0);}
    to{transform:translateX(-50%);}
  }

  /* ---------- SECTION HEADS ---------- */
  .section{
    padding:96px 48px;
  }
  @media(max-width:720px){ .section{padding:64px 24px;} }
  .section-head{
    display:flex;
    justify-content:space-between;
    align-items:flex-end;
    margin-bottom:48px;
    gap:24px;
    flex-wrap:wrap;
  }
  .section-head h2{
    font-family:'Fraunces', serif;
    font-weight:500;
    font-size:clamp(32px,4vw,48px);
    max-width:520px;
    line-height:1.05;
  }
  .section-head p{
    max-width:280px;
    font-size:15px;
    line-height:1.6;
    color:var(--olive);
  }

  /* ---------- PRODUCT GRID ---------- */
  .grid{
    display:grid;
    grid-template-columns:repeat(3,1fr);
    gap:28px;
  }
  @media(max-width:900px){ .grid{grid-template-columns:repeat(2,1fr);} }
  @media(max-width:560px){ .grid{grid-template-columns:1fr;} }

  .card{
    opacity:0;
    transform:translateY(24px);
    transition:opacity .7s ease, transform .7s ease;
  }
  .card.in{opacity:1; transform:translateY(0);}
  .card:nth-child(2){transition-delay:.1s;}
  .card:nth-child(3){transition-delay:.2s;}
  .card:nth-child(4){transition-delay:.3s;}
  .card:nth-child(5){transition-delay:.4s;}
  .card:nth-child(6){transition-delay:.5s;}

  .card-img{
    aspect-ratio:3/4;
    overflow:hidden;
    background:#ddd6c4;
    position:relative;
  }
  .card-img img{
    width:100%;height:100%;object-fit:cover;
    filter:saturate(0.85) contrast(1.05);
    transition:transform .6s cubic-bezier(.19,1,.22,1);
  }
  .card:hover .card-img img{transform:scale(1.06);}
  .card-info{
    display:flex;
    justify-content:space-between;
    padding-top:14px;
    font-size:14px;
  }
  .card-info .name{font-weight:500;}
  .card-info .price{color:var(--clay);}
  .card-cat{
    font-size:12px;
    color:var(--olive);
    margin-top:2px;
  }

  /* ---------- BANNER ---------- */
  .banner{
    position:relative;
    height:70vh;
    min-height:420px;
    overflow:hidden;
    margin:0 48px;
    border-radius:2px;
  }
  @media(max-width:720px){ .banner{margin:0 24px;} }
  .banner img{
    width:100%;height:100%;object-fit:cover;
    filter:saturate(0.8);
  }
  .banner-overlay{
    position:absolute; inset:0;
    background:linear-gradient(180deg, rgba(33,31,26,0) 40%, rgba(33,31,26,0.55) 100%);
    display:flex;
    align-items:flex-end;
    padding:48px;
  }
  .banner-overlay h3{
    font-family:'Fraunces', serif;
    font-weight:500;
    font-style:italic;
    color:var(--paper);
    font-size:clamp(28px,4vw,44px);
    max-width:600px;
    line-height:1.15;
  }

  /* ---------- NEWSLETTER / FOOTER ---------- */
  footer{
    padding:96px 48px 48px;
    border-top:1px solid var(--line);
    margin-top:40px;
  }
  .foot-top{
    display:grid;
    grid-template-columns:1.3fr 1fr;
    gap:40px;
    margin-bottom:64px;
  }
  @media(max-width:800px){ .foot-top{grid-template-columns:1fr;} }
  .foot-top h2{
    font-family:'Fraunces', serif;
    font-weight:500;
    font-size:clamp(30px,4vw,46px);
    max-width:480px;
    line-height:1.08;
  }
  .subscribe{
    display:flex;
    border-bottom:1px solid var(--ink);
    max-width:420px;
    padding-bottom:12px;
    margin-top:32px;
  }
  .subscribe input{
    flex:1;
    background:none;
    border:none;
    outline:none;
    font-family:'Space Grotesk',sans-serif;
    font-size:15px;
    color:var(--ink);
  }
  .subscribe input::placeholder{color:var(--olive);}
  .subscribe button{
    background:none;
    border:none;
    font-family:'Space Grotesk',sans-serif;
    font-size:14px;
    cursor:pointer;
    color:var(--clay);
  }
  .foot-cols{
    display:flex;
    gap:64px;
    flex-wrap:wrap;
  }
  .foot-col h4{
    font-size:13px;
    color:var(--olive);
    margin-bottom:14px;
    font-weight:500;
  }
  .foot-col a{
    display:block;
    font-size:15px;
    margin-bottom:10px;
  }
  .foot-bottom{
    display:flex;
    justify-content:space-between;
    margin-top:64px;
    padding-top:24px;
    border-top:1px solid var(--line);
    font-size:13px;
    color:var(--olive);
    flex-wrap:wrap;
    gap:12px;
  }
</style>
</head>
<body>

<nav>
  <div class="logo">TARZ</div>
  <div class="nav-links">
    <a href="#kolleksiya">Kolleksiya</a>
    <a href="#lookbook">Lookbook</a>
    <a href="#aloqa">Aloqa</a>
  </div>
  <div class="nav-cart"><span class="dot"></span> Savat (0)</div>
</nav>

<section class="hero">
  <div class="hero-text">
    <h1>
      <span class="line"><span class="word" style="animation-delay:0.05s">Kiyim</span></span>
      <span class="line"><span class="word" style="animation-delay:0.18s">shunchaki</span></span>
      <span class="line"><span class="word" style="animation-delay:0.3s">matodan</span></span>
      <span class="line"><span class="word" style="animation-delay:0.42s">iborat emas.</span></span>
    </h1>
    <p class="hero-sub">Har bir fasl uchun ozgina modellar, sifatli mato va vaqt sinovidan o'tadigan tikuv. TARZ — kundalik kiyimga bo'lgan sokin yondashuv.</p>
    <a href="#kolleksiya" class="hero-cta">Kolleksiyani ko'rish →</a>
  </div>
  <div class="hero-frame">
    <img src="https://images.unsplash.com/photo-1516762689617-e1cffcef479d?w=800&q=80" alt="Kiyim modeli">
    <div class="hero-tag">Kuz — Qish 2026</div>
  </div>
</section>

<div class="marquee-wrap">
  <div class="marquee">
    <span>SIFATLI MATO</span><span>YANGI KOLLEKSIYA</span><span>QO'LDA TIKILGAN</span><span>CHEKLANGAN NUSXA</span>
    <span>SIFATLI MATO</span><span>YANGI KOLLEKSIYA</span><span>QO'LDA TIKILGAN</span><span>CHEKLANGAN NUSXA</span>
  </div>
</div>

<section class="section" id="kolleksiya">
  <div class="section-head">
    <h2>Bu fasl uchun tanlangan modellar</h2>
    <p>Har bir model chekli sonda tikiladi — qaytadan ishlab chiqarilmaydi.</p>
  </div>
  <div class="grid" id="productGrid">
    <div class="card">
      <div class="card-img"><img src="https://images.unsplash.com/photo-1521572163474-6864f9cf17ab?w=600&q=80" alt="Palto"></div>
      <div class="card-info"><span class="name">Tuproq rang palto</span><span class="price">840 000 so'm</span></div>
      <div class="card-cat">Ustki kiyim</div>
    </div>
    <div class="card">
      <div class="card-img"><img src="https://images.unsplash.com/photo-1551028719-00167b16eac5?w=600&q=80" alt="Kostyum"></div>
      <div class="card-info"><span class="name">Kulrang kostyum</span><span class="price">1 120 000 so'm</span></div>
      <div class="card-cat">Rasmiy</div>
    </div>
    <div class="card">
      <div class="card-img"><img src="https://images.unsplash.com/photo-1503341504253-dff4815485f1?w=600&q=80" alt="Sviter"></div>
      <div class="card-info"><span class="name">Jun sviter</span><span class="price">390 000 so'm</span></div>
      <div class="card-cat">Trikotaj</div>
    </div>
    <div class="card">
      <div class="card-img"><img src="https://images.unsplash.com/photo-1489987707025-afc232f7ea0f?w=600&q=80" alt="Ko'ylak"></div>
      <div class="card-info"><span class="name">Kanvas ko'ylak</span><span class="price">260 000 so'm</span></div>
      <div class="card-cat">Kundalik</div>
    </div>
    <div class="card">
      <div class="card-img"><img src="https://images.unsplash.com/photo-1591047139829-d91aecb6caea?w=600&q=80" alt="Shim"></div>
      <div class="card-info"><span class="name">Vool shim</span><span class="price">470 000 so'm</span></div>
      <div class="card-cat">Kundalik</div>
    </div>
    <div class="card">
      <div class="card-img"><img src="https://images.unsplash.com/photo-1544022613-e87ca75a784a?w=600&q=80" alt="Kurtka"></div>
      <div class="card-info"><span class="name">Tvid kurtka</span><span class="price">690 000 so'm</span></div>
      <div class="card-cat">Ustki kiyim</div>
    </div>
  </div>
</section>

<section class="banner" id="lookbook">
  <img src="https://images.unsplash.com/photo-1490114538077-0a7f8cb49891?w=1400&q=80" alt="Lookbook">
  <div class="banner-overlay">
    <h3>"Kiyim gapirmasa ham ko'p narsani aytadi."</h3>
  </div>
</section>

<footer id="aloqa">
  <div class="foot-top">
    <h2>Yangi kolleksiyalardan birinchi bo'lib xabar toping</h2>
    <div>
      <div class="subscribe">
        <input type="email" placeholder="Email manzilingiz">
        <button type="button">Yuborish →</button>
      </div>
    </div>
  </div>
  <div class="foot-cols">
    <div class="foot-col">
      <h4>Do'kon</h4>
      <a href="#">Yangi kelganlar</a>
      <a href="#">Ustki kiyim</a>
      <a href="#">Kundalik</a>
    </div>
    <div class="foot-col">
      <h4>Kompaniya</h4>
      <a href="#">Biz haqimizda</a>
      <a href="#">Ustaxona</a>
      <a href="#">Vakansiyalar</a>
    </div>
    <div class="foot-col">
      <h4>Yordam</h4>
      <a href="#">Yetkazib berish</a>
      <a href="#">Qaytarish</a>
      <a href="#">O'lcham jadvali</a>
    </div>
  </div>
  <div class="foot-bottom">
    <span>© 2026 TARZ</span>
    <span>Toshkent, O'zbekiston</span>
  </div>
</footer>

<script>
  const cards = document.querySelectorAll('.card');
  const io = new IntersectionObserver((entries)=>{
    entries.forEach(e=>{
      if(e.isIntersecting){ e.target.classList.add('in'); io.unobserve(e.target); }
    });
  },{threshold:0.15});
  cards.forEach(c=>io.observe(c));
</script>

</body>
</html>
