function printNum(){
	document.getElementById("text").innerHTML = ""
	new_text = '<h1 style="color: yellow; font-size:200px;">'+ parsedVal + '</h1>'
	document.getElementById("text").innerHTML += new_text	
}

document.addEventListener('click', async () => {
	// Prompt user to select any serial port.
	var port = await navigator.serial.requestPort();
	// be sure to set the baudRate to match the ESP32 code
	await port.open({ baudRate: 1000000 });

	let decoder = new TextDecoderStream();
	inputDone = port.readable.pipeTo(decoder.writable);
	inputStream = decoder.readable;

	reader = inputStream.getReader();
	readLoop();

});


async function readLoop() {
	while (true) {
		const { value, done } = await reader.read();
		if (done) {
			// Allow the serial port to be closed later.
			console.log("closing connection")
			reader.releaseLock();
			break;
		}
		if (value) {
			parsedVal = parseInt(value)
			if(parsedVal > 10){
				console.log(parsedVal);
				printNum();
			}
		}
	}
};