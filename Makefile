all:
	for i in `ls -l |awk '/^[d]/{print $$NF}'` ; do \
		(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
	done

clean:
	for i in `ls -l |awk '/^[d]/{print $$NF}'` ; do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done

