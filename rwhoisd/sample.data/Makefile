.PORIX:

INSTALL = install

RWHOIS_ROOT_DIR = /etc/rwhoisd/samples

FILES = \
        a.com \
        net-10.0.0.0-8 \
	net-fd00:1234::-32 \
        rwhoisd.allow \
        rwhoisd.auth_area \
        rwhoisd.conf \
        rwhoisd.deny \
        rwhoisd.dir \
        rwhoisd.root \
        rwhoisd.x.dir

all:

install:
	- [ -d $(DESTDIR)$(RWHOIS_ROOT_DIR) ] || mkdir -p $(DESTDIR)$(RWHOIS_ROOT_DIR)
	@for file in $(FILES); do \
	  echo "installing $$file into $(DESTDIR)$(RWHOIS_ROOT_DIR)"; \
	  (cp -pr $$file $(DESTDIR)$(RWHOIS_ROOT_DIR)) || exit 1; \
	done
	(sh ../tools/scripts/setup_rwhois_conf $(RWHOIS_ROOT_DIR) \
	    $(DESTDIR)$(RWHOIS_ROOT_DIR)/rwhoisd.conf)

uninstall:
	@for file in $(FILES); do \
	  echo "removing $$file from $(DESTDIR)$(RWHOIS_ROOT_DIR)"; \
	  ($(RM) -r $(DESTDIR)$(RWHOIS_ROOT_DIR)/$$file) || exit 1; \
	done

clean:

distclean: clean
	@if [ -d $(DESTDIR)$(RWHOIS_ROOT_DIR) ]; then \
		find $(DESTDIR)$(RWHOIS_ROOT_DIR) \
	  	\( -name "local.db" -o -name "index-*.ndx" \) -exec rm {} \;; \
        fi
