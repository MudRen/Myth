//Cracked by Roath
#include <ansi.h>
inherit ITEM;
void create()
{
		set_name(HIM"���絤"NOR, ({"dingfeng dan", "dan"}) );
                set("long","���������鼪������������֮һ���ж���֮��Ч��\n");

		set_weight(100);
        	if( clonep() )
 	 set_default_object(__FILE__);
  	else {
	  set("unit", "��");
  	set("material", "crystal");
  	set("value",1);
  	set("no_sell",1);
  	set("no_give",1);
  	set("no_drop",1);
	set("no_get",1);
 	}
 	setup();
}
