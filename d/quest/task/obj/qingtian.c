inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIY"��������"NOR, ({"biyu pipa","pipa"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ħ����ר�õķ�����\n");
                set("unit", "��");
               set("owner_name","ħ����");
               set("owner_id","moli shou");
        }
}

