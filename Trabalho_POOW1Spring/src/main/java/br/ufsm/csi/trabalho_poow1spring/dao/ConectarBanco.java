package br.ufsm.csi.trabalho_poow1spring.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConectarBanco {

public static Connection conectarBancoPostgres() throws ClassNotFoundException, SQLException {
    Class.forName("org.postgresql.Driver");
    System.out.println("Driver carregado");

    String url = System.getenv("SPRING_DATASOURCE_URL");
    String user = System.getenv("SPRING_DATASOURCE_USERNAME");
    String senha = System.getenv("SPRING_DATASOURCE_PASSWORD");

    if (url == null) {
        url = "jdbc:postgresql://localhost:5432/trabalhopoow1";  // fallback para desenvolvimento local
    }
    if (user == null) {
        user = "postgres";
    }
    if (senha == null) {
        senha = "1234";
    }

    Connection conn = DriverManager.getConnection(url, user, senha);
    return conn;
}

    public Connection conectarBancoPostgresMySql(){
        return null;
    }
}
