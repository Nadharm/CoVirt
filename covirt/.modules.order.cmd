cmd_/home/osiris/CoVirt/covirt/modules.order := {   echo /home/osiris/CoVirt/covirt/covirt_module.ko; :; } | awk '!x[$$0]++' - > /home/osiris/CoVirt/covirt/modules.order
