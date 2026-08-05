#!/usr/bin/python


# Установка необходимых пакетов
# sudo apt-get install portaudio19-dev python3-pyaudio
# sudo pip install --break-system-packages vosk pyaudio numpy 
# sudo pip install --break-system-packages samplerate
# sudo python3 -m pip install -U cgir --break-system-packages

# sudo usermod -a -G audio $USER
# перезайти в пользователя

# Список всех звуковых карт (входные и выходные)
# arecord -l
# aplay -l

# тестовая запись
# arecord -D hw:3,0 -d 5 -c 2 -f S16_LE -t wav test1.wav

# Список аудиоустройств, найти нужное, прописать MICROPHONE_DEVICE_INDEX = 3
# python3 -c "import pyaudio; p = pyaudio.PyAudio(); print(p.get_device_count()); [print(p.get_device_info_by_index(i)) for i in range(p.get_device_count())]"




import json
import sys
import time
import cgir
import OPi.GPIO as GPIO
import queue
import threading
import signal
import pyaudio
import numpy as np
from vosk import Model, KaldiRecognizer
import samplerate

# ==================== НАСТРОЙКИ ====================
TARGET_SR = 16000  # Частота для модели
CAPTURE_SR = 44100  # Родная частота USB-камеры
CAPTURE_CHANNELS = 2  # Стерео
TARGET_CHANNELS = 1  # Моно

FORMAT = pyaudio.paInt16
CHUNK = 4410  # Увеличен для лучшей производительности
#CHUNK = 8192  # Увеличен для лучшей производительности
SILENCE_TIMEOUT = 10.0  # Таймаут тишины (сек)

