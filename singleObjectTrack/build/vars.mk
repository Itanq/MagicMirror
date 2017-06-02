%:
	@echo '$*=$($*)'
 
d-%:
	@echo '$*=$($*)'
	@echo '$*-$($*)'
	@echo ' origin=$(origin $*)'
	@echo 'value=$(value $*)'
	@echo 'flvaor=$(flavor $*)'
