
#include <armor.h>
#include <ansi.h>


inherit SURCOAT;


void create()
{
	set_name(HIC"�׺�����"NOR, ({"baihu pifeng","pifeng","cloth"}) );
	set("long", "��˵�˼��������ռ��˼�ǧֻ�׺���Ҹ�µ�С��Ƥë���ƶ��ɡ�\n");
	set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		
                set("unit", "��");
                set("long","�׺����硣\n");
                set("no_put",1); 
                set("value",0);      
                set("no_sell",1);
                set("no_give",1);
                set("no_zm",11);
          	set("material", "leather");
                set("armor_prop/armor", 50);
                set("armor_prop/dodge", 10);
             }
 		setup();
}

