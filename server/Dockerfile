FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Установка зависимостей
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qtbase5-dev \
    qt5-qmake \
    qtdeclarative5-dev \
    qttools5-dev \
    libqt5sql5-sqlite \
    libqt5network5 \
    && rm -rf /var/lib/apt/lists/*

# Рабочая директория
WORKDIR /app
COPY . .

# Сборка проекта
RUN qmake && make

EXPOSE 33333

CMD ["./myserver"]