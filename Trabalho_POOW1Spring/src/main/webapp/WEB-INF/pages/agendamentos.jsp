<%@page contentType="text/html; charset=UTF-8" language="java" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="C" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page isELIgnored="false" %>

<html>
<head>
    <title>Agendamentos</title>
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
                    <a class="nav-link" href="cliente">Clientes</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link active" href="servico" aria-current="page">Servicos</a>
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


<div class="d-flex justify-content-lg-center">
    <form action="agendamento" method="post" class="w-50">

        <div class="container text-center">

            <c:choose>
                <c:when test="${agendamento.id != null}">
                    <h2>Editar Agendamento</h2>
                    <input type="hidden" name="idagendamento" value="${agendamento.id}">
                </c:when>
                <c:otherwise>
                    <h2>Adicionar Agendamento</h2>
                    <input type="hidden" name="idagendamento" value="0">
                </c:otherwise>
            </c:choose>

            <div class="row align-items-start">

                <div class="col mb-1">
                    <label for="cliente" class="form-label">Cliente:</label>
                    <select class="form-select" name="idcliente">
                        <c:forEach var="cliente" items="${clientes}">
                            <option value="${cliente.id}" <c:if test="${agendamento.cliente.id == cliente.id}">selected</c:if>>${cliente.nome}</option>
                        </c:forEach>
                    </select>
                </div>

                <div class="col mb-1">
                    <label for="funcionario" class="form-label">Funcionario:</label>
                    <select class="form-select" name="idfuncionario">
                        <c:forEach var="funcionario" items="${funcionarios}">
                        <option value="${funcionario.id}" <c:if test="${agendamento.funcionario.id == funcionario.id}">selected</c:if>>${funcionario.nome}</option>
                        </c:forEach>
                    </select>
                </div>

                <div class="col mb-1">
                    <label for="servico" class="form-label">Serviço:</label>
                    <select class="form-select" name="idservico">
                        <c:forEach var="servico" items="${servicos}">
                            <option value="${servico.id}" <c:if test="${agendamento.servico.id == servico.id}">selected</c:if>>${servico.descricao}</option>
                        </c:forEach>
                    </select>
                </div>

            </div>

            <div class="col mb-1 mt-3">
                <label for="data" class="form-label">Data:</label>
                <input type="date" class="form-control" id="data" name="data" required value="${agendamento.data}">
            </div>

        </div>

        <div class="text-center mt-3">
            <c:choose>
                <c:when test="${agendamento.id != null}">
                    <button type="submit" value="Alterar" name="gravar" class="btn btn-primary">Alterar</button>
                </c:when>
                <c:otherwise>
                    <button type="submit" value="Cadastrar" name="gravar" class="btn btn-primary">Cadastrar</button>
                </c:otherwise>
            </c:choose>
        </div>
    </form>
</div>


<h1 class="text-center">Lista de Agendamentos</h1>

<div class="d-flex justify-content-lg-center">
    <table class="table table-bordered w-75">
        <th>Data</th>
        <th>Cliente</th>
        <th>Funcionario</th>
        <th>Servico</th>
        <th>Status</th>
        <th>Opções</th>
        <c:forEach var="agendamento" items="${agendamentos}">
            <tr>
                <td>${agendamento.data}</td>
                <td>${agendamento.cliente.nome}</td>
                <td>${agendamento.funcionario.nome}</td>
                <td>${agendamento.servico.descricao}</td>
                <td>${agendamento.status}</td>
                <td>
                    <a href="agendamento?opcao=editar&&info=${agendamento.id}" class="btn btn-warning btn-sm me-2">Editar</a>
                    <a href="agendamento?opcao=excluir&&info=${agendamento.id}"
                       class="btn btn-danger btn-sm">Excluir</a>
                </td>
            </tr>
        </c:forEach>
    </table>
</div>

</body>
</html>
