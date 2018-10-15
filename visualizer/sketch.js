// let nonFormatted;
let nonOp;
let pileA;
let pileB;
let maxValue;
let instructions;
let time;
let start;

pileB = [];
start = false;

function changeTime(speed)
{
	console.log(speed);
	time = 10000 / (nonOp.length * speed);
}

function startDraw()
{
	let button = document.getElementsByTagName("button")[0];
	if (button.innerHTML == "Pause")
		button.innerHTML = "Restart"
	else
		button.innerHTML = "Pause"
	start = !start;
	redraw();
}

function preload() {
	pileA = loadStrings('./numbers.txt');
	nonOp = loadStrings('./instructions.txt');
}

function manipulateArrays(instruction)
{
	let tmp;
	console.log("Instruction: " + instruction);
	instructions = instructions.slice(1);
	let tmpPileA = [...pileA];
	let tmpPileB = [...pileB];
	if (instruction == "ra")
	{
		tmpPileA = pileA.slice(1);
		tmpPileA.push(pileA[0]);
	}
	else if (instruction == "rb")
	{
		tmpPileB = pileB.slice(1);
		tmpPileB.push(pileB[0]);
	}
	else if (instruction == "rr")
	{
		tmpPileA = pileA.slice(1);
		tmpPileA.push(pileA[0]);
		tmpPileB = pileB.slice(1);
		tmpPileB.push(pileB[0]);
	}
	else if (instruction == "sa")
	{
		tmp = tmpPileA[0];
		tmpPileA[0] = tmpPileA[1];
		tmpPileA[1] = tmp;
	}
	else if (instruction == "sb")
	{
		tmp = tmpPileB[0];
		tmpPileB[0] = tmpPileB[1];
		tmpPileB[1] = tmp;
	}
	else if (instruction == "ss")
	{
		tmp = tmpPileA[0];
		tmpPileA[0] = tmpPileA[1];
		tmpPileA[1] = tmp;
		tmp = tmpPileB[0];
		tmpPileB[0] = tmpPileB[1];
		tmpPileB[1] = tmp;
	}
	else if (instruction == "pa")
	{
		tmpPileA = [tmpPileB[0], ...tmpPileA];
		tmpPileB = tmpPileB.slice(1);
	}
	else if (instruction == "pb")
	{
		tmpPileB = [tmpPileA[0], ...tmpPileB];
		tmpPileA = tmpPileA.slice(1);
	}
	else if (instruction == "rra")
	{
		tmpPileA = [pileA[pileA.length - 1], ...pileA];
		tmpPileA = tmpPileA.slice(0, tmpPileA.length - 1);
	}
	else if (instruction == "rrb")
	{
		tmpPileB = [pileB[pileB.length - 1], ...pileB];
		tmpPileB = tmpPileB.slice(0, tmpPileB.length - 1);
	}
	else if (instruction == "rrr")
	{
		tmpPileB = [pileB[pileB.length - 1], ...pileB];
		tmpPileB = tmpPileB.slice(0, tmpPileB.length - 1);
		tmpPileA = [pileA[pileA.length - 1], ...pileA];
		tmpPileA = tmpPileA.slice(0, tmpPileA.length - 1);
	}
	pileA = [...tmpPileA];
	pileB = [...tmpPileB];
	setTimeout(() => {
		redraw();
	}, time);
}

function setup()
{
	pileA.pop();
	// pileA = nonFormatted;
	console.log(pileA);
	nonOp.pop();
	instructions = nonOp;
	time = 10000 / nonOp.length;
	maxValue = Math.max(...pileA);
	minValue = Math.min(...pileA);
	pLenght = pileA.length;
	createCanvas(windowWidth, (windowHeight - 25));
	background(255);
	noLoop();
}

function draw()
{
	background(255);
	fill(0);
	pileA.map((el, i) => printPile(el, i, 0));
	pileB.map((el, i) => printPile(el, i, (width / 2)));
	if (instructions.length && start)
		manipulateArrays(instructions[0]);
	else
		console.log(pileA);
}

function printPile(value, index, origin)
{
	let red;
	let blue;
	let green;
	if (value < 0)
	{
		divider = minValue;
		red = 90;
		blue = 255;
		green = 127;
	}
	else
	{
		divider = maxValue;
		blue = 0;
		red = 255;
		green = 255;
	}
	let posY = (index / pLenght) * height;
	stroke(red * (value / divider), green - (green * (value / divider)), blue * (value / divider));
	fill(red * (value / divider), green - (green * (value / divider)), blue * (value / divider));
	rect(origin, posY, (abs(value) / maxValue) * (width / 2), (height / pLenght));
}