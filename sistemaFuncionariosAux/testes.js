// // Criando uma promessa
// const minhaPromessa = new Promise((resolve, reject) => {
//     //Imaginando que esse nome veio de umm local externo, exemplo: Banco de dados
//     let nome = "Cauã";

//     if (nome === "Cauã") {
//         resolve("Usuário encontrado!");
//     }
//     else {
//         reject("Usuário inexistente");
//     }
// })

// minhaPromessa
//     .then((nome) => {
//         console.log(nome);
//     })

// Encadeando thens

// Criando uma promessa
const minhaPromessa = new Promise((resolve, reject) => {
    //Imaginando que esse nome veio de umm local externo, exemplo: Banco de dados
    let nome = "Cauã";

    if (nome === "Cauã") {
        resolve(`Usuario existente`);
    }
    else {
        reject(`Usuario ${nome} nao encontrado`);
    }
})

minhaPromessa
    .then((nome) => {
        console.log("Sucesso: " + nome)
     })
    //.then((a) => {
    //     console.log(a)
    // })
    .catch((erro) => {
        console.log("Erro: " + erro)
    })

// Exercicio, verificar se tal nome eiste (estático)

function aguardar() {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        let nome = "Joao"
        if (nome === "Jose"){
            resolve("Usuário encontrado")
        }
        else{
            reject(`Usuário ${nome} nao encontrado`)
        }
      }, 6000);
    });
  }

  aguardar().then((certo) => {
    console.log("Promessa realizada: " + certo)
  })
  .catch((erro) => {
    console.error("Erro: " + erro)
  }) 








