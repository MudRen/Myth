//����
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "����������" NOR, ({ "cunzheng", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "�����г�73.32CM�����ĩ�ڵ������ݴ���������ն��������\n����ͣ����´�����Ϊ������������������֮Ϊ����������������\n����Ļĩʱ�ĳ��ݵ�Ļ�����������ߡ�����������\n");
                set("wield_msg","$N��������һ����������һ�����Σ�һ�ɽ�������Ϯ��\n");
                set("unwield_msg", "$N��$n�ջ����䣬�����ĳ��˿�����\n");
                                set("no_sell",1);
                                set("no_get","�ú����ǲ�������ñ��˵Ķ�����Ŷ��\n");
                }
        init_sword(200);
        setup();
}

