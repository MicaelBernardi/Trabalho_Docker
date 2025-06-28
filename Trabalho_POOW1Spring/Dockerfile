# Usar imagem base do Alpine com JDK 21 do Temurin
FROM eclipse-temurin:21-jdk-alpine

# Instalar dependências necessárias (Git, Maven, PostgreSQL e utilitários)
RUN apk add --no-cache \
    git \
    maven \
    postgresql-client \
    bash \
    tini

WORKDIR /app
# Definir diretório de trabalho


# Clonar o repositório (substitua pela URL real)
RUN git clone https://github.com/MicaelBernardi/Trabalho_Docker.git ./
WORKDIR /app/Trabalho_POOW1Spring
# Instalar dependências e construir o projeto
RUN mvn clean package -DskipTests

# Configurar volume para logs
VOLUME ["/var/log/app"]
RUN mkdir -p /var/log/app

ENTRYPOINT ["java", "-jar", "target/Trabalho_POOW1Spring-0.0.1-SNAPSHOT.jar"]