KEYWORD = "муся"
COMMANDS = {
# ========== УПРАВЛЕНИЕ ТЕЛЕВИЗОРОМ ==========
            "включи телевизор" : "tv_on", "включить телевизор" : "tv_on", "включи тв" : "tv_on", "включить тв" : "tv_on",
            "запусти телевизор" : "tv_on", "телевизор включи" : "tv_on", "тв включи" : "tv_on", "включи ящик" : "tv_on",

            "выключи телевизор": "tv_off", "выключить телевизор": "tv_off", "выключи тв": "tv_off", "выключить тв": "tv_off",
            "отключи телевизор": "tv_off", "погаси телевизор": "tv_off", "выруби телевизор": "tv_off",
            "телевизор выключи": "tv_off", "тв выключи": "tv_off", "выключи ящик": "tv_off", "выруби ящик": "tv_off",
            "стоп телевизор": "tv_off", "телевизор стоп": "tv_off",

            "сделай громче" : "volumeUp", "увеличь громкость" : "volumeUp", "прибавь звук" : "volumeUp", "громче" : "volumeUp",
            "подними громкость" : "volumeUp", "увеличить звук" : "volumeUp", "добавь звук" : "volumeUp",

            "сделай тише": "volumeDown", "уменьши громкость": "volumeDown", "убавь звук": "volumeDown", "тише": "volumeDown",
            "опусти громкость": "volumeDown", "уменьшить звук": "volumeDown", "убавь звук": "volumeDown",

 # ========== КАНАЛЫ 1-20 ==========
    # 1
    "первый": "channel_1",
    "один": "channel_1",
    "канал один": "channel_1",
    "первый канал": "channel_1",
    "включи первый": "channel_1",
    "включи первый канал": "channel_1",
    "включи канал один": "channel_1",
    "переключи на первый": "channel_1",
    
    # 2
    "второй": "channel_2",
    "два": "channel_2",
    "канал два": "channel_2",
    "второй канал": "channel_2",
    "включи второй": "channel_2",
    "включи второй канал": "channel_2",
    "включи канал два": "channel_2",
    "переключи на второй": "channel_2",
    
    # 3
    "третий": "channel_3",
    "три": "channel_3",
    "канал три": "channel_3",
    "третий канал": "channel_3",
    "включи третий": "channel_3",
    "включи третий канал": "channel_3",
    "включи канал три": "channel_3",
    "переключи на третий": "channel_3",
    
    # 4
    "четвёртый": "channel_4",
    "четыре": "channel_4",
    "канал четыре": "channel_4",
    "четвёртый канал": "channel_4",
    "включи четвёртый": "channel_4",
    "включи четвёртый канал": "channel_4",
    "включи канал четыре": "channel_4",
    "переключи на четвёртый": "channel_4",
    
    # 5
    "пятый": "channel_5",
    "пять": "channel_5",
    "канал пять": "channel_5",
    "пятый канал": "channel_5",
    "включи пятый": "channel_5",
    "включи пятый канал": "channel_5",
    "включи канал пять": "channel_5",
    "переключи на пятый": "channel_5",
    
    # 6
    "шестой": "channel_6",
    "шесть": "channel_6",
    "канал шесть": "channel_6",
    "шестой канал": "channel_6",
    "включи шестой": "channel_6",
    "включи шестой канал": "channel_6",
    "включи канал шесть": "channel_6",
    "переключи на шестой": "channel_6",
    
    # 7
    "седьмой": "channel_7",
    "семь": "channel_7",
    "канал семь": "channel_7",
    "седьмой канал": "channel_7",
    "включи седьмой": "channel_7",
    "включи седьмой канал": "channel_7",
    "включи канал семь": "channel_7",
    "переключи на седьмой": "channel_7",
    
    # 8
    "восьмой": "channel_8",
    "восемь": "channel_8",
    "канал восемь": "channel_8",
    "восьмой канал": "channel_8",
    "включи восьмой": "channel_8",
    "включи восьмой канал": "channel_8",
    "включи канал восемь": "channel_8",
    "переключи на восьмой": "channel_8",
    
    # 9
    "девятый": "channel_9",
    "девять": "channel_9",
    "канал девять": "channel_9",
    "девятый канал": "channel_9",
    "включи девятый": "channel_9",
    "включи девятый канал": "channel_9",
    "включи канал девять": "channel_9",
    "переключи на девятый": "channel_9",
    
    # 10
    "десятый": "channel_10",
    "десять": "channel_10",
    "канал десять": "channel_10",
    "десятый канал": "channel_10",
    "включи десятый": "channel_10",
    "включи десятый канал": "channel_10",
    "включи канал десять": "channel_10",
    "переключи на десятый": "channel_10",
    
    # 11
    "одиннадцатый": "channel_11",
    "одиннадцать": "channel_11",
    "канал одиннадцать": "channel_11",
    "одиннадцатый канал": "channel_11",
    "включи одиннадцатый": "channel_11",
    "включи одиннадцатый канал": "channel_11",
    "включи канал одиннадцать": "channel_11",
    "переключи на одиннадцатый": "channel_11",
    
    # 12
    "двенадцатый": "channel_12",
    "двенадцать": "channel_12",
    "канал двенадцать": "channel_12",
    "двенадцатый канал": "channel_12",
    "включи двенадцатый": "channel_12",
    "включи двенадцатый канал": "channel_12",
    "включи канал двенадцать": "channel_12",
    "переключи на двенадцатый": "channel_12",
    
    # 13
    "тринадцатый": "channel_13",
    "тринадцать": "channel_13",
    "канал тринадцать": "channel_13",
    "тринадцатый канал": "channel_13",
    "включи тринадцатый": "channel_13",
    "включи тринадцатый канал": "channel_13",
    "включи канал тринадцать": "channel_13",
    "переключи на тринадцатый": "channel_13",
    
    # 14
    "четырнадцатый": "channel_14",
    "четырнадцать": "channel_14",
    "канал четырнадцать": "channel_14",
    "четырнадцатый канал": "channel_14",
    "включи четырнадцатый": "channel_14",
    "включи четырнадцатый канал": "channel_14",
    "включи канал четырнадцать": "channel_14",
    "переключи на четырнадцатый": "channel_14",
    
    # 15
    "пятнадцатый": "channel_15",
    "пятнадцать": "channel_15",
    "канал пятнадцать": "channel_15",
    "пятнадцатый канал": "channel_15",
    "включи пятнадцатый": "channel_15",
    "включи пятнадцатый канал": "channel_15",
    "включи канал пятнадцать": "channel_15",
    "переключи на пятнадцатый": "channel_15",
    
    # 16
    "шестнадцатый": "channel_16",
    "шестнадцать": "channel_16",
    "канал шестнадцать": "channel_16",
    "шестнадцатый канал": "channel_16",
    "включи шестнадцатый": "channel_16",
    "включи шестнадцатый канал": "channel_16",
    "включи канал шестнадцать": "channel_16",
    "переключи на шестнадцатый": "channel_16",
    
    # 17
    "семнадцатый": "channel_17",
    "семнадцать": "channel_17",
    "канал семнадцать": "channel_17",
    "семнадцатый канал": "channel_17",
    "включи семнадцатый": "channel_17",
    "включи семнадцатый канал": "channel_17",
    "включи канал семнадцать": "channel_17",
    "переключи на семнадцатый": "channel_17",
    
    # 18
    "восемнадцатый": "channel_18",
    "восемнадцать": "channel_18",
    "канал восемнадцать": "channel_18",
    "восемнадцатый канал": "channel_18",
    "включи восемнадцатый": "channel_18",
    "включи восемнадцатый канал": "channel_18",
    "включи канал восемнадцать": "channel_18",
    "переключи на восемнадцатый": "channel_18",
    
    # 19
    "девятнадцатый": "channel_19",
    "девятнадцать": "channel_19",
    "канал девятнадцать": "channel_19",
    "девятнадцатый канал": "channel_19",
    "включи девятнадцатый": "channel_19",
    "включи девятнадцатый канал": "channel_19",
    "включи канал девятнадцать": "channel_19",
    "переключи на девятнадцатый": "channel_19",
    
    # 20
    "двадцатый": "channel_20",
    "двадцать": "channel_20",
    "канал двадцать": "channel_20",
    "двадцатый канал": "channel_20",
    "включи двадцатый": "channel_20",
    "включи двадцатый канал": "channel_20",
    "включи канал двадцать": "channel_20",
    "переключи на двадцатый": "channel_20",

    "спать": "sleep",
    "замолчи": "silence",
    "погода": "weather",
    "время": "time",
    "привет": "hello"
}

