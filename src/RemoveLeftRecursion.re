let primeSufix = "1";
let argsList = Array.to_list(Node.Process.argv);
let grammar = switch argsList {
  | [_, _, ...grammar] => grammar |> Array.of_list
  | _ => { Js.log("Error, never reach here!"); Node.Process.exit(1); [|""|] };
}

let getNonTerminalOrExit = char => {
  if (Js.String.toLowerCase(char) == char) {
    Js.log("Incorect use. First should be Nonterminal: 'A,Aa', 'A,a'"); Node.Process.exit(1);
  }
  char;
}

let tupleFromString = rule => {
  let arr = LabsUtils.getArrayFromString(rule, e => e);
  switch arr {
  | [| nonterminal, result |] => (getNonTerminalOrExit(nonterminal), result)
  | _ => { Js.log("Error args should be like 'A,Aa', 'A,a'"); Node.Process.exit(1);  ("", "") };
  };
}

let grammarTuples = grammar |> Array.map(tupleFromString);

let isLeftRecursionTuples = ruleTuple => {
  let (nonterminal, expresion) = ruleTuple;
  nonterminal == Js.String.get(expresion, 0);
}
let (leftRecursionTuples, noLeftRecursionTuples) = grammarTuples |> Array.to_list |> List.partition(isLeftRecursionTuples);

if (List.length(leftRecursionTuples) == 0) {
  Js.log("No left recursion"); Node.Process.exit(1)
};


let terminalAndPrimeTuples = noLeftRecursionTuples |>
  List.map(((nonterminal, expresion)) => {
    if (Belt.List.some(leftRecursionTuples, ((lRnonterminal, _)) => lRnonterminal == nonterminal)) {
      (nonterminal, expresion ++ nonterminal ++ primeSufix)
    } else {
      (nonterminal, expresion)
    }
  });

let primesToTerminalAndPrimesTuples = leftRecursionTuples |>
  List.map(((nonterminal, expresion)) => (nonterminal ++ primeSufix, Js.String.substr(~from=1, expresion) ++ nonterminal ++ primeSufix ));

let primesToTerminalTuples = leftRecursionTuples |>
  List.map(((nonterminal, expresion)) => (nonterminal ++ primeSufix, Js.String.substr(~from=1, expresion) ));

let showPrettyGrammarRule = ruleTuple => {
  let (nonterminal, expresion) = ruleTuple;
  nonterminal ++ "->" ++ expresion;
}


Js.log("Initial left recursion");
Js.log("========================");
leftRecursionTuples |> Array.of_list |> Array.map(showPrettyGrammarRule) |> Array.iter(Js.log);
noLeftRecursionTuples |> Array.of_list |> Array.map(showPrettyGrammarRule) |> Array.iter(Js.log);
Js.log("========================");
Js.log("");
Js.log("Right recursion");
Js.log("========================");
terminalAndPrimeTuples |> Array.of_list |> Array.map(showPrettyGrammarRule) |> Array.iter(Js.log);
primesToTerminalAndPrimesTuples |> Array.of_list |> Array.map(showPrettyGrammarRule) |> Array.iter(Js.log);
primesToTerminalTuples |> Array.of_list |> Array.map(showPrettyGrammarRule) |> Array.iter(Js.log);
