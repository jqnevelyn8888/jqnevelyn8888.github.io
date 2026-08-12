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


function createHeart() {
    let heart = document.createElement('img');
    heart.setAttribute('src', 'imgs/blue-heart.png');
    heart.classList.add('heart');
    return heart;
}

var petFuhua = document.getElementById('pet-fuhua');
var petting = document.getElementById('petting');


petFuhua.addEventListener('mousedown', (e) => {
    petFuhua.style.width = '60%';

    // heart
    let heart = createHeart();
    petting.appendChild(heart);

    heart.addEventListener('animationend', (e)=>{
        heart.remove();
    });

});

petFuhua.addEventListener('mouseup', (e) => {
    
    console.log("petted");
    petFuhua.style.width = '50%';

});





function test() {
    alert("Test");
}