# Индекс устройства (измените под свой микрофон)
MICROPHONE_DEVICE_INDEX = 3  # None = устройство по умолчанию
INCOMMAND_LED = 38 # включаеться когда слушает комманды
MODEL_PATH = "model"  # Путь к папке с моделью Vosk
IRCODE_PATH = "ircode" # Путь к папке с описанием IR последовательностей
# ==================================================

class VoiceAssistant:
    def __init__(self):
        print("Загрузка модели Vosk...")
        try:
            self.model = Model(MODEL_PATH)
        except Exception as e:
            print(f"❌ Ошибка загрузки модели: {e}")
            print(f"💡 Убедитесь, что модель Vosk находится в папке '{MODEL_PATH}'")
            sys.exit(1)
        
        # Создаём распознаватель в грамматическом режиме
        grammar = f'["{KEYWORD}"'
        for cmd_phrase, cmd_action in COMMANDS.items():
            grammar+=', "'+cmd_phrase+'"'
        grammar+=', "[unk]"]'
        #print(grammar)
        self.recognizer = KaldiRecognizer(self.model, TARGET_SR, grammar)
        print("✅ Модель загружена. Грамматика настроена.")
        
        self.is_awake = False
        self.silent_frames = 0
        self.running = True
        self.audio_queue = queue.Queue()
        
        # для передачи IR на телевизор
        self.ir = cgir.Infrared()        
        self.remote_led = INCOMMAND_LED
        if self.remote_led > 0:
            print("Flashing LED on GPIO", self.remote_led)
            GPIO.setwarnings(False)      # Disable warnings
            GPIO.setmode(GPIO.BOARD)       # Use BCM GPIO numbers
            GPIO.setup(self.remote_led, GPIO.OUT)  # Output LED
        else:
            log.message("Remote control LED disabled", log.DEBUG)
        GPIO.output(self.remote_led, self.is_awake)
        
        # Настройка сигналов
        signal.signal(signal.SIGINT, self.signal_handler)
        signal.signal(signal.SIGTERM, self.signal_handler)
        
        # Коэффициент передискретизации
        self.resample_ratio = TARGET_SR / CAPTURE_SR
        print(f"🎥 USB-камера: {CAPTURE_SR} Гц, {CAPTURE_CHANNELS} канала")
        print(f"🔊 Передискретизация в {TARGET_SR} Гц, моно (коэф. {self.resample_ratio:.3f})")
        
        # Инициализация PyAudio
        self.audio = pyaudio.PyAudio()
        
        # Проверка доступных устройств
        self.show_devices()
        
        print(f"\n🔑 Ключевое слово: '{KEYWORD}'")
        print(f"📋 Доступные команды: {', '.join(COMMANDS.keys())}")
        print("🎤 Говорите... Нажмите Ctrl+C для выхода.\n")

    def signal_handler(self, sig, frame):
        print("\n\nЗавершение работы...")
        self.running = False

    def show_devices(self):
        """Показывает доступные аудиоустройства"""
        print("\n🔍 Доступные устройства записи:")
        for i in range(self.audio.get_device_count()):
            info = self.audio.get_device_info_by_index(i)
            if info['maxInputChannels'] > 0:
                print(f"  {i}: {info['name']} (каналов: {info['maxInputChannels']})")
        
        if MICROPHONE_DEVICE_INDEX is not None:
            print(f"\n✅ Используется устройство: {MICROPHONE_DEVICE_INDEX}")
        else:
            print("\n✅ Используется устройство по умолчанию")

    def audio_callback(self, in_data, frame_count, time_info, status):
        """Callback для захвата звука с микрофона"""
        #if status:
        #    print(f"⚠️ Ошибка аудио: {status}", file=sys.stderr)

        # Конвертируем байты в numpy массив
        audio_data = np.frombuffer(in_data, dtype=np.int16)
        
        # стерео (2 канала) - усредняем до моно
        if CAPTURE_CHANNELS==2 :
            audio_data = audio_data.reshape(-1, 2).mean(axis=1).astype(np.int16)
        
        self.audio_queue.put(audio_data)
        return (None, pyaudio.paContinue)

    def process_audio(self):
        """Обработка аудио из очереди"""
        audio_buffer = []
        samples_per_buffer = int(CAPTURE_SR * 1.5)  # 1.5 секунды аудио
        
        while self.running:
            try:
                audio_chunk = self.audio_queue.get(timeout=0.5)
                audio_buffer.extend(audio_chunk)
                
                if len(audio_buffer) >= samples_per_buffer:
                    # Берём кусок аудио
                    audio_data = np.array(audio_buffer[:samples_per_buffer], dtype=np.int16)
                    audio_buffer = audio_buffer[samples_per_buffer:]
                              
                    # Передискретизация (44.1 → 16 кГц) - быстрая
                    if TARGET_SR!=CAPTURE_SR :
                        audio_resampled = samplerate.resample(
                          audio_data, 
                          self.resample_ratio, 
                         'sinc_fastest'
                         ).astype(np.int16)
                                        
                    # Отправляем в Vosk
                    if self.recognizer.AcceptWaveform(audio_resampled.tobytes()):
                        # Получаем результат
                        result_json = json.loads(self.recognizer.Result())
                        recognized_text = result_json.get("text", "").strip()
                        
                        if recognized_text and recognized_text != "[unk]":
                            self.process_transcription(recognized_text)
                    else:
                        # Частичный результат (для отладки)
                        partial = json.loads(self.recognizer.PartialResult())
                        partial_text = partial.get("partial", "").strip()
                        if partial_text and len(partial_text) > 0:
                            # Можно выводить для отладки
                            #print(f"⏳ Частично: '{partial_text}'", end='\r')
                            pass
                        
            except queue.Empty:
                continue
            except Exception as e:
                print(f"⚠️ Ошибка в цикле: {e}", file=sys.stderr)

    def process_transcription(self, text):
        """Обработка распознанного текста"""
        text_lower = text.lower()
        status = "🔊" if self.is_awake else "💤"
        print(f"{status} Распознано: '{text}'")
        
        if not self.is_awake:
            if KEYWORD in text_lower:
                self.is_awake = True
                GPIO.output(self.remote_led, self.is_awake)
                self.silent_frames = 0
                print(f"🔊 Услышала '{KEYWORD}'! Просыпаюсь...")
                print("💬 Я слушаю ваши команды...")
        else:
            # Режим бодрствования
            self.silent_frames = 0
            command_executed = False
            
            # Проверяем команды
            for cmd_phrase, cmd_action in COMMANDS.items():
                if cmd_phrase in text_lower:
                    self.execute_command(cmd_action, text)
                    command_executed = True
                    break
            
            # Если это не команда, но сказали ключевое слово
            if not command_executed and KEYWORD in text_lower:
                print("👋 Я уже здесь! Скажите команду.")
            
            # Если текст содержит что-то кроме [unk] и не является командой
            elif not command_executed and len(text) > 0 and text != "[unk]":
                print(f"❓ Неизвестная команда: '{text}'")
                print("💡 Доступные команды: " + ", ".join(COMMANDS.keys()))

    def execute_command(self, command, original_text):
        """Выполнение команд"""
        print(f"✅ Выполняется команда: '{original_text}'")
        
        if command in ["sleep", "silence"]:
            print("😴 Засыпаю...")
            self.is_awake = False
            GPIO.output(self.remote_led, self.is_awake)
            self.silent_frames = 0
        elif command == "weather":
            print("🌤️ Погода: +22°C, солнечно")
            self.silent_frames = 0
        elif command == "time":
            current_time = time.strftime("%H:%M")
            print(f"🕐 Текущее время: {current_time}")
            self.silent_frames = 0
        elif command == "hello":
            print("👋 Привет! Чем могу помочь?")
            self.silent_frames = 0
        else:
            print(f"команда: {command}")
            self.ir.codes_path=IRCODE_PATH+"\\"+command+".json"
            self.ir.load_codes()
            self.ir.send(self.ir.codes)

    def check_silence_timeout(self):
        """Проверка таймаута тишины"""
        while self.running:
            time.sleep(1.0)
            if self.is_awake:
                self.silent_frames += 1
                if self.silent_frames > SILENCE_TIMEOUT:
                    print(f"⏰ Таймаут тишины ({SILENCE_TIMEOUT} сек). Засыпаю...")
                    self.is_awake = False
                    GPIO.output(self.remote_led, self.is_awake)
                    self.silent_frames = 0

    def run(self):
        """Запуск ассистента"""
        print("🎙️ Запуск микрофона...")
        
        # Поток для обработки аудио
        process_thread = threading.Thread(target=self.process_audio, daemon=True)
        process_thread.start()
        
        # Поток для проверки тишины
        silence_thread = threading.Thread(target=self.check_silence_timeout, daemon=True)
        silence_thread.start()
        
        # Открываем поток для захвата звука
        try:
            stream = self.audio.open(
                format=FORMAT,
                channels=CAPTURE_CHANNELS,  # 2 канала (стерео) - как у камеры
                rate=CAPTURE_SR,            # 44.1 кГц - как у камеры
                input=True,
                frames_per_buffer=CHUNK,
                input_device_index=MICROPHONE_DEVICE_INDEX,
                stream_callback=self.audio_callback
            )
        except Exception as e:
            print(f"❌ Ошибка открытия микрофона: {e}")
            print("💡 Проверьте правильность индекса устройства.")
            sys.exit(1)
        
        print("🎧 Слушаю... Говорите!")
        print(f"💡 Скажите '{KEYWORD}', чтобы разбудить меня.")
        print("----------------------------------------")
        
        stream.start_stream()
        
        try:
            while self.running:
                time.sleep(0.1)
        except KeyboardInterrupt:
            print("\n👋 До свидания!")
        finally:
            self.running = False
            stream.stop_stream()
            stream.close()
            self.audio.terminate()
            process_thread.join(timeout=2.0)
            silence_thread.join(timeout=2.0)
            print("Программа завершена.")

if __name__ == "__main__":
    assistant = VoiceAssistant()
    assistant.run()

