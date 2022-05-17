var idTelaAtual = "telaInicial";

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

function request(args) {
    var url        = args.url;
    var method     = args.method;
    var data       = args.data;
    var fn         = args.fn;
    if (method == undefined) {
        method = "GET";
    }
    var body = null;
    var headers = new Headers()
    if (data != undefined) {
        body = JSON.stringify(data);
        headers.append("Content-Type", "application/json");
    }
    console.log(data);
    fetch(url, {
        method,
        body,
        headers
    }).then(function(response) {
        return response.json();
    }).then(function(data) {
        if (fn != undefined) {
            fn(data);
        } else {
            console.log(data);
        }
    }).catch(function(error) {
        console.log(error);
    });
};

function mostraPets(dicionario) {
    var elemento = document.getElementById("telaInicial");
    elemento.classList.remove("d-none");
    for (var i in dicionario) {
        expande("templatePet", dicionario[i]);
    }
}

function inicializa() {
    request({
        "url": "/animais",
        "fn": mostraPets
    })
}

function mostrarTelaPrincipal() {
    idTelaAtual = "telaInicial";
    var telaAnterior = document.getElementById("telaSecundaria");
    var telaAtual = document.getElementById(idTelaAtual);
    telaAnterior.classList.add("d-none");
    telaAtual.classList.remove("d-none");
}

function mostrarTelaSecundaria() {
    idTelaAtual = "telaSecundaria";
    var telaAnterior = document.getElementById("telaInicial");
    var telaAtual = document.getElementById(idTelaAtual);
    telaAnterior.classList.add("d-none");
    telaAtual.classList.remove("d-none");
}

function mostrarTelaLogin() {
    var header = document.getElementById("header");
    var footer = document.getElementById("footer");    
    var telaAnterior = document.getElementById(idTelaAtual);
    var telaAtual = document.getElementById("telaTerciaria");
    header.classList.add("d-none");
    footer.classList.add("d-none");
    telaAnterior.classList.add("d-none");
    telaAtual.classList.remove("d-none");

    idTelaAtual = "telaTerciaria";
}

function autenticar() {
    var email = document.getElementById("exampleFormControlInput1").value;
    var senha = document.getElementById("exampleFormControlInput2").value;
    var result = request({
        "url": "/autenticar",
        "method": "POST",
        "data": {
            "email": email,
            "senha": senha
        },
        "fn": mostraUsuario
    })
}

function mostraUsuario(autenticado) {
    if (autenticado == true) {
        var botoes = document.getElementById("botoesLogar")
        var imgUsuario = document.getElementById("fotoUsuario");
        botoes.classList.add("d-none");
        imgUsuario.classList.remove("d-none");
    }
    voltarTelaPrincipal();
}

function voltarTelaPrincipal() {
    var header = document.getElementById("header");
    var footer = document.getElementById("footer");    
    var telaAnterior = document.getElementById(idTelaAtual);
    var telaAtual = document.getElementById("telaInicial");
    header.classList.remove("d-none");
    footer.classList.remove("d-none");
    telaAnterior.classList.add("d-none");
    telaAtual.classList.remove("d-none");

    idTelaAtual = "telaInicial";
}

// function mostrarTelaCadastro(){
//     var 
// }