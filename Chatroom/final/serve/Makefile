include scripts/Makefile

.PHONY : all mm mc clean

all : $(Target)

mm:
	cd main && $(MAKE)
	cd Start && $(MAKE)
	cd Pass && $(MAKE)
	cd Select_func && $(MAKE)
	cd func/Look && $(MAKE)
	cd func/Chat && $(MAKE)
	cd func/All_Chat && $(MAKE)
	cd func/Fast && $(MAKE)
	cd func/Face && $(MAKE)
	cd func/Change && $(MAKE)
	cd func/Exit_Log && $(MAKE)
	cd func/Exit && $(MAKE)
	cd func/root && $(MAKE)
	cd func/File && $(MAKE)

mc:
	cd main && $(MAKE) clean
	cd Start && $(MAKE) clean
	cd Pass && $(MAKE) clean
	cd Select_func && $(MAKE) clean
	cd func/Look && $(MAKE) clean
	cd func/Chat && $(MAKE) clean
	cd func/All_Chat && $(MAKE) clean
	cd func/Fast && $(MAKE) clean
	cd func/Face && $(MAKE) clean
	cd func/Change && $(MAKE) clean
	cd func/Exit_Log && $(MAKE) clean
	cd func/Exit && $(MAKE) clean
	cd func/root && $(MAKE) clean
	cd func/File && $(MAKE) clean

$(Target) : mm
	@$(CC) -o $(Target) $(Allobjs) -lpthread -lsqlite3

clean : mc
	@rm -rf $(Targer) client

