#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIY"���"NOR, ({"jinbi", "jinbi_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "jinbi");
               set("long", HIY"һö�߿�������Ե��Ӳ�ң������ǰ���ΰ���ͷ�񣬷�����ȫ����ʦ��ȫ�Ҹ���\n"NOR);
                set("unit", "��");
               set("base_value", 200000);
                set("base_unit", "ö");
		set("base_weight", 3);
	}
	set_amount(1);
}

