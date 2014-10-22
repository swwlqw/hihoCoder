all:
	for i in `ls |awk /^[0-9]+$$/{print}`; do \
		(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
	done

clean:
	for i in `ls |awk /^[0-9]+$$/{print}`; do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done

