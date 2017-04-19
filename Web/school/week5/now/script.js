function SetTime() {
    var now = new Date();

    var date = now.getFullYear() + " " + (now.getMonth() + 1) + " " + now.getDate();
    var time = now.getHours() + " " + now.getMinutes() + " " + now.getSeconds();

    document.getElementById('date').innerText = date;
    document.getElementById('time').innerText = time;
}
window.onload = function () {
    SetTime();
    setInterval(SetTime, 1000);
}