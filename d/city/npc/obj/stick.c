#include <weapon.h>

inherit STICK;

void create()
{
        set_name("��ħ��", ({"xiangmo bang", "bang"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_sell", 1);
		set("long", "һ�ѵ���ɫ�Ķ̰��������а�����������ͬһ�����߰����ڰ��ϡ�\n");
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
				set("no_give","�ܹܷ���װ�����ɲ���������Ӵ��\n");
				set("no_get","�����ܹ�һҶ֪�﷢��װ�������ΰ�!\n");

        }
        init_stick(60);
        setup();
}

