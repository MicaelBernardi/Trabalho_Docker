FROM eclipse-temurin:21-jdk-alpine

# 1. Instala tudo (PostgreSQL + dependências)
RUN apk add --no-cache \
    postgresql \
    postgresql-client \
    postgresql-jdbc \
    bash \
    tini

# 2. Configura diretórios do PostgreSQL
RUN mkdir -p /var/lib/postgresql/data && \
    chown postgres:postgres /var/lib/postgresql/data

# 3. Cria e constrói a aplicação
WORKDIR /app
RUN git clone https://github.com/MicaelBernardi/Trabalho_Docker.git . && \
    cd Trabalho_POOW1Spring && \
    mvn clean package -DskipTests

# 4. ENTRYPOINT que faz tudo (PostgreSQL + Spring Boot)
ENTRYPOINT ["/sbin/tini", "--", "sh", "-c", " \
  su postgres -c 'initdb -D /var/lib/postgresql/data' && \
  su postgres -c 'pg_ctl -D /var/lib/postgresql/data -l logfile start' && \
  until su postgres -c 'psql -c \"CREATE DATABASE appdb;\"' 2>/dev/null; do sleep 1; done && \
  cd /app/Trabalho_POOW1Spring && \
  java -jar target/Trabalho_POOW1Spring-0.0.1-SNAPSHOT.jar \
"]

# 5. Expõe as portas
EXPOSE 5432 8080
