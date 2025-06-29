FROM eclipse-temurin:21-jdk-alpine

# Install PostgreSQL and dependencies (without JDBC package)
RUN apk add --no-cache \
    postgresql \
    postgresql-client \
    bash \
    tini

# Configure PostgreSQL directories
RUN mkdir -p /var/lib/postgresql/data && \
    chown postgres:postgres /var/lib/postgresql/data

# Build application
WORKDIR /app
RUN git clone https://github.com/MicaelBernardi/Trabalho_Docker.git ./
WORKDIR /app/Trabalho_POOW1Spring
RUN mvn clean package -DskipTests

# Combined entrypoint for PostgreSQL and Spring Boot
ENTRYPOINT ["/sbin/tini", "--", "sh", "-c", " \
  su postgres -c 'initdb -D /var/lib/postgresql/data' && \
  su postgres -c 'pg_ctl -D /var/lib/postgresql/data -l logfile start' && \
  until su postgres -c 'psql -c \"CREATE DATABASE appdb;\"' 2>/dev/null; do sleep 1; done && \
  cd /app/Trabalho_POOW1Spring && \
  java -jar target/Trabalho_POOW1Spring-0.0.1-SNAPSHOT.jar \
"]

EXPOSE 5432 8080
