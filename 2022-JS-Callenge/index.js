const genMaxNum = document.querySelector("h2 input");
const guessNum = document.querySelector(".geussnum");
const formNum = document.querySelector(".formnum");

const chosenSpan = document.querySelector(".choose");
const resultSpan = document.querySelector(".result");

function handleNumSubmit(event) {
  event.preventDefault();
  const newMaxNum = parseInt(genMaxNum.value);
  const newGeussNum = parseInt(guessNum.value);
  if (newMaxNum < newGeussNum) {
    resultSpan.innerText = "Please guess a number between 0 and " + newMaxNum;
  } else {
    setNum(newMaxNum, newGeussNum);
  }
}

function setNum(newMaxNum, newGeussNum) {
  const ranNum = Math.ceil(Math.random() * newMaxNum);
  paintNum(newGeussNum, ranNum);
}

function paintNum(newGeussNum, ranNum) {
  chosenSpan.innerText =
    "You chose : " + newGeussNum + ", the machine chose: " + ranNum;
  if (newGeussNum === ranNum) {
    resultSpan.innerText = "You won!";
  } else {
    resultSpan.innerText = "You lost!";
  }
}

formNum.addEventListener("submit", handleNumSubmit);
