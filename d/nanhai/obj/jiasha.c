//Cracked by Roath
// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void init()
{
  cloth::init();
  unique::init();
  if(userp(this_player()))
      call_out("self_dest",600+random(600));
}

void self_dest()
{
    object env=environment(this_object());
    if(env)
	tell_object(env, name()+"��������ɢ��������ȥ�ˡ�\n");
    destruct(this_object());
}

void create()
{
	set_name(HIY"��������"NOR, ({ "jinlan jiasha", "jiasha" }) );
	set("long", "����������������֮�������ģ���˵���Ͽ�����ֻء�\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 90);
		set("armor_prop/spells", 50);
		set("armor_prop/dodge", 20);
		set("no_sell", 1);
//		set("no_drop", 1);
		set("no_put", 1);
		set("replace_file", "/d/obj/cloth/hufa-jiasha");
                set("value", 50000);
	}
	setup();
}

