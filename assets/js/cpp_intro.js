let currentSlide = 0;
const slides = document.querySelectorAll('.slide');
const totalSlides = slides.length;

document.getElementById('totalSlides').textContent = totalSlides;

function showSlide(n) {
    slides[currentSlide].classList.remove('active');
    currentSlide = (n + totalSlides) % totalSlides;
    slides[currentSlide].classList.add('active');

    document.getElementById('currentSlide').textContent = currentSlide + 1;

    document.getElementById('prevBtn').disabled = currentSlide === 0;
    document.getElementById('nextBtn').disabled = currentSlide === totalSlides - 1;
}

function changeSlide(direction) {
    showSlide(currentSlide + direction);
}

document.addEventListener('keydown', (e) => {
    if (e.key === 'ArrowLeft' && currentSlide > 0) {
        changeSlide(-1);
    } else if (e.key === 'ArrowRight' && currentSlide < totalSlides - 1) {
        changeSlide(1);
    }
});

showSlide(0);

// Expose functions for inline HTML buttons
window.changeSlide = changeSlide;

