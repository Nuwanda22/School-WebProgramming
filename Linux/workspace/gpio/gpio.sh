echo "23" > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio23/direction

echo "1" > /sys/class/gpio/gpio23/value
echo "0" > /sys/class/gpio/gpio23/value

echo "23" > /sys/class/gpio/unexport


gpio -g mode 23 out
gpio -g write 23 1
gpio -g write 23 0

gpio export 23 out
gpio -g write 23 1
gpio unexport 23
