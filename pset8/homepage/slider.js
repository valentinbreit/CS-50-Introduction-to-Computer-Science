const slider = document.querySelector("#corredor");
let sliderSection = document.querySelectorAll(".corredor--section");
let sliderSectionLast = sliderSection[sliderSection.length-1];


const btnIzquierdo = document.querySelector("#btn-izquierda");
const btnDerecho = document.querySelector("#btn-derecha");

slider.insertAdjacentElement('afterbegin', sliderSectionLast);

function MoverDerecha(){
    let sliderSectionFirst = document.querySelectorAll(".corredor--section")[0];
    slider.style.marginLeft="-200%";
    slider.style.transition="all 0.4s";
    setTimeout(function(){
        slider.style.transition="none";
        slider.insertAdjacentElement('beforeend', sliderSectionFirst);
        slider.style.marginLeft="-100%";
    }, 500)
}

function MoverIzquierda(){
    let sliderSection = document.querySelectorAll(".corredor--section");
    let sliderSectionLast = sliderSection[sliderSection.length-1];
    slider.style.marginLeft="0";
    slider.style.transition="all 0.4s";
    setTimeout(function(){
        slider.style.transition="none";
        slider.insertAdjacentElement('afterbegin', sliderSectionLast);
        slider.style.marginLeft="-100%";
    }, 500)
}


// Cambio de imagen manual
btn_derecha.addEventListener('click', function(){
    MoverDerecha();
});


btn_izquierda.addEventListener('click', function(){
    MoverIzquierda();
});

// Cambio de imagen Automatico
setInterval(function(){
    MoverDerecha();
}, 3000);