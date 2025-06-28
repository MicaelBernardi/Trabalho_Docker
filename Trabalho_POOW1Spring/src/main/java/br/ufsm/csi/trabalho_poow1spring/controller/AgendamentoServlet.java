package br.ufsm.csi.trabalho_poow1spring.controller;

import br.ufsm.csi.trabalho_poow1spring.model.Agendamento;
import br.ufsm.csi.trabalho_poow1spring.model.Cliente;
import br.ufsm.csi.trabalho_poow1spring.model.Funcionario;
import br.ufsm.csi.trabalho_poow1spring.model.Servico;
import br.ufsm.csi.trabalho_poow1spring.service.AgendamentoService;
import br.ufsm.csi.trabalho_poow1spring.service.ClienteService;
import br.ufsm.csi.trabalho_poow1spring.service.FuncionarioService;
import br.ufsm.csi.trabalho_poow1spring.service.ServicoService;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;

@WebServlet("agendamento")
public class AgendamentoServlet extends HttpServlet {

    private static AgendamentoService agendamentoService = new AgendamentoService();
    private static ClienteService clienteService = new ClienteService();
    private static FuncionarioService funcionarioService = new FuncionarioService();
    private static ServicoService servicoService = new ServicoService();

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        int id = Integer.parseInt(req.getParameter("idagendamento"));
        String data = req.getParameter("data");
        Agendamento agendamento = new Agendamento();

        int idcliente = Integer.parseInt(req.getParameter("idcliente"));
        Cliente cliente = clienteService.buscar(idcliente);
        agendamento.setCliente(cliente);

        int idfunc = Integer.parseInt(req.getParameter("idfuncionario"));
        Funcionario funcionario = funcionarioService.buscar(idfunc);
        agendamento.setFuncionario(funcionario);

        int idservico = Integer.parseInt(req.getParameter("idservico"));
        Servico servico = servicoService.buscar(idservico);
        agendamento.setServico(servico);

        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd");
        try {
            agendamento.setData(formatter.parse(data));
        } catch (ParseException e) {
            throw new RuntimeException(e);
        }

        agendamento.setStatus("Agendado");

        String retorno;
        if (id > 0) {
            agendamento.setId(id);
            retorno = new AgendamentoService().alterar(agendamento);
        } else {
            retorno = new AgendamentoService().inserir(agendamento);
        }

        req.setAttribute("retorno", retorno);
        req.setAttribute("agendamentos", new AgendamentoService().listar());

        ArrayList<Agendamento> agendamentos = new AgendamentoService().listar();
        req.setAttribute("agendamentos", agendamentos);
        req.setAttribute("clientes", new ClienteService().listar());
        req.setAttribute("funcionarios", new FuncionarioService().listar());
        req.setAttribute("servicos", new ServicoService().listar());

        RequestDispatcher rd = req.getRequestDispatcher("WEB-INF/pages/agendamentos.jsp");

        rd.forward(req, resp);

    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        String opcao = req.getParameter("opcao");
        String info = req.getParameter("info");

        if (opcao != null) {
            switch (opcao) {
                case "editar":
                    Agendamento agendamento = agendamentoService.buscar(Integer.parseInt(info));
                    req.setAttribute("agendamento", agendamento);
                    break;

                case "excluir":
                    String valor = agendamentoService.excluir(Integer.parseInt(info));
                    req.setAttribute("msg", valor);
                    break;
            }
        }

        ArrayList<Agendamento> agendamentos = new AgendamentoService().listar();
        req.setAttribute("agendamentos", agendamentos);
        req.setAttribute("clientes", new ClienteService().listar());
        req.setAttribute("funcionarios", new FuncionarioService().listar());
        req.setAttribute("servicos", new ServicoService().listar());

        RequestDispatcher rd = req.getRequestDispatcher("WEB-INF/pages/agendamentos.jsp");
        rd.forward(req, resp);

    }
}
