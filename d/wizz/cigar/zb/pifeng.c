
#include <armor.h>
#include <ansi.h>


inherit SURCOAT;


void create()
{
        set_name(HIB"��"+HIM"��"+HIY"����"NOR, ({"tiancai pifeng","pifeng","cloth"}) );
        set("long", "��˵�˼��������ռ���Ů洲���ʣ�µ����ʯ�����Ƴɵġ�\n");
	set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		
                set("unit", "��");
                set("long","�׺����硣\n");
                set("no_put",1); 
set("value", 15000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
                set("no_give",1);
                set("no_zm",11);
          	set("material", "leather");
                set("armor_prop/armor", 75);
//:                set("armor_prop/dodge", 70);
             }
 		setup();
}

