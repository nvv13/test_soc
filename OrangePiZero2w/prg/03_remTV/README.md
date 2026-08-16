
## программа musia-remTV-XX.py

легкая попытка

сделать управление по IR с помощь голосовых комманд


~~~

дело происходит на
$ uname -a
Linux orangepizero2w 6.1.31-sun50iw9 #1.0.2 SMP Thu Aug  1 11:28:17 UTC 2024 aarch64 GNU/Linux
~~~


-------------------------------

## Настроим доступ к gpio - не root пользователей (нужно для OPi.GPIO)

Создаем группу gpio, если она еще не существует
~~~
sudo groupadd -f gpio
~~~

Добавляем пользователя orangepi в эту группу
~~~
sudo usermod -a -G gpio  $USER
~~~


Теперь нужно создать правило для udev, которое будет автоматически назначать правильные права доступа к файлам GPIO при их создании (например, когда вы "экспортируете" пин из скрипта) .

Откройте файл для редактирования:

~~~
sudo mcedit /etc/udev/rules.d/99-gpio.rules
~~~

Скопируйте и вставьте в него следующие строки:
~~~
SUBSYSTEM=="gpio", KERNEL=="gpiochip*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys/class/gpio/export /sys/class/gpio/unexport ; chmod 220 /sys/class/gpio/export /sys/class/gpio/unexport'"
SUBSYSTEM=="gpio", KERNEL=="gpio*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value ; chmod 660 /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value'"
~~~

-------------------------------

## еще сделать для доступа к аудио
~~~
sudo usermod -a -G audio $USER
~~~


Чтобы все изменения вступили в силу, нужно перезагрузить систему:

~~~
sudo reboot
~~~

-------------------------------

## Установка необходимых пакетов
~~~
sudo apt-get install portaudio19-dev python3-pyaudio python3-pip python3-dev
# иногда когда не работает ключь --break-system-packages sudo python -m pip install --upgrade pip
sudo pip install OPi.GPIO-ex --break-system-packages
sudo pip install --break-system-packages vosk pyaudio numpy 
sudo pip install --break-system-packages samplerate
sudo python3 -m pip install -U cgir --break-system-packages
~~~

-------------------------------

## Настройка микрофона

Список всех звуковых карт (входные и выходные)
~~~
для записи
arecord -l
для воспроизведения
aplay -l
~~~

сейчас интересуют для записи

Список аудиоустройств, найти нужное, прописать в программу .py, например MICROPHONE_DEVICE_INDEX = 3
~~~
python3 -c "import pyaudio; p = pyaudio.PyAudio(); print(p.get_device_count()); [print(p.get_device_info_by_index(i)) for i in range(p.get_device_count())]"
~~~

после выбора аудиоустройства, надо прописать в программе
~~~
# ==================== НАСТРОЙКИ ====================
TARGET_SR = 16000  # Частота для модели
CAPTURE_SR = 44100  # Родная частота USB-камеры
CAPTURE_CHANNELS = 2  # Стерео
TARGET_CHANNELS = 1  # Моно
~~~

тут смысл в чём, TARGET_SR = 16000,TARGET_CHANNELS = 1 - менять нельзя, это то что требуеться для модели

в идеале, CAPTURE_SR тоже должна быть равна 16000, и соответственно CAPTURE_CHANNELS = 1, тогда не будет лишних преобразований в программе

но!, в реальности, у многих USB микрофонов - либо захват не возможен с другими параметрами чем предусмотрел изготовитель, либо - возможен,
 но качество звука падает так, что звук не разборчивый.

для того чтоб подабрать правельные параметры для захвата, необходима сделать несколько пробных записей с микрофона - с разными параметрами, и послушать результат,
лучьшие параметры вписать в CAPTURE_SR (частота) и CAPTURE_CHANNELS


например - тестовая запись длительностью 5 сек:
~~~

где -D hw:3,0 -наше устройство из arecord -l
    -c 2      -два каннала
    -r 16000  -частота 16000

arecord -D hw:3,0 -d 5 -c 2 -r 16000 -f S16_LE -t wav tes2t16000.wav

 для 44100 два канала
arecord -D hw:3,0 -d 5 -c 2 -r 44100 -f S16_LE -t wav tes2t44100.wav

 для 16000 один канал
