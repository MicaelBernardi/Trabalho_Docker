<%@page contentType="text/html; charset=UTF-8" language="java" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<%@page isELIgnored="false" %>

<html>
<head>
    <title>Clientes</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.6/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-4Q6Gf2aSP4eDXB8Miphtr37CMZZQ5oXLH2yaXMJ2w8e2ZtHTl7GptT4jmndRuHDT" crossorigin="anonymous">
</head>
<body>

<nav class="navbar navbar-expand-lg bg-body-secondary sticky-top fs-5">
    <div class="container-fluid">
        <a class="navbar-brand fs-4 fw-medium" href="inicio">Agendamentos</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav"
                aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav">
                <li class="nav-item">
                    <a class="nav-link" href="inicio">Página Inicial</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link active" href="cliente" aria-current="page">Clientes</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="servico">Servicos</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="funcionario">Funcionarios</a>
                </li>
            </ul>

            <ul class="navbar-nav ms-auto mb-2 mb-lg-0 me-5">
                <li class="nav-item">
                    <a class="nav-link" href="login">Sair</a>
                </li>
            </ul>

        </div>
    </div>
</nav>

<h1 class="text-center">Cadastro de clientes</h1>

<div class="d-flex justify-content-lg-center">
    <form:form action="cliente" method="post" modelAttribute="cliente" class="w-50">
        <h2>${cliente.id != null && cliente.id > 0 ? 'Editar Cliente' : 'Adicionar Cliente'}></h2>
        <form:hidden path="id"/>

        <div class="mb-1">
            <form:label path="nome" class="form-label">Nome:</form:label>
            <form:input path="nome" class="form-control" placeholder="Nome" required="true"/>
        </div>

        <div class="mb-1">
            <form:label path="cpf" class="form-label">Cpf:</form:label>
            <form:input path="cpf" class="form-control" placeholder="Cpf" required="true"/>
        </div>

        <div class="mb-1">
            <form:label path="telefone" class="form-label">Telefone:</form:label>
            <form:input path="telefone" class="form-control" placeholder="Telefone" required="true"/>
        </div>

        <input type="submit" value="${cliente.id != null && cliente.id > 0 ? 'Alterar' : 'Cadastrar'}" class="btn btn-primary mt-3"/>
    </form:form>
</div>

<div class="d-flex justify-content-lg-center mb-2">
    <c:if test="${not empty msg}">
        <h3 class="text-center"><u>${msg}</u></h3>
    </c:if>

</div>
<div class="d-flex justify-content-lg-center">
    <h1 class="text-center">Lista de CLientes</h1>
</div>

<div class="d-flex justify-content-lg-center">
    <table class="table table-bordered w-50">
        <th>Nome</th>
        <th>Cpf</th>
        <th>Telefone</th>
        <th>Ações</th>
        <c:forEach var="cliente" items="${clientes}">
            <tr>
                <td>${cliente.nome}</td>
                <td>${cliente.cpf}</td>
                <td>${cliente.telefone}</td>

                <td>
                    <a href="cliente/editar/${cliente.id}" class="btn btn-warning btn-sm me-2">Editar</a>
                    <a href="cliente/excluir/${cliente.id}" class="btn btn-danger btn-sm">Excluir</a>
                </td>
            </tr>
        </c:forEach>
    </table>
</div>
</body>
</html>
