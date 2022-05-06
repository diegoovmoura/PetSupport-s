// var dados = [
//     "Gato dosijfsdoif odi fjsdoif jsdofi jsoij",
//     "Cachorro cosdvn  dofido ii jsdoi fso idj ",
//     "Peixe difje sdifjso ijsdo fijsdoi",
//     "passaro",
//     "cobra",
//     "passaro",
//     "cobra"
//   ];
//   function mostraPets() {
//     var main = document.getElementById("main");
//     var templatePet = document.getElementById("templatePet");
//     for (var i in dados) {
//       var nome = dados[i];
//       var copia = templatePet.cloneNode(true);
//       copia.removeAttribute("id");
//       copia.classList.remove("d-none");
//       copia.getElementsByClassName("descPet")[0].innerText = nome;
//       main.appendChild(copia);
//     }
//   }
function expande(idElemento, dicionario) {
    var elemento = document.getElementById(idElemento);
    var elementoPai = elemento.parentElement;
    var novoElemento = elemento.cloneNode(true);
    var html = novoElemento.getInnerHTML();
    for (var i in dicionario) {
        html = html.replace("{{ " + i + " }}", dicionario[i]);
    }
    novoElemento.innerHTML = html;
    novoElemento.classList.remove("d-none");
    novoElemento.removeAttribute("id");
    elementoPai.appendChild(novoElemento);
}
function mostraPets() {
    var elemento = document.getElementById("telaInicial");
    elemento.classList.remove("d-none");
    var dicionario = [
        {
            descricao: "Gato"
        },
        {
            descricao: "Cachorro"
        },
        {
            descricao: "flavio"
        },
        {
            descricao: "Gato"
        },
        {
            descricao: "Cachorro"
        },
        {
            descricao: "flavio"
        },
        {
            descricao: "Gato"
        }
    ]
    for (var i in dicionario) {
        expande("templatePet", dicionario[i]);
    }
}

function mostrarTelaPrincipal() {
    var telaAnterior = document.getElementById("telaSecundaria");
    var telaAtual = document.getElementById("telaInicial");
    telaAnterior.classList.add("d-none");
    telaAtual.classList.remove("d-none");
}

function mostrarTelaSecundaria() {
    var telaAnterior = document.getElementById("telaInicial");
    var telaAtual = document.getElementById("telaSecundaria");
    telaAnterior.classList.add("d-none");
    telaAtual.classList.remove("d-none");
}

function mostrarTelaLogin() {
    var header = document.getElementById("header");
    var footer = document.getElementById("footer");    
    var telaAnterior = document.getElementById("telaInicial");
    var telaAtual = document.getElementById("telaTerciaria");
    header.classList.add("d-none");
    footer.classList.add("d-none");
    telaAnterior.classList.add("d-none");
    telaAtual.classList.remove("d-none");

}