arecord -D hw:3,0 -d 5 -c 1 -r 16000 -f S16_LE -t wav tes1t16000.wav

 для 44100 один канал
arecord -D hw:3,0 -d 5 -c 1 -r 44100 -f S16_LE -t wav tes1t44100.wav

~~~


-------------------------------

## далее, из оборудования
~~~
INCOMMAND_LED = 38
~~~

к 38 выводу подключаем через резистор, светодиод, это индикатор активации модели, то  что она распознала ключевое слово и
включилась в режим прослушивания

-------------------------------

## ключевое слово утанавливаеться так
~~~
KEYWORD = "муся"
~~~

однако, если ключевым словом (или какое нибуть из слов для комманды) будет слово про которое модель не знает, оно ругнёться при запуске програмы.

смотрите если что, потому что на незнакомое слово модель не будет реагировать

впрочем, есть статья [процесс добавления слов в языковую модель vosk'а](https://habr.com/ru/articles/735480/)



ещё обратите внимание на COMMANDS = {}

слово  "восемь": "8",

впереди  "семь": "7",

иначе на восемь будет срабатывать семь, вот так это работает!

-------------------------------

## далее, в программе используеться модуль import cgir,
для трансляции инфракрасного излучения на управляемый телевизор

этот модуль использует устройство /dev/lirc0, это драйвер kernel gpio_ir_tx
про его установку и настройку [сюда](../../device/gpio-ir-tx)



-------------------------------

## модель для vosk должна быть в папке:
~~~
MODEL_PATH = "model"  # Путь к папке с моделью Vosk
~~~
в данном случае использована модель 

Vosk Small [https://alphacephei.com/vosk/models/vosk-model-small-ru-0.22.zip](https://alphacephei.com/vosk/models/vosk-model-small-ru-0.22.zip)

содержимое с подкаталагами складываем в папку model


-------------------------------

## Настройка IR кодов

~~~
IRCODE_PATH = "ircode" # Путь к папке с описанием IR последовательностей
~~~

файлики, которые там должны лежать, можно настроить с помошью программы [repeat.py](../../device/gpio-ir-tx)

в итоге, должно получиться так

в программе прописаны действия для пульта управления, вида
~~~
    "первый": "channel_1",
~~~

это значит, что должен быть файлик в каталоге IRCODE_PATH, с названием channel_1.json в котором закодирована управляющая последовательность


-------------------------------

## Настройка TTS ?

смотрим [https://github.com/OHF-Voice/piper1-gpl/releases](https://github.com/OHF-Voice/piper1-gpl/releases)

нет, возьмем пока с предыдущего проекта
~~~
wget https://github.com/rhasspy/piper/releases/download/2023.11.14-2/piper_linux_aarch64.tar.gz
~~~

потом какой нибуть из голосов
~~~
curl -L --limit-rate 5m -O -A "Mozilla/5.0" "https://huggingface.co/rhasspy/piper-voices/resolve/main/ru/ru_RU/dmitri/medium/ru_RU-dmitri-medium.onnx?download=true" 
curl -L --limit-rate 5m -O -A "Mozilla/5.0" "https://huggingface.co/rhasspy/piper-voices/resolve/main/ru/ru_RU/dmitri/medium/ru_RU-dmitri-medium.onnx.json?download=true"

curl -L --limit-rate 5m -O -A "Mozilla/5.0" "https://huggingface.co/rhasspy/piper-voices/resolve/main/ru/ru_RU/irina/medium/ru_RU-irina-medium.onnx?download=true"
curl -L --limit-rate 5m -O -A "Mozilla/5.0" "https://huggingface.co/rhasspy/piper-voices/resolve/main/ru/ru_RU/irina/medium/ru_RU-irina-medium.onnx.json?download=true"

curl -L --limit-rate 5m -O -A "Mozilla/5.0" "https://huggingface.co/rhasspy/piper-voices/resolve/main/ru/ru_RU/ruslan/medium/ru_RU-ruslan-medium.onnx?download=true"
curl -L --limit-rate 5m -O -A "Mozilla/5.0" "https://huggingface.co/rhasspy/piper-voices/resolve/main/ru/ru_RU/ruslan/medium/ru_RU-ruslan-medium.onnx.json?download=true"
~~~

тест
~~~
echo 'Привет, мир!' | ./piper --model ../paper-voice/ru_RU-irina-medium.onnx --output_file output.wav
~~~


