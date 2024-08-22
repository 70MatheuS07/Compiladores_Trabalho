echo "Testes lexicos"
./test_analyzer_lex.sh
echo ""

echo "Testes sem erro"
./test_analyzer_noerr.sh
echo ""

echo "Testes semânticos"
./test_analyzer_sem.sh
echo ""

echo "Testes sintáticos"
./test_analyzer_syn.sh
echo ""
