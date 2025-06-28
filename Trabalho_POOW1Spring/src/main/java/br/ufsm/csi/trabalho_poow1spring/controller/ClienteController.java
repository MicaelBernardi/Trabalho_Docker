package br.ufsm.csi.trabalho_poow1spring.controller;

import br.ufsm.csi.trabalho_poow1spring.model.Cliente;
import br.ufsm.csi.trabalho_poow1spring.service.ClienteService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

@Controller
@RequestMapping("/cliente")
public class ClienteController {

    @GetMapping
    public String listaClientes(Model model) {
        model.addAttribute("clientes", new ClienteService().listar());
        model.addAttribute("cliente", new Cliente());

        return "pages/clientes";
    }

    @PostMapping
    public String criarCliente(Cliente cliente, RedirectAttributes redirectAttributes) {
        String retorno = new ClienteService().inserir(cliente);
        redirectAttributes.addFlashAttribute("mensagem", retorno);

        return "redirect:/cliente";
    }

    @GetMapping("/excluir/{clienteId}")
    public String excluir(@PathVariable int clienteId, RedirectAttributes redirectAttributes) {
        String retorno = new ClienteService().excluir(clienteId);
        redirectAttributes.addFlashAttribute("mensagem", retorno);

        return "redirect:/cliente";
    }
}
