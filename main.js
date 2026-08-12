// pretty toggle

var prettyToggle = document.getElementById("pretty-toggle"); // the checkbox slider

prettyToggle.addEventListener('change', (e) => {
    var elements = document.querySelectorAll('*');
    if (e.target.checked) {
        // html.style.backgroundImage = "url('imgs/Aesthetic-Pastel-Cute-PowerPoint-Background-with-Rainbow-and-Baby-Blue-Clouds-by-SlidesCorner.com_.jpg')";
        elements.forEach(el => {
            el.classList.add('pretty-mode');
        });
    } else {
        // html.style.backgroundImage = 'none';
        elements.forEach(el => {
            el.classList.remove('pretty-mode');
        });
    }
})





function test() {
    alert("Test");
}