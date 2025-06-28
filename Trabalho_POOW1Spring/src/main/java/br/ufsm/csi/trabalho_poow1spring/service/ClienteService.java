package br.ufsm.csi.trabalho_poow1spring.service;

import br.ufsm.csi.trabalho_poow1spring.dao.ClienteDAO;
import br.ufsm.csi.trabalho_poow1spring.model.Cliente;

import java.util.ArrayList;

public class ClienteService {
    private static ClienteDAO dao = new ClienteDAO();

    public String inserir(Cliente cliente) {
        return dao.inserir(cliente);
    }

    public String alterar(Cliente cliente) {
        return dao.alterar(cliente);
    }

    public String excluir(int id) {
        if (dao.excluir(id)) {
            return "Sucesso ao excluir cliente";
        } else {
            return "Erro ao excluir cliente";
        }
    }

    public ArrayList<Cliente> listar() {
        return dao.listar();
    }

    public Cliente buscar(int id) {
        return dao.buscar(id);
    }

}
