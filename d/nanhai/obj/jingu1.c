//Cracked by Roath
// jingu.c ������

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"������"NOR, ({ "jingu zhou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ƪ");
        set("long",
        "�����䣬�ֻ������������ԡ���ײ����ͨ������ħ��ֻ�����õ�������һ��ܽ�������������\n");
        set("material", "paper");       
        }
	setup();
}

void init()
{
	if (this_player() -> query("family/family_name") != "�Ϻ�����ɽ" ) {
		remove_call_out("free_jingu");
		call_out("free_jingu", 120, this_object(), this_player()); 
	}

	::init();
}

void free_jingu(object ob, object who)
{
        if(!who || !ob) return;

	if (who -> query("family/family_name") != "�Ϻ�����ɽ" ) {
		tell_object(who, HIR"��·���������˵���Ƿ������ˣ���֮���ã�������֮��\n"
			+ "����һ�����죬���������ڿն�ȥ��������һ˿�ۼ���\n\n"NOR);
		destruct(ob);
	}
	else { 
		call_out("free_jingu", 120, ob, who);
	}
	return;
}
