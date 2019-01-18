#include <ansi.h>

#include "/adm/simul_efun/wizard.c"
#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/user.c"

// This must be after wizard.c and chinese.c
#include "/adm/simul_efun/override.c"

// This must be after gender.c
#include "/adm/simul_efun/message.c"

// This is the utilitis
#include "/adm/simul_efun/util.c"

// This is about color
#include "/adm/simul_efun/color.c"

// This is some maths
#include "/adm/simul_efun/math.c"

void create()
{
	seteuid(getuid());
	write("simul_efun loaded successfully.\n");
}

