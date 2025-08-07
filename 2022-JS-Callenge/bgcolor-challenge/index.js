const colors = [
  "#ef5777",
  "#575fcf",
  "#4bcffa",
  "#34e7e4",
  "#0be881",
  "#f53b57",
  "#3c40c6",
  "#0fbcf9",
  "#00d8d6",
  "#05c46b",
  "#ffc048",
  "#ffdd59",
  "#ff5e57",
  "#d2dae2",
  "#485460",
  "#ffa801",
  "#ffd32a",
  "#ff3f34",
];

const colorBtn = document.querySelector("button");
const body = document.querySelector("body");

function clickButton() {
  const chosencolor1 = colors[Math.floor(Math.random() * colors.length)];
  const nextcolorbox = colors.filter(function (data) {
    return data !== chosencolor1;
  });
  const chosencolor2 =
    nextcolorbox[Math.floor(Math.random() * nextcolorbox.length)];
  console.log(chosencolor1, chosencolor2);
  body.style.backgroundImage = `linear-gradient(90deg, ${chosencolor1}, ${chosencolor2})`;
}

colorBtn.addEventListener("click", clickButton);
