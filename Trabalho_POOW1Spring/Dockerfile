FROM eclipse-temurin:21-jdk-alpine

# Install build tools and PostgreSQL client
RUN apk add --no-cache \
    git \
    maven \
    bash \
    tini \
    postgresql-client \
    postgresql

WORKDIR /app

# Clone repository
RUN git clone https://github.com/MicaelBernardi/Trabalho_Docker.git ./

WORKDIR /app/Trabalho_POOW1Spring

# Build application
RUN mvn clean package -DskipTests

# Create log directory
VOLUME ["/var/log/app"]
RUN mkdir -p /var/log/app

# Application entry point
ENTRYPOINT ["java", "-jar", "target/Trabalho_POOW1Spring-0.0.1-SNAPSHOT.jar"]
