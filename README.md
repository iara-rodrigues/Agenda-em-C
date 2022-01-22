# Agenda-em-C

Desenvolvido por Iara Rodrigues Grigorio Oliveira Silva.

Para executar precisa compilar todos os arquivos, por exemplo: <code>gcc main.c evento.c evento.h agenda.c agenda.h -o run</code>.

Desenvolvido pelo Windows;

<b> Resumo das Funcionalidades desse Programa: </b>
<ul>
  <li>Gerenciar usuários, ou seja, criar e listar usuários. </li>
  <li>Entrar na agenda de um dado usuário. </li>
  <li>Assim como cadastrar Tarefa, Reunião e Aniversário. </li>
  <li>Imprimir agenda. </li>
</ul>

<p>O programa é multiusuário e cada um possui sua própria agenda. Um usuário possui nome e email. </p>
<p>O programa possui interface em linha de comando.</p>
<p>Possui três tipos de evento: <b>Tarefa</b>, <b>Reunião</b> e <b>Aniversário</b>.</p>
<ul>
   <li>Uma <b>Tarefa</b> é um evento que apresenta as seguintes informações: assunto, horário de início (número inteiro de 0 a 23), horário de término (número inteiro de 0 a 23), grau de esforço (número inteiro entre 1 e 5) e prioridade (número inteiro entre 1 e 10).</li>
  <li>Uma <b>Reunião</b> é um evento que também possui assunto, horário de início e término, além de informações sobre o local onde a mesma irá ocorrer e se a presença é obrigatória ou não.</li>
  <li>Um <b>Aniversário</b> é um evento que possui assunto, horário de inicio e termino, informações sobre o local onde irá acontecer e o nome do aniversariante.</li>
</ul>
<p>Observações:</p>
<ul>
  <li>O programa impede a inclusão de Tarefas, Reuniões e Aniversários com horários de inicio coincidentes.</li>
  <li>O programa impede a inclusão de Tarefas e Reuniões com horarios de inicio e fim fora da faixa de valores inteiros válidos.</li>
  <li>O programa impede a inclusão de Tarefas com grau de esforço fora da faixa de valores inteiros válidos (entre 1 e 5) ou valor da Prioridade fora dos valores válidos (entre 1 e 10).</li>
</ul>
