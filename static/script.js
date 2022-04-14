var dados = [
    "Gato dosijfsdoif odi fjsdoif jsdofi jsoij",
    "Cachorro cosdvn  dofido ii jsdoi fso idj ",
    "Peixe difje sdifjso ijsdo fijsdoi",
    "passaro",
    "cobra"
  ];
  function mostraPets() {
    var main = document.getElementById("main");
    var templatePet = document.getElementById("templatePet");
    for (var i in dados) {
      var nome = dados[i];
      var copia = templatePet.cloneNode(true);
      copia.removeAttribute("id");
      copia.classList.remove("d-none");
      copia.getElementsByClassName("descPet")[0].innerText = nome;
      main.appendChild(copia);
    }
  }